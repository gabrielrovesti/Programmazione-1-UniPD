#include<iostream>

#include "code.h"
using namespace std;


struct nodoA{
	char info;
	nodoA*left,*right;
	nodoA(char a='\0',nodoA*b=0,nodoA*c=0){
		info=a;
		left=b;
		right=c;
	}
};

//-----------------parte vecchia-----------------------
void stampa_l(nodoA *r)
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
    cout<< '_';
}
int conta_n(nodoA*r)
{
   if(!r) return 0;
     else
    return conta_n(r->left)+conta_n(r->right)+1;
}

nodoA* insert(nodoA*r, char y)
{
  if(!r) return new nodoA(y);

  if(conta_n(r->left)<=conta_n(r->right))
    r->left=insert(r->left,y);
   else
    r->right=insert(r->right,y);
  return r;
}
nodo* build_list(nodoA *r);
nodoA* buildtree(nodoA*r, int dim)
{
  if(dim)
   {
    char z;
    cin>>z;
    nodoA*x=insert(r,z);
    return buildtree(x,dim-1);
   }
  return r;
}
void stampa_lista(nodo*L)
{
  if(L)
  {
    cout<<L->info<<' ';
    stampa_lista(L->next);
  }
  else
    cout<<endl;

}

nodo* fuse(nodo*L1,nodo*L2);
 int main()
{
  int  n;
  cout<<"start"<<endl;
  cin>> n;
  nodoA*R=buildtree(0,n);
  stampa_l(R);
  cout<<endl;
  nodo*x=build_list(R);
  stampa_lista(x);
  cout<<"end"<<endl;
}

// PRE=( lista(L1) e lista(L2) ben formate)
nodo* fuse(nodo*L1,nodo*L2){
    coda Q = coda();


    while(L1 ||L2){
/*		Invariante
 *
 * L1 e L2 sono ben formate
 * coda contiene n elementi, dove 0<=n<= (# elementi L1 + #elementi L2)
 *
 */
        if(L1 && L2){
            nodo *tmp;
            if(L1->info<=L2->info){
                tmp=L1->next;
                push(L1,Q);
                L1=tmp;
            }else{
                tmp=L2->next;
                push(L2,Q);
                L2=tmp;
            }

        }else if(L1){
            push_list(L1,Q);
            L1=NULL;
        }else{
            push_list(L2,Q);
            L2=NULL;
        }

    }
    return Q.inizio;

}
// POST=(restituisce la lista ordinata costruita disponendo in ordine i nodi di L1 ed L2)


 //PRE=(albero(r) ben formato)
 nodo* build_list(nodoA *r) {

    if(!r) return 0;// caso base: questo nodo e' nullo, percio' e' corretto restituire una lista vuota 0.

    //PRE_ric:albero(r->left) ben formato
	 nodo*	l1=build_list(r->left);
    //POST_ric:(restituisce la lista ordinata che consiste di un numero di nodi pari a quelli di albero(r->left) e
	 //i cui campi info sono gli stessi di albero(r->left))



	 //PRE_ric:albero(r->right) ben formato
	 nodo* l2=build_list(r->right);
	  //POST_ric:(restituisce la lista ordinata che consiste di un numero di nodi pari a quelli di albero(r->right) e
		 //i cui campi info sono gli stessi di albero(r->right))
	 nodo* l= new nodo(r->info);

	if(!l1  && !l2)
		 return l;
    if(!l1)
     return fuse(l,l2);

    if(!l2)
        return fuse(l,l1);

    return fuse(l, fuse(l1,l2));

    /*
     *	Prova di correttezza:
     *
     * caso base: il nodo e' nullo, percio' questo ramo non ha nessun nodo, quindi la lista che li contiene e' vuota. Quindi restituisco 0.
     *
     *
     *caso ricorsivo:
     *
     * Presumendo che la PRE sia vera, possiamo affermare che e' vera anche le due pre_ ric poiche' si riferiscono ai due sottoalberi
     * albero(r->left) e albero(r->right) della radice r, quindi i due sottoalberi sono ben formati poiche' garantiti dall'albero(r).
     *
     *	Per il passo induttivo, ogni sotto albero restituisce una lista, nel caso delle foglie restituiscono solo un nodo, dove ogni nodo
     *	contiene il campo info del proprio sottoalbero(r->left) e sottoalbero(r->right). Quindi utilizzando la funzione fuse, le liste vengono
     *	unite ed ordinate, quindi viene aggiunto anche il nodo che contiene informazione della radice. Quindi possiamo affermare il post ric
     *	sia vera, perche' non fa altro che l'unione delle liste restituite dagli suoi rami. Se il post ric e' vera, possiamo dire che anche
     *	il POST e' vera.
     *
     */
 }
 //POST=(restituisce la lista ordinata che consiste di un numero di nodi pari a quelli di albero(r) e i cui campi info sono gli stessi di albero(r))

