#include<iostream>
using namespace std;
// dichiarazioni strutture
struct nodo{
	int info;
	nodo* next;

	nodo(int a=0, nodo* b=0){
		info=a;
		next=b;
	}
};

struct DoppiaLista{
	nodo* listamatch, * restante;
	DoppiaLista(nodo* match=0, nodo* rest=0){
		listamatch=match;
		restante=rest;
	}
};


//prototipi funzioni
nodo* crea(int dim);
void stampa(nodo*L);
void leggi(int dim, int*P);
DoppiaLista* match2(nodo*&, int*,int);
bool confronta(nodo*& n, int*P, int dimP, nodo*& );

int main()

{
   int dim, dimP, P[20];
   cin>>dim;
   nodo* L1=crea(dim);
   cin>>dimP;
   leggi(dimP, P);
   cout<<"start"<<endl;
   DoppiaLista* D= match2(L1,P, dimP); 
   if(!D)
     {
       cout<<"no match"<<endl;
       cout<<"Lista T e':";
       stampa(L1);
     }
   else
     {
       stampa(D->listamatch);
       if(D->restante)
	 stampa(D->restante);
       else
	 cout<<"Lista restante vuota"<<endl;
     }
   cout<<"end"<<endl;
}


//PRE=(L(n) è corretta, dimP>=0, P contiene dimP elementi)
DoppiaLista* match2(nodo* &lista, int* P,int dimP){


	nodo* ultimoNodo;
	if(!lista) return 0;//caso base 1: la lista e' terminata, quindi non ci sono piu' elementi da matchare,
	//percio' e' corretto che restituisce una oggetto struct DoppiaLista  X = nulla.


	bool trovato=confronta(lista,P,dimP,ultimoNodo);

	if(trovato){
		// caso base 2: e' stato trovato un match quindi devo restituire le informazioni richieste nel POST condizione del metodo.
		/*
		 * ovvero:
		 *
		 * 	la L(matchata) e' ben formata ed e' formata dagli nodi della lista fino al ultimoNodo, inoltre ultimoNodo->next= 0.
		 *
		 * 	la L(restante) e' ben formata dalla L(lista) - L(matchata).
		 *
		 * 	e quindi restituisco un oggetto DoppiaLista(L(matchata), L(restante));
		 */

		nodo* restante, * matchata;

		matchata = lista;

		restante= ultimoNodo->next;

		ultimoNodo->next=0;
		lista= restante;

		return new DoppiaLista(matchata,lista);
	}else{

		//PRE_ric: L(N->next) e' corretta, vettore P ha dimP elementi.
		DoppiaLista* ret= match2(lista->next, P, dimP);
		//caso ricorsivo: non e' stato trovato nessun match appartire dal nodo n.

		/*
		* POST_ric: restituisce una struct di tipo DoppiaLista X sse e' stata trovata una match nella L(n->next) di P, dove
		* L(X->restante) e' la vL(lista) meno gli elementi che matchano con gli elementi dell'array P
		* che sono in L(X->listamatch) con ultimo nodo che punta a NULL, rendendola una lista ben formata.
		* se la L(lista) e' L(nonMatchIniziale)@L(match)@restante allora, ret->listamatch= match
		* mentre ret->restante = L(nonMatchInziale)@restante
		*
		*/


		if(ret != 0){

			ret->restante=lista;
			return ret;
		}
		return ret;

	}
	/*		prova di Correttezza:
	 *
	 * caso base 1: non e' stato trovato nessun match, quindi e' corretto che restituisca NULL
	 *
	 * caso base 2: e' stato trovato un match, quindi devo restituire un oggetto che contenga una lista dove e' stata trovata la match.
	 *
	 * caso ricorsivo:non e' stato ancora trovato un match, quindi devo effettuare la ricerca per il match a partire dal nodo successivo,
	 * quindi e' corretta la chiamata ricorsiva match2(lista->next,  P, dimP).
	 *
	 * Presumendo che PRE sia corretta, il PRE_ric e' corretta poiche' se non si trova il match dal nodo corrente, quindi devo fare la ricerca dal
	 * lista->next, con i stessi parametri per gli array.
	 *
	 * Per il passo induttivo, se appartire dal nodo lista->next non e' stata trovata il match, allora effettua la ricerca dal nodo successivo
	 * ancora, finche' non viene trovato un match o finche' la lista non si esaurisce.
	 *
	 * nel primo caso viene restituito indirizzo del primo nodo dove e' stata trovata la match, e ultimo nodo che punta a NULL cioe' una lista
	 *  ben formata e la lista rimanente che punta al nodo successivo dell'ultimonodo. Al ritorno da ogni chiamata ricorsiva si controlla se il risultato del return
	 * fosse NULL, se si, si restituisce di nuovo NULL, altrimenti si assegna il valore della lista attuale al ret->restante concantenando cosi'
	 * la rimanente della lista al nodo attuale formando la lista dei nodi rimanenti.
	 *
	 * nel secondo caso restituisce NULL che viene perpetuato con il ritorno delle chiamate ricorsive.
	 *
	 * Quindi POST_ric e' corretta, allora lo e' anche POST condizione della funzione, perche' la prima chiamata  effettua il controllo
	 * su intera lista, mentre la prima chiama ricorsiva sulla lista dal nodo successivo.
	 *
	 */


}
/*
 * POST=(se esiste match di P in L(n) allora match2 restituisce il puntatore X ad un valore
 * di tipo doppialista tale che X->listamatch sia la lista del match trovato e X->restante sia
 * la lista restante, se invece non c’è match, match2 restituisce il puntatore 0 e L(n) resta inalterata).
 */


bool confronta(nodo* &n, int*P, int dimP, nodo*& ultimoNodo)
{
    if (n)
    {
        if (n->info==*P)
        {
            if (dimP==1)
            {
                ultimoNodo=n;
                nodo* a=n->next;
                return true;
            }
            return confronta(n->next, P+1, dimP-1, ultimoNodo);
        }
    }
    return 0;
}
nodo* crea(int dim)
{
 if(dim)
  {
    int x;
    cin>>x;
    return new nodo(x,crea(dim-1));
  }
 return 0;
}
void stampa(nodo*L)
{
  if(L)
  {
    cout<<L->info<<' ';
    stampa(L->next);
  }
 else
    cout<<endl;
}
void leggi(int dim, int*P)
{
  if(dim)
   {
    cin>>*P;
    leggi(dim-1,P+1);
   }

}
