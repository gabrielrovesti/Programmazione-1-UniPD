
//soluzione by: Leo M.

// Versione 1:
#include <iostream>
#include<fstream>

using namespace std;


struct nodo
{
	int info;
	nodo* left, *right;

	nodo(int a=0, nodo* b=0, nodo*c=0)
	{
		info=a;
		left=b;
		right=c;
	}
};


void stampa_l(nodo *r)
{
	if(r)
	{
		cout<<r->info<<'(';
		stampa_l(r->left);
		cout<<',';
		stampa_l(r->right);
		cout<<')';
    }
	else
		cout<<'_';
}


int conta_n(nodo *r)
{
	if(!r)
		return 0;
	else
		return conta_n(r->left)+conta_n(r->right)+1;
}


nodo *insert(nodo *r, int y)
{
	if(!r)
		return new nodo(y);
	if(conta_n(r->left)<=conta_n(r->right))
		r->left=insert(r->left,y);
	else
		r->right=insert(r->right,y); 
	return r;
}


nodo *rep_ins(nodo *r, int dim, ifstream &INP)
{
	if(dim)
	{
		int z;
		INP>>z;
		nodo *x=insert(r,z);
		return rep_ins(x,dim-1,INP);
	}
	return r;
}


void sc(int*C, ofstream &OUT)
{
	if(*C!=-1)
	{
		OUT<<*C<<' ';
		sc(C+1,OUT);
	}
	else
		OUT<<"fine cammino"<<endl;
}


bool cerca_cam(nodo *r, int k, int y, int *C)
{	//PRE=(albero(r) è corretto e non vuoto, k>=0 e y valore qualsiasi, C ha almeno tanti elementi quanta è l'altezza di albero(r)).
	if(r->info==y)	//dato che almeno un nodo esiste, controllo se ha info==y
		k=k-1;	
	if(!r->left && !r->right)	//caso base: sono su una foglia
	{
		if(k==0)	//è il cammino cercato
		{
			*C=-1;	//concludo il cammino
			return true;
		}
		else	//il cammino percorso ha o troppi (k<0) o troppi pochi (k>0) nodi con info==y, quindi non è quello cercato
			return false;
	}
	else	//caso ric: sono su un nodo interno, quindi non ho ancora completato il cammino in esame, procedo
	{
		bool trov=false;
		if(r->left)	//se posso andare a sx
		{
			*C=0;	//me lo segno
			trov=cerca_cam(r->left, k, y, C+1);	//vado a sx
		}
		if(trov)
			return true;	//se ne ho trovato uno buono mi fermo
		else	//altrimenti
		{
			if(r->right)	//se posso andare a dx
			{
				*C=1;	//me lo segno
				trov=cerca_cam(r->right, k, y, C+1);	//vado a dx
			}
			return trov;
		}
	}
}	/* POST=(restituisce:
				- true sse in albero(r) esiste un cammino dalla radice ad una foglia di cui esattamente k nodi hanno campo info=y,
				  allora: C contiene una sequenza (anche vuota) di 0/1 che termina con -1 e che individua il cammino più a sinistra in albero(r) con esattamente k y;
				- false altrimenti). */



main()
{
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT) 
	{ 
		int dim, k, y;
		INP>>dim;
		nodo *R=rep_ins(0,dim,INP);	//data
      
		INP>>k>>y;
		int C[30];
		bool b=cerca_cam(R,k,y,C);	//da fare
		
		if(b)
		{
			OUT<<"true con cammino=";
			sc(C,OUT);	//data
			OUT<<endl;
		}
		else
			OUT<<"nessun cammino con "<<k<<" valori="<<y<<endl;

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
{
	int info;
	nodo* left, *right;

	nodo(int a=0, nodo* b=0, nodo*c=0)
	{
		info=a;
		left=b;
		right=c;
	}
};


void stampa_l(nodo *r)
{
	if(r)
	{
		cout<<r->info<<'(';
		stampa_l(r->left);
		cout<<',';
		stampa_l(r->right);
		cout<<')';
    }
	else
		cout<<'_';
}


int conta_n(nodo *r)
{
	if(!r)
		return 0;
	else
		return conta_n(r->left)+conta_n(r->right)+1;
}


nodo *insert(nodo *r, int y)
{
	if(!r)
		return new nodo(y);
	if(conta_n(r->left)<=conta_n(r->right))
		r->left=insert(r->left,y);
	else
		r->right=insert(r->right,y); 
	return r;
}


nodo *rep_ins(nodo *r, int dim, ifstream &INP)
{
	if(dim)
	{
		int z;
		INP>>z;
		nodo *x=insert(r,z);
		return rep_ins(x,dim-1,INP);
	}
	return r;
}


void sc(int*C, ofstream &OUT)
{
	if(*C!=-1)
	{
		OUT<<*C<<' ';
		sc(C+1,OUT);
	}
	else
		OUT<<"fine cammino"<<endl;
}


bool cerca_cam(nodo *r, int k, int y, int *C)
{	//PRE=(albero(r) è corretto e non vuoto, k>=0 e y valore qualsiasi, C ha almeno tanti elementi quanta è l'altezza di albero(r)).
	if(r->info==y)	//dato che almeno un nodo esiste, controllo se ha info==y
		k=k-1;
	if(k<0)	//se ho trovato "troppi" campi info==y nel mio cammino
		return false;
	if(!r->left && !r->right)	//caso base: sono su una foglia
	{
		if(k==0)	//è il cammino cercato
		{
			*C=-1;	//concludo il cammino
			return true;
		}
		else	//il cammino percorso ha troppi pochi nodi con info==y, quindi non è quello cercato
			return false;
	}
	else	//caso ric: sono su un nodo interno, quindi non ho ancora completato il cammino in esame, procedo
	{
		bool trov=false;
		if(r->left)	//se posso andare a sx
			trov=cerca_cam(r->left, k, y, C+1);	//vado a sx
		if(trov)
		{
			*C=0;	//se andare a sx ha portato esiti positivi, me lo segno (costruirò C solo quando avrò trovato il cammino richiesto)
			return true;	//se ne ho trovato uno buono mi fermo
		}
		else	//altrimenti
		{
			if(r->right)	//se posso andare a dx
				trov=cerca_cam(r->right, k, y, C+1);	//vado a dx
			if(trov)
				*C=1;	//se andare a dx ha portato esiti positivi, me lo segno (costruirò C solo quando avrò trovato il cammino richiesto)
			return trov;
		}
	}
}	// POST=(restituisce:
	//			- true sse in albero(r) esiste un cammino dalla radice ad una foglia di cui esattamente k nodi hanno campo info=y,
	//			  allora: C contiene una sequenza (anche vuota) di 0/1 che termina con -1 e che individua il cammino più a sinistra in albero(r) con esattamente k y;
	//			- false altrimenti (nulla è detto per quanto riguarda gli elementi di C)).



main()
{
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT) 
	{ 
		int dim, k, y;
		INP>>dim;
		nodo *R=rep_ins(0,dim,INP);	//data
      
		INP>>k>>y;
		int C[30];
		bool b=cerca_cam(R,k,y,C);	//da fare
		
		if(b)
		{
			OUT<<"true con cammino=";
			sc(C,OUT);	//data
			OUT<<endl;
		}
		else
			OUT<<"nessun cammino con "<<k<<" valori="<<y<<endl;

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
{
	int info;
	nodo* left, *right;

	nodo(int a=0, nodo* b=0, nodo*c=0)
	{
		info=a;
		left=b;
		right=c;
	}
};


void stampa_l(nodo *r)
{
	if(r)
	{
		cout<<r->info<<'(';
		stampa_l(r->left);
		cout<<',';
		stampa_l(r->right);
		cout<<')';
    }
	else
		cout<<'_';
}


int conta_n(nodo *r)
{
	if(!r)
		return 0;
	else
		return conta_n(r->left)+conta_n(r->right)+1;
}


nodo *insert(nodo *r, int y)
{
	if(!r)
		return new nodo(y);
	if(conta_n(r->left)<=conta_n(r->right))
		r->left=insert(r->left,y);
	else
		r->right=insert(r->right,y); 
	return r;
}


nodo *rep_ins(nodo *r, int dim, ifstream &INP)
{
	if(dim)
	{
		int z;
		INP>>z;
		nodo *x=insert(r,z);
		return rep_ins(x,dim-1,INP);
	}
	return r;
}


void sc(int*C, ofstream &OUT)
{
	if(*C!=-1)
	{
		OUT<<*C<<' ';
		sc(C+1,OUT);
	}
	else
		OUT<<"fine cammino"<<endl;
}


bool cerca_cam(nodo *r, int k, int y, int *C)
{	//PRE=(albero(r) è corretto e non vuoto, k>=0 e y valore qualsiasi, C ha almeno tanti elementi quanta è l'altezza di albero(r)).
	if(r->info==y)	//dato che almeno un nodo esiste, controllo se ha info==y
		k=k-1;
	bool trov=false;
	if(k<0)	//se ho trovato "troppi" campi info==y nel mio cammino
		return trov;
	if(!r->left && !r->right)	//caso base: sono su una foglia
	{
		if(k==0)	//è il cammino cercato
		{
			*C=-1;	//concludo il cammino
			return true;
		}
	}
	else	//caso ric: sono su un nodo interno, quindi non ho ancora completato il cammino in esame, procedo
	{
		if(r->left)	//se posso andare a sx
			trov=cerca_cam(r->left, k, y, C+1);	//vado a sx
		if(trov)
			*C=0;	//se andare a sx ha portato esiti positivi, me lo segno (costruirò C solo quando avrò trovato il cammino richiesto)
		if(!trov && r->right)	//se non l'ho trovato e se posso andare a dx
		{
			trov=cerca_cam(r->right, k, y, C+1);	//vado a dx
			if(trov)
				*C=1;	//se andare a dx ha portato esiti positivi, me lo segno (costruirò C solo quando avrò trovato il cammino richiesto)
		}
	}
	return trov;
}	// POST=(restituisce:
	//			- true sse in albero(r) esiste un cammino dalla radice ad una foglia di cui esattamente k nodi hanno campo info=y,
	//			  allora: C contiene una sequenza (anche vuota) di 0/1 che termina con -1 e che individua il cammino più a sinistra in albero(r) con esattamente k y;
	//			- false altrimenti (nulla è detto per quanto riguarda gli elementi di C)).



main()
{
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT) 
	{ 
		int dim, k, y;
		INP>>dim;
		nodo *R=rep_ins(0,dim,INP);	//data
      
		INP>>k>>y;
		int C[30];
		bool b=cerca_cam(R,k,y,C);	//da fare
		
		if(b)
		{
			OUT<<"true con cammino=";
			sc(C,OUT);	//data
			OUT<<endl;
		}
		else
			OUT<<"nessun cammino con "<<k<<" valori="<<y<<endl;

		INP.close();
		OUT.close(); 
	}
	else
		cout<<"errore con i files";
}
*/
