#include<iostream>
using namespace std;

struct nodo{int info; nodo*next; nodo(int a=0, nodo*b=0){info=a; next=b;}};
struct nodoL{nodo* p;nodoL* next; nodoL(nodo*a=0, nodoL*b=0){p=a; next=b;}};
//------------------------funzioni di lettura e stampa----------------------

nodo *buildL(int k)
{
	if(!k) return 0;
	else {
		int x;
		cin>>x;
		return new nodo(x,buildL(k-1));
    }
}

nodo* clone(nodo*L)
{
	if(!L) return 0;
	else
		return new nodo(L->info,clone(L->next));
}

void stampa(nodo*L);
void stampaL(nodoL*LL)
{
	if(LL) {
		stampa(LL->p);
		stampaL(LL->next);
    }
}

void stampa(nodo*L)
{
	if(!L) cout<<endl;
	else {
      cout<<L->info<<' ';
      stampa(L->next);
	}
}

// PRE=(lista(L) e' ben formata) 
nodo* tagliaric(nodo* p) {
	if (!p->next || p->info>p->next->info) {
		return p;
	}
	return tagliaric(p->next);
}
// POST=(restituisce il puntatore all'ultimo pezzo CeNA )	

// PRE=(lista(L) ben formata) 
nodoL* Gric(nodo*L) {
	if (!L) {
		return 0;
	}
	nodo*x=L;
	nodo* y=tagliaric(L);
	L=y->next;
	y->next=0;
	nodoL* z= new nodoL(x);
	z->next=Gric(L);
	return z;
}
/* 
POST=(restituisce una lista concatenata LL di nodi di tipo nodoL con tanti nodi quanti sono i 
	  pezzi CeNA di L e tale che il primo nodo di LL ha campo p che punta al primo pezzo CeNA 
	  di L, il secondo nodo punta al secondo pezzo CeNA e così via. I pezzi CeNA puntati da LL 
	  sono trasformati in liste ben formate mettendo a 0 il campo next del loro ultimo nodo) 
*/

int contanodi(nodo* t) {
	int i=0;
	while(t) {
		i=i+1;
		t=t->next;
	}
	return i;
}

nodoL* push_iter(nodoL* x, nodoL* z) {
	// caso base 1: x vuota
	if (!x) {
		return z;
	}
	// caso base 2: voglio inserire il nodo z all'inizio di x
	if (contanodi(z->p)>contanodi(x->p)) {
		z->next=x;
		x=z;
		return x;
	}
	nodoL* inizio=x;
	while (x->next && (contanodi(z->p)<=contanodi(x->next->p))) {
		x=x->next;			
	}
	// x punta al nodo precedente al nodo che voglio aggiungere
	if (!x->next) {
		x->next=z;
		return inizio;
	}
	else {
		z->next=x->next;
		x->next=z;
		return inizio;
	}
}

// PRE=(lista(LL) ben formata di nodi nodoL) 
nodoL* ordina(nodoL* LL) {
	nodoL* x=0;
	while (LL) {
		nodoL* z=LL;
		LL=LL->next;
		z->next=0;
		x=push_iter(x, z);
	}
	return x;
}
/* POST=(restituisce la lista LL’ che contiene i nodi di LL ordinati per lunghezza 
		 decrescente dei pezzi puntati. I nodi che puntano a pezzi di uguale lunghezza 
		 mantengono la loro posizione relativa in LL) */

main() {
	cout<<"start"<<endl;
	int n;
	cin >> n;
	nodo*L=buildL(n);
	stampa(L);
   
	nodoL* LL=Gric(L);
	cout<<"Lista dei pezzi:"<<endl;
	stampaL(LL);
 
	nodoL* LL1=ordina(LL);
	cout<<"Lista ordinata:"<<endl;
	stampaL(LL1);
	cout<<"end"<<endl;
}