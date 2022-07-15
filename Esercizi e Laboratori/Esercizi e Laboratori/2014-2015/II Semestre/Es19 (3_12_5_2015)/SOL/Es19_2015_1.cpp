
//soluzione by: Leo M.

#include <iostream>
#include<fstream>

using namespace std;


//ADT - Dichiarazione, Definizione

struct nodo
{
	//membri - campi dati
	int info;
	nodo* next;
	
	//costruttore
	nodo(int a=0, nodo* b=0)
	{
		info=a;
		next=b;
	}
};


//Prototipi di FUNZIONI (Dichiarazioni)

nodo* crea(int dim, ifstream &INP);

nodo* del_z(nodo *n, int z);

void print_list(nodo *x, ofstream &OUT);



main()
{	//PRE=().
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT)
	{
		//creazione (puntatore a) lista vuota
		nodo *inizio=0;
		
		int dim;
		INP>>dim;
		
		//inserimento di dim nodi nella lista
		inizio=crea(dim, INP);
		
		int z;
		INP>>z;
		
		//cancello dalla lista tutti i nodi il cui campo info==z
		inizio=del_z(inizio,z);
		
		//se c'è almeno un nodo, stampo la lista "purgata dei nodi con info==z, se non c'è non faccio niente
		if(inizio)
			print_list(inizio, OUT);
		
		OUT<<"fine"<<endl;
		
		INP.close();
		OUT.close();
	}
	else
		cerr<<"Errore con i File!"<<endl;
}	//POST=().



//Implementazioni delle FUNZIONI (Definizione)

nodo* crea(int dim, ifstream &INP)
{	//PRE=(INP (che è lo stream collegato a "input") contiene dim interi, 0<=dim).
	if(dim==0)	//caso base: non ho più nodi da creare
		return 0;
	else	//dim>0, quindi ho almeno un altro nodo da creare
	{
		int inf;	//variabile ausiliaria
		INP>>inf;	//carico dal file "input" il valore da mettere in "info" del nodo corrente
		
		return new nodo(inf, crea(dim-1, INP));	//ricorsione, passo al prossimo nodo di cui restituirò un puntatore
	}
}	//POST=(restituisce (un punt al)la lista concatenata con dim nodi che hanno campo info uguale ai dim valori su INP e sono nello stesso ordine in cui sono letti).


nodo* del_z(nodo* n, int z)
{	//PRE=(lista(n) è una lista corretta, eventualmente vuota, z è un intero).
	if(!n)	//caso base: sono appena uscito dalla lista
		return 0;
	else	//sono su un nodo
	{
		if(n->info==z)	//se il nodo in cui sono ha il campo info==z devo cancellarlo
		{
			nodo* temp=n->next;	//mi salvo il valore del campo next del nodo in cui sono
			delete n;	//cancello il nodo in cui sono (puntato da "n")
			n=0;	//per sicurezza azzero il puntatore a mano, perchè delete NON lo fa
			return del_z(temp, z); //mi trasferisco al prossimo nodo
		}
		else	//il nodo in cui sono ha il campo info!=z, aggiorno il suo campo "next" e procedo al prossimo nodo
		{
			n->next=del_z(n->next, z);	//aggiorno il campo next del nodo corrente (che ha info!=z) e quindi non è stato cancellato
			return n;	//ritorno un puntatore al nodo attuale che non essendo stato cancellato và "riattaccato" al suo predecessore
		}
	}
}	//POST=(restituisce (un punt a) una lista(n) composta da nodi il cui campo info!=z; i nodi con campo info==z della vL sono stati deallocati (con delete)).


void print_list(nodo *x, ofstream &OUT)
{	//PRE=(x è una lista corretta e non vuota).
	if(!x->next)	//caso base: sono sull'ultimo nodo, lo stampo e poi basta
	{
		OUT<<x->info<<endl;	//stampo il campo info dell'ultimo nodo e vado a capo
		return;
	}
	else	//c'è almeno un nodo dopo l'attuale, stampo l'attuale, e vado avanti
	{
		OUT<<x->info<<"->";	//stampo l'info del nodo attuale seguito da "->"
		print_list(x->next, OUT);	//passo al prossimo nodo
	}
}	//POST=("output" conterrà i campi "info" di tutti i nodi della lista, dal primo all'ultimo, separati da "->").
