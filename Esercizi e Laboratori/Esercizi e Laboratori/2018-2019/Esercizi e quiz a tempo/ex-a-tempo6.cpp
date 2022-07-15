#include<iostream>
using namespace std;
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};
struct nodoP{nodo* P; nodoP* next; nodoP(nodo* a=0, nodoP* b=0){P=a; next=b;}};

// PRE=(y è lista di nodoP ben formata)
void stampa(nodoP* y){
    if(y)
    {
        cout<<y->P->info<<" ";
        if(y->next)
            stampa(y->next);
    }
}
// POST=(stampa i campi info dei nodi di L puntati dagli elementi di y)

// PRE=(P è lista di nodoP ben formata)
nodoP* ultimo(nodoP* P){
    if(!P) return 0;
        
    return !P->next ? P : ultimo(P->next);
}
// POST=(ritorna l'ultimo nodoP della lista)

// PRE=(cin contiene almeno un -11)
nodo* leggi(){
    int in;
    cin>>in;

    return in==-1 ? 0 : new nodo(in, leggi());
}
// POST=(return lista di nodo ben formata)

// PRE=(Lista(L) è ben formata, x è definito)
nodoP* aux(nodo* L, int x){
    if(!L) return 0;

    return L->info==x ? new nodoP(L, aux(L->next, x)) : aux(L->next, x);
}
// POST=(return lista di nodoP lunga come il n. di nodi di Lista(L) con x=info e i cui nodi puntano a questi nodi di L nell’ordine in cui i nodi sono in L)

// PRE=(Lista(L) ben formata e in cin ci sia un -1)
nodoP* F(nodo* L){
    int in;
    cin>>in;

    if(in==-1) return 0;
    
    nodoP* P=aux(L, in);
    if(!P)
        return F(L);
    
    ultimo(P)->next=F(L);
    return P;
}
// POST=()

main()
{
    cout<<"start"<<endl;

    nodo* L=leggi();
    nodoP* y=F(L);

    stampa(y);
    cout<<endl;

    cout<<"end"<<endl;
}