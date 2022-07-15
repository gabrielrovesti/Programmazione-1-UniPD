//sol by: owl
#include <iostream>
#include <fstream>
using namespace std;

 
//PRE input contiene >=48 interi
main(){

ifstream IN("input");
ofstream OUT("output");

if (IN&&OUT)
{
	int A[6][8];
	bool B[8][6];
	
	int*p=&A[0][0];
	for(int i=0; i<48;i++)
		IN>>p[i];
 	
//input


for(int i=0; i<6 ; i++) //R scorse righe da 0..i-1
{
	for(int j=0; j<8 ; j++) // scorsi elem riga da 0..j-1
	{	
		
		bool condizione=true;
		
		for(int z=0; z<6 && condizione==true; z++) //scorro colonna A[i][j]
		{
			
			int conta=-1;
			
			//R -X = # occorrenze di A[i][j] sulla col per z..h-1; conta=X (X<0)
			for(int h=z+1; h<6; h++)
				if(A[z][j]==A[h][j]) conta--;
			
			//R Y= #occorrenze di A[i][j] sulla riga in 0..k-1; conta=Y+X
			for(int k=0; k<8; k++)
				if(A[z][j]==A[i][k]) conta++;
			
			
			if (conta<0) condizione=false;
			
			// conta>=0 sse X+Y>=0 
		}
		
		if (condizione==true) B[j][i]=true;
		else B[j][i]=false;
		
	}
}

for(int i=0; i<8; i++){
	for(int j=0; j<6; j++){
		if(j==0) cout<<endl;
		cout<<B[i][j]<<' '; 
	}
}
 
cout<<'\n' <<"end"<<'\n';
 

}
else cout<<"errore con i files\n";

}//POST B contiene 0/1 secondo la f iniettiva definita


