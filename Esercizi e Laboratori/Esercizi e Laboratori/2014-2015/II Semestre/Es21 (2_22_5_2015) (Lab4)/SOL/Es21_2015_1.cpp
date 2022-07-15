//sgranare una lista creandone 2 che utilizzano alternativamente i nodi di quella originale

/*
Si tratta di "sgranare" una lista concatenata L in 2 liste concatenate, L1 e L2,
tali che L1 contenga i nodi nelle posizioni dispari di L, mentre L2 contenga i nodi di L nelle posizioni pari.
I nodi di L1 ed L2 devono mantenere tra loro lo stesso ordine relativo che avevano in L.
Nel seguito useremo la seguente terminologia per indicare le 2 liste L1 ed L2 ottenute "sgranando" L: SG(L)=(L1,L2).
*/

#include<iostream>
#include<fstream>

using namespace std;



struct nodo
{
	int info;
	nodo *next;
	
	nodo(int a=0, nodo* b=0)
	{
		info=a;
		next=b;
	}
};


struct dueL
{
	nodo *prima, *seconda;
	
	dueL(nodo*a=0, nodo* b=0)
	{
		prima=a;
		seconda=b;
	}
};


nodo *crea(int dim, ifstream &INP)
{
	if(dim)
	{
		int x;
		INP>>x;
		return new nodo(x,crea(dim-1,INP));
	}
	return 0;
}


nodo *clona_rov(nodo *L, nodo* rov)
{
	if(L)
		return clona_rov(L->next,new nodo(L->info,rov));
	else
		return rov;
}


void stampa(nodo *L, ofstream &OUT)
{
	if(L)
	{
		OUT<<L->info<<' ';
		stampa(L->next,OUT);
	}
	else
		OUT<<endl;
}


dueL sgrana(nodo *L)
{	//PRE=(L è una lista corretta, eventualmente vuota).
	/*
	 se ho ancora 2 nodi:
	  - il primo va' in L1
	  - il secondo in L2
	  - ricorro saltando i due nodi
	 se non ho 2 nodi:
	  - o ne ho solo 1 (che va' in L1)
	  - o ne ho 0 (null'altro da fare)
	  
	 cambio in:
	  - se ho 0 nodi: niente da fare.
	  - se ho 1 nodo: attacco in L1.
	  - se ho due (o piu') nodi:
	  	ricorro (con L-2), otterrò L1 ed L2 (di L-2);
		attacco il primo in testa ad L1 e il secondo in testa ad L2;
		aggiorno L1 ed L2 da tornare.
	*/
	if(!L)
	{
		dueL W;	//di default W.L1=0 e W.L2=0
		return W;
	}
	else	//ho almeno 1 nodo
	{
		if(!L->next)	//ho solo questo nodo
		{
			dueL W(L,0);	//attacco ad L1 l'ultimo nodo che ha gia' campo next=0, e termino L2
			return W;
		}
		else	//ho almeno un altro nodo oltre a questo
		{
			dueL W=sgrana(L->next->next);	//invocazione ricorsiva che mi restituirà le cose giuste per il resto della lista L senza i primi due nodi
			
			nodo *x=L->next;	//diamo un nome nodo 2 dei due che ho qui (il primo è L)
			L->next=W.prima;	//attacchiamo al (campo next del) nodo 1 la lista dei dispari restituita dalla ricorsione
			x->next=W.seconda;	//attacchiamo al (campo next del) nodo 2 la lista dei pari restituita dalla ricorsione
			
			//preparo la struttura da ritornare, dato che ne ho già una (W), al momento inutilizata, la reciclo:
			W.prima=L;		//dato che ho attaccato in testa ad L1 il nodo L ora L1 deve puntare al nodo L
			W.seconda=x;	//dato che ho attaccato in testa ad L2 il nodo x ora L2 deve puntare al nodo x
			
			return W;
			
		}
	}
	
/*
	//NOTA:
	//questa stessa funzione la si potrebbe scrivere in tanti altri modi, ad esempio dichiarando un dueL W prima di tutto, aggiornare nel modo giusto quello e ritornarlo;
	//oppure in modo più "compatto", segue una versione compatta:
		
	if(!L)
		return dueL(0,0);	//è una chiamata al costruttore, crea un temp_anonimo e o ritorna (in teroia funziona anche: "return dueL;")
	else	//ho almeno 1 nodo
	{
		if(!L->next)	//ho solo questo nodo
			return dueL(L,0);	//è una chiamata al costruttore, crea un temp_anonimo e o ritorna; attacco ad L1 l'ultimo nodo che ha gia' campo next=0, e termino L2
		else	//ho almeno un altro nodo oltre a questo
		{
			dueL W=sgrana(L->next->next);	//chiamata ricorsiva su quel che resta della lista tolti i primi 2 nodi
			
			L->next->next=W.seconda;	//attacco al nodo 2 la lista L2 (dei pari) tornata dalla ricorsione
			W.seconda=L->next;			//ora L2 comprende un nuovo nodo, quindi aggiorno il puntatore
			
			L->next=W.prima;			//attacco al nodo 1 la lista L1 (dei dispari) tornata dalla ricorsione
			W.prima=L;					//ora L1 comprende un nuovo nodo, quindi aggiorno il puntatore
			
			return W;	//ritorno la nuova coppia di puntatori alle nuove L1 ed L2
		}
	}
*/
}	//POST=(detto V quanto restituito dalla funzione, allora V.prima=L1 e V.seconda=L2, dove SG(L)=(L1,L2)).


nodo* sgrana2(nodo* &L)
{	//PRE=(L è una lista corretta, eventualmente vuota).
	/*
	tramite (side effect su) L restituirò la lista dei nodi pari
	tramite la return restituirò la lista dei nodi dispari
	*/
	if(!L)
	{
		L=0;	//inutile, se sono qui L è già 0
		return 0;
	}
	else	//ho almeno 1 nodo
	{
		if(!L->next)	//ho solo 1 nodo
		{
			nodo *x=L;	//copia locale di L
			L=0;		//essendo "L" alias del campo next del precedente nodo (che sarà l'ultimo della lista dei pari) lo azzero
			return x;
		}
		else	//ho almeno 2 nodi
		{
			nodo *x, *y;	//chiamo il primo dei due "x" ed il secondo "y"
			x=L;
			y=L->next;
			
			L=y;	//dato che tramite L (alias del campo next del nodo che precede l'attuale coppia di nodi) devo restituire la lista dei pari, ci attacco y (SIDE-EFFECT)
			
			/* al campo next del primo nodo (x), dispari, devo attacare L1 (la lista dei dispari di L-2), restituita dall'invocazione ricorsiva;
			   il campo next del secondo nodo (y), pari, dovrà essere aggiornato tramite il side-effect della chiamata ricorsiva */
			x->next=sgrana2(y->next);
			
			return x;
		}
	}
	
/*
	//NOTA:
	//questa stessa funzione la si potrebbe scrivere in tanti altri modi, ad esempio in modo più "compatto";
	//segue una versione compatta:
		
	if(!L)
		return 0;	//L è già =0
	else	//ho almeno 1 nodo
	{
		if(!L->next)	//ho solo questo nodo
		{
			nodo *x=L;	//copia locale di L
			L=0;		//essendo "L" alias del campo next del precedente nodo (che sarà l'ultimo della lista dei pari) lo azzero
			return x;
		}
		else	//ho almeno un altro nodo oltre a questo
		{
			nodo *x=L;	//copia locale di L
			
			//dato che tramite L (alias del campo next del nodo che precede l'attuale coppia di nodi) devo restituire la lista dei pari, ci attacco il secondo (SIDE-EFFECT)
			L=L->next;
			
			// al campo next del primo nodo (x), dispari, devo attacare L1 (la lista dei dispari di L-2), restituita dall'invocazione ricorsiva;
			// il campo next del secondo nodo (L->next), pari, dovrà essere aggiornato tramite il side-effect della chiamata ricorsiva
			x->next=sgrana2(L->next);	//oppure: x->next=sgrana2(x->next->next);
			
			return x;
		}
	}
*/	
}	//POST=(detti: "v" quanto restituito dalla funzione e "vL" la lista d'invocazione, allora: L=L1 e v=L2, dove SG(vL)=(L1,L2)).



main()
{
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT)
	{ 
		int dim;
		INP>>dim;
		nodo *L1=crea(dim,INP);	//data
		nodo *L2=clona_rov(L1,0);	//clona L1 in ordine inverso, data
		
		dueL W=sgrana(L1);	// da fare (a)
		
		nodo *L3=sgrana2(L2);	// da fare (b)
		
		stampa(W.prima,OUT);	//data
		stampa(W.seconda,OUT);	//data
		stampa(L3,OUT);	//data
		stampa(L2,OUT);	//data
		
		INP.close();
		OUT.close(); 
	}
	else
		cout<<"errore con i files";
}
