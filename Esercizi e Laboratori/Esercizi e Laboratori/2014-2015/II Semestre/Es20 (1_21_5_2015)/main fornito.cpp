//sgranare una lista creandone 2 che utilizzano alternativamente i nodi di quella originale
#include<iostream>

#include<fstream>
using namespace std;


struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

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