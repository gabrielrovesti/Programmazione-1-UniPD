#include<iostream>
#include<fstream>
using namespace std;
// PRE: X puntatore dell'array, i indice della sottoseq richiesta
int S(int*X, int i)
{
	//cerco la sseq di indice i
	
	int conta=0; // indice sseq corrente. 
	//OSS do per scontato di partire dalla prima
	//caso speciale: nessuna sseq. Unico caso in cui conta=-1
	if(X[0]==-2)
	{
		conta--; // nessuna sseq; nella pratica non serve, lo scriviamo per correttezza
		return X[0];
	}
	//else, ho almeno una sseq
	//conto le sseq
	// R: (0<=k && conta<=i && conta indica il # di sottoseq di cui X[k] fa parte)
	for(int k=0; ; k++)
  {
  	//se ho l'indice k richiesto, e X[k]!=-2, ritorno k
    if(conta==i) 
    	return k;
    if (X[k]==-1 && X[k+1]!=-2) //fine sottoseq, se poi ho altre sseq, aggiorna conta
    	conta++;
    if(X[k]==-2) 
    	return X[k];
    
  }//POST1: if (k==i), la sseq esiste, return indice k;
  				//else, k<i, la sseq non esiste, return sentinella -2
  
}// POST2: == POST1

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
