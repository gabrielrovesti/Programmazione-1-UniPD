#include <iostream>
using namespace std;
int main()

{
/*
Scrivere un programma che legge 20 interi e calcola quanti 1, 2, 3, 4 e 5 ci sono tra i 20 valori.*/

int a[20], i=0; //inizializzazione del vettore e del suo puntatore 

int cont_1=0, cont_2=0, cont_3=0, cont_4=0, cont_5=0; //inizializzazione dei contatori per il conteggio dei valori

//PRE=(i definito a 1, a[] definito con 20 elementi e inizializzati i contatori)
while(i<20)		//R=(1<=i<=20) && (i 5 contatori conteggiano il numero di volte che il numero N appare con i rispettivi valori)
{
cin>>a[i];

if(a[i]==1)
cont_1++;

if(a[i]==2)
cont_2++;

if(a[i]==3)
cont_3++;

if(a[i]==4)
cont_4++;

if(a[i]==5)
cont_5++;

i++;		
} 		

cout<<cont_1<<" "<<cont_2<<" "<<cont_3<<" "<<cont_4<<" "<<cont_5<<" ";
//POST(i>=20) && (i 5 contatori sono stati riempiti con io rispettivi valori e vengono stampati)

/* 
Altra soluzione: 

int a[20], i=0, N=1;

while (i<20){
cin>>a[i];
i++;
}

while(N<6){
i=0;
int count=0;

while(i<20){
	if(a[i]==n)
	count++;
i++;
}

cout<<count<<end1;
N++;
}
*/
}

