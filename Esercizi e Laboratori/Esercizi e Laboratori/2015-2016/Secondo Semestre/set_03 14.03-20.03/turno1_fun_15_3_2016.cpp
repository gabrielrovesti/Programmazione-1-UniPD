/*
Compitino, turno1. Sol. con funzioni - Rando.
Descrizione: Array A a 3 dim pieno, cercare se tutti i valori delle h-fette sono contenuti nelle v-fette, contando e segnando le occorrenze su un array di supporto S. Si segnano i risultati sull'array B.
*/
#include <iostream>
#include <fstream>
using namespace std;

bool scorri_v_fetta(const int A[][8][5], const int i, const int j, const int k1, const int k2, bool S[][8])
{
	for(int z1=0; z1<4; z1++)
	{
		for(int z2=0; z2<8; z2++)
		{
			//ho l'elem A[z1][z2][j] della v-fetta j
			//cerco A[k1][i][k2] in A[z1][z2][j], 
			//senza ridondanze: S[z1][z2]==false
			if(A[k1][i][k2]==A[z1][z2][j] && !S[z1][z2])
			{
				S[z1][z2]=true;
				return true;
			}
			// else:
			// a) A[k1][i][k2]!=A[z1][z2][j], elem diversi
			// b) S[z1][z2]==true, gia` usato
		}
	} //POST: ho scorso la v-fetta j:
		// a) se match, esci e return true; b) no match, return false
	return false;
}//END



bool scorri_h_fetta(int A[][8][5], const int i, const int j)
{
	bool presente= true;
	//nuova fetta, nuovo array di supporto S
	bool S[4][8]={{0}};
	
	
	for(int k1=0; k1<4; k1++)
	{
		for(int k2=0; k2<5; k2++)
		{
			//ho l'elem A[k1][i][k2] della h-fetta i
			//deve essere presente nella v-fetta j
			
			presente= scorri_v_fetta(A,i,j,k1,k2,S);
			if(!presente) return false;
			//l'elem A[k1][i][k2] manca nella v-fetta j, allora non ci sono tutti gli el dell'h-fetta nella v-fetta => B[i][j]=false => return false
		}
	}
	return true;
	// POST: if presente==true =>tutti gli el della h-fetta i sono presenti nella v-fetta j => return true;
	// if presente==false => l'elem A[k1][i][k2] non matcha sulla v-fetta j => return false.
}//END

void stampa(ofstream & out, bool B[][5])
{
	bool*p2= &B[0][0];
	for(int i=0; i<40; i++)
	{
		if(i%5==0)cout<<'\n';
		cout<<p2[i]<<' ';
	}
	cout<<"end\n";
}//END

main()
{

ifstream in("input");
ofstream out("output");
if(in&&out)
{
	int A[4][8][5];
	int*p= &A[0][0][0];
	// riempi A
	for(int i=0; i<160; i++)
		in>> p[i];
	
	bool B[8][5]={};
	
	// cicla su griglia rig-col di A
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<5; j++)
		{
			
			//confronta H-fetta con V-fetta
			//scorri H-f, poi scorri V-f, poi cfr
			
			//scorri h-fetta
			B[i][j]= scorri_h_fetta(A, i, j);
						
		}
	}
	
	stampa(out,B);
	
}
else cout<<"errore files\n";

}//END MAIN
