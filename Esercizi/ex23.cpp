/*Abbiamo un albero binario r, un valore intero y e k>=0 e vogliamo sapere se in r c'è un cammino 
che si estende dalla radice fino ad una foglia che contiene esattamente k nodi con campo info 
uguale a y. Nel seguito i cammini su un albero binario saranno rappresentati con una sequenza di 
0/1 terminante con -1 a indicare appunto la fine del cammino. Quindi il cammino -1 è il cammino 
vuoto che coincide con la radice. 

Esempio: se il nostro albero r fosse il seguente, nel quale in ogni nodo è riportato il valore del 
campo info, 
e se k=2 e y=1, allora un cammino con esattamente due 1 sarebbe il cammino 01-1. C'è anche un 
altro cammino con esattamente due 1 ed è il cammino 101-1. Invece i cammini 0-1 e 00-1, che 
avrebbero due 1 non andrebbero bene perché non arrivano ad una foglia. Se invece k=1 e y=2 il 
cammino, 001-1 soddisferebbe la richiesta e lo stesso cammino andrebbe bene per k=3 e y=1.
Invece nessun cammino di albero(r) soddisfa k=0, y=1, visto che la radice contiene 1. Si osservi che 
un albero vuoto non ha cammini, quindi tanto meno ha cammini con una data proprietà. Questo 
spiega perché nella pre-condizione di cerca_cam che segue, si assume che albero(r) sia non vuoto.

Per risolvere il problema appena descritto, si chiede di realizzare una funzione ricorsiva:
bool cerca_cam(nodo*r, int k, int y, int*C) corretta rispetto alla seguente coppia di pre e- e postcondizioni:

PRE=(albero(r) è ben formato e non vuoto, k>=0 e y valore qualsiasi, C ha almeno tanti elementi 
quanta è l'altezza di albero(r))
POST= (restituisce true sse in albero(r) esiste un cammino da r ad una foglia con esattamente k 
nodi con campo info=y e false altrimenti) &&(in caso restituisca true, C contiene una sequenza 
(anche vuota) di 0/1 seguita da -1 e che individua il cammino più a sinistra in albero(r) con 
esattamente k nodi con campo info=y). 

Correttezza: fare la prova induttiva di correttezza di cerca_cam.

Il programma dato contiene diverse funzioni ausiliarie. In particolare quelle usate per costruire 
l’albero e quelle per stampare l’albero stesso e il cammino qualora trovato*/

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
		return 0;
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

bool foglia(nodo* T){
    return !T->left && !T->right;
}

//PRE=(albero(r) è ben formato e non vuoto, k>=0 e y valore qualsiasi, C ha almeno tanti elementi 
//quanta è l'altezza di albero(r))

bool cerca_cam(nodo*r, int k, int y, int*C){
    if(foglia(r)){
        //Attenzione: il k==1 si mette perché consideriamo il caso in cui
        //l'albero non sia completo (ti fai uno schema e capisci perché)
        //in quel caso, siamo in una foglia
        //Comunque sia, viene considerato normalmente il caso anche di albero completo
        if(r->info==y && k==1 || r->info!=y && k==0){
            *C = -1;
            return true;
        }
        return false;
    }
    if(r->info==y && k==0) return false;    //dice che siamo in eccesso di 1
    if(r->info==y && k > 0){                //altrimenti diminuiamo k normalmente
        k--;
    }
    if(r->left){
        //PRE_RIC= r->left e non vuoto, ben formato
        if(cerca_cam(r->left, k, y, C+1)){
        //POST_RIC=percorso con n elementi salvato in C+1
            *C=0;
            return true;
        }
    }
    if(r->right){
        //PRE_RIC= r->right e non vuoto, ben formato
        if(cerca_cam(r->right, k, y, C+1)){
        //POST_RIC=percorso con n elementi salvato in C+1
            *C=1;
            return true;
        }
        return false;   //non c'è un modo in cui riusciamo a farlo andare bene considerato che hanno fallito le altre due e ritorno false
    }
}

//POST= (restituisce true sse in albero(r) esiste un cammino da r ad una foglia con esattamente k 
//nodi con campo info=y e false altrimenti) &&(in caso restituisca true, C contiene una sequenza 
//(anche vuota) di 0/1 seguita da -1 e che individua il cammino più a sinistra in albero(r) con 
//esattamente k nodi con campo info=y). 

//CORRETTEZZA=
/*
Nella funzione individuata si considera l'albero definito e non vuoto
se l'albero è definito, si verifica se il nodo attuale corrisponde ad y;
se così, lo conto e mi sposto ricorsivamente sul sottoalbero sinistro (induttivamente giusto, essendo da PRE e PRE_RIC definito e
verificando POST_RIC definito, mi sposto sull'elemento, come verificato dal condizionale)
se poi l'elemento corrisponde ad Y, lo conto e pongo C*=0;
qualora il nodo non fosse uguale ad Y,
mi sposto solo sul sottoalbero sinistro, ripetendo la stessa operazione;
se invece non fosse definito il sottoalbero sinistro, mi sposto a destra
e, se il nodo del sottoalbero dx è uguale ad Y (albero definito e sottoalbero definito, ciò viene garantito da PRE e PRE_RIC, verificando POST_RIC), lo conto e pongo C*=1.
Altro caso base, se non fossero definiti entrambi i nodi
semplicemente siamo su una foglia e C* vale -1.
Alla fine della funzione abbiamo due casi:
se i nodi contati sono tanti quanti k, restituisco true e C valorizzato col cammino
altrimenti restituisco false, verificando POST in entrambi i casi.
*/


int main() {
    int dim;
    cin >>dim;
    int* a= new int[dim];

    for (int i=0; i<dim; i++)
    cin >> a[i];

    nodo* root = NULL;
    root = buildTree(a, 0, dim);
    stampa_l(root);
    cout<<endl;
    int h=height(root);
    int*C=new int[h];

    int k,val;  
    cin>> val >> k;    
    
    bool b=cerca_cam(root,k,val,C);
    cout<<endl;

    if(b)
    {cout<<"trovato  cammino= "; sc(C); cout<<endl;}
    else
    cout<<" nessun cammino con "<<k<<" valori="<<val<<endl;
    
}