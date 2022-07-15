#include <iostream>
#include <fstream>
using namespace std;

bool scorri_h_fetta(const int A[][5][8], const int i, const int j, const int k1, const int k2, bool S[][8])
{
	for(int z1=0; z1<4; z1++)
	{
		for(int z2=0; z2<8; z2++)
		{
			//ho l'elem A[z1][i][z2] della h-fetta i
			//cerco match A[k1][k2][j] con A[z1][i][z2], 
			//senza ridondanze: S[z1][z2]==false
			if(A[k1][k2][j]==A[z1][i][z2] && !S[z1][z2])
			{
				S[z1][z2]=true;
				return true;
			}
			// else:
			// a) A[k1][k2][j]!=A[z1][j][z2], elem diversi
			// b) S[z1][z2]==true, gia` usato
		}
	} //POST: ho scorso l'h-fetta i:
		// a) se match, esci e return true; b) no match, return false
	return false;
}//END

bool scorri_v_fetta(const int A[][5][8], const int i, const int j)
{
	bool presente= true;
	//nuova fetta, nuovo array di supporto S
	bool S[4][8]={};
	
	
	for(int k1=0; k1<4; k1++)
	{
		for(int k2=0; k2<5; k2++)
		{
			//ho l'elem A[k1][k2][j] della v-fetta j
			//deve essere presente nella h-fetta i
			
			presente= scorri_h_fetta(A,i,j,k1,k2,S);
			if(!presente) return false;
			//l'elem A[k1][k2][j] manca nella h-fetta i, allora non ci sono tutti gli el della v-fetta nella h-fetta => B[i][j]=false => return false
		}
	}
	return true;
	// POST: if presente==true =>tutti gli el della v-fetta j sono presenti nella h-fetta i => return true;
	// if presente==false => l'elem A[k1][k2][j] non matcha sulla h-fetta i => return false.
}//END

void stampa(ofstream & out, bool B[][5])
{
	bool*p2= &B[0][0];
	for(int i=0; i<40; i++)
	{
		if(i%5==0)cout<<'\n';
		cout<<p2[i]<<' ';
	}
	cout<<"\nend\n";
}//END

main()
{

ifstream in("input");
ofstream out("output");
if(in&&out)
{
	int A[4][5][8];
	int*p= &A[0][0][0];
	// riempi A
	for(int i=0; i<160; i++)
		in>> p[i];

	
	
	bool B[8][5]={{0}};
	
	// cicla su griglia rig-col di A
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<8; j++)
		{
			
			//confronta v-fetta con h-fetta
			//scorri v-f, scorri h-fetta, cfr.
			
			//scorri v-fetta
			B[j][i]= scorri_v_fetta(A, i, j);
						
		}
	}
	
	stampa(out,B);
	
}
else cout<<"errore files\n";

}//END MAIN
