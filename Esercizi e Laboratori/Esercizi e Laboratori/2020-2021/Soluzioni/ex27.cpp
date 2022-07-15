/*

Esercizio 3 del 3/6/2021
Si tratta di un esercizio di pattern matching in cui il pattern è, come di consueto, un array P di interi ma il 
testo è un albero binario T. Si chiede di attraversare T in ordine prefisso e questo significa fissare un ordine
totale dei nodi di T e quindi P va cercato sui campi info di questa sequenza di nodi. Non si richiede che il 
match sia contiguo (cioè non è richiesto che P appaia in nodi contigui della sequenza che corrisponde al 
percorso prefisso) e neppure si richiede che il match sia completo (cioè, non è necessario che tutto P sia 
trovato). Basta matchare nei nodi di T (ordinati secondo il percorso infisso) il prefisso di P più lungo 
possibile.
Esempio: sia P=[12,3,6,5] e T=10(12(4(_,3(_,_)),5(_,_)),7(_,6(_,0(_,_)))). Solo i primi 3 elementi di P si 
trovano in T: P[0]=12 si trova nel figlio sinistro (lo chiamiamo n0) della radice di T, P[1]=3 si trova nel nodo a 
cui si arriva dalla radice seguendo il cammino [0.0,1] (lo chiamiamo n1). Infine P[2]=6 lo si trova nel nodo 
che corrisponde al cammino [1,1,1] (lo chiamiamo n2). Dopo n2, nell’ordine prefisso resta solo il nodo 
[1,1,1,1] che non matcha P[3]. Quindi il match trovato non è completo. Inoltre non è contiguo perché 
l’ordine dei nodi di T secondo l’attraversamento prefisso sarebbe 10, 12, 4, 3, 5, 7, 6, 0 e i match sono quelli 
sottolineati che sono evidentemente non contigui (nell’ordinamento prefisso dei nodi). Si vuole costruire 
una lista costituita da nodi come segue:
struct nodoE{nodo*info; nodoE*next; nodoE(nodo*a=0, nodoE* b=0){info=a; next=b;}};
Per il match dell’esempio precedente, si deve costruire una lista con 3 nodi nodoE, dove il primo punta a 
n0, il secondo a n1 e il terzo a n2. Insomma si vuole produrre una lista di nodoE i cui nodi puntino ai nodi di 
T in cui si è trovato un match e nell’ordine in cui questi nodi vengono trovati nell’attraversamento prefisso
di T. Insomma prima n0, poi n1 e infine n2.
Si chiede di scrivere una funzione ricorsiva PM che soddisfi alle seguenti specifiche:
PRE=(albero(T) ben formato, P contiene dimP>=0 elementi)
nodoE* PM(nodo*T, int*&P, int &dimP) 
POST=(se n0, n1, …,n(k-1), con k<=dimP, sono i nodi di T che matchano il massimo possibile di P
percorrendo T in ordine prefisso, allora PM restituisce una lista di k nodoE che puntano a n0,..,n(k-1)).
Correttezza: dimostrare la correttezza della funzione PM rispetto alla PRe e POST date.
Attenzione: osservare che P e dimP sono passate per riferimento

*/
#include<iostream>
using namespace std;

struct nodo{
	int info;
	nodo* left;
	nodo* right;

	nodo(int x=0, nodo* l=0, nodo* r=0){
		info = x;
		left = l;
		right = r;
	}
};

// FUNZIONI AUSILIARIE FORNITE
nodo* buildTree(int arr[], int i, int n)  {

    if (i >= n) {
    return NULL;
    }
    nodo* root = new nodo(arr[i]);
    // insert left child
    root->left = buildTree(arr, 2 * i + 1, n);
    // insert right child
    root->right = buildTree(arr, 2 * i + 2, n);

    return root;

}

int height(nodo* root) {
	if(!root) {
		return -1;
	}
	return 1 + max(height(root->left), height(root->right));
}

void stampa_l(nodo *r)
{
    if(r)
    {
    cout<<r->info<<'(';
    stampa_l(r->left);
    cout<<',';
    stampa_l(r->right);
    cout<<')';
    }
    else
    cout<< '_';
}

struct nodoE{nodo*info; nodoE* next; nodoE(nodo*a=0, nodoE*b=0){info=a; next=b;}};
nodoE* conc(nodoE*a,nodoE*b)
{
    if(!a) return b;
    a->next=conc(a->next,b);
    return a;
}

void stampaE(nodoE*x)
{
    if(x)
    {cout << x->info->info<<' ';stampaE(x->next);}
    else
    cout << endl;

}

//PRE=(albero(T) ben formato, P contiene dimP>=0 elementi)
nodoE* PM(nodo*T, int*&P, int &dimP){
    nodoE*a;

    if(!T || !dimP)     //quando ho terminato tutto il pattern o l'albero da esplorare
        return 0;
    //l'albero T ha ancora almeno una foglia e ho ancora almeno un elemento in P
    if(T->info == *P){
        P = P + 1;
        dimP = dimP - 1;        
        //NB: Il fatto di utilizzare gli alias, in poche parole, garantisce un "risparmio" sugli spostamenti; vuol dire che una volta
        //esaminati x elementi a sinistra, percorro solo un numero di x-n elementi a destra, senza cercare su tutto l'albero
        nodoE *x= PM(T->left, P, dimP);

        nodoE *y= PM(T->right, P, dimP);
        nodoE *pat_albero = conc(x,y);      //concateno i due nodoE (vengono pensate come liste e quindi, essendo una funzione fornita e si attaccano i 2 pezzi) e si ritorna
        return new nodoE(T, pat_albero);
    }
    else{                                   //altrimenti ritorno senza il match
        nodoE *x= PM(T->left, P, dimP);

        nodoE *y= PM(T->right, P, dimP);
        
        nodoE *pat_albero = conc(x,y);     

        return pat_albero;
    }
}
//POST=(se n0, n1, …,n(k-1), con k<=dimP, sono i nodi di T che matchano il massimo possibile di P
//percorrendo T in ordine prefisso, allora PM restituisce una lista di k nodoE che puntano a n0,..,n(k-1)).

int main()
{
    int dim,dimP;
    cin >>dim>>dimP;
    nodo*r=0;
    int*A=new int[dim];
    for(int i=0; i<dim;i++)
    cin >> A[i];
	r=buildTree(A,0,dim);
    stampa_l(r);
    cout<<endl;
    
    int*P=new int[dimP];
    for(int i=0; i < dimP; i++)
    cin>>P[i];
    
    nodoE*z= PM(r,P,dimP); //da fare
    stampaE(z);
}
