
//soluzione by: Leo M.

// Versione 1:
#include <iostream>
#include <fstream>

using namespace std;



//Prototipi di FUNZIONI (Dichiarazioni)

int *posiz(int *h, int tempEl, int rig, int col);

bool match(int *h, int elemento, int *p, int dimP, int rig, int col);

int contaMatch(int *h, int dimH, int *p, int dimP, int rig, int col);



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
			
		if(str*rig*col<n_el)		//evita che i successivi conti e bound vengano calcolati male se ci sono elementi sovrabondanti rispetto a quelli di interesse (Y)
			n_el=str*rig*col;
			
		int  str_p, eus, rig_p, eur, hFet, dimH;
		str_p=n_el/(rig*col);	//str_p=StratiPieni
		eus=n_el%(rig*col);		//eus=ElementiUltimoStrato
		rig_p=eus/col;			//rig_p=RighePiene (dell'eventuale ultimo strato incompleto)
		eur=eus%col;			//eur=ElementiUltimaRiga (dell'eventuale ultimo strato incompleto)
		
		if(n_el>=rig*col)
			hFet=rig;
		else
		{
			hFet=rig_p;
			if(eur)
				hFet++;
		}
		
		
		/*
			Le H-Fette per dimensione si dividono in 3 tipologie in base alla porzione dello strato incompleto che coinvolgono:
			 a)	una riga piena (se ce ne sono)
			 	dimH=str_p*col+col
			 b)	la riga con eur elementi (se c'è)
			 	dimH=str_p*col+eur
			 c) una riga vuota (NB: se l'array Y è completamente pieno tutte le H-Fette sono di questo tipo)
			 	dimH=str_p*col
		*/
		
		//scorro tutte le H-Fette, in ordine per tipologia
		int n=0;
		dimH=str_p*col+col;
		for( ; n<rig_p; n++)
			OUT<<"H-fetta "<<n<<" = "<<contaMatch((X+n*col), dimH, P, dimP, rig, col)<<" match"<<endl;
			
		dimH=str_p*col+eur;
		if(eur)
		{
			OUT<<"H-fetta "<<n<<" = "<<contaMatch((X+n*col), dimH, P, dimP, rig, col)<<" match"<<endl;
			n++;
		}
			
		dimH=str_p*col;
		for( ; n<hFet; n++)
			OUT<<"H-fetta "<<n<<" = "<<contaMatch((X+n*col), dimH, P, dimP, rig, col)<<" match"<<endl;
		
		
	
	
		INP.close();
		OUT.close();	
	}
	else
		cerr<<"Errore File!"<<endl;	
}	/* POST=(per ogni H-fetta n dell'array X visto come Y[str][rig][col],
			 OUT contiene una riga "H-fetta n = count match", dove "count" è il numero di match contigui e non sovrapposti degli eleme dell'array P sugli elem della H-fetta n). */



//Implementazioni delle FUNZIONI (Definizione)

int *posiz(int *h, int tempEl, int rig, int col)
{	//PRE=(h punta all'inizio di una H-Fetta valida che ha dimH>=dimP elem, 0<=tempEl<dimH è l'indice dell'elemento della H-Fetta in questione che va matchato con l'elem di P).
	int *p=0, r, e;	//r=numero di righe da saltare nell'H-Fetta (cioè strati) per raggiungere quella dove c'è l'elem d'interesse; e=indice dell'elem di interesse sulla riga r
	r=tempEl/col;
	e=tempEl%col;
	
	p=( h + e + r*rig*col );
	
	return p;
}	//POST=(p punta all'elemento da controllare).


bool match(int *h, int elemento, int *p, int dimP, int rig, int col)
{	//PRE=(h punta all'inizio di una H-Fetta valida che ha dimH>=dimP elem, "elemento" è l'indice dell'elemento della H-Fetta in questione fino al quale si è già controllato).
	bool trovato=true;
	for(int m=0; m<dimP && trovato; m++)
	{
		if(*posiz(h, elemento+m, rig, col) != *(p+m))
			trovato=false;
	}
	return trovato;
}	/*POST=(trovato=true se tutti i dimP elementi di P matchavano il loro corrispondente a partire dalla posizione fornita da "posiz";
			trovato=false se almeno un elemnto di P non matchava con il suo corrispondente a partire dalla posizione fornita da "posiz"). */


int contaMatch(int *h, int dimH, int *p, int dimP, int rig, int col)
{	//PRE=(h è il puntatore all'inizio di una H-fetta con dimH elem definiti).
	int count=0;
	for(int k=0; k<(dimH-dimP+1); k++)	// k è l'elem della H-fetta vista come un array monodimensionale da cui partire alla rierca del match;
	{									// k<=dimV-dimP perchè inutile cercare se non ci sono ancora almeno dimP elem.
		if(match(h, k, p, dimP, rig, col))
			{
				k=k+dimP-1;	//il -1 perchè poi viene sistemato dall'incremento del ciclo; +dimP perchè se ho trovato match salto dopo la sua fine così da non trovarne di sovrapposti
				count++;
			}
	}
	return count;	
}	//POST=(count contiene il numero di match contigui e non sovrapposti di P sugli elem della H-fetta passata).





/* Versione 2:
#include <iostream>
#include <fstream>

using namespace std;



//Prototipi di FUNZIONI (Dichiarazioni)

bool match(int *h, int elemento, int *p, int dimP, int rig, int col);

int contaMatch(int *h, int dimH, int *p, int dimP, int rig, int col);



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
			
		if(str*rig*col<n_el)		//evita che i successivi conti e bound vengano calcolati male se ci sono elementi sovrabondanti rispetto a quelli di interesse (Y)
			n_el=str*rig*col;
			
		int  str_p, eus, rig_p, eur, hFet, dimH;
		str_p=n_el/(rig*col);	//str_p=StratiPieni
		eus=n_el%(rig*col);		//eus=ElementiUltimoStrato
		rig_p=eus/col;			//rig_p=RighePiene (dell'eventuale ultimo strato incompleto)
		eur=eus%col;			//eur=ElementiUltimaRiga (dell'eventuale ultimo strato incompleto)
		
		if(n_el>=rig*col)
			hFet=rig;
		else
		{
			hFet=rig_p;
			if(eur)
				hFet++;
		}
		
		
		
//			Le H-Fette per dimensione si dividono in 3 tipologie in base alla porzione dello strato incompleto che coinvolgono:
//			 a)	una riga piena (se ce ne sono)
//			 	dimH=str_p*col+col
//			 b)	la riga con eur elementi (se c'è)
//			 	dimH=str_p*col+eur
//			 c) una riga vuota (NB: se l'array Y è completamente pieno tutte le H-Fette sono di questo tipo)
//			 	dimH=str_p*col

		
		//scorro tutte le H-Fette, in ordine per tipologia
		int n=0;
		dimH=str_p*col+col;
		for( ; n<rig_p; n++)
			OUT<<"H-fetta "<<n<<" = "<<contaMatch((X+n*col), dimH, P, dimP, rig, col)<<" match"<<endl;
			
		dimH=str_p*col+eur;
		if(eur)
		{
			OUT<<"H-fetta "<<n<<" = "<<contaMatch((X+n*col), dimH, P, dimP, rig, col)<<" match"<<endl;
			n++;
		}
			
		dimH=str_p*col;
		for( ; n<hFet; n++)
			OUT<<"H-fetta "<<n<<" = "<<contaMatch((X+n*col), dimH, P, dimP, rig, col)<<" match"<<endl;
		
		
	
	
		INP.close();
		OUT.close();	
	}
	else
		cerr<<"Errore File!"<<endl;	
}	// POST=(per ogni H-fetta n dell'array X visto come Y[str][rig][col],
	//		 OUT contiene una riga "H-fetta n = count match", dove "count" è il numero di match contigui e non sovrapposti degli eleme dell'array P sugli elem della H-fetta n).



//Implementazioni delle FUNZIONI (Definizione)

bool match(int *h, int elemento, int *p, int dimP, int rig, int col)
{	//PRE=(h punta all'inizio di una H-Fetta valida che ha dimH>=dimP elem, "elemento" è l'indice dell'elemento della H-Fetta in questione fino al quale si è già controllato).
	bool trovato=true;
	for(int m=0; m<dimP && trovato; m++)
	{
		if( *(h+((elemento+m)%col)+(((elemento+m)/col)*rig*col)) != *(p+m))
			trovato=false;
	}
	return trovato;
}	//POST=(trovato=true se tutti i dimP elementi di P matchavano il loro corrispondente a partire dalla posizione fornita da "posiz";
	//		trovato=false se almeno un elemnto di P non matchava con il suo corrispondente a partire dalla posizione fornita da "posiz").


int contaMatch(int *h, int dimH, int *p, int dimP, int rig, int col)
{	//PRE=(h è il puntatore all'inizio di una H-fetta con dimH elem definiti).
	int count=0;
	for(int k=0; k<(dimH-dimP+1); k++)	// k è l'elem della H-fetta vista come un array monodimensionale da cui partire alla rierca del match;
	{									// k<=dimV-dimP perchè inutile cercare se non ci sono ancora almeno dimP elem.
		if(match(h, k, p, dimP, rig, col))
			{
				k=k+dimP-1;	//il -1 perchè poi viene sistemato dall'incremento del ciclo; +dimP perchè se ho trovato match salto dopo la sua fine così da non trovarne di sovrapposti
				count++;
			}
	}
	return count;	
}	//POST=(count contiene il numero di match contigui e non sovrapposti di P sugli elem della H-fetta passata).
*/
