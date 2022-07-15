
//soluzione by: Leo M.

#include <iostream>
#include <fstream>

using namespace std;



//Prototipi di FUNZIONI (Dichiarazioni)

bool check(int *X, int *P, int dimP);

void match(int *X, int dimX, int *P, int dimP, int i, int count_match, ofstream &OUT);



main()
{	//PRE=("input" contiene nell'ordine: 0<n_el<=400, n_el valori, 0<dimP<=20, dimP valori).
	ifstream INP("input");
	ofstream OUT("output");
	if( INP && OUT)
	{
		int X[400], P[20], n_el, dimP;
		INP >> n_el;
		
		for(int i=0; i<n_el; i++)	//inserisco in X i primi n_el valori per righe
			INP >> *(X+i);
		for(int i=n_el; i<400; i++)	//setto a "0" tutte le restanti (400-n_el) celle di X
			*(X+i)=0;
		
		INP >> dimP;
		for(int i=0; i<dimP; i++)	//inserisco in P i primi dimP valori per righe
			INP >> *(P+i);
		for(int i=dimP; i<20; i++)	//setto a "0" tutte le restanti (20-dimP) celle di P
			*(P+i)=0;
			
		int count_match=0, i=0;		//count_match=numero di match trovati fin'ora; i=indice (assoluto) degli elem di X già esaminati
										// quindi in ogni istante in X[0..i-1] ci sono count_match match di P
		match(X, n_el, P, dimP, i, count_match, OUT);
		
		OUT<<"fine"<<endl;
	
		INP.close();
		OUT.close();	
	}
	else
		cerr<<"Errore File!"<<endl;	
}	/* POST=(per ogni match (contiguo ed eventualmente sovrapposto) di P[0..dimP-1] in X[0..n_el-1],
			 OUT contiene una riga "match n.count_match a partire dalla posizione i", dove:
			 "count_match" è il numero di match contigui ed eventualmente sovrapposti degli elementi dell'array P sugli elem dell'array X, e
			 "i" è l'indice dell'elemento di X da cui parte tale match). */



//Implementazioni delle FUNZIONI (Definizione)

bool check(int *X, int *P, int dimP)
{	//PRE=(a partire da quello punt da X e da quello punt da P, ci sono almeno dimP elem nell'array X e dimP elem nell'array P (cioè: dimP>=0, X[0..dimP-1] e P[0..dimP-1] definiti)).

	if(dimP==0)	//più tricky: if(!dimP)
		return true;
	else
	{
		if(X[0] != P[0])
			return false;
		else
			check(X+1, P+1, dimP-1);
	}
}	/* POST=("trovato" è:
			- true sse a partire dall'elem puntato da X, in X c'è un match contiguo di tutto P;
			- false altrimenti). */


void match(int *X, int dimX, int *P, int dimP, int i, int count_match, ofstream &OUT)
{	//PRE=(dimX>=0, dimP>=0, X[0..dimX-1] e P[0..dimP-1] sono definiti, i>=0, count_match>=0).

	if(dimX-i<dimP)	//CASO BASE: se non ho più abbastanza elementi ancora da guardare in X per trovarci dentro un match;
		return;			//in alternativa un controllo onesto poteva essere: (dimX<dimP) però la ricorsione di match doveva essere match(X+1, dimX-1, P, dimP, i+1, count_match, OUT)
	else	//in X mancano almeno altri dimP elementi da guardare -> ci può essere un match
	{
		if(check(X, P, dimP))
		{
			count_match++;
			OUT<<"match n."<<count_match<<" a partire dalla posizione "<<i<<endl;
		}
		match(X+1, dimX, P, dimP, i+1, count_match, OUT);	//RICORSIONE di match
	}
	
}	/* POST=(trova tutti i match (contigui ed eventualmente sovrapposti) di P[0..dimP-1] in X[i..dimX-1] ed esegue le corrispondenti stampe, dove:
			il numero del match parte da "count_match", poi "count_match+1", ecc). */



/*
 idea del programma:
 
 main() chiama match su tutto X (passando anche tutto P);
 
 match -> caso base:
   quando non ho più abbastanza elementi ancora da analizzare in X per trovarci dentro un match (di dimensioni dimP);
 match -> caso ricorsivo:
   match chiama check (che dice se c'è match a partire da quel punto)
     check -> caso base:
       dato che ho come PRE che in X mi rimangono ALMENO dimP elementi da guardare, gestisco solo dimP
       quando non mi restano altri elem da guardare (dimP==0) ritorno true, perchè se sono arrivato qua li ho guardati tutti e tutti han matchato
     check -> caso ricorsivo:
       checka l'elem:
         se NON matchano return false
         se matchano invoca check su X e P meno i primi elem, si assottigliano; quando P e' finito hanno metchato tutti quindi return true
   se true -> c'e' match -> quindi stampo e count_match++ e la posizione
   se false -> nada
   match chiama match su X meno il primo elemento (finche' ce ne sono almeno dimP necessari per matchare, quindi X si assottiglia)
*/
