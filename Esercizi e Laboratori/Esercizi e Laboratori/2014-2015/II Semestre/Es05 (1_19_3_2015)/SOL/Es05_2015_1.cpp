
//soluzione by: Leo M.

// Versione 1:
#include<iostream>
#include<fstream>

using namespace std;



main()
{	//PRE=(PRE=("input" contiene n_el (0<n_el<=400), n_el interi, seguiti da 4 interi positivi e da 2 interi r e c).
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
			
		//leggo i 4 limiti della "vista" e "r" e "c" del tassello
		int tor, str, rig, col, r, c;
		INP >> tor >> str >> rig >> col >> r >> c;
		
		/* TASSELLO VUOTO
		- dato che PRE non garantisce nulla su "r" e "c" se non sono "legali" -> tassello vuoto. (legali se: 0<=r<rig e 0<=c<col)
		- se "r" e "c" sono "legali" allora un tassello è vuoto SOLO se c'è un solo strato, è incompleto e "r*rig+c">=n_el
		*/
		if(r<0 || r>=rig || c<0 || c>=col || ((r*col+c)>=n_el))
			OUT<<"il tassello "<<r<<" "<<c<<" e' vuoto"<<endl;
		else	//il tassello esiste ed ha almeno un elemento (NON è vuoto)
		{
			OUT<<"il tassello "<<r<<" "<<c<<" contiene ";
			for(int i=(r*col+c); i<n_el && i<(tor*str*rig*col); i=(i+(rig*col)))
				OUT<<*(X+i)<<" "; //in alternativa: OUT<<*(X+((r*rig+c)+(i*rig*col)))<<" ";
			
		}
	
		INP.close();
		OUT.close();
	}
	else
		cerr<<"Errore File!"<<endl;
}	/*	POST=("output" contiene la stringa "il tassello r c contiene t1 t2 .. tn" dove t1 t2 .. tn sono i valori degli elementi del tassello (r,c);
		nel caso il tassello (r,c) fosse vuoto, su "output" deve apparire la frase "il tassello r c e' vuoto"). */





/* Versione 2:
#include<iostream>
#include<fstream>

using namespace std;



main()
{	//PRE=("input" contiene n_el (0<n_el<=400), n_el interi, seguiti da 4 interi positivi e da 2 interi r e c).
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
			
		//leggo i 4 limiti della "vista" e "r" e "c" del tassello
		int tor, str, rig, col, r, c;
		INP >> tor >> str >> rig >> col >> r >> c;
		
		int tor_p=n_el/(str*rig*col);	//tor_p=Torte Piene
		int eut=n_el%(str*rig*col);	//eut=ElementiUltimaTorta
		int str_p=eut/(rig*col);	//str_p=StratiPieni (della Torta Incompleta)
		int eus=eut%(rig*col);	//eus=ElementiUltimoStrato (della Torta Incompleta)
		int rig_p=eus/col;	//rig_p=RighePiene (dello Strato Incompleto della Torta Incompleta)
		int eur=eus%col;	//eur=ElementiUltimaRiga (dello Strato Incompleto della Torta Incompleta)
		
		
		if(r>=0 && r<rig && c>=0 && c<col)	//condizioni perchè il tassello sia "legale"
		{
			
			//gli strati pieni NON sono un problema ed avranno un elem da stampare; il totale strati pieni è "tor_p*str+str_p"
			int tot_str_p=tor_p*str+str_p;	//tutti gli strati pieni di tutte le torte complete e non
			
			
			//un tassello (legale) è vuoto se NON c'è nessuno strato pieno (!tot_str_p) e:
			//- o se nello Strato Incompleto "r" è oltre le righe piene (r>rig_p)
			//- o se nello Strato Incompleto "r" è la Riga Incompleta (r==rig_p) e "c" è oltre gli elementi definiti di quella riga (c>=eur)
			
			if((!tot_str_p) && ((r>rig_p) || ((r==rig_p) && (c>=eur))))
				OUT<<"il tassello "<<r<<" "<<c<<" e' vuoto"<<endl;
			else	//il tassello NON è vuoto
			{
				OUT<<"il tassello "<<r<<" "<<c<<" contiene ";
				
				//Strati Pieni (di tutte le torte)
				for(int i=0; i<tot_str_p && i<(tor*str); i++)
					OUT<<*(X+((r*col+c)+(i*rig*col)))<<" ";
			
				//nell'ultimo strato, se il tassello è entro una delle righe piene avrà un elemento valido
				if(r<rig_p && tot_str_p<tor*str)
					OUT<<*(X+((r*col+c)+(tot_str_p*rig*col)))<<" ";
			
				//nell'ultimo strato, se il tassello è sulla riga incompleta (r==rig_p) ed entro gli elem definiti (c<eur) avrà un elem valido
				if(r==rig_p && c<eur && tot_str_p<tor*str)
					OUT<<*(X+((r*col+c)+(tot_str_p*rig*col)))<<" ";
			}
		}
		else	//tassello illegale, il testo non dice bene che farne, ma assumerò che sia "vuoto"
		{
			OUT<<"il tassello "<<r<<" "<<c<<" e' vuoto"<<endl;
		}
	
		INP.close();
		OUT.close();
	}
	else
		cerr<<"Errore File!"<<endl;
}	//	POST=("output" contiene la stringa "il tassello r c contiene t1 t2 .. tn" dove t1 t2 .. tn sono i valori degli elementi del tassello (r,c);
	//	nel caso il tassello (r,c) fosse vuoto, su "output" deve apparire la frase "il tassello r c e' vuoto").



/* Versione 3:
#include<iostream>
#include<fstream>

using namespace std;



//Prototipi di FUNZIONE (Dichiarazione)

void ScorriRiga(int *X, int lung, ofstream &OUT, int c, bool &empty);

void ScorriStrato(int *X, int es, int rig, int col, ofstream &OUT, int r, int c, bool &empty);

void ScorriTorta(int *X, int et, int str, int rig, int col, ofstream &OUT, int r, int c, bool &empty);



main()
{	//PRE=("input" contiene in sequenza: 0<n_el<=400, n_el numeri interi, tor>0, str>0, rig>0, col>0, 2 interi r e c).
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
			
		//leggo i 4 limiti della "vista" e i due interi "r" e "c" che definiscono il tassello
		int tor, str, rig, col, r, c;
		INP>>tor>>str>>rig>>col>>r>>c;
		
		bool empty=true;
		
		OUT<<"il tassello "<<r<<" "<<c;
		
		if(r>=0 && r<rig && c>=0 && c<col)	//condizioni perchè il tassello sia "legale"
		{
		
	
//		un tassello legale può essere "pieno" (cioè avere almeno un elemento) o vuoto (cioè senza alcun elemento);
//		per capire se è VUOTO ci sono diversi sistemi, tra i quali:
//		
//			a)	fare tutta una serie di considerazioni grazie ai vari limiti (tor, str, rig, col), ovvero:
//				   non c'è nessuna torta piena e nessuno strato pieno (nella torta incompleta) (!tor_p && !str_p) e:
//				   - o se nello Strato Incompleto "r" è oltre le righe piene (r>rig_p)
//				   - o se nello Strato Incompleto "r" è la Riga Incompleta (r==rig_p) e "c" è oltre gli elementi definiti di quella riga (c>=eur)
//				che portano ad una condizione del tipo:
//				if((!tor_p && !str_p) && ((r>rig_p) || ((r==rig_p) && (c>=eur))))
//				ma è evidente che quasi tutte le informazioni necessarie sono calcolate dalle funzioni,
//				ed appare quindi errato calcolarle tutte e poi invocare funz che le ricalcolino.
//				
//			b)	operare dei conti sulla posizione esatta del tassello (r*col+c) ed n_el. (basta aggiungere all'if soprastante: && r*col+c>=n_el)
//				
//			c)	dato che le funzioni sono scritte per scorrere/analizzare SOLO elementi definiti, se il tassello è vuoto nulla verrà scritto sullo stream OUT;
//				pertanto basterebbe verificare alla fine se OUT è stato "modificato" o meno.
//				
//			d)	non conoscendo i "metodi" per implementare il sistema "c)", un escamotage può essere quello di usare un booleano, che diverrà "true" non appena
//				qualcosa viene stampato su "OUT" e quindi resterà "false" se non viene mai stampato nulla.
//		
//		in questa versione del programma ho optato per la d, le altre (eccetto la c) sono utilizzate nelle altre versioni del programma.

		
		
			//Gestione Torte
			//Torte Piene
			int et=str*rig*col, tor_p=n_el/et;	//et=ElementiTorta, tor_p=TortePiene
			for(int i=0; i<tor_p && i<tor; i++)
				ScorriTorta(X+i*et, et, str, rig, col, OUT, r, c, empty);
		
			//Torta Incompleta
			int eut=n_el%et;	//eus=ElementiUltimoTorta
			if(eut && tor_p<tor)
				ScorriTorta(X+tor_p*et, eut, str, rig, col, OUT, r, c, empty);
				
			if(empty)
				OUT<<" e' vuoto"<<endl;
			else
				OUT<<endl;
		}
		else	//tassello illegale, il testo non dice bene che farne, ma assumerò che sia "vuoto"
		{
			OUT<<" e' vuoto"<<endl;
		}
		
		INP.close();
		OUT.close();
	}
	else
		cerr<<"Errore File!"<<endl;
}	//POST=( ).



//Implementazione delle FUNZIONI (Definizione)

void ScorriRiga(int *X, int lung, ofstream &OUT, int c, bool &empty)
{	//PRE=(X è un punt all'inizio della riga da stampare, tale riga ha lung elementi definiti).
	if(c<lung)
	{
		if(empty)
			OUT<<" contiene ";
		OUT<<*(X+c)<<" "; //in alternativa: OUT<<X[c]<<" ";
		empty=false;
	}
	//return;	
}	//POST=( ).

void ScorriStrato(int *X, int es, int rig, int col, ofstream &OUT, int r, int c, bool &empty)
{	//PRE=( ).
	//Gestione Righe
	//Righe Piene
	int er=col, rig_p=es/er;	//er=ElementiRiga, rig_p=RighePiene
	if(r<rig_p && r<rig)
		ScorriRiga(X+r*er, er, OUT, c, empty);
	//Riga Incompleta
	int eur=es%er;	//eur=ElementiUltimaRiga
	if(eur && r==rig_p)
		ScorriRiga(X+rig_p*er, eur, OUT, c, empty);
	//return;
}	//POST=( ).

void ScorriTorta(int *X, int et, int str, int rig, int col, ofstream &OUT, int r, int c, bool &empty)
{	//PRE=( ).
	//Gestione Strati
	//Strati Pieni
	int es=rig*col, str_p=et/es;	//es=ElementiStrato, str_p=StratiPieni
	for(int i=0; i<str_p && i<str; i++)
		ScorriStrato(X+i*es, es, rig, col, OUT, r, c, empty);
	//Strato Incompleto
	int eus=et%es;	//eus=ElementiUltimoStrato
	if(eus && str_p<str)
		ScorriStrato(X+str_p*es, eus, rig, col, OUT, r, c, empty);
	//return;
}	//POST=( ).
*/



/* Versione 4:
#include<iostream>
#include<fstream>
using namespace std;
main()
{	int n_el; INP>>n_el;
	int X[400]; for(int i=0; i<n_el; i++) INP>>X[i];
	int tor,str,rig,col,r,c; INP>>tor>>str>>rig>>col>>r>>c;
	if(r<0 || r>=rig || c<0 || c>=col || r*col+c>=n_el) OUT<<"il tassello "<<r<<" "<<c<<" e' vuoto"<<endl;
	else
	{	OUT<<"il tassello "<<r<<" "<<c<<" contiene ";
		for(int i=r*col+c; i<n_el && i<tor*str*rig*col; i=i+rig*col) OUT<<*(X+i)<<" "; }
}
*/
