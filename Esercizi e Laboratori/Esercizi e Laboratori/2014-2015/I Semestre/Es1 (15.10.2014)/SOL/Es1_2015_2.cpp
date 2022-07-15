
//soluzione by: Leo M.

// Parte 1
#include<iostream>
using namespace std;

main()
{
    int A[20], i=0, temp;
	bool continua=true;

	while(i<20 && continua)
	{
		cin >> temp;
		if(temp==0)
		{
		    continua=false;
	    	cout << "trovato sentinella\n";
		}
		else
		{
			A[i]=temp;
			i++;
		}
	}
	cout << "N=" << i << endl;
}



/*
PRE=(cin contiene almeno 20 interi) || (cin contiene 0).

R=((continua=true) && (letti 0<=i<=20 valori diversi da 0 e sono in A[0..i-1])) || ((continua=false) && (letti 0<=i<=20 valori diversi da 0 e sono in A[0..i-1])).

POST=(se cin contiene almeno 20 valori senza 0, allora A[0..19] contiene i primi 20 valori di cin e i=20 e continua=true) && (se cin contiene 0 preceduto da 0<=n<20 valori diversi da 0 allora A contiene i primi n valori di
cin e i=n e continua=false).
*/
