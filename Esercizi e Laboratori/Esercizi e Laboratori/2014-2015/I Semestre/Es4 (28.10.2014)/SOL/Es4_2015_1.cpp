
//soluzione by: Leo M.

// Versione 1:
#include<iostream>
using namespace std;

main()	//PRE0
{
	int T[100], P[10], dimT, dimP, nMatch=0;
	cin >> dimT >> dimP;
	
	int t=0;
	while(t<dimT)	//R1 - riempio T[0..dimT-1]
	{
		cin >> T[t];
		t++;
	}
	
	int p=0;
	while(p<dimP)	//R2 - riempio P[0..dimP-1]
	{
		cin >> P[p];
		p++;
	}
	
/*### PARTE I, restituisce il numero di match (anche sovrapposti) ###*/
	
	t=0;	//reset indice t per scorrere T
	bool stopP;
	while(t<dimT && !(dimT-t<dimP))		//R3
	{	//"!(dimT-t<dimP)" sostituisce "stopT" e serve quando non restano abbastanza celle in T ancora da verificare per contenere P (non è <= ma solo < perchè è DOPO t++
		stopP=false;	//stopP serve per bloccare non appena un elemento è diverso
		p=0;	//reset indice p per scorrere P
		while(p<dimP && !stopP)		//R4
		{
			if(T[t+p]!=P[p])
				stopP=true;
			p++;
		}
		if(stopP==false)
			nMatch++;
		t++;
	}
	
	cout<<nMatch<<" match (anche sovrapposti)."<<endl;
	
/*### PARTE II, restituisce il numero di match contigui (NON sovrapposti) ###*/
	
	t=0;	//reset indice t per scorrere T
	nMatch=0;	//reset contatore nMatch del numero di match trovati
	while(t<dimT && !(dimT-t<dimP))		//R5
	{
		stopP=false;	//stopP serve per bloccare non appena un elemento è diverso
		p=0;	//reset indice p per scorrere P
		while(p<dimP && !stopP)		//R4
		{
			if(T[t+p]!=P[p])
				stopP=true;
			p++;
		}
		if(stopP==false)
			{
				nMatch++;
				t=t+p-1;	//se ho trovato un match sposto in avanti il puntatore t fino all'ultima cella di quel match, poi con il t++ è pronto per andare avanti
			}
		t++;
	}
	
	cout<<nMatch<<" match (NON sovrapposti)."<<endl;
	
}	//POST0



/*
PRE0=(cin contiene 0<dimT<=100 e 0<dimP<=10, seguite da dimT interi e poi ancora dimP interi).

R1=().

R2=().

R3=().

R4=().

R5=().

R0=().

POST0=((il programma stampa su cout il numero di match di P in T) && (il programma stampa su cout il numero di match NON sovrapposti di P in T)).
*/



/* Versione 2:
#include <iostream>
using namespace std;

main()	//PRE
{
	int T[100], P[10], dimT, dimP, nMatch=0;
	cin >> dimT >> dimP;
	
	int t=0;
	while(t<dimT)	//riempio T[0..dimT-1]
	{
		cin >> T[t];
		t++;
	}
	
	int p=0;
	while(p<dimP)	//riempio P[0..dimP-1]
	{
		cin >> P[p];
		p++;
	}
	

// - PARTE I, restituisce il numero di match (anche sovrapposti)
// - PARTE II, restituisce il numero di match (NON sovrapposti), per abilitarla rimuovere "//" ad inizio riga 43

	
	t=0;	//reset indice t per scorrere T
	bool stopP;
	while(t<dimT && !(dimT-t<dimP))
	{	//"!(dimT-t<dimP)" serve quando non restano abbastanza celle in T ancora da verificare per poter contenere P e regola anche il caso in cui dimT<dimP
		stopP=false;	//stopP serve per bloccare non appena un elemento è diverso
		p=0;	//reset indice p per scorrere P
		while(p<dimP && !stopP)
		{
			if(T[t+p]!=P[p])
				stopP=true;
			p++;
		}
		if(stopP==false)
			{
				nMatch++;
//				t=t+p-1;	//se ho trovato un match sposto in avanti il puntatore t fino all'ultima cella di quel match, poi con il t++ è pronto per andare avanti
			}
		t++;
	}
	
	cout<<nMatch<<" match."<<endl;
}	//POST


//PRE=(cin contiene 0<dimT<=100 e 0<dimP<=10, seguite da dimT interi e poi ancora dimP interi).

//POST=((il programma stampa su cout il numero di match di P in T) && (il programma stampa su cout il numero di match NON sovrapposti di P in T)).
*/
