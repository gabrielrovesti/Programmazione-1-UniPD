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
	
	for(int i=0; i<6; i++) //0<=i<=6
	{
		for(int j=0; j<8; j++) //0<=j<=8
		{
			
			bool ok=true;
			bool T[8]={false};

			//T segna le posizioni gia` matchate della riga
				

			for(int z=0; z<6 && ok==true; z++)//R1
			{
				
				bool trovato=false;
				
				//R2 T[0..k-1] ==true per valori gia` trovati
				// in A[i][0..k-1]
				for(int k=0; k<8 && trovato==false; k++)
				{
										
					if(A[z][j]==A[i][k] && T[k]==false)
						{trovato=true; T[k]=true;}
					//confronto; se matcho, segna in T ed esco
					
				}// k==8 && trovato==false || k<=8 && trovato==true
				
				if (trovato==false) ok=false; 
				
			}//POST1
						
			if(ok==true) {B[j][i]=true; cout<<"1 ";}
			else {B[j][i]=false; cout<<"0 ";}
			
		}// POST scorsa riga j, completata colonna j-esima di B
		
	} //POST scorso tutto l'array, completato B
	
	


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
