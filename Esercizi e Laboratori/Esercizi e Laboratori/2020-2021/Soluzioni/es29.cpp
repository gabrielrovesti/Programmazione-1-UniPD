//Consegna:
//trovare un pattern matching tra un albero binario
//e un vettore di interi

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
    void sc(int*C)
    {
        cout<<*C<<' ';    
        if(*C!=-1)
        sc(C+1);
    }

struct nodoE{nodo*info; nodoE* next; nodoE(nodo*a=0, nodoE*b=0){info=a; next=b;}};

void stampaE(nodoE*x)
{
    if(x)
        {cout << x->info->info<<' ';stampaE(x->next);}
    else
        cout << endl;

}

//PRE= dimP > 0 && r ben formato
nodoE* match(nodo*r, int*P, int dimP){
    if(height(r) + 1 < dimP)    return 0;

    if(r->info != *P)   return 0;

    if(dimP == 1)   return new nodoE(r);        //(quindi match di dimensione 1) -- dimensione 1 e r->info == pattern di dimensione 1
            
    nodoE*x = match(r->left, P+1, dimP-1);      //cerco il match a sx
    if(!x)  x = match(r->right, P+1, dimP-1);   //altrimenti provo a cercare a dx
    if(x){
        return new nodoE(r, x);     //in pratica metto l'albero e concateno la parte matchata
    }
    else return 0;
}
//POST=(se T->info==*P ritorna ricorsivamente il match a dx o sx, altrimenti restituisce 0)

//PRE=(albero(T) ben formato, P contiene dimP>=0 elementi)
nodoE* PM1(nodo*T, int*P, int dimP){
    if(dimP == 0 || !T)  return 0;
    nodoE* x = match(T, P, dimP);
    if(!x)
        x = PM1(T->left, P, dimP);    //verificare se da tutti i nodi dell'albero parte il possibile match
    if(!x)
        x = PM1(T->right, P, dimP);
    return x;
}
//POST=(se in T esiste un cammino che contiene un match di P completo e contiguo, allora PM1 restituisce 
//una lista di dimP nodi di tipo nodoE che puntano ai nodi del cammino più a sinistra su cui esiste un tale 
//match di P, altrimenti PM1 restituisce 0 ).

/*
Correttezza:

-Caso base: dimp==0 e albero ha finito gli elementi-->termino la funzione, in quanto 
non esiste match. Se non si verifica, si passa al caso ricorsivo

-Caso ricorsivo: si richiama la funzione di match, che verifica l'esistenza di un pattern tra gli elementi

La funzione di match ha vari casi base:

--assumendo corretta PRE, se l'altezza dell'albero non è abbastanza alta, termino la ricorsione
--se !=*P ritorna false, verificando POST

--Caso ricorsivo funzione di match:
si cerca il cammino più a sx e si ricorre prima a sx; se presente un cammino
si valutano i due condizionali;
-se vero, si ritorna l'elemento più a sx, creando una lista che attacca l'albero alla parte sx
-se falso, si ritorna l'elemento più a dx, verificando in entrambi i casi POST.

Tornando al caso ricorsivo di PM1:
-si valutano due condizionali, qualora non ci fosse il match, ci si sposta ricorsivamente a dx e a sx
ritornando poi x come lista di nodi di match, sempre verificando POST
*/


int main()
{
    int dim,dimP;
    cin >>dim>>dimP;
    nodo*r=0;
    int*A=new int[dim];
    for(int i=0; i<dim;i++)
    {
        cin >> A[i];
        r=buildTree(A,0,dim);
    }
    int*P=new int[dimP];
    for(int i=0; i < dimP; i++)
    cin>>P[i];
    nodoE*z= PM1(r,P,dimP);
    if(z)
    {
        stampa_l(r);
        cout<<endl;
        cout<<"trovato match: ";
        stampaE(z);
    }
    else
        cout<<"nessun match"<<endl;
}
