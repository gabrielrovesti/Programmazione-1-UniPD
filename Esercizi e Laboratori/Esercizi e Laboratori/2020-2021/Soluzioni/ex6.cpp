/*

Si chiede un programma che usa le funzioni leggi e stampa dell’esercizio 1. Il main, dopo aver letto n valori 
(n tra 1 e 30) nell’array A con la funzione leggi, deve fare la seguente operazione:

Per prima cosa si deve assumere (Precondizione) che in A ci siano solo 2 valori che chiameremo x e y, dove 
x è A[0] e y è l’altro valore in A. Potrebbe essere che in A tutti i valori siano uguali, quindi che ci sia solo x e 
niente y. Il main deve modificare A in modo che all’inizio ci siano tutti gli x e dopo ci siano tutti i valori y. 

Questo risultato deve essere raggiunto con operazioni di scambio tra elementi di A. Non si deve definire un 
array di supporto, ma tutto deve avvenire in A. Non è accettato di ordinare A.

Dopo aver modificato A come richiesto, il main lo stampa con l’apposita funzione dell’Esercizio 1.

Correttezza: scrivere la post-condizione e l’invariante del ciclo del main.

*/

#include<iostream>
using namespace std;

int leggi(int*X, int dimX){
int n=0; //inizializzo l'intero n che l'utente deve inserire, l'indice i e l'intero array

cin>>n;	

while(n<1 || n>dimX){	
cin>>n;	
}

int i=0;

while(i<n){
	cin>>X[i];
	i=i+1;
}

return n;

};

void stampa(int*X, int lim){
int i=0;

while(i<lim){
cout<<X[i]<<" ";
i++;
}

cout<<"\n";	//alla fine stampo un newline
};

main()
{
  int A[10];
  int nelemA=leggi(A,10);
  
  //PRE=(0<nelemA<=30) e (assumiamo che A[0..nelemA-1] contiene solo 2 valori distinti,  il valore iniziale di A  lo chiamiamo A_orig)
    
    int primo=1, secondo=nelemA-1, x=A[0];
    
	while(primo<secondo)		//R1=(primo<=secondo && sec_iniziale<=nelemA-1 (valore iniziale di secondo))
	{
		if(A[primo]!=x)
		{
			while(A[secondo]!=x && secondo>primo)	//R2=(se primo<secondo allora A[secondo]=x, A[sec_iniziale..secondo]!=x )&&(se primo<secondo allora A[0...primo-1]=x, A[secondo..sec_iniziale]!=x)	
				secondo=secondo-1;
				
				if(secondo>primo)
				{
					int z=A[primo];
					A[primo]=A[secondo];
					A[secondo]=z;
					primo=primo+1;
					secondo=secondo-1;
				}
				else
				secondo=secondo-1;
		}
		else 
		primo=primo+1;
	}
  cout<<"primo="<<primo<<" secondo="<<secondo<<endl;
  stampa(A,nelemA);			//POST=A[primo...secondo-1]!=A[sec_iniziale...secondo] con primo<secondo
		
}
  
  

