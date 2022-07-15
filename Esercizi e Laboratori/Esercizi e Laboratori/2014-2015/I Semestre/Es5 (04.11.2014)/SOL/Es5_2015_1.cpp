
//soluzione by: G. Filè (Prof)

// Versione 1
#include<iostream>
using namespace std;

int main()
{	//PRE
	int T[100], P[20], dimT, dimP;
	cin >> dimT >> dimP;
	
	int i=0;
	while(i<dimT)	//riempio T[0..dimT-1]
	{
		cin >> T[i];
		i++;
	}
	
	int j=0;
	while(j<dimP)	//riempio P[0..dimP-1]
	{
		cin >> P[j];
		j++;
	}
	
	
	int bestIn=-1, bestMIS=dimP;					//variabili ausiliarie
	i=0;											//reset indice i per scorrere T
	while(i<dimT-dimP+1)	//R						//in alternativa "(i<=dimT-dimP)"
	{
		int mis=0, m=i;								//variabili ausiliarie
		bool fine=false;							//ferma il ciclo non appena ho due mis consecutivi
		j=0;										//reset indice j per scorrere P
		while(j<dimP && !fine && m<dimT)	//R1
		{
			if(P[j]==T[m])
			{
				j++;
				m++;
			}
			else
				if(m+1<dimT && P[j]==T[m+1])
				{
					j++;
					m=m+2;
					mis++;
				}
				else
					fine=true;
		}
		if(j==dimP && mis<bestMIS)
		{
			bestIn=i;
			bestMIS=mis;
		}
		i++;
	}

	cout<<bestIn<<" "<<bestMIS<<endl;
	
}	//POST


/*
PRE=(cin contiene dimT e dimP (0<dimT<=100 e 0<dimP<=20), seguiti da dimT+dimP valori interi qualsiasi).

R=(ho considerato i punti di inizio T[0..i-1]) && (0<=i<=dimT):
- (bestIn=-1 => non esistono M1MIS che iniziano in [0..i-1])
- (bestIn!=-1 => bestIn e bestMIS sono l'inizio e il MIS del match migliore che inizia in T[0..i-1]).

R1=(!fine <=> a partire da i, in T[i..m-1] ho un M1MIS di P[0..j-1] con MIS=mis).

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
	
	int i=0;
	while(i<dimT)	//riempio T[0..dimT-1]
	{
		cin >> T[i];
		i++;
	}
	
	int j=0;
	while(j<dimP)	//riempio P[0..dimP-1]
	{
		cin >> P[j];
		j++;
	}
	
	
	int bestIn=-1, bestMIS=dimP;					//"bestIn=-1" posiz inesistente; "bestMIS=dimP" basta che sia abbastanza grande (>dimP-1)
	i=0;											//reset indice i per scorrere T
	while(i<dimT-dimP+1 && bestMIS>0)	//R			//in alternativa "(i<=dimT-dimP && bestMIS>0)"; "bestMIS>0" ferma al primo pattern senza mis (di meglio non c'è)
	{
		int mis=0, m=i;								//variabili ausiliarie
		bool fine=false;							//ferma il ciclo non appena ho due mis consecutivi
		j=0;										//reset indice j per scorrere P
		while(j<dimP && !fine && m<dimT)	//R1
		{
			if(P[j]==T[m])
			{
				j++;
				m++;
			}
			else
				if(m+1<dimT && P[j]==T[m+1])
				{
					j++;
					m=m+2;
					mis++;
				}
				else
					fine=true;
		}
		
//		// il seguente condizionale (se abilitato) mostra come il programma considera "M1MIS" anche quelli con un mis prima del pattern (evidenziati da: "<- THIS").
//		if(j==dimP)
//		{
//			if(T[i]!=P[0])
//				cout<<"start at: "<<i<<" con "<<mis<<" miss."<<" <- THIS"<<endl;
//			else
//				cout<<"start at: "<<i<<" con "<<mis<<" miss."<<endl;
//		}
		
		if(j==dimP && mis<bestMIS)
		{
			bestIn=i;
			bestMIS=mis;
		}
		i++;
	}

	if(bestIn==-1)
		cout<<"nessun M1MIS"<<endl;
	else
		cout<<bestIn<<" "<<bestMIS<<endl;
	
}	//POST



PRE=(cin contiene dimT e dimP (0<dimT<=100 e 0<dimP<=20), seguiti da dimT+dimP valori interi qualsiasi).

R=(ho considerato i punti di inizio T[0..i-1]) && (0<=i<=dimT):
- (bestIn=-1 => non esistono M1MIS che iniziano in [0..i-1])
- (bestIn!=-1 => bestIn e bestMIS sono l'inizio e il MIS del match migliore che inizia in T[0..i-1]).
NB: da rifare/integrare alla luce dell'aggiunta di "&& bestMIS>0"

R1=(!fine <=> a partire da i, in T[i..m-1] ho un M1MIS di P[0..j-1] con MIS=mis).

POST=(se c'è almeno un M1MIS di P in T, il programma stampa l'inizio del M1MIS a MIS minimo (e quello che inizia prima se ce ne fossero diversi minimi)
e il valore del suo MIS) && (se non esiste M1MIS di P in T allora il programma scrive su cout "nessun M1MIS").
*/



/* Versione 3:
#include<iostream>
using namespace std;

int main()
{	//PRE
	int T[100], P[20], dimT, dimP;
	cin >> dimT >> dimP;
	
	int i=0;
	while(i<dimT)	//riempio T[0..dimT-1]
	{
		cin >> T[i];
		i++;
	}
	
	int j=0;
	while(j<dimP)	//riempio P[0..dimP-1]
	{
		cin >> P[j];
		j++;
	}
	
	
	int bestIn=-1, bestMIS=dimP;					//"bestIn=-1" posiz inesistente; "bestMIS=dimP" basta che sia abbastanza grande (>dimP-1)
	i=0;											//reset indice i per scorrere T
	while(i<dimT-dimP+1 && bestMIS>0)	//R			//in alternativa "(i<=dimT-dimP && bestMIS>0)"; "bestMIS>0" ferma al primo pattern senza mis (di meglio non c'è)
	{
		int mis=0, m=i;								//variabili ausiliarie
		bool fine=false;							//ferma il ciclo non appena ho due mis consecutivi
		j=0;										//reset indice j per scorrere P
		while(j<dimP && !fine && m<dimT && T[i]==P[0])	//R1
		{
			if(P[j]==T[m])							//NB: qui la prima volta (m=i e j=0) viene ripetuto il controllo T[i]==P[0]; si può evitare ma complica il codice
			{
				j++;
				m++;
			}
			else
				if(m+1<dimT && P[j]==T[m+1])
				{
					j++;
					m=m+2;
					mis++;
				}
				else
					fine=true;
		}
		
		if(j==dimP && mis<bestMIS)
		{
			bestIn=i;
			bestMIS=mis;
		}
		i++;
	}

	if(bestIn==-1)
		cout<<"nessun M1MIS"<<endl;
	else
		cout<<bestIn<<" "<<bestMIS<<endl;
	
}	//POST



PRE=(cin contiene dimT e dimP (0<dimT<=100 e 0<dimP<=20), seguiti da dimT+dimP valori interi qualsiasi).

R=(ho considerato i punti di inizio T[0..i-1]) && (0<=i<=dimT):
- (bestIn=-1 => non esistono M1MIS che iniziano in [0..i-1])
- (bestIn!=-1 => bestIn e bestMIS sono l'inizio e il MIS del match migliore che inizia in T[0..i-1]).
NB: da rifare/integrare alla luce dell'aggiunta di "&& bestMIS>0"

R1=(!fine <=> a partire da i, in T[i..m-1] ho un M1MIS di P[0..j-1] con MIS=mis).
NB: da rifare/integrare alla luce dell'aggiunta di "&& T[i]==P[0]"

POST=(se c'è almeno un M1MIS di P in T, il programma stampa l'inizio del M1MIS a MIS minimo (e quello che inizia prima se ce ne fossero diversi minimi)
e il valore del suo MIS) && (se non esiste M1MIS di P in T allora il programma scrive su cout "nessun M1MIS").
*/
