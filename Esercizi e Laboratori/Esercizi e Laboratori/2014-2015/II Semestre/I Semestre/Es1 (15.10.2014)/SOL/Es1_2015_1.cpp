
//soluzione by: Antonio M.

#include<iostream>
#include <climits>
using namespace std;


main() {
	// PARTE 1

	int A[20];
	int N=0, num;
	bool trovato=false;
	
	while(N<20 && !trovato) {
		cin>>num;
		
		if (num==0) {
			trovato=true;
		}
		else {
			A[N]=num;
			N=N+1;
		}
	}

	if (N==0)
		cout<<"N="<<N<<", quindi in A non e' stato inserito alcun numero!";
	else {
		cout<<"N="<<N<<" e A[0.."<<N-1<<"] = ";

		int i=0;
		while (i < N) {
			cout<<A[i]<<" ";
			i = i + 1;
		}
	}


	// PARTE 2
	cout<<endl<<endl;

	int primo=INT_MAX, secondo=INT_MAX, terzo=INT_MAX;

	if (N<3)
		cout<<"Problema mal posto: N="<<N;
	else {
		int j=0;
		while (j<N) {
			if (A[j]<primo) {
				terzo = secondo;
				secondo = primo;
				primo = A[j];
			} else {
				if (A[j]<secondo) {
					terzo = secondo;
					secondo = A[j];
				} else {
					if (A[j]<terzo)
						terzo = A[j];
				}
			}
			j = j + 1;
		}
		
		cout<<"Il terzo valore e': "<<terzo;
	}
}

// CORRETTEZZA:
// PRE_1=(cin contiene (almeno) 20 interi) || (cin contiene 0)

// R_1=((letti N valori) && ((se trovato=true) || (N=20)) && (i primi n valori sono diversi da 0 e sono in A[0..N-1]) && (0<=N<=20) => (N=n))

/* POST_1=((se cin contiene (almeno) 20 valori senza 0) => (A sarà riempito con i primi 20 valori di cin e N=20)) 
&& ((se cin contiene 0 preceduto da 0<=n<20 valori diversi da 0) => (A contiene i primi n valori di cin e N=n)) */

// Delucidazione: n --> Sottoinsieme di N!


// PRE_2=(N>=0, A[0..N-1] contiene interi)

/* R_2=(letti N valori) && (primo = min dei valori letti, secondo = il secondo min dei valori letti, 
terzo = il terzo min dei valori letti) && (0<=j<=N) */

// POST_2=(se N<3 => stampa "Problema mal posto!") && (se N>=3 => stampa il terzo tra i valori in A[0..N-1])
