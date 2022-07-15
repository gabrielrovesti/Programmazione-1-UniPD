#include <iostream>

using namespace std;

// PRE = i <= j
void inverti(int *A, int i, int j);
void stampa(int *, int );
// POST = A viene modificato invertendo l’ordine degli elementi nel sottoarray A[i,...,j]

int main()
{
    int lung, primo, ultimo;
    int A[100];
    cin >> lung >> primo >> ultimo;
    for(int i = 0; i < lung; i++) {
        cin >> A[i];
    }
    cout << "start" << endl;

    inverti(A,primo, ultimo);

    stampa(A,lung);

    cout<<endl;
    cout << "end" << endl;
}

//PRE: A e' array degli elementi da stampare, mentre lunghezza e' la quantita' dei numeri presenti nell'array.
void stampa(int *A,int lunghezza){


	//Caso base 1: lunghezza==0 <==> gli elementi da stampare sono terminati quind stampo il carattere \n .
    if(lunghezza==0)
     cout<<endl;

    //Caso Ricorsivo: lunghezza>0 vuol dire che nell'array A ci sono ancora elementi da stampare
    if(lunghezza >0){
        cout<<" "<< A[0];

//PRE_ric: A[1,2....lunghezza-1] elementi sono ancora da stampare && lunghezza >0
        stampa(A+1,lunghezza-1);
//POST_ric: E' stato stampato il primo elemento dell'array A+1
    }

    /** DIMOSTRAZIONE DI CORRETTEZZA:
     *  Dimostro che valga la PRE_ric supponendo che valga la PRE:
     *
     *  caso base 1: la lunghezza dell'array e' zero, percio' non ci sono elementi da stampare, quindi stampo il carattere per mandare a capo.
     *
     *  caso ricorsivo: se la lunghezza dell'array e' > 0, vuol dire che ci sono ancora degli elementi da stampare e sono A[0, 1, 2...Lunghezza-1]
     *   quindi stampo il primo elemento dell'array che e' A[0], avendone stampato uno, sposto il puntatore verso prossimo elemento (A[1])
     *   da stampare che e' A[1] e quindi decremento di uno la lunghezza dell'array. E se lunghezza e' uguale a zero, il flusso esecutivo si ferma
     *   al primo caso base.
     *
     *   Siccome la PRE
     *
     *
     */
    // https://pastebin.com/bHRGDAY3

}
//POST: stampati tutti i numeri dell'array A

void inverti(int *A, int i, int j){

//PRE: 	A e' una array di numeri interi, 0<=i<=j<= numeri di elementi presenti nell'array (valore della variabile lung della funzione main() ).



	// quando i>=j non c'e' nulla da fare.

	if(i<j){
		int temp;
		temp=A[i];
		A[i]=A[j];
		A[j]=temp;

//		PRE_ric: A e' array dei numeri dei quali bisogna invertire i numeri, 0<=i<=j<= numero Elementi dell'array
		/*
		 * A[i+1...j-1]
		 */

		inverti(A,i+1,j-1);

//		POST_ric: sono stati invertiti la coppia di numeri A[i] e A[j] sse i<j,
	}



//POST: A e' l'array di numeri interi, dove dalla posizione i alla posizione j gli elementi sono stati invertiti mentre altri sono rimasti tali quali..
}
