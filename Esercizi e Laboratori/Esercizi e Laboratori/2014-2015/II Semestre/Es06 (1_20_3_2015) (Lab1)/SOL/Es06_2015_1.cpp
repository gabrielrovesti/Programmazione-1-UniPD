
//soluzione by: Leo M. (Teoria e Suggerimenti di Filè by: Antonio M.)

/*
ESERCIZIO DI TEORIA DEL 20-03-2015:
Ovvero: PRIMA PARTE DI ESERCIZIO 06...


Dato un array int X[3][4][5][10], nel seguito dovete rappresentare l'R-valore di X con X. Si chiede di:

i) Specificare il tipo di X e la dimensione dell'oggetto puntato (ovvero la SIZE (o TAGLIA) di tale oggetto);
ii) Specificare il valore e il tipo di (*X)+2 e di *(X+2);
iii) Specificare il valore e il tipo di *(X[-8])+8;


Potete scrivere la soluzione di questo esercizio come commento nel file in cui scriverete la soluzione dell'esercizio di programmazione che segue.


SOLUZIONE ESERCIZIO DI TEORIA:

i)		Tipo di X: int (*)[4][5][10]
		Taglia (ovvero Dimensione Oggetto Puntato): (4*5*10)*4 = 800	{L'ultimo "*4" è perchè il tipo è int, quindi 4 Byte}

ii.1)	Tipo di (*X): int (*)[5][10]
		Taglia: (5*10)*4	{int => 4 Byte!}
		
		Quindi:
		- Tipo di (*X)+2 rimane lo stesso...: int (*)[5][10]
		- Taglia: X + 2 * ((5*10)*4)
		{Per la taglia...: "X +" perchè X e *X hanno lo stesso indirizzo (ovvero l'L-valore); "2 *" perchè sommo 2 a "(*X)"; e "*4" perchè int occupa 4 Byte}

ii.2)	Tipo di X+2: int (*)[4][5][10]
		Taglia: X + 2 * ((4*5*10)*4)
		{Per il tipo...: "X+2" ha lo stesso tipo di "X"; Per la taglia...: "2 *" perchè sommo 2 a "X"; e "*4" perchè int occupa 4 Byte}
		
		Quindi:
		- Tipo di *(X+2): int (*)[5][10]
		- Taglia: X + 2 * ((5*10)*4)
		{Per il tipo...: Perchè *(X+2)==X[2] il tipo diventa il tipo di "*X"}
		{Per la taglia...: "X +" perchè X e *X hanno lo stesso indirizzo (ovvero l'L-valore); "2 *" perchè sommo 2 a "X"; e "*4" perchè int occupa 4 Byte}

iii)	*(X[-8])+8 == *(*(x-8)+8)

		Tipo di **X: int (*)[10]
		Taglia: 10*4 = 40	{Il "*4" è perchè il tipo è int, quindi 4 Byte}

		Il "-8" lo applico al tipo: int (*)[5][10]
		Mentre il "+8" lo applico al tipo: int (*)[10]
		
		Quindi:
		-> X[-8] == *(X-8)
			Tipo: int (*)[5][10]
			Taglia: X - 8 * ((5*10)*4)
		-> X[-8][8] == *(*(x-8)+8)
			Tipo: int (*)[10]
			Taglia: [X - 8 * ((5*10)*4)] + 8 * (10 * 4)
*/



//Segue: SECONDA PARTE DI ESERCIZIO 06:
//Scrivere un programma che faccia ciò che è richiesto dalla consegna dell'esercizio 06 del 20-03-2015...

//Suggerimenti forniti dal professore G. Filè per scrivere il programma richiesto...:

/*
IN>>n_el;
int *p=**X;

//Lettura da "input"//
for (int i=0; i<n_el; i++)
	IN>>p[i];

int sp=n_el/(5*8), rem=n_el%(5*8), nrpu=rem/8, ru=rem%8;
//Dove: sp=Strati_Pieni +++ rem=Resto_Elementi_Mancanti (ovvero: Elementi_Ultimo_Strato) +++//
//nrpu=Numero_Righe_Piene_Ultimo (ovvero: Righe_Piene_Ultimo_Strato (cioè lo "strato parzialmente pieno")) +++//
//ru=Riga_Ultima (ovvero: Elementi_Ultima_Riga (cioè la "riga parzialmente piena"))//


Nel MAIN --> Mi calcolo il numero di fette!
Per farlo: Controllo che n_el sia >= 4*5 (cioe' che ALMENO uno strato sia pieno!)


Pseudo-Codice by G. Filè:

if (n_el >= strato)
	rFette=5
else
	rfette= n. righe non vuote dell'unico strato parzialmente pieno

int somma=0, sommax=INT_MIN, indmax=-1;
for (int f=0; f<rfette; f++)	//Pseudo_R=(sommax e' la somma massima tra le fette da 0 a f-1, e se sono uguali... --> IndiceMassimo!!!)
{
	//Calcola somma fetta f

	//Confrontala con sommamax e indmax

}	//Vale di nuovo l'invariente R


//Calcola somma fetta f:

-> Somma fetta f sugli strati pieni...
	Chiama la funzione somma_riga(int * inizio_riga, 8)


//Sapere se la riga e' vuota o no sull'ultimo strato...e poi:

-> Invoca somma_riga(int * inizio_riga, ??? (8 oppure ru))
*/



#include<iostream>
#include<fstream>
#include<climits>

using namespace std;



//Prototipi di FUNZIONI (Dichiarazioni)

int SommaRiga(int* X, int lung);



main()
{	//PRE=("input" contiene un intero 0<n_el<=400, seguito da n_el interi).
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT)
	{
		int n_el;
		INP>>n_el;
		int X[10][5][8]; //X[str][rig][col]
		
		int str_p, eus;
		str_p=n_el/(5*8);	//str_p = Strati Pieni
		eus=n_el%(5*8);		//eus = Elementi Ultimo Strato (se c'è uno strato incompleto)
		
		//riempio gli strati pieni
		for(int str=0; str<str_p; str++)
			for(int rig=0; rig<5; rig++)
				for(int col=0; col<8; col++)
					INP>>X[str][rig][col];
		
		int rig_p, eur;			
		rig_p=eus/8;		//rig_p = Righe Piene (dello strato incompleto)
		eur=eus%8;		//eur = Elementi Ultima Riga (se c'è una riga incompleta dello strato incompleto)
			
		//se ci sono (rig_p>0), riempio le righe complete (dello strato incompleto se c'è, se non c'è rig_p=0)
		for(int rig=0; rig<rig_p; rig++)
			for(int col=0; col<8; col++)
				INP>>X[str_p][rig][col];
		
		//se c'Ã¨ (eur>0), riempio la riga incompleta (dello strato incompleto se c'è, se non c'è eur=0)
		for(int col=0; col<eur; col++)
			INP>>X[str_p][rig_p][col];
		
		/*
		//in alternativa per riempire l'array tramite puntatori
		int *p=**X;
		for(int i=0; i<n_el; i++)
			INP>>p[i];
		*/
		
		
		
		
		
		int BestSomma=INT_MIN, IndMax=-1;
		bool stop=false;
		for(int fetta=0; fetta<5 && !stop; fetta++)	//fetta = numero della fetta desiderata, scorro 1 ad 1 tutte le fette (anche quelle vuote, tanto non ci faccio niente)
		{
			int TempSomma=0;
			
			//sommo gli elem delle righe che servono degli strati pieni
			for(int str=0; str<str_p; str++)
				TempSomma=TempSomma+SommaRiga(X[str][fetta], 8);
			
			//se serve (fetta<rig_p), sommo gli elem di una delle righe complete (dello strato incompleto se c'è, se non c'è rig_p=0)
			if(fetta<rig_p)
			{
				TempSomma=TempSomma+SommaRiga(X[str_p][fetta], 8);
			}
			
			//se serve (fetta==rig_p && eur!=0), sommo gli elem della riga incompleta (dello strato incompleto se c'è, se non c'è eur=0)
			if(fetta==rig_p && eur)
			{
				TempSomma=TempSomma+SommaRiga(X[str_p][rig_p], eur);
			}
			
			//se la fetta risulta vuota (cioe' se: NO strati pieni e o fetta>rig_p o fetta=rig_p && NO riga incompleta): TempSomma=-1 e fermo tutto
			if(!str_p && (fetta>rig_p || (fetta==rig_p && !eur)))
			{
				TempSomma=-1;
				stop=true;
			}
			
			//controllo se la nuova fetta ha una somma totale degli elem maggiore della massima trovata fin'ora
			if(TempSomma>=BestSomma)
			{
				BestSomma=TempSomma;
				IndMax=fetta;
			}
		}
		
		OUT<<"H-fetta massima="<<IndMax<<endl;
		
		INP.close();
		OUT.close();
	}
	else
		cerr<<"Errore File!"<<endl;
}	//POST=("output" deve contenere la stringa "H-fetta massima=" seguito dall'indice massimo tra quelli di fette dalla somma degli elementi massima).



//Implementazioni delle FUNZIONI (Definizione)

int SommaRiga(int* X, int lung)
{	//PRE_somma=(X[0..lung-1] sono definiti e lung>0).
	int somma=0;
	
	for(int i=0; i<lung; i++)	//con l'aritm dei punt, scorro e sommo tutti gli elem (definiti) della riga
		somma=somma+*(X+1*i);
	
	return somma;	//ritorno la somma di tutti gli elem (definiti) della riga su cui viene invocata la funz SommaRiga
}	//POST_somma=(la funzione restituisce la somma degli elementi in X[0..lung-1]).
