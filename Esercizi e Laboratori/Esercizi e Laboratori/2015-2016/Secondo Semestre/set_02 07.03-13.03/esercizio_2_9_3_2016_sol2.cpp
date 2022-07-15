#include <iostream>
#include <fstream>
using namespace std;

/*
PRE=("input" contiene un intero nel che soddisfa la condizione 0<nel<=40, seguito 
da nel interi,  seguiti  a loro volta o dalla coppia "H"  x o dalla coppia 'V'  y dove x 
sarà tra 0 e 3 e y tra 0 e 4)
-Soluzione alla File`
*/
main(){

ifstream IN("input");
ofstream OUT("output");

if(IN&&OUT)
{
	int A[2][4][5];
	int nel; IN>>nel;
	int*p= &A[0][0][0];
	
	
	for(int g=0; g<nel; g++)
		IN>>p[g];

	
	char fetta; IN>>fetta;
	int n; IN>>n;
	
	int nsp= nel/(4*5); // #strati pieni
	int eus= nel%(20);	// #elementi ultimo strato
	int nrpu= eus/5;	// #righe piene ultimo strato
	int nru= nrpu;		// #righe (totali) ultimo strato
	int eur= eus%5;		// #elementi ultima riga
	if (eur>0) nru++;
	
	if(fetta=='H')
	{
		//if posiz_primo_elemento_fetta > nel, fetta vuota
		
		if(!nsp && n>=nru) OUT<<"H fetta " <<n <<" vuota\n";
		
		else
		{
			//stampa strati pieni
			if(nsp>0)
			{
				for(int i=0; i<nsp; i++)
				{
					for(int k=0; k<5; k++)
					{
						OUT<<A[i][n][k]<<' ';
					}
					OUT<<endl;
				}
			}
			
			//stampa strato non pieno;
			//casi: a)ultima riga piena; b)ultima riga non piena c)ultima riga vuota
			
			// a)
			if(n<nrpu)
			{
				for(int u=0; u<5; u++)
					OUT<< A[nsp][n][u];
				//nota che nsp coincide anche con l'indice dell'ultimo strato
			}
			
			// b) 
			//nota che nrpu coincide anche con l'indice della prima riga non piena, ultimo str.
			if(n==nrpu)
			{	
				//c)
				if(eur>0)
				{
					for(int i=0; i<eur; i++)
						OUT<<A[nsp][n][i]<<' ';
				}
				// else, eur==0 => nient'altro da stampare
			}
			
		}
	}
	
	if(fetta=='V')
	{
		if(!nsp && !nrpu && eur<=n) OUT<<"V fetta " <<n <<" vuota\n";
		
		else
		{
			if(nsp>0)
			{
				//stampa strati pieni
				// R: i<=0<=nsp && stampati gli strati 0..i-1 della V-fetta n
				for(int i=0; i<nsp; i++)
				{
					// R: j<=0<=5 && stampati elem da 0..j-1 della V-fetta n
					for(int j=0; j<4; j++)
					{
						OUT<<A[i][j][n]<<' ';
					}
					OUT<<endl;
				}
			}
	
			//stampa strato non pieno
			// 2 casi:
			// a) la fetta taglia l'ultima riga non piena; b) fetta piu piccola, 
			if(eur>0)
			{
				// a)
				if(n<eur)
				{
					// R: 0<=i<=nru && stampati 0..i-1 elementi, ultimo strato, V-fetta grande
					for(int i=0; i<nru; i++)
						OUT<<A[nsp][i][n] <<' ';
				}
			}
			else //(eur==0) 
			// b)
			//R: 0<=i<=nrpu && stampati 0..i elem, ultimo strato, V-fetta piccola
			for(int i=0; i<nrpu; i++)
				OUT<<A[nsp][i][n] <<' ';
	
		}
	}

	OUT<<"\nend\n";
}

else cout<<"errore files\n";

}//END
