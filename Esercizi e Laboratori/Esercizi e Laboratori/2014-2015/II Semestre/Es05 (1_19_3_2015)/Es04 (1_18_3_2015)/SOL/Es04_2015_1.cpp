
//soluzione by: Leo M.

// Versione 1:
#include<iostream>
#include<fstream>

using namespace std;



//Prototipi di FUNZIONE (Dichiarazione)

void StampaRiga(int *X, int lung, ofstream &OUT);

void StampaStrato(int *X, int es, int rig, int col, ofstream &OUT);



main()
{	//PRE=("input" contiene in sequenza: 0<n_el<=400, n_el numeri interi, str>0, rig>0, col>0).
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT)
	{
		int n_el;
		INP>>n_el;
		int X[400];
		
		//inserisco gli n_el elementi nell'array
		for(int i=0; i<n_el; i++)
			INP>>X[i];
			
		//leggo i 3 limiti della "vista"
		int str, rig, col;
		INP>>str>>rig>>col;
		
		
		//Gestione Strati
		//Strati Pieni
		int es=rig*col, str_p=n_el/es;	//es=ElementiStrato, str_p=StratiPieni
		for(int i=0; i<str_p && i<str; i++)
		{
			OUT<<"strato "<<i<<endl;
			StampaStrato(X+i*es, es, rig, col, OUT);
		}
		
		//Strato Incompleto
		int eus=n_el%es;	//eus=ElementiUltimoStrato
		if(eus && str_p<str)
		{
			OUT<<"strato "<<str_p<<endl;
			StampaStrato(X+str_p*es, eus, rig, col, OUT);
		}
		
		INP.close();
		OUT.close();
	}
	else
		cerr<<"Errore File!"<<endl;
}	//POST=( ).



//Implementazione delle FUNZIONI (Definizione)

void StampaRiga(int *X, int lung, ofstream &OUT)
{	//PRE=(X è un punt all'inizio della riga da stampare, tale riga ha lung elementi definiti).
	for(int i=0; i<lung; i++)
		OUT<<*(X+i)<<" "; //in alternativa: OUT<<X[i]<<" ";
	
	
}	//POST=( ).

void StampaStrato(int *X, int es, int rig, int col, ofstream &OUT)
{	//PRE=( ).
	//Gestione Righe
	//Righe Piene
	int er=col, rig_p=es/er;	//er=ElementiRiga, rig_p=RighePiene
	for(int i=0; i<rig_p; i++)
	{
		OUT<<"r"<<i<<":";
		StampaRiga(X+i*er, er, OUT);
		OUT<<endl;
	}
		
	//Riga Incompleta
	int eur=es%er;	//eur=ElementiUltimaRiga
	if(eur)
	{
		OUT<<"r"<<rig_p<<":";
		StampaRiga(X+rig_p*er, eur, OUT);
		OUT<<endl;
	}
	//return;
}	//POST=( ).





/* Versione 2:
#include<iostream>
#include<fstream>

using namespace std;



//Prototipi di FUNZIONE (Dichiarazione)

void StampaRiga(int *X, int lung, ofstream &OUT);

void StampaStrato(int *X, int es, int rig, int col, ofstream &OUT);



main()
{	//PRE=("input" contiene in sequenza: 0<n_el<=400, n_el numeri interi, str>0, rig>0, col>0).
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT)
	{
		int n_el;
		INP>>n_el;
		int X[400];
		
		//inserisco gli n_el elementi nell'array
		for(int i=0; i<n_el; i++)
			INP>>X[i];
			
		//leggo i 3 limiti della "vista"
		int str, rig, col;
		INP>>str>>rig>>col;
		
		
		//Gestione Strati
		//Strati Pieni
		int str_p=n_el/(rig*col);	//str_p=StratiPieni
		for(int i=0; i<str_p && i<str; i++)
		{
			OUT<<"strato "<<i<<endl;
			StampaStrato(X+i*rig*col, rig*col, rig, col, OUT);
		}
		
		//Strato Incompleto
		if((n_el%(rig*col)) && (str_p<str))
		{
			OUT<<"strato "<<str_p<<endl;
			StampaStrato(X+str_p*rig*col, (n_el%(rig*col)), rig, col, OUT);
		}
		
		INP.close();
		OUT.close();
	}
	else
		cerr<<"Errore File!"<<endl;
}	//POST=( ).



//Implementazione delle FUNZIONI (Definizione)

void StampaRiga(int *X, int lung, ofstream &OUT)
{	//PRE=(X è un punt all'inizio della riga da stampare, tale riga ha lung elementi definiti).
	for(int i=0; i<lung; i++)
		OUT<<*(X+i)<<" "; //in alternativa: OUT<<X[i]<<" ";
	
	
}	//POST=( ).

void StampaStrato(int *X, int es, int rig, int col, ofstream &OUT)
{	//PRE=( ).
	//Gestione Righe
	//Righe Piene
	int rig_p=es/col;	//er=ElementiRiga, rig_p=RighePiene
	for(int i=0; i<rig_p; i++)
	{
		OUT<<"r"<<i<<":";
		StampaRiga(X+i*col, col, OUT);
		OUT<<endl;
	}
		
	//Riga Incompleta
	if(es%col)
	{
		OUT<<"r"<<rig_p<<":";
		StampaRiga(X+rig_p*col, es%col, OUT);
		OUT<<endl;
	}
	//return;
}	//POST=( ).
*/
