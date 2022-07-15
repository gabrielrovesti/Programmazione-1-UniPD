#include<iostream>
using namespace std;


bool cerca( int [],int [],int ,int , int ,int , int , int &);
int main()
{

  cout<<"start"<<endl;
  int matriceBase[400], nElementi, nElementiDaCercare, elementiDaCercare[20];
    cin>> nElementi;
    for(int i=0; i<nElementi; i++)
      cin >> matriceBase[i];
    int lim1,lim2,lim3;
    cin>> lim1>>lim2>>lim3;
    cin >> nElementiDaCercare;
    for(int i=0; i<nElementiDaCercare; i++)
      cin>>elementiDaCercare[i];

    int stratoTrovato=0;

    if(cerca(matriceBase,elementiDaCercare,nElementi,nElementiDaCercare,lim1,lim2,lim3,stratoTrovato)){
    	cout<<"Lo strato "<< stratoTrovato <<" di T, contiene un match"<<endl;

    }else{
    	cout<<"Nessun match trovato"<<endl;
    }





  cout<<"end"<<endl;
}

//PRE:
/*
 *-in p ci sono elementi dell'array base
 *-in daConfrontare ci sono i elementi da trovare il match
 *-in numeroElmentoDaTrovare c'e' la dimensione di daConfrontare
 *-in numeroStrato == lim1
 *-in numeroRighe == lim2
 *-in numeroColonne == lim3
 *-in stratoTrovato e' una variabile passato per riferimento che conterra' il numero del primo strato che contiene il match
 */
bool cerca(  int p[],int daConfrontare[],int nElementi,int numeroElementiDaTrovare, int numeroStrato,int numeroRighe, int numeroColonne, int & stratoTrovato){

	bool trovato[numeroElementiDaTrovare];
	for(int i=0; i<numeroElementiDaTrovare; i++)
		trovato[i]=false;
	int numeroElementiPerStrato=numeroRighe*numeroColonne;


	bool isMatch=false;
	for(int i=0,elementoConfrontato=0; i<numeroStrato &&  elementoConfrontato <nElementi && !isMatch; i++){
		/* R1:
		 *  0<=i<=numeroStrato
		 *  && 0<=elementoConfrontato<=nElementi
		 *  && !isMatch
		 *  && ricercato nei primi i strati della matrice e non e' stato trovato nessuno match finora
		 *
		 */

		/*PRE:
		 * j=0 &&
		 * k=0 &&
		 * elementoConfrontato<=nElementi
		 */
		for(int j=0,k=0; j<numeroElementiPerStrato && k<numeroElementiDaTrovare &&  elementoConfrontato <nElementi ;  elementoConfrontato++,j++){
			/*
			 * 0<=j<=numeroElementoPerStrato
			 * && 0<=k<=numeroElementiDaTrovare
			 * && elementoConfrontato <=nElementi
			 * && confrontati j elementi dello strato i
			 * && trovato una sequenza di k elementi che coincide con i primi k elementi della sequenza da trovare il match
			 *
			 */

			if(p[elementoConfrontato]==daConfrontare[k]){
				trovato[k]=true;
				k++;
			}else{
				trovato[k]=false;
				k=0;
			}
		}
		/*
		 * POST:
		 * j>=numeroElementiPerStrato ==> non e' stato trovato un match nello strato corrente ||
		 * k>=numeroLEmentiDaTrovare ==> e stato trovato un match ||
		 * elementoConfrontato >=nElementi ==> il numero degli elementi definiti e' esaurito
		 */

		/*				PROVA DI CORRETTEZZA:
		 * 1: 	All'inizio, j=0, k=0 ed elementoConfrontato <=nElementi, al primo ciclo, viene esaminato il primo elemento dello strato corrente,
		 * 		se e' uguale al primo elemento della sequenza k viene incrementato di 1, per permettere di confrontare il secondo elemento della
		 * 		sequenza, quindi viene incrementato il contatore degli elementi dello strato (j) e il contatore di tutti gli elementi confrontati.
		 * 2:	Al secondo ciclo, j < numeroElementiPerStrato, e k<numeroElementiDaTrovare e  elementoConfrontato <nElementi, se il secondo elemento
		 * 		dello strato e' uguale al secondo elemento della sequenza viene incrementato il contatore k di uno, altrimenti k viene messo a 0 per
		 * 		ricominciare con il ciclo successivo a fare il confronto fra il primo elemento della sequenza e j-esimo elemento dello strato, fino a
		 * 		j=numeroElementiPerStrato-1 il che vuol dire che abbiamo esaurito gli elementi dello strato senza trovare il match,
		 * 		oppure k== numeroElementiDaTrovare-1 cioe' abbiamo trovato un match
		 * 		oppure elementoConfrontato=nElementi-1 cioe' abbiamo esaurito gli elementi della matrice.
		 * 3:   dopo il secondo passaggio, se troviamo abbiamo tre possibilita'
		 * 		-Primo: esaurito gli elementi dello strato ovvero la condizione j<numeroElementiPerStrato viene falsificato,
		 * 			quindi intera guardia diventa falsa, percio' ciclo termina
		 * 		-Secondo: abbiamo trovato un match, e k diventa >= numeroElementiDaTrovare, ==> guardia falsificata, ciclo terminata.
		 * 		-Terzo: elementoConfrontato =nElementi perche' abbiamo esaurito gli elementi della matrice ==> guardia falsificata, ciclo termina.
		 *
		 */


		for(int l=0; l<numeroElementiDaTrovare; l++)
			//R: 0<=l<=numeroElementiDaTrovare && tutti gli l elementi controllati sono true ==> isMatch==true altrimenti isMatch=false
			if(trovato[l]){
			    isMatch=true;
			}else{
				isMatch=false;
				break;
			}

        stratoTrovato=i;
	}
	return isMatch;

}
/*POST:
 * return true <==> e' stato trovato un match altrimenti false'
 * stratoTrovato contiene il valore del primo strato che contiene il match.
 */
