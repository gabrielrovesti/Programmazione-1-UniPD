
//soluzione by: Leo M.

// Versione 1:
#include<iostream>
#include<fstream>

using namespace std;



main()
{	//PRE=("input" contiene: i 4 interi str>0, rig>0, col>0 ed 0<n_el<=400, seguiti da n_el interi).
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT)
	{
		
	//Inizializzazione
		int str, rig, col, n_el;
		INP >> str >> rig >> col >> n_el;
		int X[400]; //Y[str][rig][col]
		
		int vFet_p, euf, col_p, euc;
		vFet_p=n_el/(rig*str);	//vFet_p = V-FettePiene
		euf=n_el%(rig*str);		//euf=ElementiUltimaFetta (se incompleta)
		col_p=euf/rig;			//col_p=ColonnePiene (della V-Fetta Incompleta)
		euc=euf%rig;			//euc=ElementiUltimaColonna (della V-Fetta Incompleta)
	
	
	
	for(int l=0; l<400; l++)
		*(X+l)=-1;
	
	//Riempimento
		//Gestione V-Fette Piene
		for(int i=0; i<vFet_p && i<col; i++)	//scorro v-fette piene (con i<col mi fermo se le fette legali sono ad es 3 e le potenziali piene sono ad es 8)
			for(int j=0; j<str; j++)			//scorro le righe (colonne) della v-fetta piena
				for(int k=0; k<rig; k++)		//scorro gli elem delle singole righe (colonne) della v-fetta piena
					INP>> *(X + k*col + j*rig*col + i);
		
		
		//Gestione eventuale V-Fetta Incompleta (fetta fissata = vFet_p)
		
		//Gestione righe (colonne) piene della V-Fetta Incompleta
		for(int j=0; j<col_p && euf && vFet_p<col; j++)	//vFet_p<col perchè magari le fette complete hanno già riempito tutto l'array
			for(int k=0; k<rig; k++)
				INP>> *(X + k*col + j*rig*col + vFet_p);
		
		//Gestione della riga (colonna) incompleta della V-Fetta Incompleta (riga (colonna) fissata = col_p)
		for(int k=0; k<euc && vFet_p<col; k++)	//comprende già automaticamente la condizione "if(euc)", vFet_p<col perchè magari le fette complete hanno già riempito tutto l'array
			INP>> *(X + k*col + col_p*rig*col + vFet_p);
		
		
		
	//Stampa
		/*
		Divido il problema della stampa per strati (e righe) come segue:
		
		- strati "pieni", cioè strati che hanno il massimo numero di colonne e queste sono tutte complete;
			gli strati pieni sono esattamente col_p ed il numero di colonne di questi strati è: vFet_p+1
					
		- strato "ibrido", cioè lo strato che ha il massimo numero di colonne ma l'ultima ha solo "euc" elementi:
			if(euc) -> esiste ed ha indice col_p
			else -> non esiste
			le prime euc sue righe hanno vFet_p+1 elementi e le altre ne hanno vFet_p
		
		- strati "poveri", cioè strati che hanno una colonna in meno:
			sono gli strati non vuoti che restano, hanno vFet_p colonne tutte complete (esistono solo se vFet_p>0)
		
		- strati "vuoti", non hanno neanche un elemento e non sono da stampare, esistono solo se vFet_p=0.
		*/
	
		
		int s=0;	//occorre dichiararlo qua perchè serve anche più in giù
			
		//Stampa Strati "Pieni"
		for(s=0; s<col_p && vFet_p<col; s++)	//scorro strati (vFet_p<col bound per la legalità della stampa, altrimenti l'array è tutto pieno)
		{
			OUT<<"strato "<<s<<endl;		
			for(int r=0; r<rig; r++)	//scorro righe
			{
				for(int c=0; c<vFet_p+1; c++)
					OUT<< *(X + c + r*col + s*rig*col)<<" ";
				OUT<<endl;
			}		
		}
		
		//Stampa (eventuale) Strato "Ibrido"
		if(euc)
		{
			OUT<<"strato "<<s<<endl;
			for(int r=0; r<euc && vFet_p<col; r++)	//stampo le prime euc righe che hanno vFet_p+1 elementi
			{
				for(int c=0; c<vFet_p+1; c++)
					OUT<< *(X + c + r*col + s*rig*col)<<" ";
				OUT<<endl;
			}
			for(int r=euc; r<rig && vFet_p<col && vFet_p; r++)	//stampo le restanti rig-euc righe di questo strato che hanno vFet_p elementi (vFet_p per evitare cicli inutili)
			{
				for(int c=0; c<vFet_p; c++)
					OUT<< *(X + c + r*col + s*rig*col)<<" ";
				OUT<<endl;
			}
			s++;	//sistemo l'indice dello strato aumentandolo di uno dato che ho stampato lo strato ibrido
		}
		
		//Stampa Strati "Poveri"
		for( ; s<str && vFet_p; s++)	//scorro strati (necessario vFet_p per sapere che esistono strati "poveri", altrimenti stamperei "strato x" anche quando vuoto)
		{
			OUT<<"strato "<<s<<endl;
			for(int r=0; r<rig; r++)	//scorro righe
			{
				for(int c=0; c<vFet_p && c<col; c++)	//nel caso in cui tutte le fette siano piene (n_el>=str*rig*col) c<col garantisce di non sforare
					OUT<< *(X + c + r*col + s*rig*col)<<" ";
				OUT<<endl;
			}
		}
		
		//stampo la stringa "fine"
		OUT<<"fine"<<endl;
		
		
		
	//Chiusura
		INP.close();
		OUT.close();
	}
	else
		cerr<<"Errore File!"<<endl;
}	//POST=(Y contiene gli n_el elementi inseriti per Vfette; poi solo gli elem definiti di Y vengono stampati su "output" per strati (e righe)).





/* Versione 2:
#include<iostream>
#include<fstream>

using namespace std;



main()
{	//PRE=("input" contiene: i 4 interi str>0, rig>0, col>0 ed 0<n_el<=400, seguiti da n_el interi).
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT)
	{
		
	//Inizializzazione
		int str, rig, col, n_el;
		INP >> str >> rig >> col >> n_el;
		int X[400]; //Y[str][rig][col]
		
		int vFet_p, euf, col_p, euc;
		vFet_p=n_el/(rig*str);	//vFet_p = V-FettePiene
		euf=n_el%(rig*str);		//euf=ElementiUltimaFetta (se incompleta)
		col_p=euf/rig;			//col_p=ColonnePiene (della V-Fetta Incompleta)
		euc=euf%rig;			//euc=ElementiUltimaColonna (della V-Fetta Incompleta)
	
	
	
	for(int l=0; l<400; l++)
		*(X+l)=-1;
	
	//Riempimento
		//Gestione V-Fette Piene
		for(int i=0; i<vFet_p && i<col; i++)	//scorro v-fette piene (con i<col mi fermo se le fette legali sono ad es 3 e le potenziali piene sono ad es 8)
			for(int j=0; j<str; j++)	//scorro le righe (colonne) della v-fetta piena
				for(int k=0; k<rig; k++)	//scorro gli elem delle singole righe (colonne) della v-fetta piena
					INP>> *(X + k*col + j*rig*col + i);
		
		
		//Gestione eventuale V-Fetta Incompleta (fetta fissata = vFet_p)
		
		//Gestione righe (colonne) piene della V-Fetta Incompleta
		for(int j=0; j<col_p && euf && vFet_p<col; j++)	//vFet_p<col perchè magari le fette complete hanno già riempito tutto l'array
			for(int k=0; k<rig; k++)
				INP>> *(X + k*col + j*rig*col + vFet_p);
		
		//Gestione della riga (colonna) incompleta della V-Fetta Incompleta (riga (colonna) fissata = col_p)
		for(int k=0; k<euc && vFet_p<col; k++)	//comprende già automaticamente la condizione "if(euc)", vFet_p<col perchè magari le fette complete hanno già riempito tutto l'array
			INP>> *(X + k*col + col_p*rig*col + vFet_p);
		
		
		
	//Stampa
	
//		Divido il problema della stampa per strati (e righe) come segue:
//		
//		- strati "pieni", cioè strati che hanno il massimo numero di colonne e queste sono tutte complete;
//			gli strati pieni sono esattamente col_p ed il numero di colonne di questi strati è: vFet_p+1
//					
//		- strato "ibrido", cioè lo strato che ha il massimo numero di colonne ma l'ultima ha solo "euc" elementi:
//			if(euc) -> esiste ed ha indice col_p
//			else -> non esiste
//			le prime euc sue righe hanno vFet_p+1 elementi e le altre ne hanno vFet_p
//		
//		- strati "poveri", cioè strati che hanno una colonna in meno:
//			sono gli strati non vuoti che restano, hanno vFet_p colonne tutte complete (esistono solo se vFet_p>0)
//		
//		- strati "vuoti", non hanno neanche un elemento e non sono da stampare, esistono solo se vFet_p=0.

	
		
		int s=0;	//occorre dichiararlo qua perchè serve anche più in giù
			
		//Stampa Strati "Pieni"
		for(s=0; s<col_p && vFet_p<col; s++)	//scorro strati (vFet_p<col bound per la legalità della stampa)
		{
			OUT<<"strato "<<s<<endl;		
			for(int r=0; r<rig; r++)	//scorro righe
			{
				for(int c=0; c<vFet_p+1; c++)
					OUT<< *(X + c + r*col + s*rig*col)<<" ";
				OUT<<endl;
			}		
		}
		
		//Stampa (eventuale) Strato "Ibrido"
		if(euc)
		{
			OUT<<"strato "<<s<<endl;
			for(int r=0; r<euc && vFet_p<col; r++)	//stampo le prime euc righe che hanno vFet_p+1 elementi
			{
				for(int c=0; c<vFet_p+1; c++)
					OUT<< *(X + c + r*col + s*rig*col)<<" ";
				OUT<<endl;
			}
			for(int r=euc; r<rig && vFet_p<col; r++)	//stampo le restanti rig-euc righe di questo strato che hanno vFet_p elementi
			{
				for(int c=0; c<vFet_p; c++)
					OUT<< *(X + c + r*col + s*rig*col)<<" ";
				OUT<<endl;
			}
			s++;	//sistemo l'indice dello strato aumentandolo di uno dato che ho stampato lo strato ibrido
		}
		
		//Stampa Strati "Poveri"
		for( ; s<str; s++)	//scorro strati
		{
			OUT<<"strato "<<s<<endl;
			for(int r=0; r<rig; r++)	//scorro righe
			{
				for(int c=0; c<vFet_p && c<col; c++)	//nel caso in cui tutte le fette siano piene (n_el>=str*rig*col) c<col garantisce di non sforare
					OUT<< *(X + c + r*col + s*rig*col)<<" ";
				OUT<<endl;
			}
		}
		
		//stampo la stringa "fine"
		OUT<<"fine"<<endl;
		
		
		
	//Chiusura
		INP.close();
		OUT.close();
	}
	else
		cerr<<"Errore File!"<<endl;
}	//POST=(Y contiene gli n_el elementi inseriti per Vfette; poi solo gli elem definiti di Y vengono stampati su "output" per strati (e righe)).
*/
