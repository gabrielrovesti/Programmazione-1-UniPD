#include<iostream>
#include<fstream>
using namespace std;
// PRE: X puntatore dell'array, i indice della sottoseq richiesta
int S(int*X, int i)
{
	//cerco la sottoseq chiesta
	int conta=0; 
	
	//conto le sottoseq, partendo dalla prima
	// R: (0<=k<=100 && conta indica il # di sottoseq di cui X[k] fa parte && conta<=i)
	for(int k=0; X[k]!=-2; k++)
  {

  	//se ho l'indice k richiesto, e X[k]!=-2, ritorno k
    if(conta==i) 
    {
    	return k;
    }
    if (X[k]==-1) //fine sottoseq, aggiorna conta
    {
    	conta++;
    }
  }//POST: se esci, non hai trovato la sottoseq, rip
  
	return -2;
}// POST: if (la sottoseq esiste), return k!=-2 che e` l'indice del suo inizio; else, return -2

main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int X[100];
   IN>>X[0]; //ins il primo elem anche se e` -2
   //poi, ins fino a trovare -2
   for(int i=1; i<100 && X[i-1]!=-2; i++)
   {IN>>X[i];}
    
    int a;
    IN>>a; //indice sottoseq richiesta 
 
    int b=S(X,a); // funzione da fare
    //scorri array fino a trovare inizio della sottoseq richiesta. i e` l'indice richiesto   	
		
  	if(b==-2)
	  	cout<<"sottosequenza "<<a<<" non presente"<<endl;
	  else	  	
	  	cout<<"inizio sottosequenza "<<a<<" indice="<<b<<endl;

		

   cout<<"end"<<endl;
   IN.close(); OUT.close(); 
  }
 else
 cout<<"errore con i files";
 }
