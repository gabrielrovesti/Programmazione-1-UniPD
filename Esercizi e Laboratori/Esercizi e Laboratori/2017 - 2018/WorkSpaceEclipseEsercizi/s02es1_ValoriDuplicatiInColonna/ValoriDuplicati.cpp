#include <iostream>

using namespace std;

/*
 Dato un array int A[6][8], si tratta di confrontare le righe di A con le sue colonne in modo tale da valutare
per ciascuna coppia i in [0..5] e j in [0..7] se vale la seguente condizione (*):
	la riga i ha in comune con la colonna j solo il valore A[i][j], che potrebbe occorrere anche molte volte sulla riga i.
Vediamo un paio di esempi.
Esempio.  Sia A come segue:

						0 0 1 1 2 2 3 3
						0 0 0 1 2 2 1 2
						2 1 1 1 2 2 1 3
						0 3 2 0 0 2 0 3
						0 0 1 1 2 2 3 3
						0 0 2 1 2 2 3 3

se confrontiamo la riga 0 con la colonna  1, vediamo che la riga 0 condivide con la colonna 1,
sia il valore 0 (per forza visto che  A[0][1]=0) che il valore 1 (e anche 3).
Quindi per questa coppia di riga e colonna la condizione (*) è falsa.
Confrontiamo ora la riga 0 con la colonna 5. Hanno in comune solo il valore 2 (A[0][5]=2), visto che la colonna 5 è composta solo da 2.

Il programma da fare deve definire tutti gli elementi dell'array bool B[6][8] in modo che:
per ciascuna coppia i in [0..5] e j in [0..7], B[i][j] = true sse la condizione (*) vale per la riga i  e la colonna j di A.

Correttezza: scrivere l'invariante e la postcondizione di ciascun ciclo del vostro programma.
 */
int main(){
	cout<<"start"<<endl;
	    int A[6][8],numberToCompair;
	    bool B[6][8];
	    for(int i=0; i<6; i=i+1)
	        for(int j=0; j<8; j=j+1)
	            cin >> A[i][j];

	    for(int i=0; i<6; i=i+1){
	    	for(int j=0; j<8; j=j+1){
	    		numberToCompair=A[i][j];
	    		for(int k=0; k<6; k++){
	    			for(int l=0; l<8; l++){
						if((A[i][l]==A[k][j])&&(A[k][j]!=numberToCompair)){
							B[i][j]=false;
							l=7;
							k=5;
						}
						else{
							B[i][j]=true;
						}
	    			}
	    		}
	    	}
	    }

	     for(int i=0; i<6; i=i+1)
	        {
	            for(int j=0; j<8; j=j+1)
	                cout << B[i][j]<<' ';
	        cout<<endl;
	        }

	    cout << "end"<<endl;
}

