#include <iostream>
using namespace std;


void ordina(int *, int );
void cercaMinimo(int*, int, int,int,int&);
int main()
{
    int lung;
    int A[100];
    cin >> lung;
    for(int i = 0; i < lung; i++) {
        cin >> A[i];
    }
    cout << "start" << endl;


    ordina(A,lung);
    for(int i=0; i<lung; i++)
    	cout<< A[i]<<" ";
    cout<<endl;
    cout << "end" << endl;
}


void ordina(int *A, int dim){
//PRE= (A è un array di int di lunghezza lung >= 0, sia oldA il valore iniziale di A)

	//caso base: dim==0 sse non ci sono elementi nell'array quindi non c'e nulla da ordinare.
	if(dim>0){
		/*
		 * caso ricorsivo: dim>0 ci sono dim-1 elementi da ordinare nell'array quindi cerco la posizione del numero piu' piccolo nell'array
		 * con la funione cercaMinimo, e supponendo che sia corretta, la funzione causa un side-effect su posMin in modo tale che contenga la
		 * posizione del numero piu' piccolo presente nell'array. Quindi scambio il numero piu' piccolo con il primo numero dell'oldA
		 *
		 */
		int posMin=0;
		cercaMinimo(A,dim,0,A[0],posMin);

		int temp= A[posMin];
		A[posMin]=A[0];
		A[0]=temp;

		/*
		 * PRE_ric: oldA[A+1... dim-1] e' un array di int  non ordinati di lunghezza dim-1..dim-2..dim-dim >=0
		 */
		ordina(A+1,dim-1);
		/*
		 * POST_ric: A[0..1..n] sono gli elementi di oldA ordinati in modo crescente
		 */

		/*
		 * Prova di correttezza:
		 *
		 * caso base: dim==0, A e' vuoto, quindi nessun elemento da ordinare
		 *
		 * caso ricorsivo: ci sono gli elementi da ordinare sse dim >0, supponendo che la PRE sia vera la Pre_ric e' vera poiche' ogni volta che
		 * viene ordinato un  numero, oldA diminuisce di un elemento conseguentemente anche dim viene diminuito. Sfruttando l'induzione,
		 * se PRE_ric e' vera, e' vera anche il POST_ric perche' se oldA[A+1... dim-1] e' la parte non ordinata, allora la A[0..1..n-1] dove n e'
		 * il numero di invocazioni ricorsive effettuate, e' formato dai elementi ordinati in modo crescente.
		 *
		 * Avendo dimostrato la correttezza del POST_ric, la correttezza del POST e' semplice poiche' se effettuaiamo dim-1 invocazioni ricorsive,
		 * allora n==dim-1, quindi abbiamo ordinato tutti i numeri prima, tranne ultimo, ma avendolo sempre confrontato con altri elementi dell'array
		 * ultimo numero e' il maggiore di tutti.
		 *
		 *
		 */
	}

// POST= ( A è una permutazione di oldA ed  è ordinato in modo crescente)
}



void cercaMinimo(int* A, int dim, int posizione,int numeroDaConfrontare ,int& posMin){
	if(dim>0){
		if(A[0]<=numeroDaConfrontare){
			posMin=posizione;
		}
		cercaMinimo(A+1,dim-1,posizione+1,numeroDaConfrontare,posMin);
	}
}
