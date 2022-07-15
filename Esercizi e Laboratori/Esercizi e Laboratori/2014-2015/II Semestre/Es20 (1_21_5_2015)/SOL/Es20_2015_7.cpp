
//soluzione by: Nicolò S.

#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

bool ok(nodo* L,int* P,int dimP){
	if(!dimP) return true; 
	if(!L) return false;
	if(L->info==*P)
		return ok(L->next,P+1,dimP-1);
	return false;
}

//PRE=(L Ã¨ una lista corretta, P ha dimP elementi, chiamiamo vL=L)
nodo* match(nodo* &L,int* P,int dimP){
	if(!L)
		return 0;
	
	if(!dimP)
		return 0;
	
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
//	e L=resto_mach(vL,P[0..dimP-1]))

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
