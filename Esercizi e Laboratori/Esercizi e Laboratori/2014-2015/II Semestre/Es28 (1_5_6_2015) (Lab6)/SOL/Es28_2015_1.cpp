
//soluzione by: Leo M.

// Versione 1:
#include <iostream>
#include<fstream>

using namespace std;



struct nodo
{
	int info1, info2;
	nodo* next;
	nodo(int a=0, int b=0, nodo* c=0)
	{	info1=a;
		info2=b;
		next=c;
	}
};


struct cop
{
	nodo* N;
	int num;
	cop(nodo* a=0, int b=0)
	{	N=a;
		num=b;
	}
};


cop f_next(nodo* T, int *P)
{	//PRE=(lista(T) corretta, P[0] definito (ho almeno un altro elemento da matchare)).
	if(!T)	//se ho finito la lista T, non ho trovato il nodo su cui "saltare"
		return cop(0,0);	//chiamata al costruttore di cop che per default ritorna (0,0)
	if(T->info1==*P)	//se ho trovato il nodo su cui "saltare" (il primo che matcha)
		return cop(T, 0);	//da qui devo fare 0 salti (ci sono sopra), ed il puntatore è T (il nodo attuale)
	cop a=f_next(T->next, P);
	a.num=a.num+1;	//aggiungo me stesso
	return a;
}	/* POST=(restituisce z di tipo strutturato cop;
			 se z.N==0 allora ho finito lista(T) senza trovare un nodo che matcha con P[0];
			 altrimenti:
			 	- z.N è tale che z.N->info1==P[0],
			 	- z.num è il numero di nodi che non matchano e quindi da saltare (a partire da quello puntato da T) per arrivare a z.N). */


cop f_match(nodo *T, int *P, int dimP)
{	//PRE=(lista(T) corretta, P[0..dimP-1] definito, dimP>=0).
	 if(!T)	//stavo matchando ma sono uscito dalla lista T, quindi non ci saranno nodi dopo la sequenza di match e l'attuale nodo NON matcha (non esiste)
		return cop();	//chiamata al costruttore di cop che per default ritorna (0,0)
	if(!dimP)	//stavo matchando ma ho finito le cose da matchare, quindi il nodo attuale non è da considerare, di T non me ne farò niente
		return cop(T,0);
	if(T->info1==*P)	//se questo matcha...
	{
		cop b=f_match(T->next, P+1, dimP-1);	//..continuo
		b.num=b.num+1;	//aggiungo me stesso
		return b;
	}
	else	//altrimenti sono sul primo dopo la sequenza di match che non matcha, lo restituisco per un futuro "salto"
		return cop(T,0);
}	//POST=(restituisce z di tipo strutturato cop; i primi z.num nodi di lista(T) matchano P[0..z.num] e z.N punta al nodo successivo (cioè al "z.num+1_esimo")).


nodo* TM(nodo *T, int *P, int dimP)
{	//PRE(lista(T) è corretta, P[0..dimP-1] è definito, dimP>=0).
	if(!T || !dimP)	//se ho finito la lista(T) o gli elementi da cercare il lavoro è finito
		return 0;	//chiudo la lista(X)

	cop a=f_next(T,P);	//scopri se, dove e di quanto saltare
	if(!a.N)	//se NON c'è un posto dove saltare
		return 0;	//ferma tutto

	nodo *X=new nodo();	//(altrimenti) crea un nuovo nodo
	X->info1=a.num;	//e inserisci "di quanto" saltare nel campo info1 del nodo di X;

	cop b=f_match(a.N, P, dimP);	//vai e scopri per quanto si estende il match (e ritorna anche un puntatore all'eleme successivo all'ultimo del match)
	X->info2=b.num;	//inserisci "per quanti" nodi consecutivi c'è match nel campo info2 del nodo di X;
	
	X->next=TM(b.N, P+(b.num), dimP-(b.num));	//passa alla costruzione del prossimo nodo di lista(X) che andrà agganciato a questo
	
	return X;
}	/* POST=(restituisce la lista che rappresenta il match di P[0..dimP-1] su lista(T);
			 tale lista (X) è composta di nodi nei quali:
			 - info1 è il numero di nodi da saltare per trovare il prossimo match,
			 - info2 indica per quanti nodi il match si prolunga senza interruzzioni). */


nodo* costruisci(int n, int dim, ifstream &IN)
{
	if(n==dim)
		return 0;
	int x;
	IN>>x;
	return new nodo(x,n,costruisci(n+1, dim, IN));
}


void stampa(nodo* L, ofstream &OUT)
{
	if(L)
	{
		OUT<<"salta="<<L->info1<<" matcha="<<L->info2<<' ';
		stampa(L->next,OUT);
	}
	else
	OUT<<endl;
}





main()
{
	ifstream IN("input");
	ofstream OUT("output");
	if(IN && OUT) 
	{
		
		int dim, dimP, P[30];
		IN>>dim;
		nodo* L=costruisci(0,dim,IN);	//data

		IN>>dimP;
		for(int i=0; i<dimP; i++)
		IN>>P[i];
		nodo* K=TM(L,P,dimP);	//da fare 
		stampa(K,OUT);	//data
		OUT<<"fine"<<endl;
		
   
		IN.close();
		OUT.close(); 
	}
	else
		cout<<"errore con i files";
}





/* Versione 2:
#include<iostream>
#include<fstream>

using namespace std;



struct nodo
{
	int info1, info2;
	nodo* next;
	nodo(int a=0, int b=0, nodo* c=0)
	{	info1=a;
		info2=b;
		next=c;
	}
};


struct cop
{
	nodo* N;
	int num;
	cop(nodo* a=0, int b=0)
	{	N=a;
		num=b;
	}
};


cop f_next(nodo* T, int *P)
{	//PRE=(lista(T) corretta, P[0] definito (ho almeno un altro elemento da matchare)).
	if(!T || T->info1==*P)
		return cop(T,0);
	cop a=f_next(T->next, P);
	return cop(a.N, a.num+1);
}	// POST=(restituisce z di tipo strutturato cop;
	//		 se z.N==0 allora ho finito lista(T) senza trovare un nodo che matcha con P[0];
	//		 altrimenti:
	//		 	- z.N è tale che z.N->info1==P[0],
	//		 	- z.num è il numero di nodi che non matchano e quindi da saltare (a partire da quello puntato da T) per arrivare a z.N).


cop f_match(nodo *T, int *P, int dimP)
{	//PRE=(lista(T) corretta, P[0..dimP-1] definito, dimP>=0).
	 if(!dimP || !T || T->info1!=*P)
		return cop(T,0);
	cop b=f_match(T->next, P+1, dimP-1);
	return cop(b.N, b.num+1);
}	//POST=(restituisce z di tipo strutturato cop; i primi z.num nodi di lista(T) matchano P[0..z.num] e z.N punta al nodo successivo (cioè al "z.num+1_esimo")).


nodo* TM(nodo *T, int *P, int dimP)
{	//PRE(lista(T) è corretta, P[0..dimP-1] è definito, dimP>=0).
	if(!T || !dimP)	//se ho finito la lista(T) o gli elementi da cercare il lavoro è finito
		return 0;	//chiudo la lista(X)

	cop a=f_next(T,P);	//scopri se, dove e di quanto saltare
	cop b=f_match(a.N, P, dimP);	//vai e scopri per quanto si estende il match (e ritorna anche un puntatore all'eleme successivo all'ultimo del match)
	
	return (new nodo(a.num, b.num, TM(b.N, P+b.num, dimP-b.num)));
}	// POST=(restituisce la lista che rappresenta il match di P[0..dimP-1] su lista(T);
	//		 tale lista (X) è composta di nodi nei quali:
	//		 - info1 è il numero di nodi da saltare per trovare il prossimo match,
	//		 - info2 indica per quanti nodi il match si prolunga senza interruzzioni).


nodo* costruisci(int n, int dim, ifstream &IN)
{
	if(n==dim)
		return 0;
	int x;
	IN>>x;
	return new nodo(x,n,costruisci(n+1, dim, IN));
}


void stampa(nodo* L, ofstream &OUT)
{
	if(L)
	{
		OUT<<"salta="<<L->info1<<" matcha="<<L->info2<<' ';
		stampa(L->next,OUT);
	}
	else
	OUT<<endl;
}





main()
{
	ifstream IN("input");
	ofstream OUT("output");
	if(IN && OUT) 
	{
		
		int dim, dimP, P[30];
		IN>>dim;
		nodo* L=costruisci(0,dim,IN);	//data

		IN>>dimP;
		for(int i=0; i<dimP; i++)
		IN>>P[i];
		nodo* K=TM(L,P,dimP);	//da fare 
		stampa(K,OUT);	//data
		OUT<<"fine"<<endl;
		
   
		IN.close();
		OUT.close(); 
	}
	else
		cout<<"errore con i files";
}
*/



/* Versione 3:
#include<iostream>
#include<fstream>

using namespace std;



struct nodo
{
	int info1, info2;
	nodo* next;
	nodo(int a=0, int b=0, nodo* c=0)
	{	info1=a;
		info2=b;
		next=c;
	}
};


struct cop
{
	nodo* N;
	int num;
	cop(nodo* a=0, int b=0)
	{	N=a;
		num=b;
	}
};


nodo* f_next(nodo* T, int *P, int &a)
{	//PRE=(lista(T) corretta, P[0] definito (ho almeno un altro elemento da matchare), va=a).
	if(!T)	//se ho finito la lista T, non ho trovato il nodo su cui "saltare"
		return 0;	//ritorno 0
	if(T->info1==*P)	//se ho trovato il nodo su cui "saltare" (il primo che matcha)
		return T;	//da qui devo fare 0 salti (ci sono sopra), ed il puntatore è T (il nodo attuale)
	a++;	//mi preparo a passare al prossimo, me lo ricordo per side-effect
	nodo* ta=f_next(T->next, P, a);
	return ta;
}	// POST=(restituisce un puntatore z tale che;
	//		 se z==0 allora ho finito lista(T) senza trovare un nodo che matcha con P[0];
	//		 altrimenti:
	//		 	- z è tale che z->info1==P[0],
	//		 	- a-va è il numero di nodi che non matchano e quindi da saltare (a partire da quello puntato da T) per arrivare a z).


nodo* f_match(nodo *T, int *P, int dimP, int &b)
{	//PRE=(lista(T) corretta, P[0..dimP-1] definito, dimP>=0, vb=b).
	 if(!T)	//stavo matchando ma sono uscito dalla lista T, quindi non ci saranno nodi dopo la sequenza di match e l'attuale nodo NON matcha (non esiste)
		return 0;	//ritorno 0
	if(!dimP)	//stavo matchando ma ho finito le cose da matchare, quindi il nodo attuale non è da considerare, di T non me ne farò niente
		return T;
	if(T->info1==*P)	//se questo matcha...
	{
		b++;	//mi preparo a passare al prossimo, me lo ricordo per side-effect
		nodo* tb=f_match(T->next, P+1, dimP-1, b);	//..continuo
		return tb;
	}
	else	//altrimenti sono sul primo dopo la sequenza di match che non matcha, lo restituisco per un futuro "salto"
		return T;
}	//POST=(restituisce un puntatore z tale che: z punta al nodo successivo (cioè al "b-vb_esimo") e i primi b-vb nodi di lista(T) matchano P[0..b-vb]).
// nota:
//è "b-vb" e non semplicemente "b" perchè la POST si riferisce ad una generica istanza di match che ha "un suo zero" (o punto di partenza) che è vb;
//la prima volta vb==0.
//(stesso ragionamento per la post di f_next).


nodo* TM(nodo *T, int *P, int dimP)
{	//PRE(lista(T) è corretta, P[0..dimP-1] è definito, dimP>=0).
	if(!T || !dimP)	//se ho finito la lista(T) o gli elementi da cercare il lavoro è finito
		return 0;	//chiudo la lista(X)

	int a=0, b=0;
	nodo* ta=f_next(T,P,a);	//scopri se, dove e di quanto saltare
	if(!ta)	//se NON c'è un posto dove saltare
		return 0;	//ferma tutto

	nodo *X=new nodo();	//(altrimenti) crea un nuovo nodo
	X->info1=a;	//e inserisci "di quanto" saltare nel campo info1 del nodo di X;

	nodo* tb=f_match(ta, P, dimP, b);	//vai e scopri per quanto si estende il match (e ritorna anche un puntatore all'eleme successivo all'ultimo del match)
	X->info2=b;	//inserisci "per quanti" nodi consecutivi c'è match nel campo info2 del nodo di X;
	
	X->next=TM(tb, P+(b), dimP-(b));	//passa alla costruzione del prossimo nodo di lista(X) che andrà agganciato a questo
	
	return X;
}	// POST=(restituisce la lista che rappresenta il match di P[0..dimP-1] su lista(T);
	//		 tale lista (X) è composta di nodi nei quali:
	//		 - info1 è il numero di nodi da saltare per trovare il prossimo match,
	//		 - info2 indica per quanti nodi il match si prolunga senza interruzzioni).


nodo* costruisci(int n, int dim, ifstream &IN)
{
	if(n==dim)
		return 0;
	int x;
	IN>>x;
	return new nodo(x,n,costruisci(n+1, dim, IN));
}


void stampa(nodo* L, ofstream &OUT)
{
	if(L)
	{
		OUT<<"salta="<<L->info1<<" matcha="<<L->info2<<' ';
		stampa(L->next,OUT);
	}
	else
	OUT<<endl;
}





main()
{
	ifstream IN("input");
	ofstream OUT("output");
	if(IN && OUT) 
	{
		
		int dim, dimP, P[30];
		IN>>dim;
		nodo* L=costruisci(0,dim,IN);	//data

		IN>>dimP;
		for(int i=0; i<dimP; i++)
		IN>>P[i];
		nodo* K=TM(L,P,dimP);	//da fare 
		stampa(K,OUT);	//data
		OUT<<"fine"<<endl;
		
   
		IN.close();
		OUT.close(); 
	}
	else
		cout<<"errore con i files";
}
*/
