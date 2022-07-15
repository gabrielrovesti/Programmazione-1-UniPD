
//soluzione by: Fabrizio C.

#include<iostream>
#include<fstream>
using namespace std;
 
 
bool ok(nodo* L,int* P,int dimP){
        if(!dimP) return true;
        if(!L) return false;
        if(L->info==*P)
                return ok(L->next,P+1,dimP-1);
        return false;
}
 
//PRE=(L è una lista corretta, P ha dimP elementi, chiamiamo vL=L)
nodo* match(nodo* &L,int* P,int dimP){
        if(!L) return 0;
       
        if(!dimP) return 0;
       
        if(L->info==*P){
                nodo* x=L;
                bool y=ok(L->next,P+1,dimP-1);
                if(y){
                        nodo* z=L;
                        L=L->next;
                        z->next=match(L,P+1,dimP-1);
                        return z;
                }
                return match(L->next,P,dimP);
        }
        else
                return match(L->next,P,dimP);
}
//POST=(la funzione restituisce col return match(vL,P[0..dimP-1])
//      e L=resto_mach(vL,P[0..dimP-1]))
 
 
 
 
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
