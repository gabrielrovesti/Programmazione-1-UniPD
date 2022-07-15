
//soluzione by: Alberto G.

#include<iostream>
#include<fstream>
using namespace std;
 
 
nodo *cerca_match(nodo* &L, int *P, int dimP)
{
        nodo *temp = 0;
        if (!L)
                return 0;
        if (L->info == *P)
        {
                if (dimP == 1)
                        return L;
                else return cerca_match(L->next, P + 1, dimP - 1);
        }
        return 0;
}
 
nodo* match(nodo* &L, int*P, int dimP)
{
        if (!L)
                return 0;
        if (L->info == *P)
        {
                nodo *fine = cerca_match(L->next, P+1, dimP-1);
                if (fine != 0)
                {
                        nodo *temp = fine->next;
                        fine->next = 0;
                        nodo *x = L;
                        L = temp;
                        return x;
                }
        }
        return match(L->next, P, dimP);
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
