
//soluzione by: Leo M.

// Versione 1:
#include <iostream>
#include<climits>
#include<fstream>

using namespace std;

//idea:
//scorro T di uno alla volta [inizioT+1]
//decido la lunghezza della porzione (lung-1 ogni step)
//shifto la porzione da P[0] fino a P[dimP-lung] di uno alla volta
//check se quella porzione P[inizioP..lung-1] matcha con T[inizioT..lung-1]


//ADT - Dichiarazione & Definizione

struct M
{
	//membri - campi dati
	int lung, inizioP, inizioT;
	
	//costruttore
	M(int a=0, int b=0, int c=0)
	{
		lung=a;
		inizioP=b;
		inizioT=c;
	}
	
	/* L'idea è che il campo lung contenga la lunghezza della porzione di P che viene matchata,
		inizioP contenga la posizione in P in cui inizia la porzione matchata 
		e inizioT indichi la posizione in T in cui inizia il match. */
};


//Prototipi di FUNZIONI (Dichiarazioni)

bool check(int *T, int *porz, int lung);

M slide(int* T, int* P, int dimP, int lung);

M windower(int* T, int* P, int dimP, int lung);

M match(int* T, int dimT, int* P, int dimP, int indiceT);

M best(M M1, M M2);



main()
{	//PRE=().
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT) 
	{ 
		int T[200], P[20], dimT, dimP;
		
		INP>>dimT;
		for(int i=0; i<dimT; i++)
			INP>>T[i];
		
		INP>>dimP;
		for(int i=0; i<dimP; i++)
			INP>>P[i];
		
		
		M x=match(T, dimT, P, dimP, 0);// funzione ricorsiva da fare
		
		OUT<<"[lung="<<x.lung<<" inizioP="<<x.inizioP<<" inizioT="<<x.inizioT<<"]"<<endl; // e' l'occasione di ridefinire << per M
    
    
		INP.close();
		OUT.close(); 
	}
	else
		cout<<"errore con i files"<<endl;
}	//POST=().



//Implementazioni delle FUNZIONI (Definizione)

bool check(int *T, int *porz, int lung)
{	//PRE=(a partire da quello puntato da T ci sono almeno "lung" elementi nell'array T).

	if(lung==0)
		return true;
	else
	{
		if(T[0] != porz[0])
			return false;
		else
			check(T+1, porz+1, lung-1);
	}
}	/* POST=(ritorna:
				- true sse a partire dall'elem puntato da T, in T c'è un match contiguo di tutta la porzione di P lunga "lung" e che parte dall'elem puntato da "porz";
				- false altrimenti). */


M slide(int* T, int* P, int dimP, int lung, int indiceP)	//deve scorrere in tutti i modi possibili (0<=inizioP<=dimP-lung) la finestra di lunghezza "lung"
{	//PRE=().
	
	M M1(0, 25, -1);
	
	if(dimP<lung)
		return M1;
	else
	{
		//chiamare check che ritornerà true sse la window corrente a partire dall'elem attualmente puntato da P ha un match perfetto a partire dall'elem attualmente puntato da T
		if(check(T, P, lung))	//se true costruisco un nuovo M1
		{
			M1.lung=lung;
			M1.inizioP=indiceP;
			M1.inizioT=-1;
		}
		
		//chiamare slide con con P+1, che restituirà il miglior M (M2) per P+1 (tengo traccia di dove sono arrivato con indiceP+1)
		M M2=slide(T, P+1, dimP-1, lung, indiceP+1);
		
		return best(M1, M2);
	}
}	//POST=().


M windower(int* T, int* P, int dimP, int lung)	//deve generare tutte le possibili 0<=lung<=dimP di una "window" (porzione) di P
{	//PRE=().

	M M1(0, 25, -1);
	
	if(lung==0)
		return M1;
	else
	{
		//chiamare slide che ritornerà il miglir M (M1) fra tutti i vari sliding possibili per questa finestra di lunghezza "lung"
		M1=slide(T, P, dimP, lung, 0);
	
		//chiamare windower con lung-1 che ritornerà il miglior M (M2) per la prossima window/porzione
		M M2=windower(T, P, dimP, lung-1);
	
		return best(M1, M2);
	}	
}	//POST=().


M match(int* T, int dimT, int* P, int dimP, int indiceT)
{	//PRE=(dimT>0, dimP>0, T[0..dimT-1] è definito, P[0..dimP-1] è definito, 0<=indiceT<=dimT).
	
	M M1(0, 25, -1);	//25 o altro purchè >20 che è dimP
	
	if(dimT<dimP-1)
		return M1;
	else
	{
		//chiamare windower a partire dall'elem attualmente puntato da T che restituiranno il miglior M (M1) per questo T
		M1=windower(T, P, dimP, dimP);
		M1.inizioT=indiceT;		//così non devo passare "indiceT" a windower()
		
		//invocare match con T+1, che restituirà il miglior M (M2) per T+1 (tengo traccia di dove sono arrivato con indiceT+1)
		M M2=match(T+1, dimT-1, P, dimP, indiceT+1);
		
		return best(M1, M2);
	}
	
}	/* POST=(restituisce un valore M che rappresenta il massimo match in T[indiceT..dimT-1] della porzione P[inizioP..lung-1] di P
		(secondo l'ordine descritto prima:
			lunghezza massima;
			a parità di lunghezza, inizioP minimo,
			a parità di lunghezza e inizioP, inizioT massimo);
		qualora non ci siano match, la funzione deve restituire [lung=0, inizioP=-1, inizioT=-1]). */


M best(M M1, M M2)	//lo si potrebbe incapsulare in un overloading di operator>
{	//PRE=(M1 ed M2 sono due valore strutturati di tipo M).
	if(M1.lung > M2.lung)
		return M1;
	else	//M1.lung<=M2.lung
	{
		if(M1.lung < M2.lung)
			return M2;
		else	//M1.lung==M2.lung
		{
			if(M1.inizioP < M2.inizioP)
				return M1;
			else	//M1.inizioP>=M2.inizioP
			{
				if(M1.inizioP > M2.inizioP)
					return M2;
				else	//M1.inizioP==M2.inizioP
				{
					if(M1.inizioT > M2.inizioT)
						return M1;
					else
						return M2;
				}
			}
		}
	}
}	/* POST=(restituisce il massimo tra M1 ed M2 secondo:
			- lunghezza massima;
			- a parità di lunghezza, inizioP minimo;
			- a parità di lunghezza e di inizioP, inizioT massimo). */





/* Versione 2:
#include<iostream>
#include<climits>
#include<fstream>

using namespace std;


//ADT - Dichiarazione, Definizione & Overloading Operator<<

struct M
{
	//membri - campi dati
	int lung, inizioP, inizioT;
	
	//costruttore
	M(int a=0, int b=0, int c=0)
	{
		lung=a;
		inizioP=b;
		inizioT=c;
	}
	
	// L'idea è che il campo lung contenga la lunghezza della porzione di P che viene matchata,
	//	inizioP contenga la posizione in P in cui inizia la porzione matchata 
	//	e inizioT indichi la posizione in T in cui inizia il match.
};

//overloading operator<<
ofstream & operator<<(ofstream &OUT, M trip)
{
	OUT<<"[lung="<<trip.lung;
	OUT<<" inizioP="<<trip.inizioP;
	OUT<<" inizioT="<<trip.inizioT;
	OUT<<"]"<<endl;
}
 
//  poi nel main basta scrivere:
//  OUT<<x; //dove x è la variabile di tipo M ritornata dall'invocazione di match


//Prototipi di FUNZIONI (Dichiarazioni)

bool check(int *T, int *porz, int lung);

M slide(int* T, int* P, int dimP, int lung);

M windower(int* T, int* P, int dimP, int lung);

M match(int* T, int dimT, int* P, int dimP, int indiceT);

M best(M M1, M M2);



main()
{	//PRE=().
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT) 
	{ 
		int T[200], P[20], dimT, dimP;
		
		INP>>dimT;
		for(int i=0; i<dimT; i++)
			INP>>T[i];
		
		INP>>dimP;
		for(int i=0; i<dimP; i++)
			INP>>P[i];
		
		
		M x=match(T, dimT, P, dimP, 0);// funzione ricorsiva da fare
		
		OUT<<x<<endl; // e' l'occasione di ridefinire << per M
    
    
		INP.close();
		OUT.close(); 
	}
	else
		cout<<"errore con i files"<<endl;
}	//POST=().



//Implementazioni delle FUNZIONI (Definizione)

bool check(int *T, int *porz, int lung)
{	//PRE=(a partire da quello puntato da T ci sono almeno "lung" elementi nell'array T).

	if(lung==0)
		return true;
	else
	{
		if(T[0] != porz[0])
			return false;
		else
			check(T+1, porz+1, lung-1);
	}
}	// POST=(ritorna:
	//			- true sse a partire dall'elem puntato da T, in T c'è un match contiguo di tutta la porzione di P lunga "lung" e che parte dall'elem puntato da "porz";
	//			- false altrimenti).


M slide(int* T, int* P, int dimP, int lung, int indiceP)	//deve scorrere in tutti i modi possibili (0<=inizioP<=dimP-lung) la finestra di lunghezza "lung"
{	//PRE=().
	
	M M1(0, 25, -1);
	
	if(dimP<lung)
		return M1;
	else
	{
		//chiamare check che ritornerà true sse la window corrente a partire dall'elem attualmente puntato da P ha un match perfetto a partire dall'elem attualmente puntato da T
		if(check(T, P, lung))	//se true costruisco un nuovo M1
		{
			M1.lung=lung;
			M1.inizioP=indiceP;
			M1.inizioT=-1;
		}
		
		//chiamare slide con con P+1, che restituirà il miglior M (M2) per P+1 (tengo traccia di dove sono arrivato con indiceP+1)
		M M2=slide(T, P+1, dimP-1, lung, indiceP+1);
		
		return best(M1, M2);
	}
}	//POST=().


M windower(int* T, int* P, int dimP, int lung)	//deve generare tutte le possibili 0<=lung<=dimP di una "window" (porzione) di P
{	//PRE=().

	M M1(0, 25, -1);
	
	if(lung==0)
		return M1;
	else
	{
		//chiamare slide che ritornerà il miglir M (M1) fra tutti i vari sliding possibili per questa finestra di lunghezza "lung"
		M1=slide(T, P, dimP, lung, 0);
	
		//chiamare windower con lung-1 che ritornerà il miglior M (M2) per la prossima window/porzione
		M M2=windower(T, P, dimP, lung-1);
	
		return best(M1, M2);
	}	
}	//POST=().


M match(int* T, int dimT, int* P, int dimP, int indiceT)
{	//PRE=(dimT>0, dimP>0, T[0..dimT-1] è definito, P[0..dimP-1] è definito, 0<=indiceT<=dimT).
	
	M M1(0, 25, -1);	//25 o altro purchè >20 che è dimP
	
	if(dimT<dimP-1)
		return M1;
	else
	{
		//chiamare windower a partire dall'elem attualmente puntato da T che restituiranno il miglior M (M1) per questo T
		M1=windower(T, P, dimP, dimP);
		M1.inizioT=indiceT;		//così non devo passare "indiceT" a windower()
		
		//invocare match con T+1, che restituirà il miglior M (M2) per T+1 (tengo traccia di dove sono arrivato con indiceT+1)
		M M2=match(T+1, dimT-1, P, dimP, indiceT+1);
		
		return best(M1, M2);
	}
	
}	// POST=(restituisce un valore M che rappresenta il massimo match in T[indiceT..dimT-1] della porzione P[inizioP..lung-1] di P
	//	(secondo l'ordine descritto prima:
	//		lunghezza massima;
	//		a parità di lunghezza, inizioP minimo,
	//		a parità di lunghezza e inizioP, inizioT massimo);
	//	qualora non ci siano match, la funzione deve restituire [lung=0, inizioP=-1, inizioT=-1]).


M best(M M1, M M2)	//lo si potrebbe incapsulare in un overloading di operator>
{	//PRE=(M1 ed M2 sono due valore strutturati di tipo M).
	if(M1.lung > M2.lung)
		return M1;
	else	//M1.lung<=M2.lung
	{
		if(M1.lung < M2.lung)
			return M2;
		else	//M1.lung==M2.lung
		{
			if(M1.inizioP < M2.inizioP)
				return M1;
			else	//M1.inizioP>=M2.inizioP
			{
				if(M1.inizioP > M2.inizioP)
					return M2;
				else	//M1.inizioP==M2.inizioP
				{
					if(M1.inizioT > M2.inizioT)
						return M1;
					else
						return M2;
				}
			}
		}
	}
}	// POST=(restituisce il massimo tra M1 ed M2 secondo:
	//		- lunghezza massima;
	//		- a parità di lunghezza, inizioP minimo;
	//		- a parità di lunghezza e di inizioP, inizioT massimo).
*/
