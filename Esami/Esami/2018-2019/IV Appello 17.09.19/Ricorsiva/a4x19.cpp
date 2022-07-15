// Author: https://github.com/ivanarena/

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

void build_BST(nodo *&r, int x)
{
    if (!r)
        r = new nodo(x);
    else
    {
        nodo *q = r;
        bool continua = true;
        while (r && continua)
        {
            if (r->info >= x)
                if (r->left)
                    r = r->left;
                else
                {
                    r->left = new nodo(x);
                    continua = false;
                }
            else if (r->right)
                r = r->right;
            else
            {
                r->right = new nodo(x);
                continua = false;
            }
        }
        r = q;
    }
}

int height(nodo *root)
{
    if (!root)
    {
        return -1;
    }
    return 1 + max(height(root->left), height(root->right));
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

struct nodoP
{
    nodo *info;
    nodoP *next;
    nodoP(nodo *a = 0, nodoP *b = 0)
    {
        info = a;
        next = b;
    }
};

nodoP *conc(nodoP *a, nodoP *b)
{
    if (!a)
        return b;
    a->next = conc(a->next, b);
    return a;
}

void stampaE(nodoP *x)
{
    if (x)
    {
        cout << x->info->info << ' ';
        stampaE(x->next);
    }
    else
        cout << endl;
}

// PRE=(albero(R) è benformato, profondita>=0,  dimP>=0 e P ha dimP elementi)
nodoP *match(nodo *R, int profondita, int *&P, int &dimP)
{
    if (!R || !dimP) {
        return 0;
    } else {
        nodoP *L = 0;
        if (R->info == *P) {
            P++;
            dimP--;
            L = new nodoP(R);
        }
        if (R->info > *P) {
            L = conc(L, match(R->left, profondita, P, dimP));
            // return L;
        }
        if (R->info < *P) {
            L = conc(L, match(R->right, profondita, P, dimP));
            // return L;
        }
        return L;
    }
}
// POST=(restituisce una lista di nodoP che corrisponde al massimo match di P nei nodi di R esaminati in ordine prefisso, la lista, P e dimP sonocome descrittiprima)

int main()
{
    nodo *r = 0;
    int n;
    cin >> n;
    while (n != -1)
    {
        build_BST(r, n);
        cin >> n;
    }
    stampa_l(r);
    cout << endl;

    int dimP;
    cin >> dimP;
    int *P = new int[dimP];
    for (int i = 0; i < dimP; i++)
        cin >> P[i];
    
    nodoP *z = match(r, height(r), P, dimP);
    stampaE(z);

}
