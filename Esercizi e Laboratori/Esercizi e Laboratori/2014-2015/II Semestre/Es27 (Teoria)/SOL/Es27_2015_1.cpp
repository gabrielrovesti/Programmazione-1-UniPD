
//soluzione by: Leo M.


// Esercizi di Teoria (02.06.2015)


/*

Es1: Scrivere una PRE ed una POST sensate per il seguente programma ricorsivo:

int F(nodo* L, int k1, int k2)
{	//PRE=(lista(L) corretta, k1 e k2 definiti).
	if(L)
		if(k2>0)
			return F(L,k1,k2-1);
		else
			return k1+F(L->next,k1,k1);
	else
		return k1;
}	//POST=(detto n il numero di nodi di lista(L) allora ritorna il valore k=k1*(n+1)).



Es2: Errato/Corretto? Cosa stampa?

int* f(int *&p)		//tipo ritorno: int*, passaggio di un puntatore per riferimento (alias)
{	int b=0, *x=&b;	//b var locale, x puntatore locale a b locale
	x=p+2;			//x prende l'R-val di p+2 (ora punta a b[4]=5 del main) (vedi schema)
	p++;			//sposta p, quindi anche q del main (per side effect) che ora punterà a b[3]=4
	return x-3; }	//ritorna un puntatore a b[1]=2 (tipo int*)
main()
{	int b[]={1,2,3,4,5}, *q=b+2;		//crea un array b[0..4], q punta al suo terzo elemento cioè a b[2]=3
	*f(q)=*q;							//invoca f passando q, poi dereferenzia il punt ritornato e vi mette ciò che è ountato da q (vedi  schema)
	cout<<b[0]<<b[1]<<b[2]<<b[3]<<b[4];	//stampa: 14345 (vedi sotto!)
}
(semi)CORRETTO:
tutti i tipi mathcano, e tutti gli accessi sono legali, tramite side-effect vengono spostati i puntatori e avviene una sovrascrittura di una cella dell'array.
stampa il contenuto dell'array b[0..4] alla fine di tutto il processo.
NB: c'è un'ambiguità, nel main() l'istruzione "*f(q)=*q;" è ambigua, dato che il C++ non specifica quale parte viene "valutata" per prima,
ovvero se viene prima eseguita l'invocazione (parte sx) o prima "pescato" il valore da mettere poi nella locazione indicata (parte dx).
normalmente viene eseguita l'invocazione (parte sinistra) per prima, ma lo standard C++ non lo garantisce, delegando tale scelta alla singola implementazione del compilatore.
se viene eseguita prima la parte sinistra, allora stamperà: 14345
altrimenti, se viene eseguita prima la parte destra, allora stamperà: 13345
(lo schema si riferisce alla situazione in cui viene valutata prima la parte sx dell'assegnazione, altrimenti il 2 in b[1] è sostituito con un "3" anzichè con un "4").



Es3: Considerate le seguenti conversioni:

int x=3, *pi;
double y=3.1,*pd=&y;
a) x=y;
b) pi=reinterpret_cast<int*>(pd);

Entrambe le assegnazioni (a e b) sono accettate dal compilatore?
Spiegare la risposta; in caso ce ne fossero di accettate, che valore assumerebbero le variabili coinvolte
e/o gli oggetti puntati dopo l'esecuzione delle corrispondenti assegnazioni?

a) si vuole assegnare ad una variabile di tipo "int" un valore di tipo "double", il compilatore procede, ma verificandosi una perdita d'informazione
   (l'int da 4 byte non può "ospitare" tutto il double da 8 byte, pertanto tipicamente la parte decimale viene troncata) dovrebbe emettere un "warning".
b) si vuole assegnare ad un puntatore ad intero l'indirizzo contenuto in un puntatore a double;
   entrambi i puntatori sono memorizzati in 4 byte per cui non si presenta il problema visto al punto a);
   il problema è invece sul tipo, e trattandosi di puntatori il C++ non ammette conversione (automatica) alcuna.
   "reinterpret_cast" forza la conversione: ora "pi" punterà alla locazione di memoria ove risiede "y",
   tuttavia, accedendo a tale locazione per mezzo di "pi", i primi 4 byte del double "y" verranno interpretati come contenenti un valore int.
   l'effetto (ad esempio di cout<<*pi) dipende dal tipo di rappresentazione che viene adottato per i valori int e per i valori double (come "complemento a 2" e/o "virgola mobile").
*/
