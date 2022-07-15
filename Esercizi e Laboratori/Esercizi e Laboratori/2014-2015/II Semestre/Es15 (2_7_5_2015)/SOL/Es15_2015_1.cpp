
//soluzione by: Leo M.

// Versione 1:
#include <iostream>
#include<fstream>

using namespace std;


//Prototipi di FUNZIONI (Dichiarazioni)

void stamparic(int *X, int dimX, ofstream &OUT);

int compatta(int* X, int dimX, int z, int n_z, int n_e);



main()
{	//PRE=("input" contiene 0<dimT<=48 seguito da dimT valori interi, un valore intero z).
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT) 
	{ 
		int T[3][4][4], dimT, z;
		INP>>dimT;
		int* x=**T;
		for(int i=0; i<dimT; i++)
			INP>>x[i];
		
		stamparic(x,dimT,OUT);	//stampa ricorsiva per righe da fare
	
		OUT<<endl;
		INP>>z;
		
		int ne=compatta(x,dimT,z,0,0);	//da fare
		stamparic(x,ne,OUT);	//stampa quello che resta
		
		OUT<<endl<<"fine"<<endl;
		
		INP.close();
		OUT.close(); 
	}
	else
		cout<<"errore con i files"<<endl;
}	/* POST=("output" contiene:
		- la stampa per righe dell'array iniziale
		- la stampa dell'array "purgato" di tutte le occorrenze di z e ricompattato
		- la stringa "fine"). */



//Implementazioni delle FUNZIONI (Definizione)

void stamparic(int *X, int dimX, ofstream &OUT)
{	//PRE=(X contiene dimX elementi).
	if(dimX==0)
		return;
	else
	{
		OUT<<X[0]<<" ";
		return stamparic(X+1, dimX-1, OUT);
	}
}	// POST=("output" conterrà dimX elementi stampati per righe).


int compatta(int* X, int dimX, int z, int n_z, int n_e)	//n_z=numero di elementi==z trovati, n_e=dimX-n_z cioè elementi ancora validi
{	//PRE=(0<=n_z,n_e<=dimX, X definito ed ha dimX elementi da esaminare).
	if(dimX==0)
		return n_e;	//se volessi sapere quanti elementi ho eliminato basterebbe restituire n_z
	else
	{
		if(X[0]==z)
			n_z++;		
		else
		{
			n_e++;
			X[-n_z]=X[0];
		}
		return compatta(X+1, dimX-1, z, n_z, n_e);
	}
}	//POST=().
/* POST (NON ricorsiva):
alla fine X[0..n_e] contiene tutti gli elementi diversi da z originariamente contenuti in old_X, n_z sarà invece il numero totale delle occorrenze di z in old_X
quindi n_e+n_z=old_dimX. */

/*nota su compatta:
ufficialmente sarebbe:
PRE=(X ha dimX elementi, 0<dim<=48, 0<=fino<=cur<=dimX)
int compatta(int* X, int dimX, int z, int fino, int cur)
POST=(se k è restituito dalla funzione, allora X[fino..(fino+k)-1] contiene gli elementi contenuti in X[curr..dim-1] diversi da z (che sono k)).
quindi sarebbero da rideclinare n_z e n_e come "indici"...
*/




/* Versione 2:
#include<iostream>
#include<fstream>

using namespace std;


//Prototipi di FUNZIONI (Dichiarazioni)

void stamparic(int *X, int dimX, ofstream &OUT);

int compatta(int* X, int dimX, int z, int n_z, int n_e);



main()
{	//PRE=("input" contiene 0<dimT<=48 seguito da dimT valori interi, un valore intero z).
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT) 
	{ 
		int T[3][4][4], dimT, z;
		INP>>dimT;
		int* x=**T;
		for(int i=0; i<dimT; i++)
			INP>>x[i];
		
		stamparic(x,dimT,OUT);	//stampa ricorsiva per righe da fare
	
		OUT<<endl;
		INP>>z;
		
		int ne=compatta(x,dimT,z,0,0);	//da fare
		stamparic(x,ne,OUT);	//stampa quello che resta
		
		OUT<<endl<<"fine"<<endl;
		
		INP.close();
		OUT.close(); 
	}
	else
		cout<<"errore con i files"<<endl;
}	// POST=("output" contiene:
	//	- la stampa per righe dell'array iniziale
	//	- la stampa dell'array "purgato" di tutte le occorrenze di z e ricompattato
	//	- la stringa "fine").



//Implementazioni delle FUNZIONI (Definizione)

void stamparic(int *X, int dimX, ofstream &OUT)
{	//PRE=(X contiene dimX elementi).
	if(dimX==0)
		return;
	else
	{
		OUT<<X[0]<<" ";
		return stamparic(X+1, dimX-1, OUT);
	}
}	// POST=("output" conterrà dimX elementi stampati per righe).


int compatta(int* X, int dimX, int z, int fino, int cur)
{	//PRE=(X ha dimX elementi, 0<dim<=48, 0<=fino<=cur<=dimX).
	if(dimX==cur)
		return fino;	//se volessi sapere quanti elementi ho eliminato basterebbe restituire "cur-fino"
	else
	{
		if(X[cur]==z)
			cur++;
		else
		{
			X[fino]=X[cur];
			cur++;
			fino++;
		}
		return compatta(X, dimX, z, fino, cur);
	}
}	//POST=(se k è restituito dalla funzione, allora X[fino..(fino+k)-1] contiene gli elementi contenuti in X[curr..dimX-1] diversi da z (che sono k)).
*/



/* Versione 3:
#include<iostream>
#include<fstream>

using namespace std;


//Prototipi di FUNZIONI (Dichiarazioni)

void stamparic(int *X, int dimX, ofstream &OUT);

int compatta(int* X, int dimX, int z, int n_z, int n_e);



main()
{	//PRE=("input" contiene 0<dimT<=48 seguito da dimT valori interi, un valore intero z).
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT) 
	{ 
		int T[3][4][4], dimT, z;
		INP>>dimT;
		int* x=**T;
		for(int i=0; i<dimT; i++)
			INP>>x[i];
		
		stamparic(x,dimT,OUT);	//stampa ricorsiva per righe da fare
	
		OUT<<endl;
		INP>>z;
		
		int ne=compatta(x,dimT,z,0,0);	//da fare
		stamparic(x,ne,OUT);	//stampa quello che resta
		
		OUT<<endl<<"fine"<<endl;
		
		INP.close();
		OUT.close(); 
	}
	else
		cout<<"errore con i files"<<endl;
}	// POST=("output" contiene:
	//	- la stampa per righe dell'array iniziale
	//	- la stampa dell'array "purgato" di tutte le occorrenze di z e ricompattato
	//	- la stringa "fine").



//Implementazioni delle FUNZIONI (Definizione)

void stamparic(int *X, int dimX, ofstream &OUT)
{	//PRE=(X contiene dimX elementi).
	if(dimX==0)
		return;
	else
	{
		OUT<<X[0]<<" ";
		return stamparic(X+1, dimX-1, OUT);
	}
}	// POST=("output" conterrà dimX elementi stampati per righe).


int compatta(int* X, int dimX, int z, int fino, int cur)
{	//PRE=(X ha dimX elementi, 0<dim<=48, 0<=fino<=cur<=dimX).
	if(dimX==cur)
		return fino;	//se volessi sapere quanti elementi ho eliminato basterebbe restituire "cur-fino"
	else
	{
		if(X[cur]!=z)
		{
			X[fino]=X[cur];
			fino++;
		}
		return compatta(X, dimX, z, fino, cur+1);
	}
}	//POST=(se k è restituito dalla funzione, allora X[fino..(fino+k)-1] contiene gli elementi contenuti in X[curr..dimX-1] diversi da z (che sono k)).
*/



/* Versione 4:
#include<iostream>
#include<fstream>

using namespace std;


//Prototipi di FUNZIONI (Dichiarazioni)

void stampa_riga(int *p, int lung, ofstream &OUT);

void stampa(int *X, int dimX, ofstream &OUT);

int compatta(int* X, int dimX, int z, int n_z, int n_e);



main()
{	//PRE=("input" contiene 0<dimT<=48 seguito da dimT valori interi, un valore intero z).
	ifstream INP("input.txt");
	ofstream OUT("output.txt");
	if(INP && OUT) 
	{ 
		int T[3][4][4], dimT, z;
		INP>>dimT;
		int* x=**T;
		for(int i=0; i<dimT; i++)
			INP>>x[i];
		
		stampa(x,dimT,OUT);	//stampa ricorsiva per righe da fare
	
		OUT<<endl;
		INP>>z;
		
		int ne=compatta(x,dimT,z,0,0);	//da fare
		stampa(x,ne,OUT);	//stampa quello che resta
		
		OUT<<"fine"<<endl;
		
		INP.close();
		OUT.close(); 
	}
	else
		cout<<"errore con i files"<<endl;
}	// POST=("output" contiene:
	//	- la stampa per righe dell'array iniziale
	//	- la stampa dell'array "purgato" di tutte le occorrenze di z e ricompattato
	//	- la stringa "fine").



//Implementazioni delle FUNZIONI (Definizione)

void stampa(int *X, int dimX, ofstream &OUT)	//PRE=(X contiene dimX elementi).
{
	if(dimX<=4)	//4 è la dim di una riga
		stampa_riga(X, dimX, OUT);
	else
	{
		stampa(X, 4, OUT);
		stampa(X+4, dimX-4, OUT);
	}
}	// POST=("output" conterrà dimX elementi stampati per righe).


void stampa_riga(int *p, int lung, ofstream &OUT)
{
	if(lung==0)
		OUT<<endl;	//fine di una riga
	else
	{
		OUT<<p[0]<<" ";
		stampa_riga(p+1, lung-1, OUT);
	}
}


int compatta(int* X, int dimX, int z, int fino, int cur)
{	//PRE=(X ha dimX elementi, 0<dim<=48, 0<=fino<=cur<=dimX).
	if(dimX==cur)
		return fino;	//se volessi sapere quanti elementi ho eliminato basterebbe restituire "cur-fino"
	else
	{
		if(X[cur]!=z)
		{
			X[fino]=X[cur];
			fino++;
		}
		return compatta(X, dimX, z, fino, cur+1);
	}
}	//POST=(se k è restituito dalla funzione, allora X[fino..(fino+k)-1] contiene gli elementi contenuti in X[curr..dimX-1] diversi da z (che sono k)).
*/



/* Versione 5:
#include<iostream>
#include<fstream>

using namespace std;


//Prototipi di FUNZIONI (Dichiarazioni)

void stampa_aux(int *p, int lung, ofstream &OUT);

void stampa(int *X, int dimX, ofstream &OUT);

int compatta(int* X, int dimX, int z, int n_z, int n_e);



main()
{	//PRE=("input" contiene 0<dimT<=48 seguito da dimT valori interi, un valore intero z).
	ifstream INP("input.txt");
	ofstream OUT("output.txt");
	if(INP && OUT) 
	{ 
		int T[3][4][4], dimT, z;
		INP>>dimT;
		int* x=**T;
		for(int i=0; i<dimT; i++)
			INP>>x[i];
		
		stampa(x,dimT,OUT);	//stampa ricorsiva per righe da fare
	
		OUT<<endl;
		INP>>z;
		
		int ne=compatta(x,dimT,z,0,0);	//da fare
		stampa(x,ne,OUT);	//stampa quello che resta
		
		OUT<<endl<<"fine"<<endl;
		
		INP.close();
		OUT.close(); 
	}
	else
		cout<<"errore con i files"<<endl;
}	// POST=("output" contiene:
	//	- la stampa per righe dell'array iniziale
	//	- la stampa dell'array "purgato" di tutte le occorrenze di z e ricompattato
	//	- la stringa "fine").



//Implementazioni delle FUNZIONI (Definizione)

void stampa(int *X, int dimX, ofstream &OUT)
{	//PRE=(X contiene dimX elementi).
	if(dimX<=16)	//16 è la dim di uno strato
	{
		if(dimX<=4)	//4 è la dim di una riga, quindi questa è l'ultima riga (di uno strato o l'ultima definita)
			stampa_aux(X, dimX, OUT);
		else
		{
			stampa_aux(X, 4, OUT);
			stampa(X+4, dimX-4, OUT);
		}
		return;
	}
	else
	{
		stampa(X, 16, OUT);
		OUT<<endl;	//lo spazio tra strati diversi
		stampa(X+16, dimX-16, OUT);
		return;
	}
}	// POST=("output" conterrà dimX elementi stampati per righe).


void stampa_aux(int *p, int lung, ofstream &OUT)
{
	if(lung==0)
	{
		OUT<<endl;	//fine di una riga
		return;
	}
	else
	{
		OUT<<p[0]<<" ";
		stampa_aux(p+1, lung-1, OUT);
		return;
	}
}


int compatta(int* X, int dimX, int z, int fino, int cur)
{	//PRE=(X ha dimX elementi, 0<dim<=48, 0<=fino<=cur<=dimX).
	if(dimX==cur)
		return fino;	//se volessi sapere quanti elementi ho eliminato basterebbe restituire "cur-fino"
	else
	{
		if(X[cur]!=z)
		{
			X[fino]=X[cur];
			fino++;
		}
		return compatta(X, dimX, z, fino, cur+1);
	}
}	//POST=(se k è restituito dalla funzione, allora X[fino..(fino+k)-1] contiene gli elementi contenuti in X[curr..dimX-1] diversi da z (che sono k)).
*/
