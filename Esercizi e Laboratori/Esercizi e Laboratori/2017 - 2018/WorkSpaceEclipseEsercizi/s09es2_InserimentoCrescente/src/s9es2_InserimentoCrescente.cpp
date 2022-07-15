#include<iostream>
using namespace std;

struct nodo{int info; nodo*next; nodo(int a=0, nodo*b=0){info=a; next=b;}};


void stampa_lista(nodo*);

nodo* F(nodo*);
nodo* inserisci(nodo*,int );

int main()
{
  cout<<"start"<<endl;
  nodo* L= F(0);


  stampa_lista(L);
  cout<<endl;
  cout<<"end"<<endl;
}

nodo* F(nodo * L){




	int num;
	cin>>num;

	if(num != -1){

		L= inserisci(L, num);
		return F(L);

	}

	return L;
}

nodo* inserisci(nodo * L, int numero){

	if(!L)	return new nodo (numero, 0);

	if(numero <= (L->info)) return new nodo(numero,L);

	L->next= inserisci(L->next,numero);
	return L;
}
void stampa_lista(nodo * L){

	if(L){
		cout<<L->info;
		if(L->next){
			cout<<" -> ";
			stampa_lista(L->next);
		}
	}else{
	    cout<<"lista vuota"<<endl;
	}

}
