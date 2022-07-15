
//soluzione by: Leo M.

#include <iostream>
#include <fstream>

using namespace std;



//Prototipi di FUNZIONI (Dichiarazioni)

bool match(int *y, int *p, int dimP, int col);

int contaMatch(int *v, int dimV, int *p, int dimP, int col);



main()
{	//PRE=("input" contiene nell'ordine: str>0, rig>0, col>0, 0<n_el<=400, n_el valori, 0<dimP<=50, dimP valori).
	ifstream INP("input");
	ofstream OUT("output");
	if( INP && OUT)
	{
		int X[400], P[50], str, rig, col, n_el, dimP;
		INP >> str >> rig >> col >> n_el;
		
		for(int i=0; i<n_el; i++)	//inserisco in X i primi n_el valori per righe
			INP >> *(X+i);
		for(int i=n_el; i<400; i++)	//setto a "-1" tutte le restanti (400-n_el) celle di X
			*(X+i)=-1;
		INP >> dimP;
		for(int i=0; i<dimP; i++)
			INP >> *(P+i);
			
		if(str*rig*col<n_el)
			n_el=str*rig*col;
			
		int  str_p, eus, rig_p, eur, vFet, dimV;
		str_p=n_el/(rig*col);	//str_p=StratiPieni
		eus=n_el%(rig*col);		//eus=ElementiUltimoStrato
		rig_p=eus/col;			//rig_p=RighePiene (dell'eventuale ultimo strato incompleto)
		eur=eus%col;			//eur=ElementiUltimaRiga (dell'eventuale ultimo strato incompleto)
		
		if(n_el>=col)
			vFet=col;
		else
			vFet=eur;
		
		dimV=rig*str_p+rig_p+1;
		for(int n=0; n<eur; n++)
			OUT<<"V-fetta "<<n<<" = "<<contaMatch((X+n), dimV, P, dimP, col)<<" match"<<endl;
			
		dimV=rig*str_p+rig_p;
		for(int n=eur; n<vFet; n++)
			OUT<<"V-fetta "<<n<<" = "<<contaMatch((X+n), dimV, P, dimP, col)<<" match"<<endl;
		
		
	
	
		INP.close();
		OUT.close();	
	}
	else
		cerr<<"Errore File!"<<endl;	
}	/* POST=(per ogni V-fetta n dell'array X visto come Y[str][rig][col],
			 OUT contiene una riga "V-fetta n = count match", dove "count" è il numero di match contigui e non sovrapposti degli eleme dell'array P sugli elem della V-fetta n). */



//Implementazioni delle FUNZIONI (Definizione)

bool match(int *y, int *p, int dimP, int col)
{	//PRE=(a partire dall'elem puntato da y seguono almeno dimP elem definiti).
	bool trovato=true;
	for(int m=0; m<dimP && trovato; m++)
	{
		if(*(y+m*col)!=*(p+m))
			trovato=false;
	}
	return trovato;
}	//POST=().


int contaMatch(int *v, int dimV, int *p, int dimP, int col)
{	//PRE=(v è il puntatore all'inizio di una V-fetta con dimV elem definiti).
	int count=0;
	for(int k=0; k<(dimV-dimP+1); k++)	//k è l'elem della V-fetta da cui partire alla rierca del match; k<dimV-dimP perchè inutile cercare se non ci sono ancora almeno dimP elem
	{
		if(match(v+k*col, p, dimP, col))
			{
				k=k+dimP-1;	//il -1 perchè poi viene sistemato dall'incremento del ciclo; +dimP perchè se ho trovato match salto dopo la sua fine così da non trovarne di sovrapposti
				count++;
			}
	}
	return count;	
}	//POST=(count contiene il numero di match contigui e non sovrapposti di P sugli elem della V-fetta passata).
