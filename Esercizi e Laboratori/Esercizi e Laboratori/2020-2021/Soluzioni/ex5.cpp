/*
Si chiede un programma composto da 2 funzioni e dal main. 

1)La funzione int leggi (int*A, int dim) riceve un array A con dim posizioni e deve chiedere che l’utente dia 
un valore intero n, deve controllare che n sia tra 1 e dim. Se non lo è chiede un nuovo valore finché non 
riceve un valore tra 1 e dim, dopo di che legge in A[0..n-1] n valori e restituisce n.
2) La funzione void stampa(int*X, int dim) che stampa dim valori dall’array X seperati da uno spazio. Alla 
fine deve stampare un newline.

3) Il main invoca leggi per leggere n valori in A, poi legge un valore y ed elimina da A tutte le occorrenze di y 
compattando i valori diversi da y verso sinistra. Consideriamo un esempio.
Esempio, se A=[1,0,2,0,0,1,2] e y=2, allora A deve diventare [1,0,0,0,1], quindi il numero di elementi definiti 
in A passa da 7 a 5 essendo stati eliminati due 2.

Per finire il main stampa gli elementi rimasti in A con la funzione stampa*/

#include<iostream>
using namespace std;

int leggi(int*X, int dimX){
int n=0; //inizializzo l'intero n che l'utente deve inserire, l'indice i e l'intero array

cin>>n;	

while(n<1 || n>dimX){	
cin>>n;	
}

int i=0;

while(i<n){
	cin>>X[i];
	i=i+1;
}

return n;

};

void stampa(int*X, int lim){
int i=0;

while(i<lim){
cout<<X[i]<<" ";
i++;
}

cout<<"\n";	//alla fine stampo un newline
};


int main()
{
//PRE=(0<nelemA<=30) &&(A[0..nelemA-1 =  A_orig])

  int A[10];
  int nelemA=leggi(A,10);	//ricevo il numero di elementi da leggi()
	
  int y=0;
  cin >> y;
  
  int comp=0, read=0;
  
  while(read<nelemA){
  
  //R={0<=read<=nelemA)&&(A[0, comp-1]==A_orig[0, read-1] senza valori y)&&(A[0, comp-1]==A_orig[0, read-1]}
  if(A[read]!=y){
  		A[comp]=A[read];
		comp=comp+1;
		read=read+1;
	}
	else{
		read=read+1;
	}
}
  
  stampa(A,comp);
}
//POST=(A[0..comp-1] e A_orig senza y)

//Dimostrazione di correttezza:
//la prima volta che entro nel ciclo, certamente read corrisponderà a 0, A[0, comp-1] sarà uguale ad A_orig[0, read-1] e A[0, comp-1] sarà uguale a A_orig[0, read-1]
//induttivamente, ogni volta che entro nel ciclo, ogni qual volta venga trovato una valore diverso da y vengono effettuati degli scambi, contando i valori da elinimare
//ed i valori letti in totale. In forza dello scambio, induttivamente le due condizioni finali dell'invariante valgono fino al limite comp-1 e read-1
//Alla fine, quando i l'array nei due puntatori rimane uguale fino a nelemA--->Post
