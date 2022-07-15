
//soluzione by: G. Filè (Prof)

#include <iostream>
using namespace std;

main()
{
	//ESERCIZIO 6 - PARTE (3):
	//PRE=(letti da cin 0<dimT<=50 interi e 0<dimP<=10 interi)
	
	int T[10][5], P[10];
	int dimT, dimP;
	
	cin>>dimT>>dimP;
	
	int rp=dimT/5, eur=dimT%5;		//rp=Righe Piene +++ eur=Elementi Ultima Riga
									//% -> {Operatore MOD, fornisce il RESTO della divisione del primo valore [dimT] diviso il secondo valore [5]}
	
	
	//PARTE A: Riempi array!
	int i=0;
	while(i<rp)
	{
		int j=0;
		while(j<5)
		{
			cin>>T[i][j];
			j++;
		}
		i++;
	}
	
	i=0;
	while(i<eur)
	{
		cin>>T[rp][i];
		i++;
	}
	
	i=0;
	while(i<dimP)
	{
		cin>>P[i];
		i++;
	}
	
	
	//PARTE B:
	int bestCol=-1, bestMatch=-1;
	i=0;
	while(i<5)		//R=(0<=i<=5) && (considerate le colonne (0..i-1)) => (bestCol è la colonna con il massimo di match tra quelle considerate,
					//e bestMatch è il numero di match della colonna bestCol)
	{
		int lungCol=rp;
		
		if(i<eur)
			lungCol++;
		//POST_IF=(la colonna i ha lungCol elementi definiti)
		
		int j=0, contaMatch=0;
		while(j<lungCol-dimP+1)		//R1=(considerati i punti d'inizio (0..j-1)) => (contaMatch è il numero di match trovati a partire
									//dai punti di inizio considerati)
		{
			int k=0;
			bool ok=true;
			while(k<dimP && ok)		//R2=(ok <=> c'è match tra P[0..k-1] e T[j..j+k-1][i])
			{
				if(T[j+k][i] != P[k])
					ok=false;
				
				k++;
			}
			//POST2=(ok <=> c'è match tra P[0..dimP-1] e T[j..j+dimP-1][i])
			
			if(ok)
				contaMatch++;
			
			j++;	
		}
		//POST1=(contaMatch è il numero di match presenti nella colonna T[0..lunCol-1][i])

		if(contaMatch>bestMatch)
		{
			bestMatch=contaMatch;
			bestCol=i;
		}
		
		i++;
	}
	//POST=(sono state considerate le colonne (0..4) e la migliore è bestCol che ha bestMatch match)

	cout<<"Colonna: "<<bestCol<<" con Numero Match: "<<bestMatch<<endl;

}
