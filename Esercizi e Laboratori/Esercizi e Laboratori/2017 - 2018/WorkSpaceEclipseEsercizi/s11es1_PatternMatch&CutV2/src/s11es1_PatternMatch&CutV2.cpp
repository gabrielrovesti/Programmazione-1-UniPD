#include<iostream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

nodo* crea(int );
void leggi(int , int*);
nodo* match(nodo* &, int*, int ) ;
void stampa(nodo*);
bool confronta(nodo* ,int* , int, nodo*&);

nodo* confronta(nodo* &n, int*P, int dimP, bool &f);
nodo* match(nodo* &n, int*P, int dimP);

bool tenta(nodo*& y, int *P, int dimP, nodo*& m){
	if(!dimP){
		m=y;

		y=0;
		return true;
	}

	if(!y) return false;

	if(y->info == P[0])
		return tenta(y->next, P+1, dimP-1, m);
	return false;
}



nodo* match1( nodo* & L, int * P, int dimP){

	if(!L) return 0;

	nodo* r= L;

	if(tenta(r, P, dimP, L)){
		L= r;
		return r;
	}else{
		L= L->next;
		r->next= match1(L,P,dimP);
		return r;

	}
}
int main()
{
  int dim, dimP, P[20];
  cout<<"start"<<endl;
  cin>>dim;
  nodo* L1=crea(dim);
  cin>>dimP;
  leggi(dimP, P);


  nodo* L2= match(L1,P, dimP);//da fare

  stampa(L2); //da fare

cout<<endl;
  stampa(L1);
cout<<endl;
  cout<<"end"<<endl;
}

//PRE=(L(n) è una lista corretta, P ha dimP elementi, chiamiamo vL(n)=L(n))
nodo* match(nodo* &n, int*P, int dimP)
{
    if (n)
    {
        bool f=false;
        nodo* a=confronta(n,P, dimP, f);
        if (f)
        {
            return a;
        } else
        {
            nodo*a=n;
            n=n->next;
            a->next=match(n,P,dimP);
            return a;
        }
    }
    return 0;

}
/*	POST=(se in L(n) c’è un match di P, allora la funzione restituisce col return
 *  resto_mach(vL(n),P[0..dimP-1]) e L(n)=match(vL(n),P[0..dimP-1]), se invece non
 *  c’è il match allora la funzione restituisce  vL(n) col return e n=0)
 *
 */
nodo* confronta(nodo* &n, int*P, int dimP, bool &f)
{
    if (n)
    {
        if (n->info==*P)
        {
            if (dimP==1)
            {
                f=true;
                nodo* a=n->next;
                n->next=0;
                return a;
            }
            return confronta(n->next, P+1, dimP-1, f);
        }
    }
    return 0;
}

bool confronta(nodo* n,int* P, int dimP, nodo* & ultimoNodo){

	if(dimP==0){
		return true;
	}

	if(!n) return false;

	if(n->info == P[0]){

		ultimoNodo= n;
		return confronta (n->next,P+1,dimP-1, ultimoNodo);
	}
	return false;

}
nodo* crea(int dim)
{
 if(dim)
  {
    int x;
    cin>>x;
    // cout<<"Inserisco "<<x<<endl;
    return new nodo(x,crea(dim-1));
  }
 return 0;
}


void leggi(int dim, int*P)
{
  if(dim)
   {
    cin>>P[0];
    // cout<<"Leggo : "<<P[0]<<endl;
    leggi(dim-1,P+1);
   }

}

void stampa(nodo* L){
	if(L){
		cout<<L->info<<" ";
		stampa(L->next);
	}
}
