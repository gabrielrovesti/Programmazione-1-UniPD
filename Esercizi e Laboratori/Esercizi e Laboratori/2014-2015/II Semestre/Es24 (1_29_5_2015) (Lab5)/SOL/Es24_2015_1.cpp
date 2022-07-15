
//soluzione by: Leo M.

/*
INTRODUZIONE:

BFS (Breadth-First Search, Ricerca in Ampiezza) � un metodo di ricerca non informato, ed il suo obiettivo � quello di espandere il
raggio d'azione al fine di esaminare tutti i nodi del grafo (qui un albero binario) sistematicamente, fino a trovare il nodo cercato.
In altre parole, se il nodo cercato non viene trovato, la ricerca procede in maniera esaustiva su tutti i nodi del grafo (albero).
Questo algoritmo non � di tipo euristico.

Il procedimento da seguire per metterlo in pratica � sintetizzato come segue:

1. Mettere in coda il nodo radice.
2. Togliere dalla testa della coda un nodo (la prima volta il nodo radice) ed esaminarlo.
	- se l'elemento cercato � trovato in questo nodo viene restituito il risultato e la ricerca si interrompe.
	- se l'elemento cercato non era in questo nodo, aggiungere in coda tutti i successori (non ancora visitati) del nodo in analisi.
3. Se la coda � vuota, ogni nodo dell'albero � stato visitato e l'elemento non � stato trovato (perch� non presente), quindi la ricerca si interrompe.
4. Se la coda non � vuota si ripete il passo 2.

Ad ogni iterazione/istanza, i nodi fanno parte di una di queste tre famiglie:
- "visitato"
	� gi� stato verificato che non � il nodo cercato (di certo i sui discendenti sono gi� stati visitati oppure sono nella coda, cio� in corso di visita).
- "in corso di visita"
	� all'interno della coda, in attesa di essere visitato.
- "non visitato".
	non � gi� stato visitato e non � ancora nella coda.
*/


#include<iostream>
#include<fstream>

using namespace std;



struct nodo_a
{
	int info;
	nodo_a *left;
	nodo_a *right;
	
	nodo_a(int a=0, nodo_a *b=0, nodo_a *c=0)
	{	info=a;
		left=b;
		right=c;
	}
};


struct nodo_l
{
	nodo_a *t;
	nodo_l *next;
	
	nodo_l(nodo_a *a=0, nodo_l *b=0)
	{	t=a;
		next=b;
	}
};


struct FIFO
{
	nodo_l *primo;
	nodo_l *ultimo;
	
	FIFO(nodo_l *a=0, nodo_l *b=0)
	{	primo=a;
		ultimo=b;
	}
};


FIFO togli_primo(FIFO x)
{	//PRE=(x � corretto e lista(x) corretta e non � vuota).
	if( (x.primo)->next==0 )	//se c'� solo un nodo nella coda
	{
		delete (x.primo);
		return FIFO();	//chiamata al costruttore che restituisce un temporaneo anonimo con due puntatori a 0
	}
	else	//ho almeno due nodi nella coda
	{
		nodo_l *temp=x.primo;	//backup nodo corrente
		x.primo=(x.primo)->next;
		delete temp;
		return x;
	}
}	//POST=(restituisce un nuovo valore v di tipo FIFO corretto e tale che lista(v)=L', dove lista(x)=a::L' e il nodo_l "a" � stato deallocato con la delete).


FIFO accoda(FIFO x, nodo_a *a)
{	//PRE=(x � corretto, possibilmente vuoto, "a" punta ad un nodo valido)
	if(!(x.primo))	//la coda era vuota, devo "accodare" il primo nodo
		x.primo=x.ultimo= new nodo_l(a,0);
	else	//la coda non era vuota, per cui in fondo aggiungo un nodo
	{
		(x.ultimo)->next= new nodo_l(a,0);
		x.ultimo=(x.ultimo)->next;
	}
	return x;
}	//POST=(restituisce v di tipo FIFO corretto con lista(v)=lista(x)@nodo_l(a,0))


void del(FIFO &x)
{	//PRE(x � corretto).
	if( !(x.primo) )
	{
		x.ultimo=0;	//x.primo � gi� zero, azzero anche x.ultimo
		return;
	}
	else
	{
		nodo_l *a=x.primo;	//backup nodo attuale
		x.primo=(x.primo)->next;	//bypasso il nodo attuale
		delete a;	//cancello il nodo attuale
		del(x);	//ricorro
		return;
	}
}	//POST(tutta la coda sar� deallocata e x.primo=x.ultimo=0).


FIFO f1(nodo_a *r)
{	//PRE=(albero(r) � corretto).
	if(!r)	//l'albero � vuoto
		return FIFO();	//chiamata al costruttore che restituisce un temporaneo anonimo con due puntatori a 0
	else	//l'albero ha almeno un nodo (cio� almeno la radice)
	{
		nodo_l *a=new nodo_l(r, 0);	//creo il primo elemento della coda il cui info � un puntatore alla root dell'albero
		return FIFO(a,a);	//restituisco la coda di tipo FIFO, con primo e ultimo che puntano all'unico nodo della coda che punta alla root dell'albero
		/*in alternativa:
		FIFO x;
		return accoda(x, r);
		//o ancora peggio: return accoda(FIFO(), r); */
	}
}	/*POST=(se albero(r) � NON vuoto: restituisce il valore FIFO x che � corretto e tale che lista(x) � costituita da un solo nodo che punta a r;
			altrimenti: restituisce il valore FIFO x corretto e tale che lista(x) non � costituita da nessun nodo (x.primo=x.ultimo=0)). */
/* NOTA:
Un valore x di tipo FIFO � corretto se i suoi due campi (x.primo e x.ultimo) puntato rispettivamente al primo e all�ultimo nodo di una lista di tipo nodo_l corretta.
Con lista(x) indicheremo questa lista che pu� anche essere vuota (nel qual caso x.primo e x.fine sarebbero 0).
*/


nodo_a *f2(FIFO x, int y, ofstream &OUT)
{	//PRE=(x � corretto, y definito).
	
	/* deve fare:
	prendere un valore FIFO x
	testare se il primo nodo matcha
		se NON matcha (continuare):
			stampare il campo info
			aggiungere i suoi figli in fondo alla coda
			togliere dalla coda il primo nodo (appena testato)
			ricorrere (finch� ho nodi in coda)
		se matcha (fermare tutto):
			distruggere tutta la coda
			ritornare il puntatore al nodo attuale
	*/
	
	if(!x.ultimo)	//non esiste un ultimo elemento della coda, quindi la coda � vuota
		return 0;
	else	//ci sono ancora elementi in coda, continuo l'esplorazione
	{
		if( ((x.primo)->t)->info != y )	//se il primo nodo della coda, punta ad un nodo dell'albero che ha un campo info che NON matcha con y
		{
			OUT<<"nodo:"<<((x.primo)->t)->info<<" ";	//stampo il campo info in questione
			
			if(((x.primo)->t)->left)	//se il nodo in valutazione ha un figlio sinistro
				x=accoda(x, ((x.primo)->t)->left);	//aggiungilo alla coda
			if(((x.primo)->t)->right)	//se il nodo in valutazione ha un figlio sinistro
				x=accoda(x, ((x.primo)->t)->right);	//aggiungilo alla coda
			
			x=togli_primo(x);	//rimuove il primo elemento della coda (appena testato e non andava bene)
			
			return f2(x, y, OUT);	//procediamo con gli altri elementi della coda
		}
		else	//il primo nodo della coda, punta ad un nodo dell'albero che ha un campo info che MATCHA con y
		{
			nodo_a *temp=(x.primo)->t;
			del(x);	//dealloca tutta la coda
			return temp;
		}
	}
}	/*POST=(stampa i campi info di tutti i nodi esaminati (con ordine breadth-first da sinistra) alla ricerca del primo nodo con info==y:
			- la stampa avviene nella forma: "nodo:w ",	dove w � il campo info del nodo esaminato;
			- se trovato un nodo con campo info==y, ritorna un puntatore a tale nodo e distrugge (con la delete) la lista x (di tipo FIFO) residua, altrimenti ritorna 0). */


void stampa_l(nodo_a *r)
{
	if(r)
	{
		cout<<r->info<<'(';
		stampa_l(r->left);
		cout<<',';
		stampa_l(r->right);
		cout<<')';
	}
	else
		cout<<'_';
}


int conta_n(nodo_a *r)
{
	if(!r)
		return 0;
	else
		return conta_n(r->left)+conta_n(r->right)+1;
}


nodo_a *insert(nodo_a *r, int y)
{
	if(!r)
		return new nodo_a(y);
   
	if(conta_n(r->left)<=conta_n(r->right))
		r->left=insert(r->left,y);
	else
		r->right=insert(r->right,y); 
	return r;
}


nodo_a *rep_ins(nodo_a *r, int dim, ifstream &INP)
{
	if(dim)
	{
		int z;
		INP>>z;
		nodo_a *x=insert(r,z);
		return rep_ins(x,dim-1,INP);
	}
	return r;
}





main()
{
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT) 
	{ 
		int dim, y;
		INP>>dim;
		nodo_a* R=rep_ins(0,dim,INP);	//data

		INP>>y;
		FIFO x=f1(R);	//da fare
		nodo_a *a=f2(x,y,OUT);	//da fare
		
		if(a)
			OUT<<"trovato "<<a->info<<endl;
		else
			OUT<<"non trovato"<<endl;

		INP.close();
		OUT.close();
	}
	else
		cout<<"errore con i files";
}
