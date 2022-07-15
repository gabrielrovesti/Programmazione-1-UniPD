
//soluzione by: Leo M.

// Versione 1:
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
	{info=a;
	next=b;
	}
};


//Prototipi di FUNZIONI (Dichiarazioni)

nodo* crea(int dim, ifstream &INP);

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
		
		//se c'� almeno un nodo, stampo la lista, se non c'� non faccio niente
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
{	//PRE=(INP (che � lo stream collegato a "input") contiene dim interi, 0<=dim).
	if(dim==0)	//caso base: non ho pi� nodi da creare quindi dico che il nodo precedente dovr� avere campo next=0
	{
		nodo *temp;
		temp=0;
		return temp;
	}
	else	//dim>0, quindi ho almeno un altro nodo da creare
	{
		int inf;	//variabile ausiliaria
		INP>>inf;	//carico dal file "input" il valore da mettere in "info" del nodo corrente
		
		nodo *temp1, *temp2;	//puntatori ausiliari
		temp1=crea(dim-1, INP);	//chiedo che puntatore mettere nel campo next del nodo da creare
		temp2=new nodo(inf, temp1);	//creo un il nuovo nodo e mi salvo il puntatore per poi restituirlo
		
		return temp2;
	}
}	//POST=(restituisce (un punt al)la lista concatenata con dim nodi che hanno campo info uguale ai dim valori su INP e sono nello stesso ordine in cui sono letti).


void print_list(nodo *x, ofstream &OUT)
{	//PRE=(x � una lista corretta e non vuota).
	if(!x->next)	//caso base: sono sull'ultimo nodo, lo stampo e poi basta
	{
		OUT<<x->info<<endl;	//stampo il campo info dell'ultimo nodo e vado a capo
		return;
	}
	else	//c'� almeno un nodo dopo l'attuale, stampo l'attuale, e vado avanti
	{
		OUT<<x->info<<"->";	//stampo l'info del nodo attuale seguito da "->"
		print_list(x->next, OUT);	//passo al prossimo nodo
	}
}	//POST=("output" conterr� i campi "info" di tutti i nodi della lista, dal primo all'ultimo, separati da "->").





/* Versione 2:
#include<iostream>
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
	{info=a;
	next=b;
	}
};


//Prototipi di FUNZIONI (Dichiarazioni)

nodo* crea(int dim, ifstream &INP);

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
		
		//se c'� almeno un nodo, stampo la lista, se non c'� non faccio niente
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
{	//PRE=(INP (che � lo stream collegato a "input") contiene dim interi, 0<=dim).
	if(dim==0)	//caso base: non ho pi� nodi da creare
		return 0;
	else	//dim>0, quindi ho almeno un altro nodo da creare
	{
		int inf;	//variabile ausiliaria
		INP>>inf;	//carico dal file "input" il valore da mettere in "info" del nodo corrente
		
		return new nodo(inf, crea(dim-1, INP));	//ricorsione, passo al prossimo nodo di cui restituir� un puntatore
	}
}	//POST=(restituisce (un punt al)la lista concatenata con dim nodi che hanno campo info uguale ai dim valori su INP e sono nello stesso ordine in cui sono letti).


void print_list(nodo *x, ofstream &OUT)
{	//PRE=(x � una lista corretta e non vuota).
	if(!x->next)	//caso base: sono sull'ultimo nodo, lo stampo e poi basta
	{
		OUT<<x->info<<endl;	//stampo il campo info dell'ultimo nodo e vado a capo
		return;
	}
	else	//c'� almeno un nodo dopo l'attuale, stampo l'attuale, e vado avanti
	{
		OUT<<x->info<<"->";	//stampo l'info del nodo attuale seguito da "->"
		print_list(x->next, OUT);	//passo al prossimo nodo
	}
}	//POST=("output" conterr� i campi "info" di tutti i nodi della lista, dal primo all'ultimo, separati da "->").
*/
