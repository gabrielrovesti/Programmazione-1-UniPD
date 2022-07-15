
//soluzione by: Leo M.

#include<iostream>
#include<fstream>

using namespace std;



main()
{	//PRE=("input" contiene 40 interi, seguiti o dalla coppia "H" 0<=x<=3 o dalla coppia 'V' 0<=y<=4)
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT)
	{
		int A[2][4][5]; //A[k][i][j]
		
		//riempio A da file di input
		for(int k=0; k<2; k++)			//scorro strati
			for(int i=0; i<4; i++)		//scorro righe (di uno strato)
				for(int j=0; j<5; j++)		//scorro elem (di una riga)
					INP>>A[k][i][j];	//scrivo elem
		
		//fetta Horizontal o Vertical, e fetta = numero della fetta desiderata
		char c;
		INP>>c;
		int fetta;
		INP>>fetta;
		
		//stampo la fetta desiderata
		if(c=='H')	//fetta Horizontal, riga fissata
		{
			for(int k=0; k<2; k++)				//scorro strati
			{
				for(int j=0; j<5; j++)			//scorro colonne/elem
					OUT<<A[k][fetta][j]<<" ";	//stampo elem tabulati
				OUT<<endl;
			}
		}
		else //fetta Vertical, col fissata
		{
			for(int k=0; k<2; k++)				//scorro strati
			{
				for(int i=0; i<4; i++)			//scorro righe/elem
					OUT<<A[k][i][fetta]<<" ";	//stampo elem taulati
				OUT<<endl;
			}
		}
		
		INP.close();
		OUT.close();
	}
	else
		cerr<<"Errore File!"<<endl;
}	//POST=("output" deve contenere gli elementi della fetta specificata dalla coppia letta)
