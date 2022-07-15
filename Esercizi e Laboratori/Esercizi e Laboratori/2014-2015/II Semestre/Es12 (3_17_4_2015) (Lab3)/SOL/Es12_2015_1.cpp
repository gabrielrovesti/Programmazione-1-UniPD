
//soluzione by: Leo M.

// Versione 1:
#include <iostream>
#include<fstream>

using namespace std;

int calcola_dist(int fetta, int e, int lim2, int lim3, int n_el);

main()
{	//PRE=(input contiene nell'ordine, lim1>0, lim2>0, lim3>0, 0<n_el<=400, n_el valori).
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT) 
	{ 
		int X[400], n_el, lim1, lim2, lim3;
		
		for(int i=0; i<400; i++)
			X[i]=-1;
			
		INP >> lim1 >> lim2 >> lim3 >> n_el;
		
		for(int i=0; i<n_el; i++)
			INP >> X[i];
		
		if(n_el>lim1*lim2*lim3)
			n_el=lim1*lim2*lim3;
			
		for(int q=0; q<3; q++)	//legge le tre quadruple
		{
			int f, e[3];
			INP >> f >> e[0] >> e[1] >> e[2];

			for(int j=0; j<3; j++)
			{
				int d=calcola_dist(f, e[j], lim2, lim3, n_el); //questa e' da fare (restituisce -1 a indicare che l'elemento e[j] non c'e' nella V-fetta f)
				if(d==-1)
					OUT<<e[j]<<" elemento inesistente della V-fetta "<<f<<" ";
				else
					OUT<<d<<" ";
			}
			OUT<<endl;
		}
		
		INP.close();
		OUT.close(); 
	}
	else
		cout<<"errore con i files";
}


int calcola_dist(int fetta, int e, int lim2, int lim3, int n_el)
{
	int dist, lung_tas, n_str, n_rig;
	lung_tas=n_el/(lim2*lim3);
	n_str=(e%lung_tas);
	n_rig=(e/lung_tas);
	
	
	if(e>=( (n_el/(lim2*lim3))*lim2 ) )
		dist=-1;
	else
		dist = n_str*lim2*lim3 + n_rig*lim3 + fetta;
	
	return dist;
}





/* Versione 2:
#include<iostream>
#include<fstream>

using namespace std;

int calcola_dist(int fetta, int e, int lim2, int lim3, int n_el);

int lung_tas(int tas, int lim2, int lim3, int fetta, int n_el);

main()
{	//PRE=(input contiene nell'ordine, lim1>0, lim2>0, lim3>0, 0<n_el<=400, n_el valori).
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT) 
	{ 
		int X[400], n_el, lim1, lim2, lim3;
		
		for(int i=0; i<400; i++)
			X[i]=-1;
			
		INP >> lim1 >> lim2 >> lim3 >> n_el;
		
		for(int i=0; i<n_el; i++)
			INP >> X[i];
		
		if(n_el>lim1*lim2*lim3)
			n_el=lim1*lim2*lim3;
			
		for(int q=0; q<3; q++)	//legge le tre quadruple
		{
			int f, e[3];
			INP >> f >> e[0] >> e[1] >> e[2];

			for(int j=0; j<3; j++)
			{
				int d=calcola_dist(f, e[j], lim2, lim3, n_el); //questa e' da fare (restituisce -1 a indicare che l'elemento e[j] non c'e' nella V-fetta f)
				if(d==-1)
					OUT<<e[j]<<" elemento inesistente della V-fetta "<<f<<" ";
				else
					OUT<<d<<" ";
			}
			OUT<<endl;
		}
		
		INP.close();
		OUT.close(); 
	}
	else
		cout<<"errore con i files";
}




int lung_tas(int tas, int lim2, int lim3, int fetta, int n_el)
{	//PRE=().
	int l_tas;
	int str_p, eus, rig_p, eur;
	str_p=n_el/(lim2*lim3);	//str_p=StratiPieni
	eus=n_el%(lim2*lim3);	//eus=ElementiUltimoStrato
	rig_p=eus/lim3;			//rig_p=RighePiene (dell'eventuale strato incompleto)
	eur=eus%lim3;			//eur=ElementiUltimaRiga (dell'eventuale strato incompleto)
	
	l_tas=str_p;	//un qualunque tassello di certo avrà almeno tanti elementi quanti sono gli strati pieni
	
	
	// ora le possibilità sono:
	//	a) sono in una fetta<eur:
	//		quindi i primi rig_p+1 tasselli hanno lunghezza l_tas+1, i restanti l_tas;
	//	b) sono in una fetta>=eur
	//		quindi i primi rig_p tasselli hanno lunghezza l_tas+1, i restanti l_tas;

	
	if(fetta<eur)
	{
		if(tas<rig_p+1)	//+1 per la riga di indice rig_p, che contiene gli eur elementi
			l_tas++;
	}
	else	//fetta>=eur
	{
		if(tas<rig_p)
			l_tas++;
	}
	
	
	
// 	  quanto segue serve per verificare indirettamente se la v-fetta ha un indice valido o meno, nel caso la v-fetta sia fuori dai baound dell'array (o fuori dagli elementi definiti)
//	  forza la restituzione di 0 come lunghezza tassello, così facendo e non viene mai decrementato e il ciclo della funzione chiamante termina come se il tassello fosse troppo
//	  lungo, restituendo quindi al main -1.
	if((rig_p) || (str_p))
	{
		if(fetta>=lim3)
		{
			l_tas=0;
		}
	}
	else
	{
		if(fetta>=eur)
		{
			l_tas=0;
		}
	}
		
	
	return l_tas;
}	//POST=().


int calcola_dist(int fetta, int e, int lim2, int lim3, int n_el)
{	//PRE=().
	bool stop=false;
	int dist, tas=0;
	for( ; tas<lim2 && !stop; tas++)	//tas è l'indice del tassello che sto controllando
		{
			int l_tas=lung_tas(tas, lim2, lim3, fetta, n_el);
			if(e>=l_tas)
				e=e-l_tas;
			else
				stop=true;
			
		}
//		 ora:
//			(se stop==true):
//			- "e" è l'indice dell'elem nel suo tassello (cioè anche il numero di strati pieni che stanno sopra quell'elem);
//			- "tas" è l'indice del tassello successivo a quello in cui c'è l'elem (tas-1 è il numero di righe complete che ci sono sopra l'elem, all'interno dello strato in cui si trova).
//			(se stop==false):
//			- mi sono fermato perchè e è "troppo lungo" ed ho finito i tasselli da contare;
//			- devo ritornare -1.

			
	if(!stop)	//stop==false
		dist=-1;
	else	//stop==true -> l'elem di indice "e" esiste, ne calcolo la distanza da restituire
	{
		dist = e*lim2*lim3 + (tas-1)*lim3 + fetta;	//tas-1 perchè è il numero di righe complete che stanno sopra la posiz dell'elemento d'interesse su quello strato
	}
	
	return dist;
}	//POST=().
*/
