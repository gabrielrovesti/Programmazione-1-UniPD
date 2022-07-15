#include <iostream>
using namespace std;

struct nodo{
	int info;
	nodo* next;
	nodo (int x=0, nodo* n=0){
		info=x;
		next=n;
	}
};

void stampa(nodo* x){
	if(x){
		cout<<x->info;
		stampa(x->next);
	}
}

void stampaRovescio(nodo *x){
	if(x){
		stampa(x->next);
		cout<<x->info<<"";
	}
}


//operazioni sulle liste concatenate

/*
								 ********************************************************
								 * 														*
								 * 														*
								 * 	 	Inserire i nodi alla fine della lista			*
								 * 														*
								 * 														*
								 ********************************************************

 * Per indicare la lista puntata da n si usa L(n) oppure Lista(n)
 * una lista e' benformata sse ultimo nodo ha il nodo* =0
 *
 *
 *
 * L1 @ L2 concatena due lista: quando ultimo nodo del L1 punta al primo nodo di L1
 *
 * scrivere un metodo che ha come parametro un indirizzo nodo* e un'unita' informativa, e inserisce l'informazione alla fine del nodo
 */

// 									PrimaSoluzione
//PRE: L(n) e' ben formata vL(n) = L(n)
nodo* ins_end(nodo *inizio, int n){
	//caso base: la lista e' vuota, quindi basta creare il nuovo nodo e restituire indirizzo del nuovo nodo

	if(!inizio){
		return new nodo(n,0);

	}else{

		inizio->next=ins_end(inizio->next,n);

		//  inizio->next ha L valore, mentre al secondo inizio->next ha R valore.
		return inizio;
	}
}
//POST: restituisce vL(n) @ nodo(c,0)

//								SecondaSoluzione

//PRE: L(n) e' ben formata e non vuota vL(n) = l(n)
void ins_end2(int n,nodo* inizio){

	if(!inizio->next){
		inizio->next= new nodo(n, 0);
	}else{
		ins_end2(n,inizio->next);
	}

}
//POST: L(n) = vL(n) @ nodo(num,0)


//								TerzaSoluzione

//PRE: L(n) e' lista corretta, vL(n) = L(n)
void ins_end3(int num, nodo* & inizio){

	if(!inizio)
	inizio= new nodo(num, 0);
	else{
		ins_end3(num,inizio->next);
	}

}
//POST L(n) = vL(n) @nodo(c,0)


/*
										 ********************************************************
										 * 														*
										 * 														*
										 * 		Eliminare ultimo nodo della lista				*
										 * 														*
										 * 														*
										 ********************************************************
 */

// 							Prima soluzione


//PRE: L(n) e' lista ben formata e non vuota, vL(n)= L(n)
nodo* elimina(nodo * n){

	if(!n->next){
		delete n;
		return 0;
	}
	n->next= elimina(n->next);
	return n;

}
//POST:


// 							Seconda Soluzione

//PRE:
void elimina2(nodo* n){
	if(!n->next->next){
		delete(n->next);
		n->next=0;
	}else{
		elimina2(n->next);
	}

}
//POST: L(n) = vL(n) - ultimo nodo ==> primo nodo di L(n) e uguale a quello di vL(n)


// 							Terza Soluzione
//		Col il passaggio per riferimento
//PRE: L(n) e' ben formata non vuota
void elimina3(nodo*& n){
	// invocazione if(inizio) elimina3(inizio);

	if(!n->next) {
		delete n;
		n=0;
	}else{
		delete (n->next);
	}


}
//POST: L(n) = vL(n) - ultimo nodo

/*
 *
								 ********************************************************
								 * 														*
								 * 														*
								 * 				Eliminare l'intera lista 				*
								 * 														*
								 * 														*
								 ********************************************************
 */


//PRE: L(n) e' ben formata
void del_all(nodo * n){
	if(n){
		del_all(n->next);
		delete n;
	}
}
//POST: tutti i nodi di vL(N) sono stati deallocati

/*
									*********************************************************
									* 														*
									* 														*
									* 		Inserire un nodo in posizione k=0,1,2 ecc 		*
									* 														*
									* 														*
									*********************************************************														*
 */
//				Prima Soluzione
//PRE:L(Q) bene formata , k>=0, vL(Q) = L(Q)
/*
 * caso base: il nuovo nodo va inserito al primo posto della lista
 * caso ricorsvio: se k>0
 */
nodo* inserimento(nodo* Q, int k, int c){

	if(!k) return new nodo(c,Q);
	if(!Q) return 0;

	Q->next= inserimento(Q->next, k-1, c);
	return Q;
}
//POST: se vL(Q) = vLk(Q)@R, restituisce vLk(Q)@nodo(c)@R, altrimenti vL(Q)
// non va con k =0


//PRE:

// non si riesce ad inserire il nodo all'inizoo della lista
 void inserimento2(nodo *Q, int k, int c){
	 if(k==1)
		 Q->next= new nodo(c,Q->next);
	 else
		 if(Q->next)
			 inserimento2(Q->next,k-1,c);
}
//POST:

//PRE: L(Q) e' ben formata,  k >=0
 void inserimento3(nodo* &Q, int k, int c){


	 if(!k)
		 //caso base 1
		 Q= new nodo(c,Q);// creo il nuovo nodo in mezzo al nodo di Q e al nodo puntato da Q.
		 // Primo Q e' L-valore mentre il secondo e' R-valore
	 else if(Q)// caso base 2

		 //chiamata ricorsiva

		 //PRE_ric: L(Q->next) e' ben formata, e k-1>=0
		 inserimento3(Q->next, k-1, c);
	 	 //POST_ric:


	 /*				Prova di correttezza:
	  *
	  *	caso base 1: k=0, il nuovo nodo (new nodo(c,Q)) garantisce che il nuovo nodo sia in cima alla lista corrente, percie' L(Q) e' corretta.
	  *
	  *	caso base 2: Q != 0 && k!= 0, il numero dei nodi della lista  (L(Q)) e' minore della k, quindi non si puo' inserire il nuovo nodo nella posizione corrente.
	  *
	  *	caso ricorsivo: se effettuo la chiamata ricorsiva vuol dire che k > 0 e il nodo corrente non e' null, percio' il PRE_ric vale, quindi possiamo assumere il POST_ric.
	  *			2 casi della POST_ric:
	  *
	  *
	  *	primo caso:	k-1 > numero di nodi di L(Q-next) significa che Q->next non cambia.
	  *		L(Q) non varia perche' il passaggio di Q->next per riferimento.e quindi k> # dei nodi di L(Q), percio' il POST e' vera.
	  *
	  * secondo caso: k-1 <= # dei nodi di L(Q->next) quindi abbiamo inserito il nodo, quindi k<= L(Q),  percio' dobbiamo inserire il nodo nuovo.
	  * dalla post_ric, L(Q->next) e' la vecchia lista con un nodo nuovo in posizione k-1. Il passaggio per riferimento di Q->next garantisce che n punta a L(Q->next)
	  * quindi il nuovo nodo e' inserito nella posizione k di L(Q). Allora vale il POST
	  *
	  *
	  *
	  *
	  */

 }
 //POST: Se  il numero di nodi di L(Q) e' >= k allora si inserisce nodo nella posizione K,
 //restituisce con il parametro passato per riferimento la lista con il nuovo nodo, altrimenti non effettua modifiche sulla L(Q)
 //

int main() {

	int num;
	cin>>num;
	nodo * inizio=0;
	ins_end(inizio,num);
	// serve l'assegnazione quando la lista e' inizialmente vuota, e negli altri casi non e' necessaria.

	if(!inizio){
		inizio= new nodo(num, 0);
	}else{
		ins_end2(num, inizio);
	}
}
