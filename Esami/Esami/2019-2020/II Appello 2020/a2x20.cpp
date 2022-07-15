// Author: https://github.com/ivanarena/

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

struct nodoE{
    nodo* info; nodoE*next; 
    nodoE(nodo*a=0, nodoE*b=0){info=a; next=b;}
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

void stampaE(nodoE *l) {
    if (l) {
        cout << l->info->info << " -> ";
        stampaE(l->next);
    } else {
        cout << "NULL" << endl;
    }
}

// PRE = (albero(R) e lista(tenere) ben formati)
bool check(nodo *R, nodoE *tenere) {
    if (!tenere) return true; // lista vuota
    if (R->info == tenere->info->info) return false;
    check(R, tenere->next);
}
// POST = (restituisce true sse tenere non contiene un nodo con campo info = R->info, false altrimenti)

// PRE = (albero(R), lista(tenere) e lista(buttare) ben formati)
void filtra(nodo *R, nodoE *&tenere, nodoE *&buttare) {
    if (R) {
        if (check(R, tenere)) tenere = new nodoE(R, tenere);
        else buttare = new nodoE(R, buttare);
        filtra(R->left, tenere, buttare);
        filtra(R->right, tenere, buttare);
    }
}
// POST = (tenere contiene tutti i nodi di R che non hanno campi info ripetuti e buttare contiene le sole ripetizioni di quelli che invece
//         hanno campi info ripetuti (= in R esistono più nodi con campo info = al campo info del nodo preso in esame))

int main()
{
    int dim;
    cin >>dim;
    nodo*r=0;
    int*A=new int[dim];
    for(int i=0; i<dim;i++) {
	    cin >> A[i];
	    r=buildTree(A,0,dim);
    }
    
    stampa_l(r);
    cout<<endl;
    nodoE *tenere = 0; 
    nodoE *buttare = 0;
    filtra(r,tenere,buttare);
    cout << "nodi da tenere: ";
    stampaE(tenere);
    cout << "nodi da buttare: ";
    stampaE(buttare);

    
}