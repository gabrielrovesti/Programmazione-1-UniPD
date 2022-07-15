#include<iostream>
using namespace std;


struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};


nodo* crea(int );

void stampa(nodo*);

void leggi(int , int*);

bool verifica_match(nodo * , int *, int);

nodo* match (nodo* & , int * , int );

int main()
{
  int dim, dimP, P[20];
  cin>>dim;
  nodo* L1=crea(dim);
  cin>>dimP;
  leggi(dimP, P);
  cout<<"start"<<endl;
  nodo* L2= match(L1,P, dimP);


  if(L2)
    stampa(L2);
  else
    cout<<"Lista del match vuota"<<endl;
   if(L1)
     stampa(L1);
   else
     cout<<"Lista restante vuota"<<endl;
   cout<<"end"<<endl;

}



nodo* crea(int dim)
{
 if(dim)
  {
    int x;
    cin>>x;
    return new nodo(x,crea(dim-1));
  }
 return 0;
}
void stampa(nodo*L)
{
  if(L)
  {
    cout<<L->info<<' ';
    stampa(L->next);
  }
 else
    cout<<endl;
}
void leggi(int dim, int*P)
{
  if(dim)
   {
    cin>>*P;
    leggi(dim-1,P+1);
   }

}

bool verifica_match(nodo*  T, int * P, int dimP){
	if(dimP==0) return true;

	if(!T) return false;

	if(T->info == P[0])
		return verifica_match(T->next, P+1,dimP-1);
	else
		return verifica_match(T->next, P, dimP);
}

//PRE=(L(T)  è corretta, dimP>0, P ha dimP elementi definiti)
nodo* match (nodo* & T, int * P, int dimP){

	if(! dimP) return 0;
	nodo* listaTemp=T;
	bool isMatch=verifica_match(listaTemp,P,dimP);
	if(!isMatch)
		return 0;


	if( T->info == P[0]){

		nodo* daRest= T;

		T=T->next;
		daRest->next= match(T,P+1,dimP-1);

		return daRest;
	}else{
		return match(T->next,P,dimP);
	}


}
//POST=(se c’è un match completo di P in L (T) allora la funzione
//restituisce col return la lista del match e in T la lista restante,
//altrimenti, restituisce 0 col return e L(T) resta uguale).


nodo* tenta(nodo *  T, int * P, int dimP, int & numeroMatch){
	if(T->info == *P){
		numeroMatch++;
		return tenta(T->next,P+1,dimP-1, numeroMatch);
	}else{

		return T;
	}

}





