
//soluzione by: G. Filè (Prof)

#include <iostream>
using namespace std;

main()
{
	//ESERCIZIO 6 - PARTE (1):
	//Devo scorrere tutte le colonne (sono 5) e contare quante di esse sono = a P!
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
	int contaMatch=0;
	i=0;
	while(i<5)		//R=(0<=i<=5) && (considerate le colonne (0..i-1) e contaMatch è il numero di queste colonne uguali a P)
	{
		int j=0;
		bool mis=false;
		while(j<10 && !mis)	//R1=(mis <=> c'è mis-match tra P[0..j-1] e T[0..j-1][i]) && (0<=j<=10)
		{
			if(T[j][i] != P[j])
				mis=true;
			j++;
		}
		//POST1=('mis' dica la cosa giusta: mis <=> c'è un mis-match tra P e la colonna i di T)
	
		if(!mis)
			contaMatch++;
		
		i++;
	}

	cout<<"Numero match: "<<contaMatch<<endl;

}
