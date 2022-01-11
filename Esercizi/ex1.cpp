#include<iostream>
using namespace std;

/*Scrivere un programma che legge 20 interi e calcola il numero di questi valori che sono maggiori o uguali a 
0 ed il numero di quelli minori a 0. Infine stampa i 2 valori calcolati.
*/
int main()
{
int a[20], i=0; //dichiarazione dell'array da 20 elementi e del puntatore;

int cont_max=0, cont_min=0; //inizializzazione dei contatori per i valori maggiori/uguali a 0 e minori di 0;

//PRE=definito l'array di 20 elementi, i=cont_max=cont_min=0;

while(i<20){ //condizione di permanenza	
cin>>a[i];	//R=(0<=i<=20) && (letti tutti gli input da tastiera fino a 20-1)

if(a[i]<0)	//conteggio valori minori di 0
cont_min++;

if(a[i]>=0)	//conteggio valori maggiori/uguali a 0
cont_max++;

i++;
	   }		

cout<<cont_max<<" "<<cont_min;

//POST=(i>=20) && (cont_max && cont_min correttamente modificati e stampati)
}
