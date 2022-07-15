#include<iostream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

nodo* crea(int );
void leggi(int , int*);
nodo* match(nodo* &, int*, int ) ;
void stampa(nodo*);
bool confronta(nodo* ,int* , int, nodo*&);

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

nodo* match2(nodo* & L, int* P, int dimP){

	if(!L) return 0;
	//caso base: lista vuota, nessun match possibile

	nodo * r=L;
	nodo * m;

	if(tenta(r,P,dimP,r)){
		L=m;

		return r;
	}
	return match2(L->next, P, dimP);

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

//PRE=(L(n) � una lista corretta, P ha dimP elementi, chiamiamo vL(n)=L(n))
nodo* match(nodo* &n, int*P, int dimP) {

	if(!n) return 0;
	nodo* ultimoNodo;
	bool trovato=confronta(n,P,dimP, ultimoNodo);
	if(trovato){
		nodo* L2=n;
		n=ultimoNodo->next;
		ultimoNodo->next=0;
		return L2;
	}
	return match(n->next, P,dimP);
}
//POST=(in L(n) c�� un match di P, allora la funzione restituisce col return
//match(vL(n),P[0..dimP-1]) e L(n)=resto_mach(vL(n),P[0..dimP-1], se invece non
//c�� il match allora la funzione restituisce 0 e L(n)=vL(n))


//PRE:
bool confronta(nodo* n,int* P, int dimP, nodo* & ultimoNodo){

	if(dimP==0){// caso base 1: match completato, quindi e' corretto restituire true.
		ultimoNodo=n;
		n=0;
		return true;
	}

	if(!n) return false;// caso base2: lista vuota, match non completato quindi si restituisce false;s

	if(n->info == P[0]){ //caso ricorsivo:

		return confronta (n->next,P+1,dimP-1, ultimoNodo);
	}
	return false;

}
//POST
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
