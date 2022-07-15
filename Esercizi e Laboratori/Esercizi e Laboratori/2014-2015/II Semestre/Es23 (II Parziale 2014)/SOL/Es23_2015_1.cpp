
//soluzione by: Leo M.

// Versione 1:
#include <iostream>
#include<fstream>

using namespace std;



struct nodo
{
	int info;
	nodo* left, *right;
	nodo(int a=0, nodo* b=0, nodo* c=0)
	{	info=a;
		left =b;
		right=c;
	}
};


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


nodo* costruz()
{
 nodo*x2=new nodo(2);
 nodo* x3=new nodo(3);
 nodo* x4=new nodo(4);
 nodo*x1=new nodo(1,x2,x3);
 x2->right=x4;
 return x1;
}


int level(nodo* &r, int dim, int lev, ifstream &INP)
{	//PRE=(albero(r) corretto, dim>=0, lev>=0, r=vr, INP contiene almeno dim interi).
	if(dim==0)	//se non ho più niente da inserire
		return 0;	//mi fermo e dico che ne mancano da inserire 0
	//altrimenti ne ho ancora da inserire (dim>0)
	if(lev==0)	//se sono la livello richiesto
	{
		if(!r)	//posso inserire un nodo? (se sono fuori dall'albero sì, altrimenti il posto è già occupato)
		{
			int x;
			INP>>x;	//recupero il campo informativo del nuovo nodo da INP
			r=new nodo(x, 0, 0);	//costruisco il nuovo nodo (attaccato per side-effect), sarà una foglia	
			return dim-1;	//dato che ne ho inserito uno lo sottraggo dal totale di quelli che devo inserire
		}
		else	//non ho spazio per inserirlo
			return dim;	//non ne ho inseriti, il totale non cambia
	}
	else	//altrimenti non sono al livello richiesto, dovrei "scendere"...
	{
		if(r)	//...per poter scendere devo essere (al momento) su un noto valido
		{
			int a=level(r->left, dim, lev-1, INP);	//scendo a sx, inserisco ciò che posso, "a" saranno quelli che ancora mi restano
			
			a=level(r->right, a, lev-1, INP);	//scendo a dx, inserisco ciò che posso, "a" saranno quelli che ancora mi restano (se a==0 all'invocaz, amen si ferma subito)
			
			return a;	//"a" sono quelli che mancano (possibilmente 0)
		}
		else	//altrimenti sono uscito dall'albero e non ho raggiunto il livello richiesto, pertanto non devo (ne dovrò da qui in giù) inserire nulla
			return dim;
	}
}	/* POST=(albero(r) corretto è ottenuto da albero(vr) aggiungendo ad albero(vr) min(Offre(vr,lev), dim) nodi a livello "lev" da sinistra a destra;
			 la funzione deve restituire col return dim-Offre(vr,lev) qualora questa quantità fosse positiva e altrimenti deve restituire 0;
			 i nodi (eventualmente) aggiunti a vr devono ricevere il loro campo info da letture effettuate su INP). */


nodo* build(nodo* r, int dim, int lev, ifstream &INP)
{	//PRE(albero(r) corretto, dim>=0, lev>=0, INP contiene almeno dim interi, r=vr, dim=vdim).

	if(!dim)
		return r;
	int rimanenti=level(r, dim, lev, INP);
	
	return build(r, rimanenti, lev+1, INP);
}	/* POST=(albero(r) è ottenuto da albero(vr) aggiungendo ad albero(vr) "dim" nuovi nodi,
			   i nuovi nodi hanno campo info letto da INP e sono stati inseriti a partire dal primo livello l tale che Offre(vr,l)>0,
			   poi al livello l+1, l+2 e così via, fino ad esaurire i dim valori che sono su INP;
			 per ogni livello i nodi vanno inseriti da sinistra a destra). */





main()
{
  try{
  ifstream INP("input");
  ofstream OUT("output");
  if(!INP) throw(0);
  if(!OUT) throw(1);
  int dim0, dim1, dim2, x;

  INP>>dim0>>dim1>>dim2;
  nodo*X=costruz();
  
  int z=level(X,dim0,2,INP);	//da fare
  stampa_l(X,OUT);
  OUT<<endl<<z<<endl;
  for(int i=0; i<z; i++)	//serve per eliminare da input i valori non usati da level
   INP>>x;

  X=costruz();
  X=build(X,dim1,0,INP);	//da fare
  stampa_l(X,OUT);
  OUT<<endl;
  
  nodo*R=0;
  R=build(R,dim2,0,INP);	//da fare
  stampa_l(R,OUT);
  OUT<<endl;
  
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



struct nodo
{
	int info;
	nodo* left, *right;
	nodo(int a=0, nodo* b=0, nodo* c=0)
	{	info=a;
		left =b;
		right=c;
	}
};


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


nodo* costruz()
{
	nodo*x2=new nodo(2);
	nodo* x3=new nodo(3);
	nodo* x4=new nodo(4);
	nodo*x1=new nodo(1,x2,x3);
	x2->right=x4;
	return x1;
}


int level(nodo* &r, int dim, int lev, ifstream &INP)
{	//PRE=(albero(r) corretto, dim>=0, lev>=0, r=vr, INP contiene almeno dim interi).
	if(lev==0 && dim!=0 && !r)	//se: sono la livello richiesto, ho ancora elementi e posso inserire un nodo (non devo scendere)
	{
			int x;
			INP>>x;	//recupero il campo informativo del nuovo nodo da INP
			r=new nodo(x, 0, 0);	//costruisco il nuovo nodo (attaccato per side-effect), sarà una foglia	
			dim--;	//dato che ne ho inserito uno lo sottraggo dal totale di quelli che devo inserire
	}
	
	if(r && dim!=0 && lev!=0)	//se: posso scendere, ho ancora elementi e non sono al livello richiesto
	{
		dim=level(r->left, dim, lev-1, INP);	//scendo a sx, inserisco ciò che posso, ricevo quelli che ancora mi restano (possibilmente 0)
		dim=level(r->right, dim, lev-1, INP);	//scendo a dx, inserisco ciò che posso, ricevo quelli che ancora mi restano (possibilmente 0)
	}
	
	return dim;	//ritorno quanti nodi ho ancora a disposizione
}	// POST=(albero(r) corretto è ottenuto da albero(vr) aggiungendo ad albero(vr) min(Offre(vr,lev), dim) nodi a livello "lev" da sinistra a destra;
	//		 la funzione deve restituire col return dim-Offre(vr,lev) qualora questa quantità fosse positiva e altrimenti deve restituire 0;
	//		 i nodi (eventualmente) aggiunti a vr devono ricevere il loro campo info da letture effettuate su INP).


nodo* build(nodo* r, int dim, int lev, ifstream &INP)
{	//PRE(albero(r) corretto, dim>=0, lev>=0, INP contiene almeno dim interi, r=vr, dim=vdim).
	if(!dim)	//se ho finito i nodi disponibili
		return r;	//ritorno la cima dell'albero
	dim=level(r, dim, lev, INP);	//inserisco tutti quelli che posso all'attuale livello
	return build(r, dim, lev+1, INP);	//passo al prossimo livello dove cercherò di inserire quelli ancora disponibili
}	// POST=(albero(r) è ottenuto da albero(vr) aggiungendo ad albero(vr) "dim" nuovi nodi,
	//		   i nuovi nodi hanno campo info letto da INP e sono stati inseriti a partire dal primo livello l tale che Offre(vr,l)>0,
	//		   poi al livello l+1, l+2 e così via, fino ad esaurire i dim valori che sono su INP;
	//		 per ogni livello i nodi vanno inseriti da sinistra a destra).





main()
{
	try
	{
		ifstream INP("input");
		ofstream OUT("output");
		if(!INP) throw(0);
		if(!OUT) throw(1);
		int dim0, dim1, dim2, x;

		INP>>dim0>>dim1>>dim2;
		nodo*X=costruz();
  
		int z=level(X,dim0,2,INP);	//da fare
		stampa_l(X,OUT);
		OUT<<endl<<z<<endl;
		for(int i=0; i<z; i++)	//serve per eliminare da input i valori non usati da level
			INP>>x;

		X=costruz();
		X=build(X,dim1,0,INP);	//da fare
		stampa_l(X,OUT);
		OUT<<endl;
  
		nodo*R=0;
		R=build(R,dim2,0,INP);	//da fare
		stampa_l(R,OUT);
		OUT<<endl;
  
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
*/



/* Versione 3:
#include <iostream>
#include <fstream>
using namespace std;

struct nodo{int info; nodo *left, *right; nodo(int a=0, nodo * b=0, nodo *c=0){info=a; left=b; right=c;} };


//PRE_level=(r è albero corretto, dim >=0, lev>=0, r=vr, INP contiene almeno dim interi)
int level(nodo *&r, int dim, int lev, ifstream &INP)
{
	if(!dim)
		return 0;
	
	if(lev==0)
	{
		if(!r)
		{
			int x;
			INP>>x;
			r=new nodo(x);
			dim=dim-1;
		}
		return dim;
	}
	else
	{
		if(!r->left && lev==1)
		{
			int x;
			INP>>x;
			r->left=new nodo(x);
			dim=dim-1;
		}
		else
			dim=level(r->left, dim, lev-1, INP);
	
		if(!r->right && lev==1 && dim)
		{
			int x;
			INP>>x;
			r->right=new nodo(x);
			dim=dim-1;
		}
		else
			dim=level(r->right, dim, lev-1, INP);
		return dim;
	}
}
//POST_level=(r è ottenuto da vr aggiungendo a vr min(Offre(vr, lev), dim) nodi a livello lev da sinistra a destra, la funzione deve restituire col return
//dim-Offre(vr, lev) qualora questa quantità fosse positiva e altrimenti deve restituire 0; i nodi (eventualmente) aggiunti a vr devono ricevere il loro campo
//info da letture effettuate su "input")


//PRE_build=(r albero corretto, dim>=0, lev>=0, INP contiene almeno dim interi, r=vr, dim=vdim)
nodo *build(nodo *r, int dim, int lev, ifstream &INP)
{
	if(dim==0)
		return r;
	dim=level(r, dim, lev, INP);
	return build(r, dim, lev+1, INP);
}
//POST_build=(r è ottenuto da vr aggiungendo a vr dim nuovi nodi (con campo info letto da INP e tali che questi nodi siano inseriti a partire dal primo livello
//'l' tale che Offre(vr, l) > 0, poi al livello l+1, l+2 e così via, fino ad esaurire i dim valori che sono su INP; per ogni livello i nodi vanno inseriti da
//sinistra a destra)


void stampa_l(nodo * r, ofstream & OUT)
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

nodo* costruz()
{
 nodo*x2=new nodo(2);
 nodo* x3=new nodo(3);
 nodo* x4=new nodo(4);
 nodo*x1=new nodo(1,x2,x3);
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
  int dim0,dim1,dim2,x;

  INP>>dim0>>dim1>>dim2;
  nodo*X=costruz();
  cout<<endl;
  int z=level(X,dim0,2,INP);// da fare
  stampa_l(X,OUT);
  OUT<<endl<<z<<endl;
  for(int i=0; i<z;i++)//serve per eliminare da input i valori non usati da level
   INP>>x;

  X=costruz();
  X=build(X,dim1,0,INP);  //da fare
  stampa_l(X,OUT);
  OUT<<endl;
  nodo*R=0;
  R=build(R,dim2,0,INP);// da fare
  stampa_l(R,OUT);
  OUT<<endl;
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
