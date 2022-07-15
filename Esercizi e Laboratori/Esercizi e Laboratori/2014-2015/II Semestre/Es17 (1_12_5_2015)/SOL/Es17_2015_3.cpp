
//soluzione by: Nicolò S.

#include <iostream>
#include <fstream>
 
using namespace std;
 
struct nodo
{
        int info;
        nodo* next;
        nodo(int a=0, nodo* b=0)
        {info=a; next=b;}
};
 
nodo * crea(int dim,ifstream & IN)
{
    if (dim==0){return 0;}
    nodo *nuovo=new nodo;
    IN>>nuovo->info;
    nuovo->next=crea(dim-1,IN);
    return nuovo;
 
}
void stampa (nodo * lista,int dim,ofstream & OUT)
{
    if (dim==0) { cout<<endl<<"fine";return;}
    cout<<lista->info;
    if (lista->next!=0) {cout<<"->";}
    stampa(lista->next,dim-1,OUT);
}
 
 
 
main()
{
    ifstream IN("input.txt");
        ofstream OUT("output");
        int dim;
        IN>>dim;
        nodo * inizio;
        inizio=crea(dim,IN);
        stampa(inizio,dim,OUT);
 
}
