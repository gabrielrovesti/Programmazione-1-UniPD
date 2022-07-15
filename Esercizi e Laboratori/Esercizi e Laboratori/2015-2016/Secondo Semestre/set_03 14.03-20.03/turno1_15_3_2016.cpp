//turno 1, sol. alla File`

#include <iostream>
using namespace std;

main(){

	int A[4][8][5];
	int*p= &A[0][0][0];
	// riempi A
	for(int i=0; i<160; i++)
		cin>> p[i];
	bool B[8][5]={};
	
	// la griglia B[8][5] mostra gli incroci di h-fette e v-fette
	
	for(int i=0; i<8; i++)//R1
	{
		for(int j=0; j<5; j++)//R2
		{
			bool S[4][8]={};//array supporto x segnare occorrenze
			bool ok=true;
			
			// scorri h-fetta i
			for(int k1=0; k1<4 && ok; k1++)//R3
			{
				for(int k2=0; k2<5 && ok; k2++)//R4
				{
					ok=false; //inizio a cercare il match

					// scorri v-fetta j
					for(int z1=0; z1<4 && !ok; z1++)//R5
					{
						for(int z2=0; z2<8 && !ok; z2++)//R6
						{
							if(A[k1][i][k2]==A[z1][z2][j] && !S[z1][z2])
							{	
								S[z1][z2]=true;
								ok=true; //match trovato
							}
						}
					}//end-v
					
				}
			}//end-h
			
			B[i][j]=ok;
		}
	}
	
	//stampa
	for(int u=0; u<8; u++){
		for(int v=0; v<5; v++){
			cout<<B[u][v]<<' ';
		}
		cout<<endl;
	}
	cout<<"end";
	
}//END MAIN

/*
Funzione iniettiva: fun costruita in modo che, per ogni coppia (i,j), che identifica una h-fetta i e una v-fetta j nell'array A, B[i][j]==true sse ogni elemento della h-f i e` contenuto nella v-f j, tenendo conto delle ripetizioni. (la h-fetta rappresenta il dominio della fun, la v-fetta e` il codominio).

R1:	0<=i<=8 && segnate righe di B[0..i-1][] secondo la fun inj
R2: 0<=j<=5 && segnato B[i][0..j-1] secondo la fun inj
R3: 0<=k1<=4 &&  ok==true => esiste una fun ink tra i val della h-fetta e v-fetta per gli strati 0..k1-1 && !ok => non esiste la fun inj
R4: 0<=k2<=5 && ok==true => esiste una fun inj tra h-f e v-f nello strato k1 per l'indice colonna 0..k2-1 && !ok =>no fun inj
R5: R4 ristretto a v-fetta j, per strati 0..z1-1
R6: R5 ristretto a v-fetta j, strato z1, indice riga da 0..z2-1 && ( match <=> S[z1][z2]=true && ok=true)
*/
