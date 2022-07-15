/*
Esercizio 3 del 12/5/2021
Date due liste concatenate T e P. Se i nodi di P sono n0, n1, …, nk, vogliamo determinare se ci sono k+1 nodi 
m0, m1, …mk in T tali che per ogni i in [0,k], ni->info=mi->info, inoltre si chiede che i nodi m0,m1,…,mk 
siano in ordine in T, cioè m0 precede in T m1, che a sua volta precede m2, ecc. I nodi m0,m1,…non devono 
necessariamente essere contigui in T, l’importante è che appaiano in T in ordine. 
Si richiede di scrivere una funzione tale che, se in T ci sono nodi m0, m1,..mk, come specificato prima, allora 
restituisca due liste: la lista dei nodi m0,...,mk e la lista che contiene gli altri nodi di T. Se invece T non 
contiene nodi m0,..,mk, allora la funzione restituisce 0 e T senza cambiamenti.
La funzione deve seguire la tipologia 1 (delle 3 studiate questa settimana).Il prototipo della funzione è:
PRE=(Lista(P) e Lista(T) sono ben formate, vT=T)
doppiaL matchX1(nodo*T,nodo*P)
POST=(La funzione restituisce sempre un valore doppiaL D come segue: se vT contiene m0,..,mk allora 
D.S=m0,..,mk e D.L contiene vT senza i nodi m0…mk, mentre se vT non contiene m0,..mk allora la funzione 
restituisce D.S=0 e D.L=vT)
Attenzione: il distacco dei nodi da vT deve avvenire solo se si trovano in vT tutti i k+1 nodi m0…mk

Spiegato in parole umane (dato che il discorso dell'ordine confonde e basta):
Date due liste, si tratta di trovare sempre il match tra T e P,
ma questa volta si guardano i match tra elementi non contigui tra di loro, restituendo T come la lista tolti gli elementi in cui ci sta il match.
Si guardi l'output e si capisce subito:

(metto T)     1 0 1 0 2 0 3 4 0 1 2 0 1 1 2
(metto P)     3 0 0 1 2
(questa è T)  1 0 1 0 2 0 4 1 2 1
(questa è P)  3 0 0 1 2
*/

#include <iostream>

using namespace std;
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=NULL){info=a; next=b;}};
int length(nodo*L)
{
  if(L) return 1 + length(L->next);
  return 0;
}
void stampa_LR_iter(nodo*L)
{       
  int k=length(L);
	for(int i=0; i<k; i++)
  {cout<<L->info<<' '; L=L->next;}
	cout<<endl;
}

nodo* build1(int m)
{
    if(m==0) return 0;
    int s;
    cin >>s;
    return new nodo(s,build1(m-1));
}

struct doppiaL
{
  nodo*L,*S; 
    doppiaL(nodo*a=0,nodo*b=0){
    L=a; 
    S=b;
    }
};

//PRE=(Lista(P) e Lista(T) sono ben formate, vT=T)
doppiaL matchX1(nodo*T,nodo*P){

      if(!P || !T){    //unico caso senza match-->P è vuoto
        return doppiaL(T, 0);
      }
     //quando non ci sta un match doppiaL.S=0
     //ma anche con un match tra T = 0 e P = 0 abbiamo doppiaL.L=0 e doppiaL.S=0
     //ed il caso in cui solo P sia 0 abbiamo il match con doppiaL.L = T e doppiaL.S=0

    //T e P non sono vuoti (entrambi hanno almeno un elemento)
    if(P->info == T->info){
        if(!P->next){   //se non ci sono elementi successivi al pattern
          nodo *q = T->next;    //semplicemente q è l'elemento dopo della lista e non ci sono elementi successivi nella lista
          T->next=0;
          return doppiaL(q, T);
        }
          doppiaL u=matchX1(T->next, P->next);    //controllo dal secondo elemento in poi
          if(!u.S){     //finiamo ogni volta in questo caso; ci sta un elemento e puntiamo all'elemento dopo nella lista
            return doppiaL(T, 0);    //vuol dire che ritorna 0
          }
          //sono sicuro che ci sia un match completo con P
          T->next=u.L;        //linka la vecchia lista alla parte matchabile
          return doppiaL(u.L, T);
      }else{     //sostanzialmente, vede che sta un match dopo i primi nodi e si ricollega al punto in cui si è trovato match
            doppiaL d=matchX1(T->next, P); 
            T->next = d.L;
            return doppiaL(T, d.S);
      }
}
//POST=(La funzione restituisce sempre un valore doppiaL D come segue: se vT contiene m0,..,mk allora 
//D.S=m0,..,mk e D.L contiene vT senza i nodi m0…mk, mentre se vT non contiene m0,..mk allora la funzione 
//restituisce D.S=0 e D.L=vT)

int main()
{
  int m,z;
  cin >> m>>z;
  nodo*T=build1(m);
  stampa_LR_iter(T);
  nodo*P=build1(z);
  stampa_LR_iter(P);
  
  doppiaL D= matchX1(T,P);  
  stampa_LR_iter(D.L);
  stampa_LR_iter(D.S);
  
  return 0;
}

