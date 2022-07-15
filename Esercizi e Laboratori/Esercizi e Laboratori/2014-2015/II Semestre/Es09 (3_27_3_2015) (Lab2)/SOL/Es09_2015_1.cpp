
//soluzione by: Leo M.

/* Parte di Teoria:
Es1:
char & C(char &x, char &y)	//tutto alias
{	y=x;	//matchano e A[1] prende A[0] (cioè "a")
	return x;	//tipo giusto e no dangling pointer
}
main()
{	char A[] = {‘a’,’b’,’c’};
	C(A[0],A[1]) = A[2];	//ok usare C(..) a sinistra dato che restituisce una var completa (con L- e R-val), A[0] prende A[2] (cioè "c")
	cout << A[0] << A[1] << A[2] <<endl;	//corretto, stampa: "cac"
}

Es2:
char * C(char *x, char &y)	//x passaggio per valore, y per riferimento
{	x=&y;	//x ora contiene un puntatore ad un alias di una var del chiamante
	return x;	//ok i tipi e no dangling pointer
}
main()
{	char A[] = {‘a’,’b’,’c’};
	*C(A,A[1]) = *(A+2);	//x punterà ad A[0] poi ad A[1], la restituisco, la deref, ottengo A[1] e ci metto *(A+2) ovvero il contenuto di A[2] (cioè "c")
	cout << A[0] << A[1] << A[2] <<endl;	//corretto, stampa: "acc"
}
*/



/* Parte di Programmazione */
// Versione 1:
#include<iostream>
#include<fstream>

using namespace std;

//Prototipi di FUNZIONE (Dichiarazione):
int S(int *X, int i);

main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int X[100];
   IN>>X[0];
   for(int i=1; i<100 && X[i-1]!=-2; i++)
	IN>>X[i];
    
    int a;
    IN>>a;
    int b=S(X,a); //funzione da fare
    if(b==-2)
     OUT<<"sottosequenza "<<a<<" non presente"<<endl;
    else
     OUT<<"inizio sottosequenza "<<a<<" indice="<<b<<endl;

   OUT<<"fine"<<endl;
   
   IN.close();
   OUT.close(); 
  }
  else
   cout<<"errore con i files";
}

//Implementazione FUNZIONI (Definizione):
int S(int *X, int i)
{	//PRE=(X contiene una sequenza che soddisfa le condizioni esposte prima, e 0<=i).

	int conta=0, j;
	if(*X==-2)
	  return -2;
	for(j=0; X[j]!=-2 && conta<i; j++)	//R=(X[0..j-1] sono diversi da -2 && conta e' = al num di -1 trovati in X[0..j-1]).
	  if(X[j]==-1)
	    conta++;
	//R && (X[j]==-2 || conta >=0)
	//se conta=i allora j o e' l'inizio della sottosequenza che stiamo cercando o e' -2
	//se conta<i allora j e' -2
	if(conta==i)
	{
	  if(A[j]==-2)
	    return -2;
	  else
	    return j;
	}
	else
	  return -2;
	  
	
}	//POST=(se X contiene la sottosequenza i, allora S restituisce l'indice di X in cui la sottosequenza i inizia, altrimenti S restituisce -2).





/* Versione 2:
#include<iostream>
#include<fstream>

using namespace std;

//Prototipi di FUNZIONE (Dichiarazione):
int S(int *X, int i);

main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int X[100];
   IN>>X[0];
   for(int i=1; i<100 && X[i-1]!=-2; i++)
	IN>>X[i];
    
    int a;
    IN>>a;
    int b=S(X,a); //funzione da fare
    if(b==-2)
     OUT<<"sottosequenza "<<a<<" non presente"<<endl;
    else
     OUT<<"inizio sottosequenza "<<a<<" indice="<<b<<endl;

   OUT<<"fine"<<endl;
   
   IN.close();
   OUT.close(); 
  }
  else
   cout<<"errore con i files";
}

//Implementazione FUNZIONI (Definizione):
int S(int *X, int i)
{	//PRE=(X contiene una sequenza che soddisfa le condizioni esposte prima, e 0<=i).

	for(int j=0; true; j++)
	{
	  if(X[j]==-2)
	    return (-2);
	  else
	  {
	  if(X[j]==-1)
	  {
	    if(!i)
	    {
	      if(j==0 || X[j-1]==-1)
		return (j);
	      else
		return (j+1);
	    }
	    i--;  
	  }
	  }
	}
	
}	//POST=(se X contiene la sottosequenza i, allora S restituisce l'indice di X in cui la sottosequenza i inizia, altrimenti S restituisce -2).
*/
