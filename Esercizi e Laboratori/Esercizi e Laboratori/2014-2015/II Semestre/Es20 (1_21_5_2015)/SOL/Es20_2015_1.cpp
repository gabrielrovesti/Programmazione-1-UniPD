
//soluzione by: Leo M.

// Versione 1:
#include <iostream>
#include<fstream>

using namespace std;



struct nodo
{	int info;
	nodo* next;
	
	nodo(int a=0, nodo* b=0)
	{
		info=a;
		next=b;
	}
};


struct explor
{	bool trov;
	nodo *punt;
	
	explor(bool a=false, nodo* b=0)
	{
		trov=a;
		punt=b;
	}
};


nodo* crea(int dim, ifstream &INP)
{
	if(dim)
	{
		int x;
		INP>>x;
		return new nodo(x,crea(dim-1,INP));
	}
	return 0;
}


void stampa(nodo *L, ofstream &OUT)
{
	if(L)
	{
		OUT<<L->info<<' ';
		stampa(L->next,OUT);
	}
	else
		OUT<<endl;
}


void leggi(int dim, int *P, ifstream &INP)
{
	if(dim)
	{
		INP>>*P;
		leggi(dim-1,P+1,INP);
	}
}


explor check(nodo *L, int *P, int dimP)
{	//PRE=(L � una lista corretta, P ha dimP elementi).
	explor L3(false, 0);	//suppongo di non trovarlo
	if(!L)	//sono uscito dalla lista
		return L3;
	else	//sono su un nodo valido della lista L
	{
		if(L->info!=P[0])	//l'elemento in esame non matcha
			return L3;
		else	//l'elemento attuale di P matcha con il campo info del nodo attuale
		{
			if(dimP!=1)	//ho ancora elementi di P da controllare
				return check(L->next, P+1, dimP-1);
			else	//ho finito di matchare tutti gli elem di P su campi info di nodi di L quindi ho trovato il match, devo sistemare le cose come da POST
			{
				explor L3(true, L->next);	//backup del "resto" della lista L, se � 0 vuol dire che il resto � "vuoto"
				L->next=0;	//perch� l'attuale nodo sar� l'ultimo di una "lista separata"
				return L3;	//ritorno il puntatore al prossimo nodo, cos� che il "resto" di L possa essere attaccato alla "prima parte" di L
			}
		}
	}
}	/* POST( - se NON c'� match (contiguo e completo) restituisce L3 (con L3.trov=false e L3.punt=0);
			 - se c'� match (contiguo e completo) allora:
			 	a) segno di averlo trovato, L3.trov=true
			 	b) salvo il campo next dell'ultimo nodo che fa parte del match in L3.punt
			 	c) azzero il campo next dell'ultimo nodo che fa parte del match, cos� sar� una lista "corretta"
			 	d) restituisco L3). */


nodo* match(nodo* &L, int *P, int dimP)
{	//PRE=(L � una lista corretta, P ha dimP elementi, chiamiamo vL=L).
	if(!L)	//caso base: lista L finita
	{
		return 0;
	}
	else	//sono su un nodo valido di L
	{
		//chiamo su questo nodo la funz di match, se c'� match restituir� L3(true,p) con p="punt al prox elem dopo il match", senn� L3(false,0)
		explor L3=check(L, P, dimP);
		
		if(!L3.trov)	//se il match non c'� passo al prossimo nodo di L
		{
			return match(L->next, P, dimP);
		}
		else	//il match c'�, comincia con il nodo in cui sono e il primo nodo dopo la lista � puntato da L3.punt (pu� essere L3.punt=0 se il match arriva fino in fondo a L)
		{
			//sistemo le cose:
			nodo* L2=L;	//creo l'inizio della lista da restituire
			L=L3.punt;	//attacco al nodo precedente a me (il cui campo next � L tramite alias) il resto della lista dopo il match
			return L2;	//restituisco la lista-pattern
		}
	}
}	//POST=(la funzione restituisce col return match(vL,P[0..dimP-1]) e L=resto_mach(vL,P[0..dimP-1])).



main()
{
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT) 
	{ 
		int dim, dimP, P[20];
		INP>>dim;
		
		nodo *L1=crea(dim, INP);	//fatta
		INP>>dimP;
		
		leggi(dimP, P, INP);	//fatta
		
		nodo *L2=match(L1,P, dimP);	//da fare
		
		stampa(L2, OUT);	//fatta
		stampa(L1, OUT);
		
		INP.close();
		OUT.close(); 
  }
  else
   cout<<"errore con i files";
}





/* Versione 2:
#include<iostream>
#include<fstream>

using namespace std;



struct nodo
{	int info;
	nodo* next;
	
	nodo(int a=0, nodo* b=0)
	{
		info=a;
		next=b;
	}
};


nodo* crea(int dim, ifstream &INP)
{
	if(dim)
	{
		int x;
		INP>>x;
		return new nodo(x,crea(dim-1,INP));
	}
	return 0;
}


void stampa(nodo *L, ofstream &OUT)
{
	if(L)
	{
		OUT<<L->info<<' ';
		stampa(L->next,OUT);
	}
	else
		OUT<<endl;
}


void leggi(int dim, int *P, ifstream &INP)
{
	if(dim)
	{
		INP>>*P;
		leggi(dim-1,P+1,INP);
	}
}


bool check(nodo* &L, nodo *L1, int *P, int dimP)
{	//PRE=(L1 � una lista corretta, P ha dimP elementi).
	if(!L1)	//sono uscito dalla lista
		return false;
	else	//sono su un nodo valido della lista L1
	{
		if(L1->info!=P[0])	//l'elemento in esame non matcha
			return false;
		else	//l'elemento attuale di P matcha con il campo info del nodo attuale
		{
			if(dimP!=1)	//ho ancora elementi di P da controllare
				return check(L, L1->next, P+1, dimP-1);	//NB: L deve restare tale, deve propagare l'alias allo stesso nodo per tutte le invocazioni di check
			else	//ho finito di matchare tutti gli elem di P su campi info di nodi di L1 quindi ho trovato il match, devo sistemare le cose come da POST
			{
				L=L1->next;	//L1->next � zero se l'ultimo nodo di L/L1 fa parte del match
				L1->next=0;	//cos� la lista-pattern sar� "corretta"
				return true;
			}
		}
	}
}	// POST( - se NON c'� match (contiguo e completo) restituisce false;
	//		 - se c'� match (contiguo e completo) allora:
	//		 	a) il campo next dell'ultimo nodo di L1 che fa parte del match diventer� il campo next del primo nodo di L che non fa parte del match (tramite side effect)
	//		 	b) azzero il campo next dell'ultimo nodo di L1 che fa parte del match (cos� L2 sar� una lista corretta)
	//		 	c) ritorno true.


nodo* match(nodo* &L, int *P, int dimP)
{	//PRE=(L � una lista corretta, P ha dimP elementi, chiamiamo vL=L).
	if(!L)	//caso base: lista L finita
	{
		return 0;
	}
	else	//sono su un nodo valido di L
	{
		//chiamo su questo nodo la funz di ricerca del match (check), a cui passo per riferimento anche L (che � un alias del campo next de nodo precedente)
		//se c'� match restituir� true e avr� gi� cambiato (con side-effect) la lista L, la lista L2 sar� da restituire
		nodo *L2=L;	//copia locale
		if(!check(L, L, P, dimP))	//se il match non c'� passo al prossimo nodo di L
		{
			return match(L->next, P, dimP);
		}
		else	//il match c'�, comincia con il nodo in cui sono (attualmente puntato da L2)
			return L2;	//restituisco la lista-pattern
	}
}	//POST=(la funzione restituisce col return match(vL,P[0..dimP-1]) e L=resto_mach(vL,P[0..dimP-1])).



main()
{	//PRE=(lista L corretta, possibilmente vuota, array P[0..dimP-1] definito, 0<dimP<=20).
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT) 
	{ 
		int dim, dimP, P[20];
		INP>>dim;
		
		nodo *L1=crea(dim, INP);	//fatta
		INP>>dimP;
		
		leggi(dimP, P, INP);	//fatta
		
		nodo *L2=match(L1,P, dimP);	//da fare
		
		stampa(L2, OUT);	//fatta
		stampa(L1, OUT);
		
		INP.close();
		OUT.close(); 
  }
  else
   cout<<"errore con i files";
}
*/



/* Versione 3:
#include<iostream>
#include<fstream>

using namespace std;



struct nodo
{	int info;
	nodo* next;
	
	nodo(int a=0, nodo* b=0)
	{
		info=a;
		next=b;
	}
};


nodo* crea(int dim, ifstream &INP)
{
	if(dim)
	{
		int x;
		INP>>x;
		return new nodo(x,crea(dim-1,INP));
	}
	return 0;
}


void stampa(nodo *L, ofstream &OUT)
{
	if(L)
	{
		OUT<<L->info<<' ';
		stampa(L->next,OUT);
	}
	else
		OUT<<endl;
}


void leggi(int dim, int *P, ifstream &INP)
{
	if(dim)
	{
		INP>>*P;
		leggi(dim-1,P+1,INP);
	}
}


//PRE=(L1 � una lista corretta, P ha 0<dimP elementi).
bool check(nodo* &L, nodo *L1, int *P, int dimP)
{
  if(!L1)  //sono uscito dalla lista
    return false;
  else  //sono su un nodo valido
  {
    if(L1->info!=P[0])  //l'elemento in esame non matcha
      return false;
    else  //l'elemento attuale di P matcha con il campo info del nodo attuale
    {
      if(dimP!=1)  //ho ancora elementi di P da controllare
        return check(L, L1->next, P+1, dimP-1);
      else  //trovato il match
      {
        L=L1->next;     //L1->next sar� zero se il match comprende l'ultimo nodo della lista
        L1->next=0;     //cos� la lista contenente il match sar� "corretta"
        return true;
      }
    }
  }
}
// POST(- se NON c'� match (contiguo e completo) restituisce false;
//      - se c'� match (contiguo e completo) allora:
//        a) con "side-effect" attacco i due pezzi restanti della lista,
//        b) azzero il campo next dell'ultimo della lista contenente il match (L2) cos� sar� una lista corretta,
//        c) ritorno true.
 
 
//PRE=(L � una lista corretta, P ha dimP elementi, chiamiamo vL=L).
nodo* match(nodo* &L, int *P, int dimP)
{
  if(!L)  //caso base: lista L finita
  {
    return 0;
  }
  else  //sono su un nodo valido di L
  {
    //chiamo su questo nodo la funzione di ricerca del match (check), a cui passo per riferimento anche L
    //(che � un alias del campo next del nodo precedente); se c'� match restituir� true e avr� gi� cambiato
    //(con side-effect) la lista L, la lista L2 sar� da restituire
 
    nodo *L2=L;  //backup, nel caso venga trovato match, ci sar� side-effect su L
    if(!check(L, L, P, dimP))  //se il match non c'� passo al prossimo nodo di L
      return match(L->next, P, dimP);
    else  //il match c'�, comincia con il nodo in cui sono (attualmente puntato da L2)
      return L2;  //restituisco la lista-pattern
  }
}
//POST=(la funzione restituisce col return match(vL,P[0..dimP-1]) e L=resto_mach(vL,P[0..dimP-1])).



main()
{	//PRE=(lista L corretta, possibilmente vuota, array P[0..dimP-1] definito, 0<dimP<=20).
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT) 
	{ 
		int dim, dimP, P[20];
		INP>>dim;
		
		nodo *L1=crea(dim, INP);	//fatta
		INP>>dimP;
		
		leggi(dimP, P, INP);	//fatta
		
		nodo *L2=match(L1,P, dimP);	//da fare
		
		stampa(L2, OUT);	//fatta
		stampa(L1, OUT);
		
		INP.close();
		OUT.close(); 
  }
  else
   cout<<"errore con i files";
}
*/
