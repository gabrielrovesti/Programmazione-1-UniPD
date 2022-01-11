#include<iostream>

//Consegna: Scrivere un programma che stabilisca se un dato array char C[10] � bilanciato o no.
using namespace std;
int main()
{
	char C[10]; //pre: c[] viene definito con 10 elementi e i=0;
	int i=0, c=0;
	
  	while(i<10)	//R=(0<=i<=10) && (C[0...10-1] riempito con gli input da tastiera)
    {
		cin >> C[i];
		i=i+1;
    }

i=0;

	while(i<10 && c>=0){		//R=(0<=i<=10) && (if c>=0 allora tutto ok in C[0... i-1] con c)
	if(C[i]=='(')
	c++;
	
	if(C[i]==')')
	c--;
	
	i++;
	}
	
	//conto le occorrenze delle parentesi; se sono uguali, � bilanciato, altrimenti non lo �
	
	if(c==0)
	cout<<"bilanciato"<<endl;
	else
	cout<<"non bilanciato"<<endl;
	
	//post: viene stampato c con le occorrenze delle parentesi conteggiate
	
	/*
	Dimostrazione di correttezza:
	-La prima volta R=0=C e ho letto 0 valori tra C[0... i-1]
	-i varia tra 1 e 10; quando i � 10 e k<0 esce dal ciclo
	-con i=10 e C[0... i-1] tutti letti-->Post
	*/	
}
