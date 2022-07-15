
//soluzione by: Leo M.

#include<iostream>
#include<fstream>

using namespace std;



//Prototipi di FUNZIONI (Dichiarazioni)

void draw_board(int B[][7], ofstream &OUT);

bool semina(int B[][7], int player, int buca, int fagioli);

int invert_player_side(int a);



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
			
/* POST=(
	i) stampare su cout una rappresentazione della situazione rappresentata da B che assomiglia (più che riuscite usando istruzione semplici) al disegno della piattaforma mostrato prima;
	ii) stampare su un file "output" solo i 14 valori di B nello stesso ordine richiesto per (i) e cioè, prima i dati del player 0, in ordine dalla buca grande alla buca piccola di numero 0 e poi i dati del player 1 in ordine dalla buca piccola 0 alla buca grande.*/
//fine BANTUMI 1
		
		
		
//BANTUMI 2
//PRE=("input" contiene 14 interi non negativi seguiti da coppie di interi non negativi che contiene anche una coppia con seconda componente uguale a -1).

		int p, b;	//una mossa è definita dalla coppia (p, b), p=player b=buca
		INP>>p>>b;	//istanza della prima mossa (di certo ce n'è almeno una, quella con b=-1 per lo stop)
		while(b!=-1)	//test: devo giocare o no?
		{
			OUT<<endl<<p<<" "<<b<<endl;
			int num_fagioli=B[p][b]; //pesco i fagioli dalla buca b del palyer p, me li tengo in mano
			B[p][b]=0;	//dato che li ho in mano azzero queli presenti nella buca b del palyer p
			

			//se la mossa (p,b) cambierà la board (cioè se num_fagioli!=0), la cambio (semina) e la ristampo aggiornata (draw_board)
			if(num_fagioli!=0)
			{
				bool player_change=semina(B, p, b, num_fagioli);
				
				//stampo la nuova configurazione della board
				draw_board(B, OUT);
				
				//stampo a chi toccherà la prossima mossa (sarà da gestire in BANTUMI 3)
				if(player_change)
					OUT<<endl<<"il giocatore non cambia"<<endl;
				else
					OUT<<endl<<"il giocatore cambia"<<endl;
			}
		/*	else
				OUT<<"mossa NON valida!<<endl<<"il giocatore cambia"<<endl;
		*/

			INP>>p>>b; //grep next move
		}
		
		OUT<<"fine"<<endl;

/* POST=("output" contiene le seguenti cose:
	a) la configurazione di gioco iniziale.
	b) per ogni coppia (p,b) letta da "input" e tale che b!=-1, i 2 interi p e b vanno scritti su "output" e:
		- se la buca b del giocatore p non è vuota, "output" contiene la nuova configurazione raggiunta eseguendo la mossa (p,b);
			- se una semina termina nella buca grande del giocatore che ha mosso allora lo stesso giocatore può fare subito un'altra mossa, scrivo: "il giocatore non cambia",
			- altrimenti scrivo: "il giocatore cambia";
		- se la buca b del giocatore p è vuota, la configurazione non cambia e quindi non va riscritta su "output".
	c) "output" termina sempre con la stringa "fine"). */
//fine BANTUMI 2

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
}	/*POST=(B è ottenuta da old_B eseguendo la mossa (player,buca) secondo le regole del gioco descritte prima;
		- semina restituisce true sse la semina termina nella buca grande del giocatore che ha mosso;
		- altrimenti semina restituisce false. ). */


int invert_player_side(int a)
{
	return !a;
}
