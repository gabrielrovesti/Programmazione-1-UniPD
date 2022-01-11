/*

Esercizio 2 del 31/5/2021 
Supponiamo di avere un albero binario albero(r) con degli interi nei campi info dei suoi nodi. Data una 
tripla, m1, m2 e y di interi tali che m1<=y<=m2, usando m1 ed m2 e tutti i valori dei campi info dei nodi di 
albero(r), vogliamo trovare la coppia di interi x1 e x2 (con x1<=x2) tale che l’intervallo [x1,x2] sia il più 
piccolo intervallo che racchiuda y. Qualora un nodo di albero(r) avesse info=y, allora la migliore coppia che 
racchiude y sarebbe x1=x2=y. 
Esempio: Dati m1=2, m2= 10, albero(r)= 12( 15(7(_,_),5(_,_)), 3(4(_,_), 2(_,_))) e y =6, la coppia cercata è 
[5,7]. Se invece, con m1, m2 e albero(r) come prima, y fosse 10 allora la coppia sarebbe [7,10], mentre per 
y= 3 sarebbe [3,3] visto che in albero(r) c’è un nodo con info=3.
Si chiede di scrivere una funzione ricorsiva calcIntMin che dato un albero binario r, i 2 valori m1 e m2 e 
l’intero y, trovi i 2 interi x1 e x2. Si chiede di specificare la PRE e la POST della vostra funzione. In particolare 
si deve specificare in che modo la funzione restituisca la coppia di interi x1 e x2.
Viene richiesta anche una funzione iterativa calcIntMinBST che trovi la coppia x1 e x2 esattamente come 
nell’esercizio precedente, ma assumendo che l’albero dato sia un BST. Anche in questa seconda parte si 
assume di avere inizialmente m1<=y <=m2.
Attenzione, l’ipotesi che albero(r) sia BST semplifica il problema e permette di risolverlo iterativamente. 
Per capire come fare, può essere utile scrivere un albero BST, magari con i valori usati nell’esempio 
precedente, e osservando cosa succede se inseriste y in questo albero. Anche qui si deve considerare 
anche il caso in cui un nodo di albero(r) abbia info=y.
Correttezza: 
i) scrivere PRE e POST delle 2 funzioni. In particolare specificare come le funzioni restituiscono il 
risultato.
ii) abbozzare l’invariante del ciclo principale di calcIntMinBST.
Attenzione: viene dato un programma con un main che invoca ripetutamente le 2 funzioni da fare. Gli 
output prodotti sono gli intervalli calcolati dalle 2 funzioni (che ovviamente devono essere uguali)

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


void buildBST(nodo*&r,int x)
{
    if(!r) {r=new nodo(x);return;}
    if(r->info>= x)
    buildBST(r->left,x);
    else
    buildBST(r->right,x);
}

//PRE=albero r ben formato, m1<=y<=m2
void calcIntMin(nodo*r, int &m1, int &m2, int y){
    if(r){
        if(r->info == y){
            m1 = y;
            m2 = y;
        }
        else{
            if(r->info > m1 && r->info < y)         //controlliamo i valori minori
                m1 = r->info;
            else if(r->info > y && r->info < m2)    //controlliamo i valori maggiori
                m2 = r->info;
            calcIntMin(r->left, m1, m2, y);
            if(m1 != m2)       //permette di bloccare la ricerca qualora i nodi fossero uguali (al primo caso base)
            calcIntMin(r->right, m1, m2, y);
        }
    }
}
//POST=la funzione restituisce due valori x1 (più grande tra gli elementi minori) 
//e x2 (più piccolo tra gli elementi maggiori) sono estremi 
//dell'intervallo con y, tale che m1<=y<=m2

//PRE= albero BST r ben formato, m1<=y<=m2
void calcIntMinBST(nodo*r, int &m1, int &m2, int y){
    bool continua=true;

    while(r && continua){           //R=(r ben formato && continua==false sse r->info != y)
        if(r->info == y){           //se l'elemento è uguale, i due estremi sono m1 ed m2 e finisco la ricerca
            m1 = y;
            m2 = y;
            continua = false;
        }else{
            if(r->info > y){        //controllo del minimo tra i maggiori
                if(r->info < m2)    //trovo l'elemento, altrimenti ricorro a destra (essendo BST cerco a sinistra per i minori rispetto alla chiave y)
                m2 = r->info;
            r = r->left;
            }else{
                if(m1 < r->info)    //stessa cosa di qua, ma cerchiamo il massimo tra i minori
                m1 = r->info;
            r = r->right;
            }
        }
    }
}
//POST=la funzione restituisce due valori x1 (più grande tra gli elementi minori) 
//e x2 (più piccolo tra gli elementi maggiori) sono estremi 
//dell'intervallo con y, tale che m1<=y<=m2

int main()
{
    int dim;
    cin >>dim;
    nodo*r=0;
    int*A=new int[dim];
    for(int i=0; i<dim;i++)
    {
	cin >> A[i];
	r=buildTree(A,0,dim);
    }
    nodo*r1=0;    
    for (int i=0; i<dim; i++)
    buildBST(r1,A[i]);

    stampa_l(r);
    cout<<endl;
    stampa_l(r1);
    cout<<endl<<endl;

    bool basta=false;
    int l1,l2,y;
    while(!basta)
    {
        cin>> l1>>l2>>y;
        int z1=l1, z2=l2;
        if(y==-1)
        basta=true;
        else
        {
        calcIntMin(r,l1,l2,y);
        cout <<"L1="<<l1<<" L2="<<l2<<endl;

        calcIntMinBST(r1,z1,z2,y);
        cout <<"L1="<<z1<<" L2="<<z2<<endl;

        cout<<endl;
        }
    }
}