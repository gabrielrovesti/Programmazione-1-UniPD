
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

nodo* crea_inv(int dim, ifstream &INP);

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
		inizio=crea_inv(dim, INP);
		
		//se c'è almeno un nodo, stampo la lista, se non c'è non faccio niente
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

nodo* crea_inv(int dim, ifstream &INP)
{	//PRE=(INP (che è lo stream collegato a "input") contiene dim interi, 0<=dim).
	if(dim==0)	//caso base: non ho più nodi da creare
		return 0;	//quindi restituisco 0, da mettere nel campo "next" del nodo precedente, che era l'ultimo
	else	//dim>0, quindi ho almeno un altro nodo da creare
	{	
		nodo* ptr=crea_inv(dim-1, INP);	//ricorsione, passo al prossimo nodo di cui restituirò un puntatore
		
		int inf;	//variabile ausiliaria
		INP>>inf;	//carico dal file "input" il valore da mettere in "info" del nodo corrente
		return new nodo(inf, ptr);	//creo il nodo e ne restituisco un punt da mettere nel campo "next" del precedente nodo
		
	}
}	//POST=(restituisce (un punt al)la lista concatenata con dim nodi che hanno campo info uguale ai dim valori su INP in ordine inverso rispetto a quello di lettura).


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
