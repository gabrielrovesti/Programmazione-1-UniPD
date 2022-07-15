
//soluzione by: G. Filè (Prof)

#include <iostream>
using namespace std;

main()
{
	//ESERCIZIO 6 - PARTE (2):
	//PRE=(T contiene 50 interi e P 10 interi)
	
	int T[10][5], P[10];
	int dimP=10;
	const int righeT=10, colonneT=5;
	
	
	//PARTE A: Riempi array!
	cout<<"T:"<<endl;
	
	int col=0;
	while(col<colonneT)
	{
		int rig=0;
		while(rig<righeT)
		{
			cin>>T[rig][col];
			rig++;
		}
		col++;
	}
	
	cout<<"P:"<<endl;
	
	int i=0;
	while(i<dimP)
	{
		cin>>P[i];
		i++;
	}
	
	
	//PARTE B:
	int bestCol=-1, bestMIS=11;		//Perchè il massimo di MIS che possono verificarsi sono TUTTI MIS, ovvero 10 MIS!
	i=0;
	
	while (i<5 && bestMIS>0)		//R=(0<=i<=5) && (sono state considerate le colonne (0..i-1) e la migliore è bestCol che ha bestMIS mis-match)
									//{Lo stesso R vale anche con la condizione 'bestMIS' aggiunta successivamente?? E la POST di questo R, vale ancora??}
	{
		int j=0, mis=0;
		while (j<10)		//R1=('mis' è il numero di mis-match tra P[0..j-1] e T[0..j-1][i]) && (0<=j<=10)
		{
			if(P[j] != T[j][i])
				mis++;
			j++;
		}
		//POST1=('mis' è il numero di mis-match tra P[0..9] e T[0..9][i])

		if(mis<bestMIS)
		{
			bestMIS=mis;
			bestCol=i;
		}
		
		i++;
	}
	//POST=(sono state considerate le colonne (0..4) e la migliore è bestCol che ha bestMIS mis-match)
	
	cout<<"Minor numero di Mis-Match: "<<endl;
	cout<<"Posizione: "<<bestCol<<" & Numero Mis-Match: "<<bestMIS<<endl;

}
