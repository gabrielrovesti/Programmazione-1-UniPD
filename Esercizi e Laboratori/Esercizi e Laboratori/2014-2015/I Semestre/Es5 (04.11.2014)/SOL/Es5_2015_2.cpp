
//soluzione by: Leo M.

// Versione 1
#include<iostream>
using namespace std;

int main()
{	//PRE
	int T[100], P[20], dimT, dimP;
	cin >> dimT >> dimP;
	
	int t=0;
	while(t<dimT)	//riempio T[0..dimT-1]
	{
		cin >> T[t];
		t++;
	}
	
	int p=0;
	while(p<dimP)	//riempio P[0..dimP-1]
	{
		cin >> P[p];
		p++;
	}
	
	t=0;										//reset indice t per scorrere T
	int MIS=dimT, posiz=-1;						//MIS=dimT perchè sia un valore molto alto, va bene qualsiasi>dimP-1; posiz=-1 perchè tale posizione in T non esiste
	bool stopP;
	while(t<=dimT-dimP)							//"!(dimT-t<dimP)" inutile entrare se dimT<dimP e/o se non avanzano abbastanza elementi in T per poter contenere P; da "t<dimT && !(dimT-t<dimP)" con DeMorgan si ha: "t<=dimT-dimP"
	{
		p=0;									//reset indice p per scorrere P
		int m=t, MIStemp=0;						//contatori ausiliari
		stopP=false;							//stopP blocca se per 2 elem consecutivi di T NON c'è match con l'elem di P in esame
		while(p<dimP && !stopP && m+p<dimT)		//m+p<dimT bound check per non sforare nella lettura degli elem di T
		{
			if(T[m+p]==P[p])					//gli elem matchano? bene passiamo ai prossimi
				p++;
			else
			{
				m++;							//controlliamo se dopo il mismatch dell'elem di P in esame con un elem di T ne segue subito un altro
				if(m+p<dimT && T[m+p]==P[p])	//m+p<dimT bound check, va fatto come primo controllo, altrimenti potremmo leggere elementi fuori da T
				{
					p++;						//questo è quello buono, posso quindi andare avanti
					MIStemp++;					//incremento il contat (temporaneo) dei mismatch (isolati) trovati fin'ora
				}
				else							//ho trovato in T due mismatch consecutivi per l'elem di P in esame -> non c'è M1MIS -> fermo il ciclo interno
					stopP=true;
			}
		}
		if(p==dimP && MIStemp<MIS)				//se mi fermo perchè p==dimP ho matchato tutto P ed ho MIStemp MIS -> aggiorno la posiz d'inizio del match col minor MIS
		{
			posiz=t;
			MIS=MIStemp;
			if(!MIS)
				t=dimT;							//se c'è match perfetto (MIS=0) di meglio non c'è, falsifico le cose per fermarmi (NB: la cosa giusta era introdurre un bool stopT da mettere nel test del I while)
		}
		t++;
	}
	
	if(MIS==dimT)
		cout<<"Match (M1MIS) NON trovato."<<endl;
	else
		cout<<"Match (M1MIS) trovato."<<endl<<"inizio: "<<posiz<<" con "<<MIS<<" miss."<<endl;
}	//POST



/*
PRE=(cin contiene dimT e dimP (0<dimT<=100 e 0<dimP<=20), seguiti da dimT+dimP valori interi qualsiasi).

POST=(se c'è almeno un M1MIS di P in T, il programma stampa l'inizio del M1MIS a MIS minimo (e quello che inizia prima se ce ne fossero diversi minimi)
e il valore del suo MIS) && (se non esiste M1MIS di P in T allora il programma scrive su cout "nessun M1MIS").
*/




/* Versione 2:
#include<iostream>
using namespace std;

int main()
{	//PRE
	int T[100], P[20], dimT, dimP;
	cin >> dimT >> dimP;
	
	int t=0;
	while(t<dimT)	//riempio T[0..dimT-1]
	{
		cin >> T[t];
		t++;
	}
	
	int p=0;
	while(p<dimP)	//riempio P[0..dimP-1]
	{
		cin >> P[p];
		p++;
	}
	
	t=0;										//reset indice t per scorrere T
	int MIS=dimT, posiz=-1;						//MIS=dimT perchè sia un valore molto alto, va bene qualsiasi>dimP-1; posiz=-1 perchè tale posizione in T non esiste
	bool stopP;
	while(t<=dimT-dimP && MIS>0)				//"!(dimT-t<dimP)" inutile entrare se dimT<dimP e/o se non avanzano abbastanza elementi in T per poter contenere P; da "t<dimT && !(dimT-t<dimP)" con DeMorgan si ha: "t<=dimT-dimP"
	{											//se c'è match perfetto (MIS=0) di meglio non c'è quindi mi posso fermare
		p=0;									//reset indice p per scorrere P
		int m=t;								//indice ausiliario (essendo che "salta" i mismatch isolati funge anche da contatore (modulo t))
		stopP=false;							//stopP blocca se per 2 elem consecutivi di T NON c'è match con l'elem di P in esame
		while(p<dimP && !stopP && m+p<dimT)		//m+p<dimT bound check per non sforare nella lettura degli elem di T
		{
			if(T[m+p]==P[p])					//gli elem matchano? bene passiamo ai prossimi
				p++;
			else
			{
				m++;							//controlliamo se dopo il mismatch dell'elem di P in esame con un elem di T ne segue subito un altro
				if(m+p<dimT && T[m+p]==P[p])	//m+p<dimT bound check, va fatto come primo controllo, altrimenti potremmo leggere elementi fuori da T
					p++;						//questo è quello buono, posso quindi andare avanti
				else							//ho trovato in T due mismatch consecutivi per l'elem di P in esame -> non c'è M1MIS -> fermo il ciclo interno
					stopP=true;
			}
		}
		
//		if(p==dimP) {
//			if(T[t]!=P[0])
//				cout<<"start at: "<<t<<" con "<<m-t<<" miss."<<" <- THIS"<<endl;
//			else
//				cout<<"start at: "<<t<<" con "<<m-t<<" miss."<<endl;
//		//questo condizionale (se abilitato) mostra come il programma considera "match" anche quelli con un miss prima del pattern.
//		}
		
		if(p==dimP && m-t<MIS)				//se mi fermo perchè p==dimP ho matchato tutto P ed ho m-t MIS -> aggiorno la posiz d'inizio del match se ho un MIS minore
		{
			posiz=t;
			MIS=m-t;
		}
		t++;
	}
	
	if(posiz==-1)
		cout<<"Match (M1MIS) NON trovato."<<endl;
	else
		cout<<"Match (M1MIS) trovato."<<endl<<"inizio: "<<posiz<<" con "<<MIS<<" miss."<<endl;
}	//POST




//PRE=(cin contiene dimT e dimP (0<dimT<=100 e 0<dimP<=20), seguiti da dimT+dimP valori interi qualsiasi).

//POST=(se c'è almeno un M1MIS di P in T, il programma stampa l'inizio del M1MIS a MIS minimo (e quello che inizia prima se ce ne fossero diversi minimi)
//e il valore del suo MIS) && (se non esiste M1MIS di P in T allora il programma scrive su cout "nessun M1MIS").
*/



/* Versione 3:
#include<iostream>
using namespace std;

int main()
{	//PRE
	int T[100], P[20], dimT, dimP;
	cin >> dimT >> dimP;
	
	int t=0;
	while(t<dimT)	//riempio T[0..dimT-1]
	{
		cin >> T[t];
		t++;
	}
	
	int p=0;
	while(p<dimP)	//riempio P[0..dimP-1]
	{
		cin >> P[p];
		p++;
	}
	
	t=0;										//reset indice t per scorrere T
	int MIS=dimT, posiz=-1;						//MIS=dimT perchè sia un valore molto alto, va bene qualsiasi>dimP-1; posiz=-1 perchè tale posizione in T non esiste
	bool stopP;
	while(t<=dimT-dimP && MIS>0)				//"!(dimT-t<dimP)" inutile entrare se dimT<dimP e/o se non avanzano abbastanza elementi in T per poter contenere P; da "t<dimT && !(dimT-t<dimP)" con DeMorgan si ha: "t<=dimT-dimP"
	{											//se c'è match perfetto (MIS=0) di meglio non c'è quindi mi posso fermare
		if(T[t]==P[0])
		{
			p=0;									//reset indice p per scorrere P
			int m=t;								//indice ausiliario (essendo che "salta" i mismatch isolati funge anche da contatore (modulo t))
			stopP=false;							//stopP blocca se per 2 elem consecutivi di T NON c'è match con l'elem di P in esame
			while(p<dimP && !stopP && m+p<dimT)		//m+p<dimT bound check per non sforare nella lettura degli elem di T
			{
				if(T[m+p]==P[p])					//gli elem matchano? bene passiamo ai prossimi
					p++;
				else
				{
					m++;							//controlliamo se dopo il mismatch dell'elem di P in esame con un elem di T ne segue subito un altro
					if(m+p<dimT && T[m+p]==P[p])	//m+p<dimT bound check, va fatto come primo controllo, altrimenti potremmo leggere elementi fuori da T
						p++;						//questo è quello buono, posso quindi andare avanti
					else							//ho trovato in T due mismatch consecutivi per l'elem di P in esame -> non c'è M1MIS -> fermo il ciclo interno
						stopP=true;
				}
			}
		
			if(p==dimP && m-t<MIS)				//se mi fermo perchè p==dimP ho matchato tutto P ed ho m-t MIS -> aggiorno la posiz d'inizio del match se ho un MIS minore
			{
				posiz=t;
				MIS=m-t;
			}
		}
		t++;
	}
	
	if(posiz==-1)
		cout<<"Match (M1MIS) NON trovato."<<endl;
	else
		cout<<"Match (M1MIS) trovato."<<endl<<"inizio: "<<posiz<<" con "<<MIS<<" miss."<<endl;
}	//POST




//PRE=(cin contiene dimT e dimP (0<dimT<=100 e 0<dimP<=20), seguiti da dimT+dimP valori interi qualsiasi).

//POST=(se c'è almeno un M1MIS di P in T, il programma stampa l'inizio del M1MIS a MIS minimo (e quello che inizia prima se ce ne fossero diversi minimi)
//e il valore del suo MIS) && (se non esiste M1MIS di P in T allora il programma scrive su cout "nessun M1MIS").
*/



/* Versione 4:
#include<iostream>
using namespace std;

int main()
{	//PRE
	int T[100], P[20], dimT, dimP;
	cin >> dimT >> dimP;
	
	int t=0;
	while(t<dimT)	//riempio T[0..dimT-1]
	{
		cin >> T[t];
		t++;
	}
	
	int p=0;
	while(p<dimP)	//riempio P[0..dimP-1]
	{
		cin >> P[p];
		p++;
	}
	
	t=0;										//reset indice t per scorrere T
	int MIS=dimT, posiz=-1;						//MIS=dimT perchè sia un valore molto alto, va bene qualsiasi>dimP-1; posiz=-1 perchè tale posizione in T non esiste
	bool stopP;
	while(t<=dimT-dimP && MIS>0)				//"!(dimT-t<dimP)" inutile entrare se dimT<dimP e/o se non avanzano abbastanza elementi in T per poter contenere P; da "t<dimT && !(dimT-t<dimP)" con DeMorgan si ha: "t<=dimT-dimP"
	{											//se c'è match perfetto (MIS=0) di meglio non c'è quindi mi posso fermare
		p=0;									//reset indice p per scorrere P
		int m=t;								//indice ausiliario (essendo che "salta" i mismatch isolati funge anche da contatore (modulo t))
		stopP=false;							//stopP blocca se per 2 elem consecutivi di T NON c'è match con l'elem di P in esame
		while(p<dimP && !stopP && m+p<dimT && T[t]==P[0])		//m+p<dimT bound check per non sforare nella lettura degli elem di T
		{
			if(T[m+p]==P[p])					//gli elem matchano? bene passiamo ai prossimi
				p++;
			else
			{
				m++;							//controlliamo se dopo il mismatch dell'elem di P in esame con un elem di T ne segue subito un altro
				if(m+p<dimT && T[m+p]==P[p])	//m+p<dimT bound check, va fatto come primo controllo, altrimenti potremmo leggere elementi fuori da T
					p++;						//questo è quello buono, posso quindi andare avanti
				else							//ho trovato in T due mismatch consecutivi per l'elem di P in esame -> non c'è M1MIS -> fermo il ciclo interno
					stopP=true;
			}
		}
		
		if(p==dimP && m-t<MIS)					//se mi fermo perchè p==dimP ho matchato tutto P ed ho m-t MIS -> aggiorno la posiz d'inizio del match se ho un MIS minore
		{
			posiz=t;
			MIS=m-t;
		}
		t++;
	}
	
	if(posiz==-1)
		cout<<"Match (M1MIS) NON trovato."<<endl;
	else
		cout<<"Match (M1MIS) trovato."<<endl<<"inizio: "<<posiz<<" con "<<MIS<<" miss."<<endl;
}	//POST




//PRE=(cin contiene dimT e dimP (0<dimT<=100 e 0<dimP<=20), seguiti da dimT+dimP valori interi qualsiasi).

//POST=(se c'è almeno un M1MIS di P in T, il programma stampa l'inizio del M1MIS a MIS minimo (e quello che inizia prima se ce ne fossero diversi minimi)
//e il valore del suo MIS) && (se non esiste M1MIS di P in T allora il programma scrive su cout "nessun M1MIS").
*/



/* Versione 5:
#include<iostream>
using namespace std;

int main()
{	//PRE
	int T[100], P[20], dimT, dimP;
	cin >> dimT >> dimP;
	
	int t=0;
	while(t<dimT)	//riempio T[0..dimT-1]
	{
		cin >> T[t];
		t++;
	}
	
	int p=0;
	while(p<dimP)	//riempio P[0..dimP-1]
	{
		cin >> P[p];
		p++;
	}
	
	t=0;										//reset indice t per scorrere T
	int MIS=dimT, posiz=-1;						//MIS=dimT perchè sia un valore molto alto, va bene qualsiasi>dimP-1; posiz=-1 perchè tale posizione in T non esiste
	bool stopP;
	while(t<=dimT-dimP && MIS>0)				//"!(dimT-t<dimP)" inutile entrare se dimT<dimP e/o se non avanzano abbastanza elementi in T per poter contenere P; da "t<dimT && !(dimT-t<dimP)" con DeMorgan si ha: "t<=dimT-dimP"
	{											//se c'è match perfetto (MIS=0) di meglio non c'è quindi mi posso fermare
		p=0;									//reset indice p per scorrere P
		int m=t;								//indice ausiliario (essendo che "salta" i mismatch isolati funge anche da contatore (modulo t))
		stopP=false;							//stopP blocca se per 2 elem consecutivi di T NON c'è match con l'elem di P in esame
		while(p<dimP && !stopP && m+p<dimT && T[t]==P[0])		//m+p<dimT bound check per non sforare nella lettura degli elem di T
		{
			if(!p)								//solo quando p==0, cioè al primo ingresso
				p++;							//lo posso fare perchè so già che T[t]==P[0], in alternativa basta inizializzare p a 1 anzichè a 0
			else
			{
				if(T[m+p]==P[p])					//gli elem matchano? bene passiamo ai prossimi
					p++;
				else
				{
					m++;							//controlliamo se dopo il mismatch dell'elem di P in esame con un elem di T ne segue subito un altro
					if(m+p<dimT && T[m+p]==P[p])	//m+p<dimT bound check, va fatto come primo controllo, altrimenti potremmo leggere elementi fuori da T
						p++;						//questo è quello buono, posso quindi andare avanti
					else							//ho trovato in T due mismatch consecutivi per l'elem di P in esame -> non c'è M1MIS -> fermo il ciclo interno
						stopP=true;
				}
			}
		}
		
		if(p==dimP && m-t<MIS)					//se mi fermo perchè p==dimP ho matchato tutto P ed ho m-t MIS -> aggiorno la posiz d'inizio del match se ho un MIS minore
		{
			posiz=t;
			MIS=m-t;
		}
		t++;
	}
	
	if(posiz==-1)
		cout<<"Match (M1MIS) NON trovato."<<endl;
	else
		cout<<"Match (M1MIS) trovato."<<endl<<"inizio: "<<posiz<<" con "<<MIS<<" miss."<<endl;
}	//POST



//PRE=(cin contiene dimT e dimP (0<dimT<=100 e 0<dimP<=20), seguiti da dimT+dimP valori interi qualsiasi).

//POST=(se c'è almeno un M1MIS di P in T, il programma stampa l'inizio del M1MIS a MIS minimo (e quello che inizia prima se ce ne fossero diversi minimi)
//e il valore del suo MIS) && (se non esiste M1MIS di P in T allora il programma scrive su cout "nessun M1MIS").
*/



/* Versione 6:
#include<iostream>
using namespace std;

int main()
{	//PRE
	int T[100], P[20], dimT, dimP;
	cin >> dimT >> dimP;
	
	int t=0;
	while(t<dimT)	//riempio T[0..dimT-1]
	{
		cin >> T[t];
		t++;
	}
	
	int p=0;
	while(p<dimP)	//riempio P[0..dimP-1]
	{
		cin >> P[p];
		p++;
	}
	
	t=0;										//reset indice t per scorrere T
	int MIS=dimT, posiz=-1;						//MIS=dimT perchè sia un valore molto alto, va bene qualsiasi>dimP-1; posiz=-1 perchè tale posizione in T non esiste
	bool stopP;
	while(t<=dimT-dimP && MIS>0)				//"!(dimT-t<dimP)" inutile entrare se dimT<dimP e/o se non avanzano abbastanza elementi in T per poter contenere P; da "t<dimT && !(dimT-t<dimP)" con DeMorgan si ha: "t<=dimT-dimP"
	{											//se c'è match perfetto (MIS=0) di meglio non c'è quindi mi posso fermare
		p=0;									//reset indice p per scorrere P (NB: per p=0 il ciclo farà 2 volte il controllo, ma amen)
		int m=t;								//indice ausiliario (essendo che "salta" i mismatch isolati funge anche da contatore (modulo t))
		stopP=false;							//stopP blocca se per 2 elem consecutivi di T NON c'è match con l'elem di P in esame
		while(p<dimP && !stopP && m+p<dimT && T[t]==P[0])		//m+p<dimT bound check per non sforare nella lettura degli elem di T
		{										//NB: qui la prima volta (m=t) viene ripetuto il controllo T[t]==P[0], ci sono soluzioni ma complicano il codice
			if(T[m+p]==P[p])					//gli elem matchano? bene passiamo ai prossimi
				p++;
			else
			{
				m++;							//controlliamo se dopo il mismatch dell'elem di P in esame con un elem di T ne segue subito un altro
				if(m+p<dimT && T[m+p]==P[p])	//m+p<dimT bound check, va fatto come primo controllo, altrimenti potremmo leggere elementi fuori da T
					p++;						//questo è quello buono, posso quindi andare avanti
				else							//ho trovato in T due mismatch consecutivi per l'elem di P in esame -> non c'è M1MIS -> fermo il ciclo interno
					stopP=true;
			}
		}
		
		if(p==dimP && m-t<MIS)					//se mi fermo perchè p==dimP ho matchato tutto P ed ho m-t MIS -> aggiorno la posiz d'inizio del match se ho un MIS minore
		{
			posiz=t;
			MIS=m-t;
		}
		t++;
	}
	
	if(posiz==-1)
		cout<<"Match (M1MIS) NON trovato."<<endl;
	else
		cout<<"Match (M1MIS) trovato."<<endl<<"inizio: "<<posiz<<" con "<<MIS<<" miss."<<endl;
}	//POST



//PRE=(cin contiene dimT e dimP (0<dimT<=100 e 0<dimP<=20), seguiti da dimT+dimP valori interi qualsiasi).

//POST=(se c'è almeno un M1MIS di P in T, il programma stampa l'inizio del M1MIS a MIS minimo (e quello che inizia prima se ce ne fossero diversi minimi)
//e il valore del suo MIS) && (se non esiste M1MIS di P in T allora il programma scrive su cout "nessun M1MIS").
*/



/* Versione 7:
#include<iostream>
using namespace std;

int main()
{	//PRE
	int T[100], P[20], dimT, dimP;
	cin >> dimT >> dimP;
	
	int t=0;
	while(t<dimT)	//riempio T[0..dimT-1]
	{
		cin >> T[t];
		t++;
	}
	
	int p=0;
	while(p<dimP)	//riempio P[0..dimP-1]
	{
		cin >> P[p];
		p++;
	}
	
	t=0;										//reset indice t per scorrere T
	int MIS=dimT, posiz=-1;						//MIS=dimT perchè sia un valore molto alto, va bene qualsiasi>dimP-1; posiz=-1 perchè tale posizione in T non esiste
	bool stopP;
	while(t<=dimT-dimP && MIS>0)				//"!(dimT-t<dimP)" inutile entrare se dimT<dimP e/o se non avanzano abbastanza elementi in T per poter contenere P; da "t<dimT && !(dimT-t<dimP)" con DeMorgan si ha: "t<=dimT-dimP"
	{											//se c'è match perfetto (MIS=0) di meglio non c'è quindi mi posso fermare
		p=0;									//reset indice p per scorrere P (NB: per p=0 il ciclo farà 2 volte il controllo, ma amen)
		int m=t;								//indice ausiliario (essendo che "salta" i mismatch isolati funge anche da contatore (modulo t))
		stopP=false;							//stopP blocca se per 2 elem consecutivi di T NON c'è match con l'elem di P in esame
		while(p<dimP && !stopP && m+p<dimT && T[t]==P[0])		//m+p<dimT bound check per non sforare nella lettura degli elem di T
		{										//NB: qui la prima volta (m=t) viene ripetuto il controllo T[t]==P[0], ci sono soluzioni ma complicano il codice
			if(T[m+p]==P[p])					//gli elem matchano? bene passiamo ai prossimi
				p++;
			else
			{
				m++;							//controlliamo se dopo il mismatch dell'elem di P in esame con un elem di T ne segue subito un altro
				if(m+p<dimT && T[m+p]==P[p])	//m+p<dimT bound check, va fatto come primo controllo, altrimenti potremmo leggere elementi fuori da T
					p++;						//questo è quello buono, posso quindi andare avanti
				else							//ho trovato in T due mismatch consecutivi per l'elem di P in esame -> non c'è M1MIS -> fermo il ciclo interno
					stopP=true;
			}
		}
		
		if(p==dimP && m-t<MIS)					//se mi fermo perchè p==dimP ho matchato tutto P ed ho m-t MIS -> aggiorno la posiz d'inizio del match se ho un MIS minore
		{
			posiz=t;
			MIS=m-t;
		}
		t++;
	}
	
	if(posiz==-1)
		cout<<"nessun M1MIS"<<endl;
	else
		cout<<posiz<<" "<<MIS<<endl;
}	//POST



//PRE=(cin contiene dimT e dimP (0<dimT<=100 e 0<dimP<=20), seguiti da dimT+dimP valori interi qualsiasi).

//POST=(se c'è almeno un M1MIS di P in T, il programma stampa l'inizio del M1MIS a MIS minimo (e quello che inizia prima se ce ne fossero diversi minimi)
//e il valore del suo MIS) && (se non esiste M1MIS di P in T allora il programma scrive su cout "nessun M1MIS").
*/



/* Versione 8:
#include<iostream>
using namespace std;

int main()
{	//PRE
	int T[100], P[20], dimT, dimP;
	cin >> dimT >> dimP;
	
	int t=0;
	while(t<dimT)	//riempio T[0..dimT-1]
	{
		cin >> T[t];
		t++;
	}
	
	int p=0;
	while(p<dimP)	//riempio P[0..dimP-1]
	{
		cin >> P[p];
		p++;
	}
	
	t=0;										//reset indice t per scorrere T
	int MIS=dimT, posiz=-1;						//MIS=dimT perchè sia un valore molto alto, va bene qualsiasi>dimP-1; posiz=-1 perchè tale posizione in T non esiste
	bool stopP;
	while(t<=dimT-dimP && MIS>0)	//R			//"!(dimT-t<dimP)" inutile entrare se dimT<dimP e/o se non avanzano abbastanza elementi in T per poter contenere P; da "t<dimT && !(dimT-t<dimP)" con DeMorgan si ha: "t<=dimT-dimP"
	{											//se c'è match perfetto (MIS=0) di meglio non c'è quindi mi posso fermare
		if(dimP==1)								//reset indice p per scorrere P
			p=0;								//p=0 il controllo T[t]==P[0] avverrà 2 volte ma è necessario nel caso degenere in cui dimP=1
		else									
			p=1;								//nel caso in cui dimP!=1 -> p=1 così evita il doppio controllo T[t]==P[0]
		int m=t;								//indice ausiliario (essendo che "salta" i mismatch isolati funge anche da contatore (modulo t))
		stopP=false;							//stopP blocca se per 2 elem consecutivi di T NON c'è match con l'elem di P in esame
		while(p<dimP && !stopP && m+p<dimT && T[t]==P[0])	//R1		//m+p<dimT bound check per non sforare nella lettura degli elem di T
		{
			if(T[m+p]==P[p])					//gli elem matchano? bene passiamo ai prossimi
				p++;
			else
			{
				m++;							//controlliamo se dopo il mismatch dell'elem di P in esame con un elem di T ne segue subito un altro
				if(m+p<dimT && T[m+p]==P[p])	//m+p<dimT bound check, va fatto come primo controllo, altrimenti potremmo leggere elementi fuori da T
					p++;						//questo è quello buono, posso quindi andare avanti
				else							//ho trovato in T due mismatch consecutivi per l'elem di P in esame -> non c'è M1MIS -> fermo il ciclo interno
					stopP=true;
			}
		}
		
		if(p==dimP && m-t<MIS)					//se mi fermo perchè p==dimP ho matchato tutto P ed ho m-t MIS -> aggiorno la posiz d'inizio del match se ho un MIS minore
		{
			posiz=t;
			MIS=m-t;
		}
		t++;
	}
	
	if(posiz==-1)
		cout<<"Match (M1MIS) NON trovato."<<endl;
	else
		cout<<"Match (M1MIS) trovato."<<endl<<"inizio: "<<posiz<<" con "<<MIS<<" miss."<<endl;
}	//POST



//PRE=(cin contiene dimT e dimP (0<dimT<=100 e 0<dimP<=20), seguiti da dimT+dimP valori interi qualsiasi).

//R=().

//R1=().

//POST=(se c'è almeno un M1MIS di P in T, il programma stampa l'inizio del M1MIS a MIS minimo (e quello che inizia prima se ce ne fossero diversi minimi)
//e il valore del suo MIS) && (se non esiste M1MIS di P in T allora il programma scrive su cout "nessun M1MIS").
*/
