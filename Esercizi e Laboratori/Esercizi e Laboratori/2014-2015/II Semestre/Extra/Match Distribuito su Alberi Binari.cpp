
//by: Leo M.

/* NOTA:
questo programma cerca un match completo (e non necessariamente contiguo) di un array P su un albero binario.
se il match viene trovato restituisce una lista opportunamente creata i cui nodi hanno come campo info un puntatore al nodo dell'albero che matchava;
quindi (as esempio) se c'è match completo, l'elemento P[3] ha matchato con il campo info del nodo dell'albero puntato dal quarto (quello di indice 3) nodo della lista restituita.
è in stretta relazione con gli esercizi svolti in aula (Es 1 e 2 del 25.06.2015 ed Es 3 e 4 del 26.06.2015);
la particolarità è che cerca i math non solo lungo un cammino, ma su TUTTO l'albero, ovunque esso sia distribuito,
anche se gli unici due elementi del match cercato sono uno sulla foglia più in basso a sinistra e l'altro su quella più in basso a destra.
PS: se non c'è match completo allora restituirà 0.

Invocazione:
nodo_lista L;
L=lancia(*R, P, dimP);

PPS: manca ovviamente il main e tutta la parte che si occupa di generare l'albero, riempire l'array P, ecc ecc (tutta roba facilmente reciclabile dagli altri esercizi).
*/

struct nodo_albero
{
	//membri - campi dati
	int info;
	nodo_albero *left, *right;

	//costruttore
	nodo_albero(int a=0, nodo_albero* b=0, nodo_albero*c=0)
	{
		info=a;
		left=b;
		right=c;
	}
};


struct nodo_lista
{
	//membri - campi dati
	nodo_albero *p;
	nodo_lista *next;

	//costruttore
	nodo_lista(nodo_albero *a=0, nodo_lista* b=0)
	{
		p=a;
		next=b;
	}
};


nodo_lista *conc(nodo_lista *L1, nodo_lista *L2)
{	//PRE=(lista(L1) e lista(L2) sono corrette).
	if(!L1)	//se L1 è vuota, ritorno semplicemente L2
		return L2;
	else	//altrimenti scorro L1 fino in fondo, al ritorno riattacco tutto
	{
		L1->next=conc(L1->next, L2);	//fa un sacco di "riagganci" inutili
		return L1;
	}
}	//POST=(detto c il puntatore restituito, allora lista(c)=lista(a)@lista(b)).


void cancella(nodo_lista* L)
{
	if(!L)
		return;
	else
	{
		cancella(L->next);
		delete L;
		L=0;
		return;
	}
}


//Versione 1 della funzione (in fondo ne trovate un'altra commentata e molto più stringata)
nodo_lista *match_alb_nc_distr(nodo_albero *r, int *&P, int &dimP)	//match non contiguo e distribuito (non solo su un cammino) su un albero
{
	if(!dimP)	//ho finito gli elem da matchare, mi fermo
		return 0;
	if(!r)	//sono uscito dall'albero, mi fermo
		return 0;
	
	if(r->info==*P)	//il nodo corrente mi interessa
	{
		nodo_lista *L1=new nodo_lista(r, 0);
		dimP=dimP-1;
		P=P+1;
		
		nodo_lista *L2=match_alb_nc_distr(r->left, P, dimP);	//esploro a sx
		nodo_lista *L3=match_alb_nc_distr(r->right, P, dimP);	//esploro a dx
		
		L1=conc(L1,L2);
		L1=conc(L1, L3);
		return L1;
	}
	else	//il nodo corrente non mi interessa
	{
		nodo_lista *L2=match_alb_nc_distr(r->left, P, dimP);	//esploro a sx
		nodo_lista *L3=match_alb_nc_distr(r->right, P, dimP);	//esploro a dx
		
		L2=conc(L2,L3);
		return L2;
	}
}


nodo_lista *lancia(nodo_albero *r, int *P, int dimP)
{
	int *q=P;
	int copia_dimP=dimP;
	
	nodo_lista *L=match_alb_nc_distr(r, q, copia_dimP);
	
	if(!copia_dimP)	//il match trovato è completo
		return L;
	else	//il match trovato è solo parziale, và distrutta la lista che lo contiene!
	{
		if(L)
			cancella(L);
		return 0;
	}
}



/* Versione 2:
nodo_lista *match_alb_nc_distr(nodo_albero *r, int *&P, int &dimP)	//match non contiguo e distribuito (non solo su un cammino) su un albero
{
	if(!dimP)	//ho finito gli elem da matchare, mi fermo	//oppure tutto con: if(!dimP || !r) return 0;
		return 0;
	if(!r)	//sono uscito dall'albero, mi fermo
		return 0;
	
	nodo_lista *L1=0;
	
	if(r->info==*P)	//il nodo corrente mi interessa
	{
		L1=new nodo_lista(r, 0);
		dimP=dimP-1;
		P=P+1;
	}
	
	nodo_lista *L2=match_alb_nc_distr(r->left, P, dimP);	//esploro a sx
	nodo_lista *L3=match_alb_nc_distr(r->right, P, dimP);	//esploro a dx
	
	if(L1)	//oppure semplicemente da qui in giù tolgo tutto e diventa: return conc(conc(L1,L2),L3);
		L2=conc(L1,L2);
		
	return conc(L2,L3);
}
*/
