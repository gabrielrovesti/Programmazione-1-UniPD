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


for(int i=0; i<6 ; i++)
{
	for(int j=0; j<8 ; j++) //sono alla pos dell elemento che sto matchando
	{	
		
		bool condizione=true;
		
		for(int z=0; z<6 && condizione==true; z++) //scorro colonna
		{
			
			int conta=-1;
			
			for(int h=z+1; h<6; h++) // conta segna (-1) # occorrenze su col in 0..h-1
				{if(A[z][j]==A[h][j]) conta--; cout<<conta<<' ';}
			
			 
			
						
			for(int k=0; k<8; k++) // (+1) per ogni match su riga 
				if(A[z][j]==A[i][k]) conta++;
			
			
			if (conta<0) condizione=false;
			
			//se il contatore e` positivo ho un numero di occorrenze sulla riga >= a quelle sulla colonna => la condizione diventa true
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
//END MAIN

