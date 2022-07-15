//============================================================================
// Name        : s7es1_RicercaSeqCrescPiuLunga.cpp
// Author      : Wen Xiaowei
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include<iostream>
using namespace std;

void F(int*,int,int,int&,int&);
int Ricerca(int*, int);
int main()
{
  int dimA, A[100];
  cin>> dimA;
  for(int i=0; i<dimA; i++)
    cin>>A[i];

  int inizio=0, lunghezza=0;

  F(A,dimA,0,inizio,lunghezza);

  cout<<"start"<<endl;

  cout<<"la sottoseq crescente piu' lunga inizia in "<< inizio<<" ed ha lunghezza "<<lunghezza<<endl;

  cout<<"end"<<endl;
}
//PRE=(A ha dimA elementi definiti, 0<=i<=dimA)
void F(int* A, int dimA, int posizione, int& posizioneInizioSeq, int& lunghezza){


	// caso base  se dimensione == 0 allora il vettore ha terminato gli elementi
	if(dimA>0){
		// caso ricorsivo: se la dimensione e' magiore di zero, vuol dire che c'e almeno un elemento nell'array.

		int lungTemp=Ricerca(A,dimA);

		posizione+=lungTemp;
		dimA-=lungTemp;

		if(lungTemp>lunghezza){
			lunghezza=lungTemp;
			posizioneInizioSeq=posizione-lungTemp;
		}

		A=A+lungTemp;

		//PRE_ric:
		/* Pre_ric: [A+lunghezza dell'ultima sequenza trovato] ha dimensione dimA-lunghezza >=0 dell'ultima sequenza trovata e la posizione e'
		 *  compresa tra 0 e dimA-lunghezza dell'ultima sequenza trovata e' posizione
		 */
			F(A,dimA,posizione,posizioneInizioSeq,lunghezza);
		/* Post_ric: Se in A[posizione, posizione+1...DimA-1] c'e' una sequenza crescente in posizione p e lunghezza l
		 * che e' piu' lunga di quello gia trovato,  allora la posizione= p e la lunghezza = l.
		 */

/* DIMOSTRAZIONE DI CORRETTEZZA:
 *
 * caso base: dimA==0 allora non ci sono elementi da contare/verificare e siccome posizioneInizioSeq e lunghezza sono inizializzate/
 * o sono state assegnate dei valori nel chiamante,  che e' corretto.
 *
 * case Ricorsivo: per la prima invocazione la PRE vale poiche' A contiene  dimA elementi, posizione, posizioneInizioSeq e lunghezza hanno valore 0,
 * per la prima chiamata, all'interno dell'IF la posizione dell'inizio dell'ultima sequenza trovata viene messa in posizione, mentre la dimensione
 * di A viene decrementato del numero di elementi confrontato in precedenza, posizioneInizioSeq e lunghezza vengono modificate sse ultima sequenza
 * crescente trovata e' strettamente maggiore della sequenza piu' lunga trovata, e quindi viene aggiornata anche la posizioneInizioSeq.
 *
 * PRE_ric: siccome la dimensione della sequenza piu' lunga possibile e' dimA-1, percio' [A+lunghezza dell'ultima sequenza trovato] <=0, e lo
 *  stesso vale anche per la posizione, che al massimo potra' avanzare di dimA-1 posizione, quindi sara' sempre compreso tra 0 e dimA, quindi
 *  la PRE_ric vale.
 * Post_ric:  Se in A[posizione, posizione+1...DimA-1] c'e' una sequenza crescente in posizione p e lunghezza l che e' piu' lunga di
 * quello gia trovato,  allora la posizione= p e la lunghezza = l vale per passo induttivo poiche' se A diventa vuoto la posizione e
 * la lunghezza non vengono aggiornati perche' non ci sono piu' elementi mentre se ha una sequenza crescente che e' piu' lunga di quello
 * gia trovato.
 *
 * Post: qui potremmo avere tre casi:
 *1. ultima chiamata ricorsiva ha la dimA==0 quindi non modifica nessun valore e termina la propria esecuzione.
 *2. dimA >0 ma A[posizione... dimA-1] non contiene una sequenza piu' lunga di quella gia trovata, quindi non modifica nessun valore.
 *3. dimA> 0 ma A[posizione... dimA-1] contiene una sequenza piu' lunga di quella gia' troata, quindi modifica i valori di posizioneInizioSequenza
 * e la lunghezza.
 *
 *Quindi il post vale alla fine del corpo della funzione F.
 *
 *
 */

	}
//POST=(se in A[i..dimA-1] la sottoseq crescente massima ha lunghezza a che e' > lunghezza allora lunghezza diventa a e
//inizio diventa i, altrimenti non cambiano).
}

//PRE: A ha dimensioneA elementi nell'array
int Ricerca(int* A, int  dimensioneA){

	if(dimensioneA==0)
		return 0;
	if(A[0]<=A[1] ){
		return 1 + Ricerca(A+1,dimensioneA-1);
	}
	else{
		return 1;
	}
}
//POST: restituisce il numero degli elementi che sono in una sequenza.
