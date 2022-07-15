#include<iostream>
using namespace std;

struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};
int contaFoglie(nodo* r);
nodo* buildtree(nodo* r, int n);
nodo* alberobil (nodo*r, int k);

void stampa_l(nodo *r);
int stampa_a_salti(nodo* r, int k, int n);

int main()
{
  int dim,k;
  cin>>dim;
  nodo* R=buildtree(0,dim);
  cout<<"start"<<endl;
  stampa_l(R);
  cin>>k;
  int b=stampa_a_salti(R,k,k);
  cout<<endl;
  cout<<"valore restituito="<<b<<endl;
  cout<<"end"<<endl;
}
//PRE= (albero(r) è ben formato, k>0, 1<=n<=k)
int stampa_a_salti(nodo* r, int k, int n){

	if(!r) return n;
	//caso base: il nodo corrente e' nulla, percio' non devo effettuare nessuna operazione se non quello di restituire valore ddi n.

	if(n==1){
		// quando ricevo il valore di n ==1  quindi devo stampare il valore info del nodo corrente
		// percio' il valore di n va ripristinato a k per ricominciare una nuova ricerca.
		cout<<r->info<<" ";
		n=k;
	}else
		n--;

	//caso ricorsivo ramo sinistro
	//PRE_ric: albero(r->left) e' ben formato k>0, 1<=n<=k
	n= stampa_a_salti(r->left,k,n);
	//POST_ric:(stampa i campi info dei nodi di albero(r->left) in ordine prefisso nel modo seguente: salta i primi n-1,
	//stampa il nodo n-esimo, poi ne salta k-1 stampa quello successivo e così via fino a visitare tutti i nodi) &&
	//(restituisce un intero m (1<=m<=k)  cheindica che si dovranno saltare m-1 nodi prima di stampare il
	//prossimo)

	//caso ricorsivo ramo destro:
	//PRE_ric: albero(r->left) e' ben formato k>0, 1<=n<=k
	n=stampa_a_salti(r->right,k, n);
	//POST_ric:(stampa i campi info dei nodi di albero(r->right) in ordine prefisso nel modo seguente: salta i primi n-1,
	//stampa il nodo n-esimo, poi ne salta k-1 stampa quello successivo e così via fino a visitare tutti i nodi) &&
	//(restituisce un intero m (1<=m<=k)  che indica che si dovranno saltare m-1 nodi prima di stampare il
	//prossimo)

	return n;

	/* 								Prova di correttezza:
	 *
	 * caso base 1: il nodo corrente e' nullo, percio'  n deve essere restituito tale quale perche' non e' stato visitato nessun nodo.
	 *
	 * caso base 2: il valore di n corrente e' pari a 1,il che vuol dire che devo stampare questo nodo, lo stampo, e ripristino il
	 * 	valore di n = k, per ricominciare a scorrere i nodi.
	 *
	 * caso ricorsivo ramo sinistro:
	 *
	 *
	 *
	 *
	 * caso ricorsivo ramo destro:
	 *
	 *
	 *
	 *
	 *
	 *
	 */

}
//POST=(stampa i campi info dei nodi di albero(r) in ordine prefisso nel modo seguente: salta i primi n-1,
//stampa il nodo n-esimo, poi ne salta k-1 stampa quello successivo e così via fino a visitare tutti i nodi) &&
//(restituisce un intero m (1<=m<=k)  cheindica che si dovranno saltare m-1 nodi prima di stampare il
//prossimo)

int contaFoglie(nodo* r){
    if(!r) return 0;

    return 1+contaFoglie(r->left)+contaFoglie(r->right);
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
