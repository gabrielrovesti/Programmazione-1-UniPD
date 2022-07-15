
//soluzione by: Nicolò S.

#include<iostream>
#include<fstream>

using namespace std;
/* PRE: la funzione riceve in input il numero dello strato e riga attuale e le dimensioni
della riga e della colonna e un parametro conta passato per riferimento che conta gli elementi 
dell'array che ho gia' visto e impedisce il segmentation fault*/
void riga(int *X,int s,int r,int lim1,int lim2,int lim3,int n_ele,int &conta,ofstream &OUT)
{	for(int c=0; c<lim3 && conta<n_ele;c++) // c=0 sono all'inizio della riga e quindi poi lo incremento fino al numero di colonne
	{
		OUT<<X[s*lim2*lim3+r*lim3+c]<<" "; // stampo i valori incrementando la c
		conta++; // incremento il conta: se esco dal ciclo prima che c=7 vuol dire che ho fino gli elementi dello strato in questione.
	}
}
/* POST: la funzione restituisce su OUT tutti gli elementi della riga r dell'array 
visto per righe
*/
/* PRE: la funzione riceve in input l'array, le dimensioni dell'array e il numero 
di elementi*/
void strato(int *X,int lim1,int lim2,int lim3,int n_ele,ofstream &OUT)
{	int conta=0; // inizializzo variabile conta che verifichera' se oltrepasso il numero di elementi dell'array
	for(int s=0;s<lim1 && conta<n_ele;s++)
	{
		OUT<<"strato "<<s<<endl; //metto in output la scritta in che strato mi trovo
		for(int r=0;r<lim2 && conta<n_ele;r++)
		{
			OUT<<"r"<<r<<" "; // metto in out il numero della riga
			riga(X,s,r,lim1,lim2,lim3,n_ele,conta,OUT); //chiamo la funzione che mi stampa i valori della riga
			OUT<<endl;	
		}
	}
}
/*POST: la funzione restituisce su OUT l'array stampato per righe con indicato lo strato e
il numero della riga stampato*/

main(){
	ifstream INP("input");
	ofstream OUT("output");
	
	int X[400],n_ele;
	INP>>n_ele;
	
	for(int a=0;a<n_ele;a++)
		INP>>X[a];
	
	int lim1,lim2,lim3;
	INP>>lim1>>lim2>>lim3;
	
	strato(X,lim1,lim2,lim3,n_ele,OUT); // passo i valori alla funzione strato
}

