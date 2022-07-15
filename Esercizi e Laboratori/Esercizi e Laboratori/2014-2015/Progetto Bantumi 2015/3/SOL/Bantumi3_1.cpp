
//soluzione by: Leo M.

#include<iostream>
#include<fstream>

using namespace std;



//Prototipi di FUNZIONI (Dichiarazioni)

void draw_board(int B[][7], ofstream &OUT);

bool semina(int B[][7], int player, int buca, int fagioli);

int invert_player_side(int a);

int sum(int B[][7], int player);



main()
{

//BANTUMI 1
//PRE=("input" contiene 14 interi per inizializzare B)

	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT)
	{
		int B[2][7];
		
		//riempie B da "input"
		for(int i=0; i<2; i++)
			for(int j=0; j<7; j++)
				INP>>B[i][j];
		
		//stampa B					
		draw_board(B, OUT);
			
/* POST=(B contiene i 14 valori che costituiscono la configurazione iniziale di gioco; e "output" contiene:
			i 14 valori di B nel'ordine:
				- prima i dati del player 0, in ordine dalla buca grande alla buca piccola di numero 0
				- poi i dati del player 1 in ordine dalla buca piccola 0 alla buca grande). */
//fine BANTUMI 1
		
		
		
//BANTUMI 3
//PRE=("input" contiene 14 interi >=0 (start configuration), l'intero p=0/1 (start player), una sequenza di interi in [0..5] (b), un -1).

		int p, b;	//p=player -> strat player, b=buca -> la mossa che dovrà fare first player
		INP>>p>>b;	//istanza della prima mossa (di certo ce n'è almeno una, quella con b=-1 per lo stop)
		bool stop=false;
		
		while(b!=-1 && !stop)	//test: devo giocare o no?
		{
			//stampo la mossa che verrà eseguita (che abbia senso o meno)
			OUT<<endl<<"il giocatore "<<p<<" fa la mossa "<<b<<endl;
				
			int num_fagioli=B[p][b]; //pesco i fagioli dalla buca b del palyer p, me li tengo in mano
			B[p][b]=0;	//dato che li ho in mano azzero queli presenti nella buca b del palyer p
			

			//se la mossa (b) del giocatore (p) cambierà la board (cioè se num_fagioli!=0), cambio e ristampo la board (semina e draw_board)
			if(num_fagioli!=0)
			{
				//effettuo la semina, e tengo traccia se da tale semina deriva una mossa extra per il giocatore di turno (true) o se và cambiato (false)
				bool extra_move = semina(B, p, b, num_fagioli);
				
				//stampo la nuova configurazione della board
				draw_board(B, OUT);
				
				//l'ultima mossa eseguita ha portato alla conclusione del gioco? -> una lato della board è vuoto (cioè: sum(B,0)==0 || sum(B,1)==0 )
				if( sum(B,0)==0 || sum(B,1)==0 )
				{
					stop=true; //ferma tutto, inutile continuare a giocare ancora
					//chi ha vinto?
					if( (sum(B,0)+B[0][6]) >= (sum(B,1)+B[1][6]) )	//vittoria player0 o parità
					{
						if( (sum(B,0)+B[0][6]) > (sum(B,1)+B[1][6]) )	//vittoria player0
						{
							OUT<<endl<<endl<<"vince il giocatore 0 con "<< (sum(B,0)+B[0][6]) <<" fagioli, mentre il giocatore 1 ne ha "<< (sum(B,1)+B[1][6]) <<endl;
						}
						else	//pareggio
							OUT<<endl<<endl<<"entrambi i giocatori hanno "<< (sum(B,0)+B[0][6]) <<" fagioli, la partita finisce in parita"<<endl;
					}
					else	//vittoria player1
						OUT<<endl<<endl<<"vince il giocatore 1 con "<< (sum(B,1)+B[1][6]) <<" fagioli, mentre il giocatore 0 ne ha "<< (sum(B,0)+B[0][6]) <<endl;
					
				
				}
				else //altrimenti a chi toccherà la prossima mossa?
				{
					if(!extra_move)	//se "p" non si è guadagnato una mossa extra con la sua semina, il controllao (p) passa all'altro giocatore, altrimenti p resta lo stesso
						p=invert_player_side(p);
				}
			}
			else
			{
				p=invert_player_side(p);
				OUT<<"mossa sbagliata, il turno passa al giocatore "<<p<<endl;
			}

			INP>>b; //grep next move che verrà eseguita dalgiocatore che qui è correttamente identificato da "p" a meno che stop non sia true.
		}

/* POST=("output" contiene le seguenti cose:
	a) la configurazione di gioco iniziale.
	b) per ogni mossa m [0..5] per il giocatore g [0..1] di turno (a partire con g dichiarato in "input") la stringa: "il giocatore g fa la mossa m", seguita da:
		- se mossa priva di senso (cioè se m è una buca vuota per g) la stringa: "mossa sbagliata, il turno passa al giocatore x" con x=1 se g=0 e x=0 se g=1.
		- se mossa è sensata: la nuova configurazione di gioco così raggiunta.
	c) la stringa: "fine"). */
//fine BANTUMI 3



		OUT<<"fine"<<endl;

		INP.close();
		OUT.close();
	}
	else
		cerr<<"Errore File!"<<endl;
}



//Implementazioni delle FUNZIONI (Definizione)

void draw_board(int B[][7], ofstream &OUT)
{	//PRE=().

	//stampa B su "output"
	for(int i=6; i>=0; i--)
		OUT<<B[0][i]<<" ";
	for(int j=0; j<7; j++)
		OUT<<B[1][j]<<" ";
		
		
/*	//stampa B "formattato" su cout
	cout<<endl<<"##############################################"<<endl;
	cout<<"       5    4    3    2    1    0"<<endl;
	cout<<"     ";
	for(int i=5; i>=0; i--)
	{
		if(B[0][i]<10)
			cout<<"|"<<" "<<B[0][i]<<"|"<<" ";
		else
			cout<<"|"<<B[0][i]<<"|"<<" ";
	}
	cout<<endl;
	cout<<"tot"<<endl;
	if(B[0][6]<10)
		cout<<" "<<B[0][6];
	else
		cout<<B[0][6];
	cout<<" --------------------------------- ";
	if(B[1][6]<10)
		cout<<" "<<B[1][6]<<endl;
	else
		cout<<B[1][6]<<endl;
	cout<<"                                     "<<"tot"<<endl;
	cout<<"     ";
	for(int i=0; i<6; i++)
	{
		if(B[1][i]<10)
			cout<<"|"<<" "<<B[1][i]<<"|"<<" ";
		else
			cout<<"|"<<B[1][i]<<"|"<<" ";
	}
	cout<<endl;
	cout<<"       0    1    2    3    4    5"<<endl;
*/
}	//POST=().


bool semina(int B[][7], int player, int buca, int fagioli)
{	//PRE=(B contiene 14 valori non negativi, player=0/1, buca in [0..5], fagioli>0. Chiamiamo old_B il valore di B all'invocazione della funzione).
	bool extra_move=false;
	int player_side=player;	//variabile che mi serve per fare il giro delle buche, da confrontare con "player" per sapere di chi è la buca grande che incontro
	while(fagioli>0)
	{
		buca++;
		
		/* ora la buca può essere:
			- <6, il lato della board resta player_side
				se fagioli==1 && B[player_side][buca]==0
					fagioli=fagioli+B[invert_player_side][buca], B[invert_player_side][buca]=0, B[player][6]=B[player][6]+fagioli, fagioli=0;
				altrimenti
					B[player_side][buca]++, fagioli--;
				
			- =6, il lato della board resta player_side e sono nella buca grande
				se player_side==player è la MIA
					se fagioli==1 extra_move=true;
					B[player_side][buca]++, fagioli--;
				altrimenti è quella dell'avversario, da saltare
				
			- >6,  vado a seminare dall'altra parte (player_side=invert_player_side) e buca=0;
		*/
				
		if(buca>6)
		{
			player_side=invert_player_side(player_side);
			buca=0;
		}
		
		if(buca<6)
		{
			if(fagioli==1 && B[player_side][buca]==0)
			{
				fagioli=fagioli+B[invert_player_side(player_side)][5-buca];	//rubo i fagioli dalla buca opposta
				B[invert_player_side(player_side)][5-buca]=0;	//azzero il contenuto della buca opposta
				B[player][6]=B[player][6]+fagioli;	//deposito tutti i fagioli nella mia buca grande
				fagioli=0;	//quindi ora ho zero fagioli in mano
			}
			else
			{
				B[player_side][buca]++;	//deposito un fagiolo
				fagioli--;				//quindi ho un fagiolo in meno
			}
		}
		else //buca==6 -> la buca grande
		{
			if(player_side==player) //se è la mia
				{
					if(fagioli==1)	//se è l'ultimo deposito da fare avrò una mossa extra -> semina deve ritornare true
						extra_move=true;
					B[player_side][buca]++;	//deposito un fagiolo
					fagioli--;				//quindi ho un fagiolo in meno
				}
			//else è la buca grande dell'avversario, la devo saltare, quindi non faccio niente
		}	
	}
	
	return extra_move;
}	/*POST=(B è ottenuta da old_B eseguendo la mossa (player,buca) secondo le regole del gioco;
		- semina restituisce true sse la semina termina nella buca grande del giocatore che ha mosso;
		- altrimenti semina restituisce false.). */


int invert_player_side(int a)
{	//PRE=("a" in [0..1] identifica un giocatore).
	return !a;
}	/*POST=(ritorna il giocatore avversario/invertito:
		- se a=1 allora ritorna 0;
		- se a=0 allora ritorna 1). */


int sum(int B[][7], int player)
{	//PRE=(player in [0..1], B definito).
	int aux=0;	//variabile temporanea ausiliaria
	for(int i=0; i<6; i++)
		aux=aux+B[player][i];
	return aux;
}	//POST=(ritorna la somma di tutti i fagioli contenuti nelle buche piccole [0..5] del giocatore "player").
