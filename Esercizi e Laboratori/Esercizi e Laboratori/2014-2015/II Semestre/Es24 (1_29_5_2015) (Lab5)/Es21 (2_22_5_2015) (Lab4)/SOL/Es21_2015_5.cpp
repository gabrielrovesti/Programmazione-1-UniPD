
//soluzione by: Gomez E. (Riccardo G. A.)

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
 
dueL sgrana(nodo* L) {
  if (!L) return dueL();
  dueL s = sgrana(L->next);
  nodo* old_next = L->next;
  L->next = s.seconda;
  s.prima = L;
  s.seconda = old_next;
  return s;
}
 
nodo* sgrana2(nodo* &L) {
  if (!L) return 0;
  nodo* n = sgrana2(L->next);
  nodo* l1 = L;
  L = n;
  return l1;
}
 
int main()
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
