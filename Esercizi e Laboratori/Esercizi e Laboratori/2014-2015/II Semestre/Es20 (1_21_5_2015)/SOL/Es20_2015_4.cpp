
//soluzione by: Luca C.

#include<iostream>
#include<fstream>
using namespace std;
 
 
bool findMatch(nodo *&L, int *P, int dimP, nodo *mL){
        if(!mL){
                return false;
        }
        else{
                if(mL->info==*P){
                        if(dimP==1){
                                L=mL->next;
                                mL->next=NULL;
                                return true;
                        }
                        return findMatch(L, P+1, dimP-1, mL->next);
                }
                else{
                        return false;
                }
        }
}
 
//PRE=(L è una lista corretta, P ha dimP elementi, chiamiamo vL=L)
nodo *match(nodo* &L, int*P, int dimP){
        if(!L){
                return NULL;
        }
        else{
                nodo *mL=L;
                if(findMatch(L, P, dimP, mL)){
                        return mL;
                }
                else{
                        return match(L->next, P, dimP);
                }
        }
}
//POST=(la funzione restituisce col return match(vL,P[0..dimP-1]) e L=resto_mach(vL,P[0..dimP-1]))
 
 
 
 
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
