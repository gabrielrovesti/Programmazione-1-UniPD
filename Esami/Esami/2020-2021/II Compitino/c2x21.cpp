// Author: https://github.com/ivanarena

#include <iostream>
using namespace std;

struct nodo
{
    int info;
    nodo *left;
    nodo *right;

    nodo(int x = 0, nodo *l = 0, nodo *r = 0)
    {
        info = x;
        left = l;
        right = r;
    }
};

// FUNZIONI AUSILIARIE FORNITE
nodo *buildTree(int arr[], int i, int n)
{

    if (i >= n)
    {
        return NULL;
    }
    nodo *root = new nodo(arr[i]);
    // insert left child
    root->left = buildTree(arr, 2 * i + 1, n);
    // insert right child
    root->right = buildTree(arr, 2 * i + 2, n);

    return root;
}

void stampa_l(nodo *r)
{
    if (r)
    {
        cout << r->info << '(';
        stampa_l(r->left);
        cout << ',';
        stampa_l(r->right);
        cout << ')';
    }
    else
        cout << '_';
}

// PRE = (alb(T) è ben formato, 0<=im<=dimP, P ed L hanno dimP posizioni, vim=im)
void matchF(nodo *T, int *P, int dimP, int &im, nodo *L[]) {
    if (T && im < dimP) {
        if (!T->left && !T->right) { // foglia
            if (T->info == P[im]) {
                L[im] = T;
                im++;
            }
        }
        // PRE_RIC = (alb(T) è ben formato, 0<=im<=dimP, vim<=im)
        matchF(T->left, P, dimP, im, L);
        matchF(T->right, P, dimP, im, L);
        // POST_RIC = (L[vim..im-1] contiene tutte le foglie di T con campo info = P[vim..vim-1])
    }
}
/* POST = (L[vim..im-1] contiene puntatori alle foglie di T che matchano P[vim]..P[im-1] in modo che
elementi successivi di L puntano a foglie successive di T (da sinistra a destra)) */

int main()
{
    int dim, dimP;
    cin >> dim >> dimP;
    nodo *r = 0;
    int *A = new int[dim];
    for (int i = 0; i < dim; i++)
    {
        cin >> A[i];
        r = buildTree(A, 0, dim);
    }
    stampa_l(r);
    cout << endl;
    int *P = new int[dimP];
    for (int i = 0; i < dimP; i++)
        cin >> P[i];
    
    int im = 0;
    nodo* *L = new nodo*[dimP];
    matchF(r, P, dimP, im, L);
    for (int i = 0; i < im; i++) {
        cout << L[i]->info << " ";
    }
    cout << endl;
}

/* DIMOSTRAZIONE DI CORRETTEZZA 

CASO BASE: alb(T) vuoto, allora nessuna foglia (e nessuna foglia da matchare), L vuoto e im=vim => vale POST.
PASSO INDUTTIVO: Vale PRE, sse T è una foglia e sse T->info è uguale a P[im], im viene incrementato, quindi
                 vale sempre vim=im, e quindi vale PRE_RIC;
                 Supponiamo vera POST_RIC, allora L contiene tutti gli elementi matchati con P da P[0] a P[im-1];
                 se im=dim allora sono stati matchati tutti gli elementi; => vale POST.

*/