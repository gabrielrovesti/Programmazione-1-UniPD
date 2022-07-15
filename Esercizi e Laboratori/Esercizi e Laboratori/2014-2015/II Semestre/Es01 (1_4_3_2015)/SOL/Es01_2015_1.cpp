
//soluzione by: Leo M.

#include<iostream>
#include<fstream>

using namespace std;



main()
{	//PRE=("input" contiene almeno 48 interi).
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT)
	{
		int A[6][8];
		bool B[6][8];
		
		//riempio la matrice A dal file di input
		for(int i=0; i<6; i++)
			for(int j=0; j<8; j++)
				INP>>A[i][j];
		
		/*
		core, riempio B di booleani:
		B[i][j]=true se e solo se tutti gli elementi della riga A[i][] sono presenti anche nella colonna A[][j], altrimenti B[i][j]=false.
		*/
		for(int i=0; i<6; i++)
		{
			for(int j=0; j<8; j++)
			{
				bool contenuta=true;
				for(int n=0; n<8 && contenuta; n++)
				{
					bool manca=true;
					for(int m=0; m<6 && manca; m++)
					{
						if(A[i][n]==A[m][j])
							manca=false;
					}
					if(manca)
						contenuta=false;
				}
				B[i][j]=contenuta;
			}
		}
		
		//stampo la matrice B sul file di output
		for(int i=0; i<6; i++)
		{
			for(int j=0; j<8; j++)
				OUT<<B[i][j]<<" ";
			OUT<<endl;
		}
		
		INP.close();
		OUT.close();
	}
	else
		cerr<<"Errore File!"<<endl;
}	//POST=("output" contiene i 48 valori 0/1 di B (stampati per riga) in base alla parte "core" del programma).
