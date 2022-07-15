#include <iostream>
using namespace std;
/*
Mettiamoci all’opera dunque con le singole funzioni, partendo da buildBST, il quale opera già su un puntatore a nodo e per questo direi tipo di ritorno un void.
Sappiamo inoltre che per non creare garbage nello heap devo subito deallocare ciò che sto ora creando, questo dalla lista tenere. La scorro iterativemente e ricorsivamente per considerare ambedue le trattazioni del problema.
*/
void buildBST(nodo* BST, nodoE* tenere){
	if(!tenere || !BST ) BST=new nodo*(tenere, 0);
	nodoE*aux=tenere;
	if(tenere->info->info < BST->info){
buildBST(BST->left, tenere);
		BST->info=tenere->info->info;
		delete tenere->info;
		tenere ->next=aux->next;
}
else{
buildBST(BST->right, tenere);
		BST->info=tenere->info->info;
		delete tenere->info;
		tenere ->next=aux->next;
}
		tenere=tenere->next;
	}
}

Ho poi la funzione butta da scrivere che dealloca i nodi di buttare, dove segnala che si devono togliere naturalmente sia gli info quindi i nodo che i nodoE, indicazione poco utile perché si sa già questa cosa.

void butta(nodoE* buttare){
	if(!buttare)	return;
	nodoE* aux=buttare;
	delete buttare;
	buttare->next=aux->next;
}

/*
Nel modo ricorsivo si richiama semplicemente la funzione e si distrugge al ritorno della ricorsione, nessuna sorpresa quindi da questo punto di vista. 

Dal punto di vista delle dimostrazioni induttive, il caso base:
-albero vuoto, quindi mi fermo nel caso di butta, invece nel caso di buildBST costruisco un nodo, anche quando ho BST senza nodi, la prima volta, per poter aggiungere il nodo.
Considerando da PRE che scrivo ora (partendo quindi in butta con una lista buttare nodoE riempita di valori, e nel caso di buildBST il nodo* BST, lista che deve essere costruita e tenere lista riempita di elementi diversi da 0), ci si sposterà nelle liste concatenate fino a quando contengono elementi, quindi matematicamente fino a l->next definito e !=0.
Intuitivamente, per ogni singolo nodo lo metto nella radice perché so dove sono in un determinato momento, altrimenti grazie al puntatore ne salvo la posizione e dealloco il nodo attuale, non lasciando garbage nello heap. A questo punto passo al nodo successivo.
Nel primo caso, si considera la condizione BST, quindi della maggioranza/minoranza di un nodo rispetto all’albero maestro e cerco di capire se posso infilarlo in una determinata posizione, a sinistra se minore e a destra se maggiore di chiave.
Nel secondo caso, semplicemente devo deallocare tutto ciò che trovo, dal punto di vista di nodi info, in quanto i nodoE* mi servono per muovermi, fintanto che si mantiene la condizione iniziale cioè nodoE* 
next!=0. POST sono dimostrate.
*/