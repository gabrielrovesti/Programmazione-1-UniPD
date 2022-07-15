#include <iostream>

using namespace std;

//N.B.: Non sono per nulla certo della correttezza della prova di correttezza, ma può essere un punto di partenza. Per quanto riguarda il codice, quello in linea di massima è giusto (dato che l'esame l'ho passato) 

struct nodo {
	int info;
	nodo* next;
	nodo(int a=0,nodo* b=0) {
		info=a;
		next=b;
	}
}; //nodo di lista

struct coda {
	nodo* primo,*ultimo;
	coda(nodo* a=0,nodo* b=0) {
		primo=a;
		ultimo=b;
	}
}; //struttura coda

coda push_end(coda a,nodo* b) {
  	if(!a.primo) {
      a.primo=a.ultimo=b;
      b->next=0;
      return a;
    }
    
  	a.ultimo->next=b;
  	a.ultimo=b;
  	b->next=0;
  	return a;
} //inserimento di nodo in coda


void stampa_lista(nodo* L) {
  	if(L) {
    	cout << L->info << ' ';
    	stampa_lista(L->next);
  	} else cout << endl;
} //stampa di una lista

void build_array(int *P,int x) {
  	if(x) {
      	cin >> *P;
      	build_array(P+1,x-1);    
    }
} //creazione di un array di x elementi

nodo* build_list(int n) {
  	if(n) {
      	int x;
      	cin >> x;
      	return new nodo(x,build_list(n-1));
    }
  	return 0;
} //creazione di una lista di n elementi

nodo* clone(nodo* L) {
  	if(!L) return 0;
  	return new nodo(L->info,clone(L->next));
} //clonazione di una lista L

//PRE=(lista(L) e' ben formata, A contiene dimA elementi non negativi e crescenti, dimA>0, vL=lista(L))
nodo* distr_iter(nodo* &L,int* A,int dimA) {
	coda L1=coda();
	coda L2=coda();
	
	int i=0,j=0; //i scorre l'array, j scorre la lista
	
	// inserimento nodi in L1 e L2, finche' esiste A (ovvero i<dimA) e esiste L
	while(L && i<dimA) { //R=(|L|=numero di nodi di lista(L)) && (0<=i<=dimA) && (0<=j<=|L|) && (j==A[i] => viene inserito il nodo L in L1) && (j!=A[i] => viene inserito il nodo L in L2)
		if(j == A[i]) {
			//recupero il singolo nodo
			nodo* inL1=L;
			L=L->next;
			inL1->next=0;
			
			//lo inserisco nella coda
			L1=push_end(L1,inL1);
			
			i++; //incremento i perche' vado a visitare il prossimo elemento dell'array			
		} else {
			//recupero il singolo nodo
			nodo* fuoriL1=L;
			L=L->next;
			fuoriL1->next=0;
			
			//lo inserisco nella coda
			L2=push_end(L2,fuoriL1);
		}
		
		j++; //incremento j perche' vado a visitare il prossimo elemento della lista
	
	}
	
	// caso in cui e' finito l'array ma la lista ha ancora elementi
	while(L) {
		nodo* fuoriL1=L;
		L=L->next;
		fuoriL1->next=0;
		L2=push_end(L2,fuoriL1);	
	}
	
	//copio L2 in L
	L=L2.primo;
	
	return L1.primo;
}
//POST=(la funzione restituisce col return la lista L1 dei nodi di vL i cui indici sono in A - nello stesso ordine relativo che avevano in vL - mentre L diventa L2, cioe' la lista dei nodi di vL i cui indici non sono in A - nello stesso ordine relativo che avevano in vL)

//PRE=(lista(L) e' ben formata, A ha dimA>=0 elementi non negativi e crescenti e, se dimA>0, n<=A[0], vL=lista(L))
nodo* distr_ric(nodo* &L,int* A,int dimA,int n) {
	if(!L) return 0; // CASO BASE (1)
	if(!dimA) return 0; // CASO BASE (2)
	
	nodo* ric=0;
	
	if(n == *A) {
		ric=L;
		L=L->next;
		ric->next=distr_ric(L,A+1,dimA-1,n+1);
	} else {
		ric=distr_ric(L->next,A,dimA,n+1); 
	}
	
	return ric;
}
//POST=(restituisce col return la lista L1 dei nodi di vL i cui indici, sommati a n, sono in A - nello stesso ordine relativo che avevano in vL - e L diventa L2, cioe' la lista dei nodi di vL i cui indici sommati a n non sono in A - nello stesso ordine relativo che avevano in vL)

//DIMOSTRAZIONE DI CORRETTEZZA DI nodo* distr_ric(nodo* &L,int* A,int dimA,int n)
/*
	- si assume la validita' di PRE
	- si dimostrano i CASI BASE
	- si dimoostra induttivamente la POST
	
	CASO BASE (1): !L (oppure L == 0)
	In questo caso la lista(L) ricevuta come parametro e' vuota, di conseguenza non vi sono nodi da restituire perche' nessun indice in A puo' riferirsi a un nodo della lista, e L=L2=vL e' una lista vuota. La POST e' rispettata.
	
	CASO BASE (2): !dimA (oppure dimA == 0)
	In questo caso l'array A degli indici e' vuoto e quindi non vi sono nodi da aggiungere a L1 e L=L2=vL, ovvero rimane invariata. Anche in questo caso, la POST e' rispettata.
	
	DIMOSTRAZIONE INDUTTIVA DELLA POST
	Nessuno dei due casi base si e' verificato, quindi lista(L) ha almeno un nodo e dimA>0.
	Va ora controllato se n, ovvero l'indice dei nodi nella lista, sia uguale all'indice indicato da *A (che e' la posizione iniziale dell'array A dell'attuale chiamata di funzione).
	In caso lo sia, viene effettuata una chiamata ricorsiva con le seguenti condizioni:
		
		-PREric=(lista(L->next) e' ben formata, A+1 ha dimA-1>=0 elementi non negativi e crescenti e, se dimA-1>0, n+1<=A[0+1], vL->next=lista(L->next))
		-POSTric=(restituisce col return la lista L1 dei nodi di vL->next i cui indici, sommati a n+1, sono in A+1 - nello stesso ordine relativo che avevano in vL->next - e L->next diventa L2, cioe' la lista dei nodi di vL->next i cui indici sommati a n+1 non sono in A+1 - nello stesso ordine relativo che avevano in vL->next
	
	Da queste condizioni, e dal codice della funzione, si capisce che si e' appena aggiunto in L1 il nodo n-esimo e quindi si va a inserire come L->next il resto della lista L1 che rispetta la POST. Si ha finito di operare con la posizione attuale di A, si passa alla successiva. n viene incrementato. La POST e' rispettata.
	
		
	In caso non lo sia, viene effettuata un'altra chiamata ricorsiva, con le seguenti condizioni:
		
		-PREric=(lista(L->next) e' ben formata, A ha dimA>=0 elementi non negativi e crescenti e, se dimA>0, n<=A[0], vL->next=lista(L->next))
		-POSTric=(restituisce col return la lista L1 dei nodi di vL->next i cui indici, sommati a n+1, sono in A - nello stesso ordine relativo che avevano in vL->next - e L->next diventa L2, cioe' la lista dei nodi di vL i cui indici sommati a n+1 non sono in A - nello stesso ordine relativo che avevano in vL)
		
		Da queste condizioni, e dal codice della funzione, si capisce che non si e' fatto nulla e che L e' rimasta uguale, va visitato il prossimo nodo L->next. n viene incrementato. La POST e' rispettata.
*/

int main() {
  	int n,m;
  	
  	cout << "start" << endl;
  	
  	// COSTRUZIONE LISTA DI n ELEMENTI
  	cin >> n;
  	
  	nodo* L=build_list(n);
  	
  	// CLONAZIONE LISTA L IN L1
  	nodo* L1=clone(L);
  	
  	stampa_lista(L);
  	
  	// CREAZIONE ARRAY INDICI
	cin >> m;
	
	int* A=new int[m];
	
	build_array(A,m);
	
	// FUNZIONE ITERATIVA
	nodo* y=distr_iter(L,A,m);
	
	//// STAMPA DELLA LISTA DEI NODI CON INDICI IN A
	stampa_lista(y);
	
	//// STAMPA DELLA LISTA DEI NODI CON INDICI NON IN A
	stampa_lista(L);
	
	
	// FUNZIONE RICORSIVA
	y=distr_ric(L1,A,m,0);
	
	//// STAMPA DELLA LISTA DEI NODI CON INDICI IN A
	stampa_lista(y);
	
	//// STAMPA DELLA LISTA DEI NODI CON INDICI NON IN A
	stampa_lista(L1);
	
	cout << "end" << endl;
}