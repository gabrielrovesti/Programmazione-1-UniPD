#include <iostream>

using namespace std;

//PRE: T ha dimT elementi definiti e P ne ha dimP elementi definiti
int match(int *T, int dimT, int* P, int dimP){

	if(!dimT || !dimP) //caso base:
		return 0;

	if(T[0]==P[0])// caso ricorsivo

		//PRE_ric:
		return 1+match(T+1,dimT-1,P+1,dimP-1);
		//POST_ric:
	return 0; //fallimento del match, quindi un altro caso base.

/*	PROVA DI CORRETTEZZA
 *
 *  caso base: se T e' vuoto o P e' vuoto match di lunghezza 0 e soddisfa la post.
 *
 *  caso base 2: T[0] e' diverso da P[0], quindi non c'e' match, e restituisco 0
 *
 *  Passo induttivo:
 *
 */


}
// POST: restituisce la lunghezza della match massimo che inizia in T[0]


//
void F(int *T, int dimT, int *P, int dimP, int & inizio, int & lunghezza){
	inizio=-1;
	lunghezza=0;

	for(int i=0; i<dimT; i++){ // i<dimT && lunghezza< dimP
		/* R:
		 * 	0<=i<=dimT
		 *&& esaminato T[0...i-1]
		 *&& inizio e lunghezza caratterizzano il miglior match che inizia in T[0...i-1]
		 *
		 *
		 *
		 *		Prova di correttezza:
		 *	1. non e' stata fatto nessun match, quindi i=0, lunghezza  e inizio hanno i valori di inizializzazione.
		 *
		 *	2.
		 *
		 */

		int lunghezzaTemp= match(T+i, dimT-i, P,dimP);

		if(lunghezzaTemp>lunghezza){
			lunghezza=lunghezzaTemp;
			inizio= i;
		}

	}

}//

int main(){
	  int T[100],P[20];
	  int dimT,dimP;
	  cin>>dimT>>dimP;
	  for(int i=0; i<dimT;i++)
	    cin>>T[i];
	  for(int i=0; i<dimP;i++)
	    cin>>P[i];
	  int inizio,lung;
	  F(T,dimT,P,dimP,inizio,lung);
	  cout<<"start"<<endl;
	  if(inizio==-1)
	    cout<<"nessun match"<<endl;
	  else
	    cout<<"il match piu' lungo inizia in "<<inizio<<" ed e' lungo "<<lung<<endl;
	  cout<<"end"<<endl;


}


