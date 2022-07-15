#include<iostream>
using namespace std;
struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};
int contaFoglie(nodo* r);

void sc(int* C)
{
  if(*C!=-1)
   {cout<<*C<<' '; sc(C+1);}
  else
    cout<<"fine cammino"<<endl;
}
nodo* buildtree(nodo* r, int n);
void stampa_l(nodo *r);


bool cerca_cam(nodo*r, int k, int y, int*C) ;


nodo* alberobil (nodo*r, int k);
int main()
{
  int n, k,y;
  cin>>n;
  nodo* R=buildtree(0,n);//da esercizio del 17/5
  cout<<"start"<<endl;
  stampa_l(R);

  cin>>k>>y;
  int C[30];
  bool b=cerca_cam(R,k,y,C); //da fare
  cout<<endl;
   if(b)
     {cout<<"trovato  cammino= "; sc(C);} //sc data
   else
    cout<<"nessun cammino con "<<k<<" valori="<<y<<endl;
   cout<<"end";
}
void stampa_l(nodo *r)
{
    if(r){
        cout<<r->info<<'(';
        stampa_l(r->left);
        cout<<',';
        stampa_l(r->right);
        cout<<')';
    }
    else
        cout<< '_';
}
nodo* alberobil (nodo*r, int k) {


    if(!r) return new nodo(k,0,0);
    //caso base 1: il nodo e' vuoto, percio' il nodo va inserito nella posizione corrente.



    if(r->left && r->right){
        int contaLeft= contaFoglie(r->left);

        int contaRight= contaFoglie(r->right);

        if(contaLeft>contaRight )


            r->right= alberobil(r->right,k);

        else

            r->left= alberobil(r->left,k);

         return r;

    }


    if(r->left ){

        r->right= alberobil(r->right,k);


        return r;
    }else{


         r->left= alberobil(r->left, k);

        return r;
    }
}

//PRE=(albero(r) è corretto e bilanciato, n>=0, valbero(r)=albero(r))
nodo* buildtree(nodo* r, int n) {
      if(n){
         int info;
         cin>> info;

         r = alberobil(r,info);

         buildtree(r,n-1);
     }
     return r;
}
//POST=(restituisce valbero(r) con n nodi aggiuntivi inseriti in modo da conservare il bilanciamento)

//PRE=(albero(r)  è ben formato e non vuoto, k>=0 e y valore qualsiasi, C ha almeno tanti elementi quanta è l'altezza di albero(r) )

bool cerca_cam(nodo*r, int k, int y, int* C){


	if(r->info == y)
		k--;
	if(!r->left && !r->right && k==0){
		//caso base 1: non esiste ne ramo destro ne quello sinistro, quindi il nodo e' una foglia, e siccome k== 0
		// il che garantisce che sono stati trovati tutti i k elementi richiesti dalla consegna. Quindi termina la sequenza dei cammini con
		// -1, e restituisce true.
		C[0]=-1;
		return true;
	}
	if(k>0){

		bool left=false,right=false;

		//PRE_ric: albero(r->left) e' ben formato e non vuoto, k>=0, y valore qualsiasi,
		//C a almeno tanti elementi quanta e' altezza dell'albero (r)
		left=cerca_cam(r->left,k,y,C+1);
		/*
		 * POST_ric: restituisce true sse in albero (r->left) esiste un cammino da r->left ad una foglia con esattamente k nodi con
		 * campo info =y e false altrimenti in caso restituisse true C+1 contiene una sequenza (anche vuota di 0/1) con -1 finale e che individua
		 * il cammino piu' a sinistra dell'albero con esattamente k nodi con campo info =y.

		*/
		C[0]=0;
		if(!left){


			//PRE_ric: albero(r->left) e' ben formato e non vuoto, k>=0, y valore qualsiasi,
			//C a almeno tanti elementi quanta e' altezza dell'albero (r)
			right=cerca_cam(r->right,k,y,C+1);
			/*
			 * POST_ric: restituisce true sse in albero (r->left) esiste un cammino da r->left ad una foglia con esattamente k nodi con
			 * campo info =y e false altrimenti in caso restituisse true C+1 contiene una sequenza (anche vuota di 0/1) con -1 finale e che individua
			 * il cammino piu' a sinistra dell'albero con esattamente k nodi con campo info =y.
			*/
			C[0]=1;

		}
		return left || right;
	}
	// caso base 2: il nodo corrente non e' non una foglia, ma sono stati trovati tutti i k elementi con info ==y,
	// quindi come da richieste dell'insegnate si restituisce false.
	return false;

	/**			Prova di correttezza:
	 *
	 *
	 * caso base 1: se non esistono ne il ramo sx ne quello sx, allora il nodo corrente e' una foglia && con k == 0 allora
	 * sono stati trovati k elementi con il campo info == y.
	 *
	 * caso base 2: il nodo corrente non e' una foglia
	 *
	 *
	 */



}
//POST_cerca=(restituisce true sse in albero(r)esiste un cammino da r ad una foglia con esattamente k nodi con campo info=y
//e false altrimenti) &&(in caso restituisca true, C contiene una sequenza (anche vuota) di 0/1
//seguita da-1 e che individua il cammino più a sinistra in albero(r) con esattamente k nodi con campo info=y).


int contaFoglie(nodo* r){


    if(!r) return 0;

    return 1+contaFoglie(r->left)+contaFoglie(r->right);
}
