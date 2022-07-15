#include <iostream>

using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo*b=0){info=a; next=b}};
struct nodoE{nodo* info; nodoE* next; nodoE(nodo*a=0, nodoE*b=0){info=a; next=b;}};

nodoE* faiIter(nodo*r){
    nodoE*lista=0;
    while(r){
        nodo*x=r;
        lista->next=new nodoE(x);
        if(r->left){
            r=r->left;
            lista->next=new nodoE(r);
        }
        if(r->right){
            r=r->right;
            lista->next=new nodoE(r);
        }
    }
}
//1) Definire invariante significativo del ciclo principale di faiIter

//R=r formata da n nodi percorribili in larghezza && riempio lista
//con i valori seguendo il percorso breadth first

//2) Definire PRE e POST significative per matchRic e per eventuali funzioni ausiliarie

//PRE=L ben formata, P array formato da dimP elementi
int matchRic(nodoE*L, int *P, int dimP){
    int max=0;
    if(!L || !dimP) return max;
    int l=aux(L, P, dimP);
    max=matchRic(L->next, P, dimP);
    if(l > max) max=l;
    return max; 
}
//POST=restituisce il match di lunghezza massima tra L e P

int aux(nodoE* L, int* P, int dimP){
    if(!L || !dimP) return 0;
    if(L->info->info == *P) return 1+conta_match(L->next, P+1, dimP-1);
    else    return conta_match(L->next, P, dimP);
}
//Dim. di correttezza:

/*
-! L || !dimP--> no match e ritorno 0

-creo un locale che salva il match migliore
e si adotta una funzione ausiliaria che va a cercarsi il match
Questa funzione ha sempre L e P riempiti di elementi (PRE)
e restituisce il numero di elementi matchati (POST)

-Se L==*P incremento ricorsivamente pattern e lista
altrimenti ritorno semplicemente la lista scorsa

-se max > l, non ci sono cambiamenti
altrimenti salvo il match migliore
*/