
//soluzione by: Robertino B.

#include<iostream>
#include<fstream>
using namespace std;
 
 
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};
struct dueL {nodo* prima, * seconda; dueL(nodo*a=0, nodo* b=0){prima=a; seconda=b;}};
 
nodo* crea(int dim, ifstream & INP)
{
 if(dim)
  {
    int x;
    INP>>x;
    return new nodo(x,crea(dim-1,INP));
  }
 return 0;
}
 
nodo* clona_rov(nodo*L, nodo* rov)
{
  if(L)
   {
    return clona_rov(L->next,new nodo(L->info,rov));
   }
  return rov;
 
}
void stampa(nodo*L,ofstream & OUT)
{
  if(L)
  {
    OUT<<L->info<<' ';
    stampa(L->next,OUT);
  }
 else
    OUT<<endl;
}
nodo * nodi(nodo *&L, int i)
{
        if (!L)
                return 0;
        if (i%2==0 )
        {
                nodo *L1= L;
                L=L->next;
                L1->next=nodi(L,i+1);
                return L1;
        }
        else
                return nodi(L->next,i+1);
       
}
dueL sgrana(nodo*L)
{
        nodo*dispari=nodi(L,0);// inserisco le posizioni dispari nel nodo dispari e li tolgo da L
        nodo *pari=L;
        dueL app;
        app.prima=dispari; // le posizioni dispari le inserisco nella prima lista
        app.seconda=pari; // il rimanente della lista inserisco nella seconda lista
        return app;
       
}
 
nodo* sgrana2(nodo*&L)
{
        nodo * app=nodi(L,0);
        return app;
}
main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT)
  {
   int dim;
   IN>>dim;
   nodo* L1=crea(dim,IN); //data
   nodo*L2= clona_rov(L1,0);//clone in ordine inverso, data
   dueL W=sgrana(L1); // da fare (a)
   nodo*L3=sgrana2(L2);// da fare (b)
   stampa(W.prima,OUT);//date
   stampa(W.seconda,OUT);
   stampa(L3,OUT);
   stampa(L2,OUT);    
   IN.close(); OUT.close();
  }
  else
   cout<<"errore con i files";
 }
