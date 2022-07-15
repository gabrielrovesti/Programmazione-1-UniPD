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
};

struct coda {
	nodo* primo,*ultimo;
	coda(nodo* a=0,nodo* b=0) {
		primo=a;
		ultimo=b;
	}
};

coda push_beg(coda x,nodo* a) {
	if(!x.primo) {
		x.primo=x.ultimo=a;
		a->next=0;
		return x;
    }
	
	a->next=x.primo;
	x.primo=a;
	
	return x;
}

coda push_end(coda x,nodo* a) {
	if(!x.primo) {
		x.primo=x.ultimo=a;
		a->next=0;
		return x;
	}
	
	x.ultimo->next=a;
	x.ultimo=a;
	a->next=0;
	
	return x;
}

nodo* buildlist(int m) {
	if(m > 0) {
		int x;
		cin >> x;
		return new nodo(x,buildlist(m-1));
    }
	return 0;
}

nodo* clone(nodo* L) {
	if(L)
		return new nodo(L->info,clone(L->next));
	return 0;
}

void stampaL(nodo* L) {
	if(L) {
		cout << L->info << ' ';
		stampaL(L->next);
    } else cout << endl;
}

//PRE=(lista(ord) e lista(L) sono due liste ben formate) && (lista(ord) ha i campi info dei suoi nodi in ordine crescente)
void ordric_aux(nodo* &ord,nodo* L) {
	if(!ord) {
		L->next=0;
		ord=L;
	} else {
		if(L->info <= ord->info) { //se fosse semplicemte "minore stretto" in caso di uguaglianza fra i due avrei una chiamata ricorsiva in più, con lo stesso risultato finale. Con "minore non stretto" evito ciò.
			L->next=ord;
			ord=L;
		} else {
			ordric_aux(ord->next,L);
		}
	}
}
//POST=(viene inserito in lista(ord) il nodo di lista(L) in modo che i valori dei campi info di lista(ord) siano ancora in ordine crescente)

//PRE=(lista(L) è ben formata, lista(ord) è ben formata e ordinata, siano v_L e v_o i valori iniziali di lista(L) e lista(ord))
void ordric(nodo* &L,nodo* &ord) {
	if(L) { 
		ordric(L->next,ord);
		ordric_aux(ord,L);
		L=0;
	} // !L ovvero CASO BASE (1)
}
//POST=(lista(L) è vuota e lista(ord) è la lista ordinata composta dai nodi di v_L e di v_o)

void orditer_aux(coda &Q,nodo* daIns) {
	if(!Q.primo || daIns->info <= Q.primo->info) { //se la coda ordinata è vuota oppure se il nodo da inserire ha campo info inferiore/uguale alla testa della coda
	
		Q=push_beg(Q,daIns); //lo inserisco all'inizio
		
	} else if(daIns->info >= Q.ultimo->info) { //se il nodo da inserire ha campo info maggiore/uguale alla fine della coda allora lo inserisco in fondo
		
		Q=push_end(Q,daIns);
		
	} else {
		
		nodo* attuale=Q.primo; //punto al primo nodo della coda ordinata
		
		while(attuale->next && daIns->info >= attuale->next->info) { //se esiste un successivo e questo ha campo info minore di quello del nodo che devo inserire allora procedo con i controlli
			attuale=attuale->next; //il nodo attuale ora punta al suo successivo
		}
		
		daIns->next=attuale->next; //il successivo del nodo che vado a inserire è il nodo successivo a quello attuale
		attuale->next=daIns; //e quindi aggiorno il nodo attuale dicendo che il suo successivo è il nodo che devo inserire
		
	}
}

//PRE=(lista(L) ben formata, v_L è il valore iniziale di lista(L))
nodo* orditer(nodo* L) {
	coda ord=coda();
	
	while(L) {
	//R=(lista(L) è ben formata) && (ord è una coda ben formata e ordinata e al momento attuale contiene i valori v_o corrispondenti ai valori v_L di lista(L)
	//fino al nodo attuale disposti in ordine crescente nei nodi della coda
		nodo* primoL=L; //primoL punta al 1° nodo di attuale L
		L=L->next; //L ora punta al suo attuale 2° nodo
		primoL->next=0; //stacco primoL dal resto della lista (ho ora un nodo isolato)
		orditer_aux(ord,primoL); //inserisco primoL in coda ord nella posizione giusta
	}
	
	return ord.primo;
}
//POST=(restituisce la lista composta dai nodi di v_L ordinati rispetto al campo info)

int main() {
	int n;
  
	cout << "start" << endl;
  
	cin >> n;
  
	nodo* L=buildlist(n);
  
	stampaL(L);
  
	nodo* L1=clone(L);
  
	cout << endl;
  
	nodo* L2=0;
	
	ordric(L,L2);
	
	stampaL(L2);
	
	nodo* y=orditer(L1);
  
	stampaL(y);
	
	cout << "end" << endl;
}

//DIMOSTRAZIONE DI CORRETTEZZA DI ordric(nodo*&,nodo*&) 
/*
	- viene assunta la validità di PRE
	- vengono verificati i casi base
	- viene dimostrata per induzione la validità di POST
	
	CASO BASE (1): !L (oppure L==0)
	In questo caso la lista(L) è vuota e lista(ord) contiene i valori di v_L e v_o in ordine crescente. Sicuramente è
	verificata la POST perché L non influisce su di essa in quanto è vuota, mentre v_o sono valori ordinati in base a 
	ciò che indica la PRE, quindi sicuramente lista(ord) è ordinata e la POST è soddisfatta.
	
	PROVA INDUTTIVA
	In questo caso, lista(L) non è certamente vuota in quanto non si è verificato il caso base e quindi ha almeno un nodo.
	A questo punto del calcolo viene effettuata la chiamata ricorsiva che ha le seguenti PRE e POST:
	
		- PRE_ric=(lista(L->next) è ben formata, lista(ord) è ben formata e ordinata, siano v_L e v_o i valori iniziali di lista(L->next) e lista(ord))
		- POST_ric=(lista(L->next) è vuota e lista(ord) è la lista ordinata composta dai nodi di v_L e di v_o)
	
	La PRE_ric si assume per valida dalla validità di PRE. Infatti essendo lista(L) ben formata, anche lista(L->next) lo è (ovvero puo contenere uno 
	o più nodi oppure essere vuota), lista(ord) è ben formata e ordinata, ovvero i valori presenti nei campi info dei nodi di lista(ord), chiamati v_o,
	sono in ordine crescente.
	
	La POST_ric è altrettanto valida poiché se si verifica il CASO BASE (1) succede esattamente ciò che viene spiegato sopra.
	Se non si verifica viene chiamata la funzione ordric_aux(nodo*&,nodo*&) che si occupa di inserire all'interno di lista(ord) un nodo passato come parametro, non in maniera casuale o in fondo a
	lista(ord) semplicemente, ma in base al valore del suo campo info. Qui di seguito la PRE e la POST di ordric_aux(nodo*&,nodo*&):
	
		-PRE=(lista(ord) e lista(L) sono due liste ben formate) && (lista(ord) ha i campi info dei suoi nodi in ordine crescente)
		-POST=(viene inserito in lista(ord) il nodo di lista(L) in modo che i valori dei campi info di lista(ord) siano ancora in ordine crescente)
	
	Quando viene inserito il nodo, la funzione azzera il valore attuale di L->next e quindi viene verificata la POST_ric, che per induzione porta alla verifica
	di POST, dimostrando la validità della ricorsione.
*/