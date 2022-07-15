
//soluzione by: Leo M.

// Versione 1:
#include<iostream>
#include<fstream>

using namespace std;



main()
{	//PRE=("input" contiene un intero 0<n_el<=40, seguito da n_el interi, seguiti o dalla coppia 'H' 0<=x<=3 o dalla coppia 'V' 0<=y<=4).
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT)
	{
		int n_el;
		INP>>n_el;
		int A[2][4][5]; //A[str][rig][col]
		
		int str_p, eus;
		str_p=n_el/(4*5);	//str_p = Strati Pieni
		eus=n_el%(4*5);		//eus = Elementi Ultimo Strato (se c'è uno strato incompleto)
		
		//riempio gli strati pieni
		for(int str=0; str<str_p; str++)
			for(int rig=0; rig<4; rig++)
				for(int col=0; col<5; col++)
					INP>>A[str][rig][col];
		
		int rig_p, eur;			
		if(eus)	//se c'è uno strato incompleto
		{
			rig_p=eus/5;	//rig_p = Righe Piene (dello strato incompleto)
			eur=eus%5;		//eur = Elementi Ultima Riga (se c'è una riga incompleta dello strato incompleto)
			
			//riempio le righe complete (dello strato incompleto)
			for(int rig=0; rig<rig_p; rig++)
				for(int col=0; col<5; col++)
					INP>>A[str_p][rig][col];
			
			if(eur)	//se c'è una riga incompleta (if inutile)
				for(int col=0; col<eur; col++)
					INP>>A[str_p][rig_p][col];
		}
		
	/*
		volendo la parte if(eus) {...} può diventare (vedi versione 2 e/o 3):
		
		rig_p=eus/5;	//rig_p = Righe Piene (dello strato incompleto)
		eur=eus%5;		//eur = Elementi Ultima Riga (se c'è una riga incompleta dello strato incompleto)
			
		//riempio le righe complete (dello strato incompleto)
		for(int rig=0; rig<rig_p && eus; rig++)
			for(int col=0; col<5; col++)
				INPA[str_p][rig][col];
		
		//riempio la riga incompleta
		for(int col=0; col<eur; col++)
			INP>>A[str_p][rig_p][col];
	*/
		
		//fetta Horizontal o Vertical, e fetta = numero della fetta desiderata
		char c;
		INP>>c;
		int fetta;
		INP>>fetta;
		
		//stampo la fetta desiderata
		if(c=='H')	//fetta Horizontal, riga fissata
		{
			//stampo gli strati pieni
			for(int str=0; str<str_p; str++)
			{
				for(int col=0; col<5; col++)
					OUT<<A[str][fetta][col]<<" ";
				OUT<<endl;
			}
					
			if(eus)	//se c'è uno strato incompleto
			{
				//se serve, stampo una delle righe complete (dello strato incompleto). [se serve -> fetta<rig_p]
				for(int col=0; col<5 && fetta<rig_p; col++)
					OUT<<A[str_p][fetta][col]<<" ";
			
				//se serve, stampo la riga incompleta (dello strato incompleto). [se serve -> fetta==rig_p]
				for(int col=0; col<eur && fetta==rig_p; col++)
						OUT<<A[str_p][fetta][col]<<" ";
				
				//se serve, stampo "V/H fetta x/y vuota". [se serve -> NO strati pieni e o fetta>rig_p o fetta=rig_p && NO riga mezza]
				if(!str_p && (fetta>rig_p || (fetta==rig_p && !eur)))
					OUT<<c<<" fetta "<<fetta<<" vuota"<<endl;
			}
		}
		else //fetta Vertical, col fissata
		{
			//stampo gli strati pieni
			for(int str=0; str<str_p; str++)
			{			
				for(int rig=0; rig<4; rig++)
					OUT<<A[str][rig][fetta]<<" ";
				OUT<<endl;
			}
					
			if(eus)	//se c'è uno strato incompleto
			{
				//stampo una delle colonne corte (o tutta -1 elem di una di quelle lunghe) (dello strato incompleto).
				for(int rig=0; rig<rig_p; rig++)
					OUT<<A[str_p][rig][fetta]<<" ";
			
				if(fetta<eur)	//se quella desiderata era una colonna lunga (dello strato incompleto) stampo l'elem mancante.
					OUT<<A[str_p][rig_p][fetta]<<" ";
				
				//se serve, stampo "V/H fetta x/y vuota". [se serve -> NO strati pieni, NO righe piene e fetta>=eur]
				if(!str_p && !rig_p && fetta>=eur)
					OUT<<c<<" fetta "<<fetta<<" vuota"<<endl;
			}
		}
		
		INP.close();
		OUT.close();
	}
	else
		cerr<<"Errore File!"<<endl;
}	//POST=("output" deve contenere gli elementi definiti della fetta specificata dalla coppia letta; nel caso la fetta non abbia elementi definiti: "V/H fetta x/y vuota").





/* Versione 2:
#include<iostream>
#include<fstream>

using namespace std;



main()
{	//PRE=("input" contiene un intero 0<n_el<=40, seguito da n_el interi, seguiti o dalla coppia 'H' 0<=x<=3 o dalla coppia 'V' 0<=y<=4).
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT)
	{
		int n_el;
		INP>>n_el;
		int A[2][4][5]; //A[str][rig][col]
		
		int str_p, eus;
		str_p=n_el/(4*5);	//str_p = Strati Pieni
		eus=n_el%(4*5);		//eus = Elementi Ultimo Strato (se c'è uno strato incompleto)
		
		//riempio gli strati pieni
		for(int str=0; str<str_p; str++)
			for(int rig=0; rig<4; rig++)
				for(int col=0; col<5; col++)
					INP>>A[str][rig][col];
		
		int rig_p, eur;			
		rig_p=eus/5;	//rig_p = Righe Piene (dello strato incompleto)
		eur=eus%5;		//eur = Elementi Ultima Riga (se c'è una riga incompleta dello strato incompleto)
			
		//se ci sono (rig_p>0), riempio le righe complete (dello strato incompleto se c'è, se non c'è rig_p=0)
		for(int rig=0; rig<rig_p; rig++)
			for(int col=0; col<5; col++)
				INP>>A[str_p][rig][col];
		
		//se c'è (eur>0), riempio la riga incompleta (dello strato incompleto se c'è, se non c'è eur=0)
		for(int col=0; col<eur; col++)
			INP>>A[str_p][rig_p][col];
		
		//fetta Horizontal o Vertical, e fetta = numero della fetta desiderata
		char c;
		INP>>c;
		int fetta;
		INP>>fetta;
		
		//stampo la fetta desiderata (indicata dalla coppia "c fetta")
		if(c=='H')	//fetta Horizontal, riga fissata (volendo, questo if è cancellabile, aggiungendo c=='H' come condiz a tutti i for e if del suo corpo)
		{
			//stampo le righe che servono degli strati pieni
			for(int str=0; str<str_p; str++)
			{
				for(int col=0; col<5; col++)
					OUT<<A[str][fetta][col]<<" ";
				OUT<<endl;
			}
					
			//se serve (fetta<rig_p), stampo una delle righe complete (dello strato incompleto se c'è, se non c'è rig_p=0)
			for(int col=0; col<5 && fetta<rig_p; col++)
				OUT<<A[str_p][fetta][col]<<" ";
			
			//se serve (fetta==rig_p), stampo la riga incompleta (dello strato incompleto se c'è, se non c'è eur=0)
			for(int col=0; col<eur && fetta==rig_p; col++)
					OUT<<A[str_p][fetta][col]<<" ";
		
			//se serve, stampo "V/H fetta x/y vuota". [se serve -> NO strati pieni e o fetta>rig_p o fetta=rig_p && NO riga incompleta]
			if(!str_p && (fetta>rig_p || (fetta==rig_p && !eur)))
				OUT<<c<<" fetta "<<fetta<<" vuota"<<endl;
		}
		else //fetta Vertical, col fissata (volendo, togliendo l'if di questo else devo aggiungere c=='V' come condiz a tutti i for e if del suo corpo)
		{
			//stampo le colonne che servono degli strati pieni
			for(int str=0; str<str_p; str++)
			{			
				for(int rig=0; rig<4; rig++)
					OUT<<A[str][rig][fetta]<<" ";
				OUT<<endl;
			}
					
			//stampo una delle colonne corte (o tutta -1 elem di una di quelle lunghe) (dello strato incompleto se c'è, se non c'è rig_p=0)
			for(int rig=0; rig<rig_p; rig++)
				OUT<<A[str_p][rig][fetta]<<" ";
		
			if(fetta<eur)	//se quella desiderata era una colonna lunga (dello strato incompleto se c'è, se non c'è eur=0) stampo l'elem mancante.
				OUT<<A[str_p][rig_p][fetta]<<" ";
				
			//se serve, stampo "V/H fetta x/y vuota". [se serve -> NO strati pieni, NO righe piene e fetta>=eur]
			if(!str_p && !rig_p && fetta>=eur)
				OUT<<c<<" fetta "<<fetta<<" vuota"<<endl;
		}
		
		INP.close();
		OUT.close();
	}
	else
		cerr<<"Errore File!"<<endl;
}	//POST=("output" deve contenere gli elementi definiti della fetta specificata dalla coppia letta; nel caso la fetta non abbia elementi definiti: "V/H fetta x/y vuota").
*/



/* Versione 3:
#include<iostream>
#include<fstream>

using namespace std;



main()
{	//PRE=("input" contiene un intero 0<n_el<=40, seguito da n_el interi, seguiti o dalla coppia 'H' 0<=x<=3 o dalla coppia 'V' 0<=y<=4).
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT)
	{
		int n_el;
		INP>>n_el;
		int A[2][4][5]; //A[str][rig][col]
		
		int str_p, eus;
		str_p=n_el/(4*5);	//str_p = Strati Pieni
		eus=n_el%(4*5);		//eus = Elementi Ultimo Strato (se c'è uno strato incompleto)
		
		//riempio gli strati pieni
		for(int str=0; str<str_p; str++)
			for(int rig=0; rig<4; rig++)
				for(int col=0; col<5; col++)
					INP>>A[str][rig][col];
		
		int rig_p, eur;			
		rig_p=eus/5;	//rig_p = Righe Piene (dello strato incompleto)
		eur=eus%5;		//eur = Elementi Ultima Riga (se c'è una riga incompleta dello strato incompleto)
			
		//se ci sono (rig_p>0), riempio le righe complete (dello strato incompleto se c'è, se non c'è rig_p=0)
		for(int rig=0; rig<rig_p; rig++)
			for(int col=0; col<5; col++)
				INP>>A[str_p][rig][col];
		
		//se c'è (eur>0), riempio la riga incompleta (dello strato incompleto se c'è, se non c'è eur=0)
		for(int col=0; col<eur; col++)
			INP>>A[str_p][rig_p][col];
		
		//fetta Horizontal o Vertical, e fetta = numero della fetta desiderata
		char c;
		INP>>c;
		int fetta;
		INP>>fetta;
		
		
		
		//stampo la fetta desiderata (indicata dalla coppia "c fetta")
		
		//stampo le righe o le colonne che servono degli strati PIENI
			for(int str=0; str<str_p; str++)
			{
				for(int col=0; col<5 && c=='H'; col++)
					OUT<<A[str][fetta][col]<<" ";
				for(int rig=0; rig<4 && c=='V'; rig++)
					OUT<<A[str][rig][fetta]<<" ";	
				OUT<<endl;
			}
			
		//se serve (fetta<rig_p), stampo una delle righe complete (dello strato incompleto se c'è, se non c'è rig_p=0)
		for(int col=0; col<5 && fetta<rig_p && c=='H'; col++)
			OUT<<A[str_p][fetta][col]<<" ";
			
		//se serve (fetta==rig_p), stampo la riga incompleta (dello strato incompleto se c'è, se non c'è eur=0)
		for(int col=0; col<eur && fetta==rig_p && c=='H'; col++)
			OUT<<A[str_p][fetta][col]<<" ";
			
		//stampo una delle colonne corte (o una di quelle lunghe, grazie al rig_p++) (dello strato incompleto se c'è, se non c'è rig_p=0 e eur=0)
		if(fetta<eur && c=='V')
			rig_p++;
		for(int rig=0; rig<rig_p && c=='V'; rig++)
			OUT<<A[str_p][rig][fetta]<<" ";
	
		//se serve, stampo "V/H fetta x/y vuota";
		//- se serve per H -> NO strati pieni e o fetta>rig_p o fetta=rig_p && NO riga incompleta
		//- se serve per V -> NO strati pieni, NO righe piene e fetta>=eur
		if(!str_p && ((fetta>rig_p || (fetta==rig_p && !eur)) || (!rig_p && fetta>=eur)))
			OUT<<c<<" fetta "<<fetta<<" vuota"<<endl;
		
		INP.close();
		OUT.close();
	}
	else
		cerr<<"Errore File!"<<endl;
}	//POST=("output" deve contenere gli elementi definiti della fetta specificata dalla coppia letta; nel caso la fetta non abbia elementi definiti: "V/H fetta x/y vuota").
*/
