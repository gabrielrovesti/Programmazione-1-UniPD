
//soluzione by: Nicolò S.

#include<iostream>
#include<fstream>
using namespace std;

main()
{
	ifstream IN("input");
    ofstream OUT("output");
    
	if(IN && OUT) 
	{ 
			int lim1,lim2,lim3, n_el;
			IN >> lim1>>lim2>>lim3>> n_el;
			int X[lim1][lim2][lim3] ;
			for ( int s=0; s<lim1; s++)
				{	for( int r=0; r<lim2; r++)
						{	for (int c=0; c<lim3; c++)
								{  
									X[s][r][c]= -1;   
								}
						}
				}
				
				
				int conta=0;
			for (int c=0; c<lim3 && conta<n_el; c++)
				{	for (int s=0; s<lim1 && conta<n_el; s++)
						{ 	for( int r=0; r<lim2 && conta<n_el; r++)
								{
									IN>> X[s][r][c];
									conta++;
								}
						}
				}
			
			for ( int s=0; s<lim1; s++)
				{ OUT<< endl<<"strato "<<s<< endl;
					for( int r=0; r<lim2; r++)
						{	for (int c=0; c<lim3; c++)
								{   OUT<<" "<<X[s][r][c];   }
							OUT<<endl;
						}
					
				}
		  OUT<<endl<<"fine";
	} 
	  else
       cout<<"errore con i files";
}
