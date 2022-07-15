// sol by Dado
#include <iostream>
#include <fstream>
using namespace std;

main(){
//PRE leggo 48 interi da IN

ifstream IN("input");
ofstream OUT("output");

if(IN && OUT)
{

	int A[6][8];
	bool B[6][8];
	
	//lettura
	for(int i=0; i<6; i++){
		for(int j=0; j<8; j++){
			IN>>A[i][j];
		}
	}
	
	/* scorri col
	2 condizioni:
		ok :tutta la riga presente nella colonna= riga di trovati
		trovato :elem riga nella colonna
	*/
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<8; j++)
		{
			bool ok=true;
			
			for(int y=0; y<8 && ok==true; y++) //R scorsa col A[i][0..y-1]
			{
				bool trovato=false;
				
				//R scorsa riga A[0..x-1][j] e cercati match
				for(int x=0; x<6 && trovato==false; x++)
				{
					if(A[x][j]==A[i][y]) trovato=true;
					//altrimenti continuo il ciclo
				}
				//POST if trovato==true, match; else no match
				
				if (trovato==false) ok=false;
				
			}
			//ok==true sse tutti gli el della linea sono nella colonna
			if (ok==true) B[i][j]=true;
			else B[i][j]=false;
			
		}
	}
	
	//STAMPA
	int a=0;
	
	bool*p=&B[0][0];
	for(int c=0; c<48;c++)
	{
		if(c%8==0) cout<<'\n';
		cout<<p[c]<<' ';
	}


			//POST: cond=false => B[i][j]=>false, mismatch
			// cond=true => B[i][j]=true, match
}
else cout<<"errore con i files";

IN.close();
OUT.close();

}
