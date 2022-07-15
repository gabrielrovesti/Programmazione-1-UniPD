
//soluzione by: Robertino B.

// Versione 1:
#include<iostream>
#include<fstream>
using namespace std;
 
 
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};
bool cerca(nodo *L,int *P,int dimP) // cerco se esiste il match
{
       
        if (dimP>0)
        {
                if (L)
                {
                        if (L->info==*P)
                                return cerca(L->next,P+1,dimP-1);
                        else
                                return false;
                }
                else
                        return false;
        }
        else
                return true;
}
nodo *stacca(nodo*&L,int dimP) // stacco i nodi
{
        if (dimP>0)
        {
                int el=L->info;
                L=L->next;
                return new nodo(el,stacca(L,dimP-1));
        }
        return 0;
}
nodo *match(nodo*&L,int*P,int dimP)
{
        if (L)
        {
                if (cerca(L,P,dimP))
                        {nodo *m=stacca(L,dimP); return m;} // se trovato il match stacco i nodi e ritorno i nodi staccati
                else
                        {
                                return match(L->next,P,dimP);
                        }
        }
        else
                return L;
}
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
void leggi(int dim, int*P, ifstream & INP)
{
  if(dim)
   {
    INP>>*P;
    leggi(dim-1,P+1,INP);
   }
 
}
 
 
main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT)
  {
   int dim, dimP, P[20];
   IN>>dim;
   nodo* L1=crea(dim,IN);//fatta
   IN>>dimP;
   leggi(dimP, P, IN);//fatta
   nodo* L2= match(L1,P, dimP); // da fare-------------------
   stampa(L2,OUT);//fatta
   stampa(L1,OUT);
   IN.close(); OUT.close();
  }
  else
   cout<<"errore con i files";
 }
 
 
 
 
 
/* Versione 2:
#include<iostream>
#include<fstream>
using namespace std;
 
 
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};
bool cerca(nodo *L,int *P,int dimP) // cerco se esiste il match
{
       
        if (dimP>0)
        {
                if (L)
                {
                        if (L->info==*P)
                                return cerca(L->next,P+1,dimP-1);
                        else
                                return false;
                }
                else
                        return false;
        }
        else
                return true;
}
nodo *stacca(nodo*&L,int dimP) // stacco i nodi
{
        if (dimP>0)
        {
               
                nodo* L1= L;
                L=L->next;
                L1->next=stacca(L,dimP-1);
                return L1;
        }
        return 0;
}
nodo *match(nodo*&L,int*P,int dimP)
{
        if (L)
        {
                if (cerca(L,P,dimP))
                        {nodo *m=stacca(L,dimP); return m;} // se trovato il match stacco i nodi e ritorno i nodi staccati
                else
                        {
                                return match(L->next,P,dimP);
                        }
        }
        else
                return L;
}
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
void leggi(int dim, int*P, ifstream & INP)
{
  if(dim)
   {
    INP>>*P;
    leggi(dim-1,P+1,INP);
   }
 
}
 
 
main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT)
  {
   int dim, dimP, P[20];
   IN>>dim;
   nodo* L1=crea(dim,IN);//fatta
   IN>>dimP;
   leggi(dimP, P, IN);//fatta
   nodo* L2= match(L1,P, dimP); // da fare-------------------
   stampa(L2,OUT);//fatta
   stampa(L1,OUT);
   IN.close(); OUT.close();
  }
  else
   cout<<"errore con i files";
 }
*/
