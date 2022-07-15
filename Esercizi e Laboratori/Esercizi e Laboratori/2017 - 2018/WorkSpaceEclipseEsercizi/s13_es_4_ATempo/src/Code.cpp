#include<iostream>
#include "code.h"

nodo::nodo(char c, nodo* n)
{
	info = c;
	next = n;
}

coda::coda()
{
	inizio = NULL;
	fine = NULL;
}

//PRE_push=(c è una lettera, Q è una coda, eventualmente vuota)

void push(nodo*n, coda &Q)
{
  n->next=0;
	if (Q.fine)
	{
		Q.fine->next = n;
		Q.fine = Q.fine->next;
	}
	else
	{
		Q.inizio = n;
		Q.fine = Q.inizio;
	}
}

//POST_push=(a Q è stato aggiunto un nodo terminale, di chiave c)

//NB: se inizo==fine, allora fine->next==NULL, e quando faccio inizio=inizio->next, inizio diventa NULL, quindi ottengo la lista vuota
//PRE_pop=(Q è una coda non vuota)

nodo* pop(coda &Q)
{
	nodo *x = Q.inizio;
	Q.inizio = x->next;

	if (Q.inizio == NULL)
		Q.fine = NULL;

	return x;
}

//POST_pop=(a Q è stato rimosso il nodo iniziale, e pop ritorna la chiave del nodo rimosso)

//PRE_e_vuota=(Q è una coda, eventualmente vuota)

bool e_vuota(coda Q)
{
	return Q.inizio == NULL;
}

//POST_e_vuota=(e_vuota ritorna true sse Q è vuota)


//PRE=(lista(L) è ben formata (potenzialmente vuota) e Q è una coda ben formata )
//(una coda Q è detta ben formata se inizio e fine sono entrambi 0 oppure puntano al primo e all’ultimo nodo di una lista ben formata)
void push_list(nodo*L, coda & Q) {
	Q.fine->next=L;
	if(L){
		Q.fine=Q.fine->next;
		// caso ricorsivo: Lista non vuota.
		//PRE_ric: lista(L->next) è ben formata (potenzialmente vuota) e Q è una coda ben formata
		push_list(L->next,Q);
		//POST_ric: restituisce la coda  Q, ben formata, che gestisce la lista iniziale a cui è stata concatenata alla fine lista(L->next).

		/*	Prova di correttezza:
		 *
		 * caso base, lista vuota, ovvero !L, non deve essere effettuato nessuna operazione, poiche' con assegnazione Q.fine->next=L, abbiamo reso
		 * la lista gestita da coda ben formata, ovvero ultimo nodo punta a NULL. Il che e' corretta.
		 *
		 * caso ricorsivo:
		 * 	La lista non e' vuota, percio' devo appendere la lista alla coda,  assegnado il valore di Q.fine next a Q.fine facendo avanzare
		 * 	la lista gestita da coda.
		 *
		 * 	Assumendo che il pre sia vera, e lo e' perche' nella chiamata della funzione, L e' ben formata, e Q e' nullo.
		 *  allora e' giusta anche il pre_ric perche' abbiamo fatto solo avanzare la lista, ponendo il primo elemento della lista alla fine della
		 *  coda, e procendo la chiamata ricorsiva, appendo sempre piu' nodi alla coda, e il valore di Coda.fine viene sempre aggiornata con
		 *  indirizzo nuovo. Quindi per il passo induttivo, e' vera anche il post ric, il che implica la correttezza della POST.
		 *
		 *
		 */
	}
	//caso base: lista vuota. non devo fare nulla
}
//POST=(restituisce la coda  Q, ben formata, che gestisce la lista iniziale a cui è stata concatenata alla fine lista(L))




















