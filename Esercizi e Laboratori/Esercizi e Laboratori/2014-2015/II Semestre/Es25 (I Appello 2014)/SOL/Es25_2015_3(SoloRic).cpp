
//soluzione by: Leo M. (SOLO PARTE RICORSIVA)

// Versione 1:
#include <iostream>
#include<fstream>

using namespace std;



struct nodo
{
	int info;
	nodo *left, *right;
	nodo(int a=0, nodo* b=0, nodo* c=0)
	{	info=a;
		left=b;
		right=c;
	}
};



int inizio_cam(int *C, int i)
{	/* PRE=(C contiene n cammini (sequenze possibilmente vuote di 0 e 1),
			- ogni singolo cammino termina con -1 (anche quelli eventualmente vuoti
			- dopo l'ultimo cammino (che termina, come tutti i cammini, con -1) c'è la sentinella -2,
			- n>=0, i>=0). */
	if(*C==-2)
		return -2;
	if(i==0)
		return 0;
	if(*C==-1)
		i--;
	int a=inizio_cam(C+1, i);
	if(a==-2)
		return -2;
	return (a+1);
}	//POST=(se i in [0..n-1] allora inizio_cam restituisce l'indice di C in cui inizia il cammino i, altrimenti, inizio_cam restituisce -2).
/* nota:
	index=inizio_cam(C, i)
	allora:
	- index==-2 se in C non c'è il camino i-esimo
	- C[index]==-1 se il cammino i-esimo è vuoto
	- C[index]==0/1 se il cammino i-esimo c'è e dice di andare a sx/dx
*/


void add_ric(int *C, nodo *&r, ifstream &INP, ofstream &OUT)
{	//PRE=(C[0...] contiene una sequenza w di 0 e 1 (possibilmente vuota) seguita da -1, r è un albero corretto, INP contiene almeno un intero che chiamiamo x, r=vr).
	if(*C==-1)	//ho finito il cammino
	{
		int x;
		INP>>x;	//prelevo il campo info
		if(!r)	//se devo inserire
			r=new nodo(x, 0, 0);	//costruisco il nuovo nodo e lo attacco all'albero per side-effect
		else	//non devo inserire perchè sono su un nodo interno
			OUT<<"cammino troppo corto "<<x<<endl;
		return;
	}
	else	//*C==0/1 (non ho ancora finito il cammino, non devo inserire)
	{
		if(!r)	//se sono uscito dall'albero
		{
			int x;
			INP>>x;	//prelevo il campo info ma non lo devo inserire
			OUT<<"cammino troppo lungo "<<x<<endl;
			return;
		}
		else	//sono ancora dentro l'albero, procedo
		{
			if(*C==0)	//devo andare a sx
				return add_ric(C+1, r->left, INP, OUT);
			if(*C==1)	//devo andare a dx
				return add_ric(C+1, r->right, INP, OUT);
		}
	}
}	/* POST=(se w è troppo corto o troppo lungo rispetto a vr, allora:
			 - v resta uguale a vr
			 - su "output" verrà scritto "cammino troppo corto" o "cammino troppo lungo" seguito da x;
			 altrimenti:
			 - r è un albero corretto che si ottiene da vr aggiungendogli un nuovo nodo y,
			 - y è tale che il cammino dalla radice di r al nuovo nodo sia w e tale che il suo campo info sia x). */


void add_iter(int *C, nodo *&r, ifstream &INP, ofstream &OUT)
{
	//DA FARE PER LA PARTE ITERATIVA	
}


void stampa_l(nodo *r, ofstream &OUT)
{
	if(r)
	{
		OUT<<r->info<<'(';
		stampa_l(r->left,OUT);
		OUT<<',';
		stampa_l(r->right,OUT);
		OUT<<')';
	}
	else
		OUT<<'_';
}


/*
nodo* build_iter(int *C, nodo *r, ifstream &INP, ofstream &OUT)
{
	bool fine=false;
	for(int i=0; !fine; i++)
	{
		int j=inizio_cam(C,i);	//da fare
    
		if(j==-2)
			fine=true;
		else
    		add_iter(C+j, r, INP, OUT);	//da fare
	}
	return r;
}
*/


nodo *build_ric(int *C, nodo *r, ifstream &INP, ofstream &OUT)
{
	bool fine=false;
	for(int i=0; !fine; i++)
	{
		int j=inizio_cam(C,i);	//da fare
		
		if(j==-2)
			fine=true;
		else
    		add_ric(C+j, r, INP, OUT);	//da fare
	}
	return r;
}


nodo *costruz()
{
	nodo* x2=new nodo(2);
	nodo* x3=new nodo(3);
	nodo* x4=new nodo(4);
	nodo* x1=new nodo(1,x2,x3);
	x2->right=x4;
	return x1;
}





main()
{
	try
	{
		ifstream INP("input");
		ofstream OUT("output");
		if(!INP) throw(0);
		if(!OUT) throw(1);
		int C[200], x;
		INP>>C[0];

		for(int i=1; C[i-1]!=-2; i++)
			INP>>C[i];

	nodo* X=costruz();  
	nodo* r = build_ric(C,X,INP,OUT);	//data
	stampa_l(r,OUT);
	OUT<<endl;

	r=build_ric(C,0,INP,OUT);	//data
	stampa_l(r,OUT);
	OUT<<endl;
  
  
  
//simulazione parte iterativa
	X=costruz();
	r=build_ric(C,X,INP,OUT);	//data
	stampa_l(r,OUT);
	OUT<<endl;
	r=build_ric(C,0,INP,OUT);	//data
	stampa_l(r,OUT); 
	OUT<<endl;


/*	//parte iterativa
	X=costruz();
	r=build_iter(C,X,INP,OUT);	//data
	stampa_l(r,OUT);
	OUT<<endl;

	r=build_iter(C,0,INP,OUT);	//data
	stampa_l(r,OUT); 
	OUT<<endl;
*/

	INP.close();
	OUT.close();
	}
	catch(int x)
	{
		switch(x)
		{
			case 0: cout<<"problemi con input"<<endl; break;
			case 1: cout<<"problemi con output"<<endl; break;
		}
	}
}





/* Versione 2:
#include<iostream>
#include<fstream>
using namespace std;
struct nodo{int info; nodo* left, * right; nodo(int a=0, nodo* b=0, nodo* c=0){info=a;left =b;  right=c;}};



int inizio_cam(int *C, int i)
{	// PRE=(C contiene n cammini (sequenze possibilmente vuote di 0 e 1),
	//		- ogni singolo cammino termina con -1 (anche quelli eventualmente vuoti
	//		- dopo l'ultimo cammino (che termina, come tutti i cammini, con -1) c'è la sentinella -2,
	//		- n>=0, i>=0).
			
	if(*C==-2)
		return -2;
	if(i==0)
		return 0;
		
	if(*C==-1)
		i--;
	int a=inizio_cam(C+1, i);
	if(a==-2)
		return -2;
	return (a+1);
	
}	//POST=(se i in [0..n-1] allora inizio_cam restituisce l'indice di C in cui inizia il cammino i, altrimenti, inizio_cam restituisce -2).
// nota:
//	index=inizio_cam(C, i)
//	allora:
//	- index==-2 se in C non c'è il camino i-esimo
//	- C[index]==-1 se il cammino i-esimo è vuoto
//	- C[index]==0/1 se il cammino i-esimo c'è e dice di andare a sx/dx



void add_ric(int *C, nodo *&r, ifstream &INP, ofstream &OUT)
{	//PRE=(C[0...] contiene una sequenza w di 0 e 1 (possibilmente vuota) seguita da -1, r è un albero corretto, INP contiene almeno un intero che chiamiamo x, r=vr).
	if(!r)	//ho finito l'albero
	{
		int x;
		INP>>x;	//prelevo il campo info
		
		if(*C==-1)	//ho finito anche il cammino, allora inserisco
			r=new nodo(x, 0, 0);	//costruisco il nuovo nodo e lo attacco all'albero per side-effect
		else	//non ho finito il cammino, quindi NON devo inserire (troppo lungo)
			OUT<<"cammino troppo lungo "<<x<<endl;
	}
	else	//ho ancora albero
	{
		if(*C==0)	//se devo andare a sx...
			return add_ric(C+1, r->left, INP, OUT);	//...vado a sx
		if(*C==1)	//se devo andare a dx
			return add_ric(C+1, r->right, INP, OUT);	//...vado a dx
			
		//altrimenti ho finito il cammino ma non l'albero (cammino troppo corto)
		int x;
		INP>>x;	//prelevo il campo info
		OUT<<"cammino troppo corto "<<x<<endl;
	}
}	// POST=(se w è troppo corto o troppo lungo rispetto a vr, allora:
	//		 - v resta uguale a vr
	//		 - su "output" verrà scritto "cammino troppo corto" o "cammino troppo lungo" seguito da x;
	//		 altrimenti:
	//		 - r è un albero corretto che si ottiene da vr aggiungendogli un nuovo nodo y,
	//		 - y è tale che il cammino dalla radice di r al nuovo nodo sia w e tale che il suo campo info sia x).


void add_iter(int* C, nodo*& r, ifstream &INP, ofstream &OUT)
{
	//DA FARE PER LA PARTE ITERATIVA	
}


void stampa_l(nodo *r, ofstream & OUT)
{
  if(r)
    {
      OUT<<r->info<<'(';
      stampa_l(r->left,OUT);
      OUT<<',';
      stampa_l(r->right,OUT);
      OUT<<')';
    }
  else
    OUT<< '_';
}



//nodo* build_iter(int*C, nodo*r,ifstream & INP, ofstream & OUT)
//{
//  bool fine=false;
//  for(int i=0; !fine; i++)
//  {
//    int j=inizio_cam(C,i);	//da fare
//    
//    if(j==-2)
//      fine=true;
//    else
//    {
//    add_iter(C+j, r, INP, OUT);	//da fare
//    
//    }
//  }
// return r;
//}


nodo* build_ric(int*C, nodo* r, ifstream &INP, ofstream &OUT)
{
  bool fine=false;
  for(int i=0; !fine; i++)
  {
    int j=inizio_cam(C,i);	//da fare
    if(j==-2)
      fine=true;
    else
    {
    
    add_ric(C+j, r, INP, OUT);	//da fare
    
   }
  }
 return r;
}



nodo* costruz()
{
 nodo* x2=new nodo(2);
 nodo* x3=new nodo(3);
 nodo* x4=new nodo(4);
 nodo* x1=new nodo(1,x2,x3);
 x2->right=x4;
 return x1;
}


main()
{
  try{
  ifstream INP("input");
  ofstream OUT("output");
  if(!INP) throw(0);
  if(!OUT) throw(1);
  int C[200], x;
  INP>>C[0];
 
  for(int i=1; C[i-1]!=-2; i++)
   {INP>>C[i];}
   
  

  nodo* X=costruz();  
  nodo* r = build_ric(C,X,INP,OUT);	//data
  stampa_l(r,OUT);
  OUT<<endl;

  r=build_ric(C,0,INP,OUT);	//data
  stampa_l(r,OUT);
  OUT<<endl;
  
  
  
  //simulazione parte iterativa
  X=costruz();
  r=build_ric(C,X,INP,OUT);	//data
  stampa_l(r,OUT);
  OUT<<endl;

  r=build_ric(C,0,INP,OUT);	//data
  stampa_l(r,OUT); 
  OUT<<endl;


// //parte iterativa
//  X=costruz();
//  r=build_iter(C,X,INP,OUT);	//data
//  stampa_l(r,OUT);
//  OUT<<endl;
//
//  r=build_iter(C,0,INP,OUT);	//data
//  stampa_l(r,OUT); 
//  OUT<<endl;

 }
 catch(int x)
{
   switch(x)
  {
   case 0: cout<<"problemi con input"<<endl; break;
   case 1: cout<<"problemi con output"<<endl; break;
  }
}
}
*/
