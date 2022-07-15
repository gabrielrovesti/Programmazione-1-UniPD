#include<iostream>
using namespace std;

int colonna(int X[],int n, int step); //da fare


//PRE=(cin contiene n_ele, 0<n_ele<=400, seguito da n_ele interi qualsiasi)
int main()
{

  cout<<"start"<<endl;
  int A[10][5][8], *p=A[0][0];
   int nElementi;
   cin>>nElementi;

  for(int i=0; i<nElementi; i=i+1)
    cin>>p[i];

  int bestfetta, bestvalue;
  int somme[8];
  for(int i=0; i<8; i++)
	  somme[i]=colonna(p+i,nElementi-i,8);

  bestfetta=0;
  bestvalue=somme[0];
  for(int i=0; i<8; i++){
	  if(bestvalue<=somme[i]){
		  bestfetta=i;
		  bestvalue=somme[i];
	  }
  }




  cout<<"V-fetta massima= "<<bestfetta<<" con somma= "<<bestvalue<<endl;
  cout<<"end"<<endl;
}
//POST=(stampa l'indice della V-fetta a somma massima seguito dalla sua somma e in caso di parità, stampa l'indice massimo)


//PRE: n>0 &&  A[0..(n-1)*step] è definito
int colonna(int* X,int n, int step){
	// questa funzione restituisce il risultato della somma della colonna
	int sommaColonna=0;
	for(int i=0; i<n; i+=step)
		sommaColonna+=X[i];


	return sommaColonna;
}
