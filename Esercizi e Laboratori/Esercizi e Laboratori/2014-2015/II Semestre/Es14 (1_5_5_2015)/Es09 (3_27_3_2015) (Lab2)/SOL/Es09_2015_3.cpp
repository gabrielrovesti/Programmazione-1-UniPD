
//soluzione by: Nicolò S.

#include<iostream>
#include<fstream>
using namespace std;

int S(int *X, int a)
{	int conta=0;
	bool esci=false;
	
	for (int i=0; i<100 && !esci; i++)
		{	if(X[i]==-2 && conta <= a)
				return -2;
				
			if(conta == a && X[i] != -2 )
				{	return i;
					esci= true; } 
				 	
			if(X[i]== -1)
				conta++; 
		}	
}

main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
	  { 
	   int X[100];
	   IN>>X[0];
	   for(int i=1; i<100 && X[i-1]!=-2; i++)
	   {IN>>X[i];}
		
		int a;
		IN>>a;

		int b=S(X,a); // funzione da fare
		if(b==-2)
		 OUT<<"sottosequenza "<<a<<" non presente"<<endl;
		else
		 OUT<<"inizio sottosequenza "<<a<<" indice="<<b<<endl;

	   OUT<<"fine"<<endl;
	   IN.close(); OUT.close(); 
	  }
	else
	   cout<<"errore con i files";
}
