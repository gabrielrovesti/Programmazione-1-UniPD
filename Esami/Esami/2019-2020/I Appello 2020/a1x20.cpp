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

// PRE = (alb(r) ben formato, min <= y <= mag)
void H(nodo *r, int &min, int &mag, int y) {
    if (r) {
        if (r->info == y) {
            min = y;
            mag = y;
        } else if (r->info < y && r->info > min) {
            min = r->info;
        } else if (r->info > y && r->info < mag) {
            mag = r->info;
        }
        H(r->left, min, mag, y);
        H(r->right, min, mag, y);
    }
}
// POST = (min è il nodo con campo info <= y maggiore di tutti gli altri (minori di y) mag è il nodo con campo info >= y
//         minore di tutti gli altri (maggiori di y); mag e min vengono modificati grazie al passaggio per riferimento)

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
       
    bool basta=false;
    int l1,l2,y;
    while(!basta) {
	    cin >> l1 >> l2 >> y;
	    int z1=l1, z2=l2;
	    if(y==-1)
	        basta=true;
	    else {
	        H(r,l1,l2,y);
	        cout <<"l1="<<l1<<" l2="<<l2<<endl;
	    }
    }
}