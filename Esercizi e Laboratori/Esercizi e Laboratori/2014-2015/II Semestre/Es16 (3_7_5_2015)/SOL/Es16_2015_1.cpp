
//soluzione by: Leo M.

// Versione 1:
#include<iostream>
#include<fstream>

using namespace std;


//Prototipi di FUNZIONI (Dichiarazioni)

int posiz(int indiceY);

void scorri_righe(int *p, int n_righe, int lung, ofstream &OUT);

void stampa_riga(int *p, int lung, ofstream &OUT);

void stampa(int *X, int dimX, ofstream &OUT);

int compattaC(int* X, int dimX, int z, int n_z, int n_e);



main()
{	//PRE=("input" contiene 0<dimT<=48 seguito da dimT valori interi, un valore intero z).
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT) 
	{ 
		int T[3][4][4], dimT, z, *x=**T;
		INP>>dimT;
		int count=dimT;
		
		//riempie T per strati e colonne
		for(int i=0; i<3 && count>0; i++)
			for(int  j=0; j<4 && count>0; j++)
				for(int k=0; k<4 && count>0; k++)
					{
						INP>>T[i][k][j];
						count--;
					}
		INP>>z;
   
		stampa(x,dimT,OUT);//stampa ricorsiva per strati e per righe, considerando solo elementi definiti
   
		int ne=compattaC(x,dimT,z,0,0);	//da fare
   
		stampa(x,ne,OUT); //stampa dell'array dopo il compattamento
		OUT<<"fine"<<endl;
		
		INP.close();
		OUT.close(); 
	}
	else
		cout<<"errore con i files";
}	// POST=("output" contiene:
	//	- la stampa per righe dell'array iniziale
	//	- la stampa dell'array "purgato" di tutte le occorrenze di z e ricompattato
	//	- la stringa "fine").



//Implementazioni delle FUNZIONI (Definizione)

void stampa(int *X, int dimX, ofstream &OUT)
{	//PRE=(a partire da quello puntato da X ci sono ancora (almeno) dimX elementi definiti).
	if(dimX<16)
	{
		//caso base: (resta da gestire lo strato incompleto)
		int lim2=4, lim3=4;		//chiamo i due "4" lim2 e lim3 per comodità
		int lung=dimX/lim2;		//numero di colonne piene dell'ultimo strato
		int euc=dimX%lim2;		//numero di righe di lunghezza "lung+1", le restanti lim2-euc avranno lunghezza "lung"
		scorri_righe(X, euc, lung+1, OUT);				//stampo le euc righe di lunghezza lung+1
		scorri_righe(X+euc*lim3, lim2-euc, lung, OUT);	//aggiusto il puntatore e stampo le restanti lim2-euc righe di lunghezza lung
		return;
	}
	else	//ho sufficienti elementi per riempire completamente uno strato
	{
		scorri_righe(X, 4, 4, OUT);	//gli strati sono composti da 4 righe di 4 elem, quindi stamperò 4 righe da 4 elem ciascuna
		stampa(X+(4*4), dimX-(4*4), OUT);	//chiamata ricorsiva, salto dopo le 4 colonne di 4 elem ciascuna già stampati
		return;
	}
}	// POST=("output" conterrà i dimX elementi stampati per righe).


void stampa_riga(int *p, int lung, ofstream &OUT)
{	//PRE=(p è un puntatore valido, a partire da quello puntato da p ci sono "lung" elementi contigui da stampare).
	if(lung==0)	//o if(!lung)
		return;
	else
	{
		OUT<<p[0]<<" ";
		return stampa_riga(p+1, lung-1, OUT);
	}
}	// POST=("output" conterrà in coda i lung elementi stampati).


void scorri_righe(int *p, int n_righe, int lung, ofstream &OUT)
{	//PRE=().
	if(n_righe==0)
		return;
	else
	{
		stampa_riga(p, lung, OUT);
		OUT<<endl;	//separa ogni riga
		scorri_righe(p+4, n_righe-1, lung, OUT);	//4 è lim3, il numero di elementi di una riga
		return;
	}
}	//POST=().


int posiz(int indiceY)
{	//PRE=().
	// Nota:
	//	immaginiamo di riversare in un array monodimensionale Y tutti gli elementi presenti nell'array X (tridimensionale) così come vi sono stati messi dentro;
	//	indicando con indiceY l'indice dell'elemento desiderato (eg: se voglio "il quarto elemento" -> indiceY=3)
	//	questa funzione restituirà l'indice della posizione in X dell'elemento che noi abbiamo indicato tramite indiceY.


	int lim2=4, lim3=4;	//chiamo lim2 e lim3 i due "4" delle dimensioni fisse dell'array X
	int str, rig, col;	//var ausiliarie
		
	str= indiceY / (lim2*lim3);					//indice dello STRato dove si trova l'elem d'interesse in X
	col= (indiceY - str*lim2*lim3) / lim2;		//indice della COLonna dove si trova l'elem d'interesse in X
	rig= indiceY - str*lim2*lim3 - col*lim2;	//indice della RIGa dove si trova l'elem d'interesse in X
  
  	return str*lim2*lim3 + rig*lim3 + col;
}	//POST=().


int compattaC(int* X, int dimX, int z, int fino, int cur)
{	//PRE=(X ha dimX elementi, 0<dim<=48, 0<=fino<=cur<=dimX).
	if(dimX==cur)
		return fino;	//se volessi sapere quanti elementi ho eliminato basterebbe restituire "cur-fino"
	else
	{
		if(X[posiz(cur)]!=z)
		{
			X[posiz(fino)]=X[posiz(cur)];
			fino++;
		}
		return compattaC(X, dimX, z, fino, cur+1);
	}
}	//POST=(se k è restituito dalla funzione, allora X[posiz(fino)..posiz(fino+k-1)] contiene gli elementi contenuti in X[posiz(curr)..dimX-1] diversi da z (che sono k)).





/* Versione 2:
#include<iostream>
#include<fstream>

using namespace std;


//Prototipi di FUNZIONI (Dichiarazioni)

int posiz(int dimX, int indiceY);

bool stampa_test(int dimX, int index);

void stampa(int *X, int dimX, int i, ofstream &OUT);

int compattaC(int* X, int dimX, int z, int n_z, int n_e);



main()
{	//PRE=("input" contiene 0<dimT<=48 seguito da dimT valori interi, un valore intero z).
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT) 
	{ 
		int T[3][4][4], dimT, z, *x=**T;
		INP>>dimT;
		int count=dimT;
		
		//riempie T per strati e colonne
		for(int i=0; i<3 && count>0; i++)
			for(int  j=0; j<4 && count>0; j++)
				for(int k=0; k<4 && count>0; k++)
					{
						INP>>T[i][k][j];
						count--;
					}
		INP>>z;
   
		stampa(x,dimT,0,OUT);//stampa ricorsiva per strati e per righe, considerando solo elementi definiti
   
		int ne=compattaC(x,dimT,z,0,0);	//da fare
   
		stampa(x,ne,0,OUT); //stampa dell'array dopo il compattamento
		OUT<<"fine"<<endl;
		
		INP.close();
		OUT.close(); 
	}
	else
		cout<<"errore con i files";
}	// POST=("output" contiene:
	//	- la stampa per righe dell'array iniziale
	//	- la stampa dell'array "purgato" di tutte le occorrenze di z e ricompattato
	//	- la stringa "fine").



//Implementazioni delle FUNZIONI (Definizione)

int posiz(int dimX, int indiceY)
{	//nota:
	//	immaginiamo di riversare in un array monodimensionale Y tutti gli elementi presenti nell'array X (tridimensionale) così come vi sono stati messi dentro;
	//	indicando con indiceY l'indice dell'elemento desiderato (eg: se voglio "il quarto elemento" -> indiceY=3)
	//	questa funzione restituirà un puntatore alla posizione in X dell'elemento che noi abbiamo indicato tramite indiceY.
	//	se l'elemento NON esiste (è dentro X ma non è definito, oppure è fuori da X) allora la funzione restituisce un puntatore nullo.


//PRE=().
	int lim1=3, lim2=4, lim3=4;	//lim1 NON serve
	int punt=0;
	
	if(indiceY<dimX)	//altrimenti l'elemento NON esiste
	{
		int str, rig, col;	//var ausiliarie
		
		str= indiceY / (lim2*lim3);					//indice dello STRato dove si trova l'elem d'interesse
		col= (indiceY - str*lim2*lim3) / lim2;		//indice della COLonna dove si trova l'elem d'interesse
		rig= indiceY - str*lim2*lim3 - col*lim2;	//indice della RIGa dove si trova l'elem d'interesse
  
  		punt = str*lim2*lim3 + rig*lim3 + col;
	}
	
	return punt;
}	//POST=().


bool stampa_test(int dimX, int index)
{
	int lim2=4, lim3=4;			//per comodità assegno le dimensioni fisse di righe e colonne a due variabili ausiliarie
	int str_p=dimX/(lim2*lim3);	//numero di strati pieni di X
	
	if(index<str_p*lim2*lim3)	//se l'elemento sta in uno strato pieno -> no problem -> stampa
		return true;
	else
	{
		index=index-str_p*lim2*lim3;	//sposto l'indice dopo gli strati pieni
		int eus=dimX%(lim2*lim3);		//ElementiUltimoStrato (quello incompleto, disposti per colonne)
		int col_p=eus/lim2;				//numero di colonne piene (dello strato incompleto)
		int euc=eus%lim2;				//ElementiUltimaColonna (dello strato incompleto)
	
		if(index<lim2*lim3)		//se sta nello strato incompleto (forse è un controllo inutile)
		{
			if((index%lim3)<col_p)	//se sta in una colonna piena -> ok
				return true;
			else	//altrimenti o sta negli elementi definiti (euc) della colonna incompleta o non è da stampare
			{
				if((index%lim3)==col_p && (index/lim2)<euc)	//se sta nella colonna incompleta e entro i suoi euc elementi definiti -> ok
					return true;
				else
					return false;
			}
		}
		else	//altrimenti sta in uno strato completamente vuoto
			return false;
	}


void stampa(int *X, int dimX, int i, ofstream &OUT)
{	//PRE=(X contiene dimX elementi).
	if(i==3*4*4)
		return;
	else
	{
		if(stampa_test(dimX, i))
			OUT<<X[i]<<" ";
			
		return stampa(X, dimX, i+1, OUT);
	}
}	// POST=("output" conterrà dimX elementi stampati per righe).


int compattaC(int* X, int dimX, int z, int fino, int cur)
{	//PRE=(X ha dimX elementi, 0<dim<=48, 0<=fino<=cur<=dimX).
	if(dimX==cur)
		return fino;	//se volessi sapere quanti elementi ho eliminato basterebbe restituire "cur-fino"
	else
	{
		if(X[posiz(dimX, cur)]!=z)
		{
			X[posiz(dimX, fino)]=X[posiz(dimX, cur)];
			fino++;
		}
		return compattaC(X, dimX, z, fino, cur+1);
	}
}	//POST=(se k è restituito dalla funzione, allora X[fino..(fino+k)-1] contiene gli elementi contenuti in X[curr..dimX-1] diversi da z (che sono k)).
*/



/* Versione 3:
#include<iostream>
#include<fstream>

using namespace std;


//Prototipi di FUNZIONI (Dichiarazioni)

int posiz(int dimX, int indiceY);

void gira(int *p, int n_giri, int lung, ofstream &OUT);

void stampa_aux(int *p, int lung, ofstream &OUT);

void stampa(int *X, int dimX, ofstream &OUT);

int compattaC(int* X, int dimX, int z, int n_z, int n_e);



main()
{	//PRE=("input" contiene 0<dimT<=48 seguito da dimT valori interi, un valore intero z).
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT) 
	{ 
		int T[3][4][4], dimT, z, *x=**T;
		INP>>dimT;
		int count=dimT;
		
		//riempie T per strati e colonne
		for(int i=0; i<3 && count>0; i++)
			for(int  j=0; j<4 && count>0; j++)
				for(int k=0; k<4 && count>0; k++)
					{
						INP>>T[i][k][j];
						count--;
					}
		INP>>z;
   
		stampa(x,dimT,OUT);//stampa ricorsiva per strati e per righe, considerando solo elementi definiti
   
		int ne=compattaC(x,dimT,z,0,0);	//da fare
   
		stampa(x,ne,OUT); //stampa dell'array dopo il compattamento
		OUT<<"fine"<<endl;
		
		INP.close();
		OUT.close(); 
	}
	else
		cout<<"errore con i files";
}	// POST=("output" contiene:
	//	- la stampa per righe dell'array iniziale
	//	- la stampa dell'array "purgato" di tutte le occorrenze di z e ricompattato
	//	- la stringa "fine").



//Implementazioni delle FUNZIONI (Definizione)

void stampa(int *X, int dimX, ofstream &OUT)
{	//PRE=(X contiene dimX elementi).
	if(dimX<16)
	{
		//caso base: (resta da gestire lo strato incompleto)
		int lim2=4, lim3=4;		//chiamo i due "4" lim2 e lim3 per comodità
		int lung=dimX/lim2;		//numero di colonne piene dell'ultimo strato
		int euc=dimX%lim2;		//numero di righe di lunghezza "lung+1", le restanti lim2-euc avranno lunghezza "lung"
		gira(X, euc, lung+1, OUT);				//stampo le euc righe di lunghezza lung+1
		gira(X+euc*lim3, lim2-euc, lung, OUT);	//aggiusto il puntatore e stampo le restanti lim2-euc righe di lunghezza lung
		
		return;
	}
	else	//ho sufficienti elementi per rimpire completamente uno strato
	{
		stampa_aux(X, 16, OUT);	//stampo lo strato
		stampa(X+16, dimX-16, OUT);	//chiamata ricorsiva
		return;
	}
}	// POST=("output" conterrà dimX elementi stampati per righe).


void stampa_aux(int *p, int lung, ofstream &OUT)
{	//PRE=(p è un puntatore valido, a partire da quello puntato da p stamperò "lung" elementi).
	if(lung==0)	//o if(!lung)
		return;
	else
	{
		OUT<<p[0]<<" ";
		return stampa_aux(p+1, lung-1, OUT);
	}
}	// POST=("output" conterrà i dim_str elementi stampati per righe).


void gira(int *p, int n_giri, int lung, ofstream &OUT)
{
	if(n_giri==0)
		return;
	else
	{
		stampa_aux(p, lung, OUT);
		gira(p+4, n_giri-1, lung, OUT);	//4 è lim3, il numero di elementi di una riga
		return;
	}
}


int posiz(int dimX, int indiceY)
{	//nota:
	//	immaginiamo di riversare in un array monodimensionale Y tutti gli elementi presenti nell'array X (tridimensionale) così come vi sono stati messi dentro;
	//	indicando con indiceY l'indice dell'elemento desiderato (eg: se voglio "il quarto elemento" -> indiceY=3)
	//	questa funzione restituirà un puntatore alla posizione in X dell'elemento che noi abbiamo indicato tramite indiceY.
	//	se l'elemento NON esiste (è dentro X ma non è definito, oppure è fuori da X) allora la funzione restituisce un puntatore nullo.
	

//PRE=().
	int lim1=3, lim2=4, lim3=4;	//lim1 NON serve
	int punt=0;
	
	if(indiceY<dimX)	//altrimenti l'elemento NON esiste
	{
		int str, rig, col;	//var ausiliarie
		
		str= indiceY / (lim2*lim3);					//indice dello STRato dove si trova l'elem d'interesse
		col= (indiceY - str*lim2*lim3) / lim2;		//indice della COLonna dove si trova l'elem d'interesse
		rig= indiceY - str*lim2*lim3 - col*lim2;	//indice della RIGa dove si trova l'elem d'interesse
  
  		punt = str*lim2*lim3 + rig*lim3 + col;
	}
	
	return punt;
}	//POST=().


int compattaC(int* X, int dimX, int z, int fino, int cur)
{	//PRE=(X ha dimX elementi, 0<dim<=48, 0<=fino<=cur<=dimX).
	if(dimX==cur)
		return fino;	//se volessi sapere quanti elementi ho eliminato basterebbe restituire "cur-fino"
	else
	{
		if(X[posiz(dimX, cur)]!=z)
		{
			X[posiz(dimX, fino)]=X[posiz(dimX, cur)];
			fino++;
		}
		return compattaC(X, dimX, z, fino, cur+1);
	}
}	//POST=(se k è restituito dalla funzione, allora X[fino..(fino+k)-1] contiene gli elementi contenuti in X[curr..dimX-1] diversi da z (che sono k)).
*/



/* Versione 4:
#include<iostream>
#include<fstream>

using namespace std;


//Prototipi di FUNZIONI (Dichiarazioni)

int posiz(int dimX, int indiceY);

void scorri_righe(int *p, int n_righe, int lung, ofstream &OUT);

void stampa_riga(int *p, int lung, ofstream &OUT);

void stampa(int *X, int dimX, ofstream &OUT);

int compattaC(int* X, int dimX, int z, int n_z, int n_e);



main()
{	//PRE=("input" contiene 0<dimT<=48 seguito da dimT valori interi, un valore intero z).
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT) 
	{ 
		int T[3][4][4], dimT, z, *x=**T;
		INP>>dimT;
		int count=dimT;
		
		//riempie T per strati e colonne
		for(int i=0; i<3 && count>0; i++)
			for(int  j=0; j<4 && count>0; j++)
				for(int k=0; k<4 && count>0; k++)
					{
						INP>>T[i][k][j];
						count--;
					}
		INP>>z;
   
		stampa(x,dimT,OUT);//stampa ricorsiva per strati e per righe, considerando solo elementi definiti
   
		int ne=compattaC(x,dimT,z,0,0);	//da fare
   
		stampa(x,ne,OUT); //stampa dell'array dopo il compattamento
		OUT<<"fine"<<endl;
		
		INP.close();
		OUT.close(); 
	}
	else
		cout<<"errore con i files";
}	// POST=("output" contiene:
	//	- la stampa per righe dell'array iniziale
	//	- la stampa dell'array "purgato" di tutte le occorrenze di z e ricompattato
	//	- la stringa "fine").



//Implementazioni delle FUNZIONI (Definizione)

void stampa(int *X, int dimX, ofstream &OUT)
{	//PRE=(X contiene dimX elementi).
	if(dimX<16)
	{
		//caso base: (resta da gestire lo strato incompleto)
		int lim2=4, lim3=4;		//chiamo i due "4" lim2 e lim3 per comodità
		int lung=dimX/lim2;		//numero di colonne piene dell'ultimo strato
		int euc=dimX%lim2;		//numero di righe di lunghezza "lung+1", le restanti lim2-euc avranno lunghezza "lung"
		scorri_righe(X, euc, lung+1, OUT);				//stampo le euc righe di lunghezza lung+1
		scorri_righe(X+euc*lim3, lim2-euc, lung, OUT);	//aggiusto il puntatore e stampo le restanti lim2-euc righe di lunghezza lung
		
		return;
	}
	else	//ho sufficienti elementi per rimpire completamente uno strato
	{
		scorri_righe(X, 4, 4, OUT);	//gli strati sono composti da 4 righe di 4 elem, quindi stamperò 4 righe da 4 elem ciascuna
		stampa(X+16, dimX-16, OUT);	//chiamata ricorsiva
		return;
	}
}	// POST=("output" conterrà dimX elementi stampati per righe).


void stampa_riga(int *p, int lung, ofstream &OUT)
{	//PRE=(p è un puntatore valido, a partire da quello puntato da p stamperò "lung" elementi).
	if(lung==0)	//o if(!lung)
		return;
	else
	{
		OUT<<p[0]<<" ";
		return stampa_riga(p+1, lung-1, OUT);
	}
}	// POST=("output" conterrà i dim_str elementi stampati per righe).


void scorri_righe(int *p, int n_righe, int lung, ofstream &OUT)
{
	if(n_righe==0)
		return;
	else
	{
		stampa_riga(p, lung, OUT);
		OUT<<endl;	//separa ogni riga
		scorri_righe(p+4, n_righe-1, lung, OUT);	//4 è lim3, il numero di elementi di una riga
		return;
	}
}


int posiz(int dimX, int indiceY)
{	//nota:
	//	immaginiamo di riversare in un array monodimensionale Y tutti gli elementi presenti nell'array X (tridimensionale) così come vi sono stati messi dentro;
	//	indicando con indiceY l'indice dell'elemento desiderato (eg: se voglio "il quarto elemento" -> indiceY=3)
	//	questa funzione restituirà un puntatore alla posizione in X dell'elemento che noi abbiamo indicato tramite indiceY.
	//	se l'elemento NON esiste (è dentro X ma non è definito, oppure è fuori da X) allora la funzione restituisce un puntatore nullo.


//PRE=().
	int lim1=3, lim2=4, lim3=4;	//lim1 NON serve
	int punt=0;
	
	if(indiceY<dimX)	//altrimenti l'elemento NON esiste
	{
		int str, rig, col;	//var ausiliarie
		
		str= indiceY / (lim2*lim3);					//indice dello STRato dove si trova l'elem d'interesse
		col= (indiceY - str*lim2*lim3) / lim2;		//indice della COLonna dove si trova l'elem d'interesse
		rig= indiceY - str*lim2*lim3 - col*lim2;	//indice della RIGa dove si trova l'elem d'interesse
  
  		punt = str*lim2*lim3 + rig*lim3 + col;
	}
	
	return punt;
}	//POST=().


int compattaC(int* X, int dimX, int z, int fino, int cur)
{	//PRE=(X ha dimX elementi, 0<dim<=48, 0<=fino<=cur<=dimX).
	if(dimX==cur)
		return fino;	//se volessi sapere quanti elementi ho eliminato basterebbe restituire "cur-fino"
	else
	{
		if(X[posiz(dimX, cur)]!=z)
		{
			X[posiz(dimX, fino)]=X[posiz(dimX, cur)];
			fino++;
		}
		return compattaC(X, dimX, z, fino, cur+1);
	}
}	//POST=(se k è restituito dalla funzione, allora X[fino..(fino+k)-1] contiene gli elementi contenuti in X[curr..dimX-1] diversi da z (che sono k)).
*/

