
//soluzione by: Antonio M.

#include<iostream>
using namespace std;


main() {
	// PARTE 1

	int A[20];
	int N=0, num;
	bool trovato=false;
	
	while(N<20 && !trovato) {	// R_1=((letti N valori) && ((se trovato=true) || (N=20)) && (i primi n valori sono diversi da 0 e sono in A[0..N-1]) && (0<=N<=20) => (N=n))
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

	int i=0, D=0;
	while (i<N) {		// R=(D=Numero di valori distinti nell'array A[0..i-1]) && (0<=i<=N)
		bool no=true;
		int j=0;

		while (j<i && no) {		// R1=(no <=> A[i] non è contenuta in A[0..j-1])   {*}
			if (A[i]==A[j])
				no = false;
			j++;
		}
		
		if (no)		// R2=(no <=> A[i] non è presente in A[0..i-1])
			D=D+1;

		i++;
	}

	cout<<"D="<<D<<" (Valori Distinti)";


// Delucidazione:
// {*} R1=(no=true <=> ... {Se è vera la 1 allora è vera anche la 2, e viceversa!})



// PRE & POST:
// PRE_1=(cin contiene (almeno) 20 interi) || (cin contiene 0)

/* POST_1=((se cin contiene (almeno) 20 valori senza 0) => (A sarà riempito con i primi 20 valori di cin e N=20)) 
&& ((se cin contiene 0 preceduto da 0<=n<20 valori diversi da 0) => (A contiene i primi n valori di cin e N=n)) */

// Delucidazione: n --> Sottoinsieme di N!


// PRE_2=(A[0..N-1] contiene N valori con N>=0)

// POST_2=(viene calcolato in D il numero di valori distinti in A[0..N-1])

}
