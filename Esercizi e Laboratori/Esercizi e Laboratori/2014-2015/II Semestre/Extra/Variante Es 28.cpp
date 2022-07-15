#include<iostream>
#include<fstream>

using namespace std;

/* VARIANTE:
rispetto all'esercizio 28 assegnato, qui si vogliono eliminare i nodi che "matchano" di lista(T)
e garantire alla fine lista(T) corretta e "purgata" di quei nodi il cui info1 matchava in P
*/


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


nodo*& f_next(nodo*&T, int *P, int &a)
{	//PRE=().
	if(!T)	//se ho finito la lista T, non ho trovato il nodo su cui "saltare" (T==0)
		return T;	//ritorno 0
	if(T->info1==*P)	//se ho trovato il nodo su cui "saltare" (il primo che matcha)
		return T;	//da qui devo fare 0 salti (ci sono sopra), ed il puntatore è T (il nodo attuale)
	a++;	//mi preparo a passare al prossimo, me lo ricordo per side-effect
	return f_next(T->next, P, a);;
}	/* POST=(). */


nodo* f_match(nodo *T, int *P, int dimP, int &b)
{	//PRE=().
	 if(!T)	//stavo matchando ma sono uscito dalla lista T, quindi non ci saranno nodi dopo la sequenza di match e l'attuale nodo NON matcha (non esiste)
		return T;	//ritorno 0
	if(!dimP)	//stavo matchando ma ho finito le cose da matchare, quindi il nodo attuale non è da considerare, di T non me ne farò niente
		return T;
	if(T->info1!=*P)	//se sono sul primo dopo la sequenza di match che non matcha, lo restituisco per un futuro "salto"
		return T;
		
	//altrimenti questo matcha...
	nodo* temp=T->next;	//backup del suo campo next
	delete T;	//lo cancello
	b++;	//mi preparo a passare al prossimo, me lo ricordo per side-effect
	return f_match(temp, P+1, dimP-1, b);

}	//POST=().


nodo* TX(nodo *&T, int *P, int dimP)
{	//PRE().
	if(!T || !dimP)	//se ho finito la lista(T) o gli elementi da cercare il lavoro è finito
		return 0;	//chiudo la lista(X)

	int a=0, b=0;
	nodo *&ta=f_next(T,P,a);	//scopri se, dove e di quanto saltare
	nodo *tb=f_match(ta, P, dimP, b);	//vai e scopri per quanto si estende il match (e ritorna anche un puntatore all'eleme successivo all'ultimo del match)
	ta=tb;	//riattacco la parte eliminata con quella non eliminata
	
	nodo *tc=TX(tb, P+b, dimP-b);
	
	return (new nodo(a,b,tc));
}	/* POST=(). */


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

void stampa_lista(nodo* x, ofstream &OUT)
{
	if(x)
	{
		OUT<<'('<< x->info1<<','<<x->info2<<')';
		if(x->next)
		OUT<<"->";
		//cout<< x->info1<<' '<<x->info2<<' ';
		stampa_lista(x->next, OUT);
	}
	else
	{
		OUT<<endl;
		//cout<<endl;
	}
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

		OUT<<"T originale: ";
		stampa_lista(L, OUT);
		OUT<<endl;

		IN>>dimP;
		for(int i=0; i<dimP; i++)
		IN>>P[i];
		nodo* K=TX(L,P,dimP);	//da fare 
		
		OUT<<"cosa dice X:"<<endl;
		stampa(K,OUT);	//data
		OUT<<endl;
		
		OUT<<"nuovo T: ";
		stampa_lista(L, OUT);
		OUT<<endl;
		
   
		IN.close();
		OUT.close(); 
	}
	else
		cout<<"errore con i files";
}
