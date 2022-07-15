/* Esame 170919 pt. ITERATIVA
 *
 * Obiettivo : Si chiede di realizzare la funzione iterativa scanliv (scandisce i livelli) che riceve
               un albero R e percorre R in larghezza, percorrendo ciascun livello da destra a sinistra.
               Devec anche restituire il numero di livelli presenti in R e deve inserire valori negli array
               X e T come segue:
                - per ogni livello i deve restituire in X[i] il numero di nodi presenti in quel livello
                - T deve contenere il campo info dei noid di R nell'ordine in cui sono stati percorsi (in larrghezza da dx a sx)

 * Prototipo funzione :   void scanliv(nodo*R, int& nliv, int*X, int*T)
 *
 *
 * PRE = albero(r) e' un albero binario ben formato, X e T contengono un numero di posizioni pari al numero dei nodi di albero(r)
 * POST = nliv e' il numero di livelli di albero(r) e X e T contengono i valori descritti nell'esempio che segue, ovviamente
 *        per l'albero(r) in input
 *
 * Esempio : per l'albero(r) = [10]([5](_,_)[20](_,[30]([21](_,_),[31](_,_))))
 *           il numero di livelli e' 5, X=[1,2,1,2,1] che indica che c'e' 1 nodo al livello 0 (X[0]), 2 al livello 1 X[1] etc
 *           Inoltre, T=[10,20,5,30,31,21,32]. I campi info dei nodi di R nell'ordine per livelli e con ogni livello percorso da dx a sx
 *
 */


#include<iostream>
using namespace std;

struct nodo{
  int info;
  nodo*left, *right;
  nodo(int a=0, nodo*b1=0,nodo*b2=0){
    info=a;
    left=b1;
    right=b2;
  }
};

struct nodoEx{
  nodo* info;
  int liv; // contiene l'info relativa al livello del nodo dell'albero considerato
  nodoEx*next;
  nodoEx(nodo*a=0,int b=0, nodoEx*c=0){
    info=a;
    liv=b;
    next=c;
  }
};

struct coda{
  nodoEx* inizio, * fine;
   coda(nodoEx*a=0, nodoEx*b=0){
     inizio=a;
     fine=b;
   }
 };

//PRE=(x è una coda che gestisce una lista di nodoEx ben formata e a punta ad un nodoEx)
coda push_end(coda x, nodoEx*a){
  a->next=0;
  if(x.inizio){
      x.fine->next=a;
      x.fine=a;
  }
  else
    x.inizio=x.fine=a;
  return x;
}
//POST=(restituisce la coda x che gestisce la lista originale con il nodoEx a aggiunto alla fine della lista)

//PRE=(C.inizio non è 0)
nodoEx* pop(coda & C){
  nodoEx* x=C.inizio;
  C.inizio=C.inizio->next;
  if(C.inizio==0)
    C.fine=0;
  return x;
}
//POST=(modifica C eliminando il suo primo nodoEx e restituendolo col return )

void build_BST(nodo*&r, int x){
  if(!r)
    r=new nodo(x);
  else {
    nodo*q=r;
    bool continua=true;
    while (r && continua){
     if(r->info>=x){
      if(r->left)
       r=r->left;
      else{
       r->left=new nodo(x);
       continua=false;
      }
      }
      else{
        if(r->right)
          r=r->right;
        else {
          r->right=new nodo(x);
          continua=false;
        }
      }
	   }
     r=q;
   }
}

void stampa_lin(nodo*r){
  if(r){
    cout <<'['<<r->info<<']'<<'(';
    stampa_lin(r->left);
    cout<<',';
    stampa_lin(r->right);
    cout<<')';
  }
  else
  cout<<'_';
}

void scanliv(nodo*r, int&liv, int*x, int*t){
  if(!r) return;
  nodoEx*a=new nodoEx(r);
  nodoEx* inizio=a; // inizio punta sempre ad a iniziale
  coda Q=0;
  Q=push_end(Q,a);
  // in questo modo scorro l'albero ed al contempo riempio una coda
  while(Q.inizio){ // ciclo fin tanto che Q.inizio!=0
    //if(!a->liv) a=pop(Q); // estraggo il primo nodo
    if(Q.inizio->info->right){ // se ho un nodo nel sottoalbero dx della radice
      a=new nodoEx(Q.inizio->info->right, Q.inizio->liv+1);
      Q=push_end(Q, a); // inserisco il nodo in coda alla coda
    }
    // faccio lo stesso per il sottoalbero sx
    if(Q.inizio->info->left){
      a=new nodoEx(Q.inizio->info->left, Q.inizio->liv+1);
      Q=push_end(Q, a);
    }
    nodoEx*y=pop(Q);
    if(y->liv>liv){
      liv=y->liv;
      x+=1;
    }
    *t=y->info->info;
    t+=1;
    *x+=1;
  }
  liv++;
}
//poiche' so che i nodi sono ordinati per livelli
/*
inizialmente liv vale 0 e pure inizio->liv vale 0 e contienee solo il puntatore alla radice



*/


int main(){
  cout<<"start"<<endl;
  int n, nnodi=0;
  nodo*R=0;
  cin >>n;
  while (n !=-1){
    build_BST(R,n);
    nnodi++; // # elementi nell'albero
    cin>>n;
  }
  stampa_lin(R);
  cout<<endl;
  // R e' l'albero costituito da nodi, X e' un array di interi che contiene il numero di nodi per livello, T e' l'array che contiene i campi info dei nodi di R
  int*X=new int[nnodi],liv=0,*T=new int[nnodi];
  scanliv(R,liv,X,T); //DA FARE
  int nt=0;
  for(int i=0; i<liv; i++){
    cout<<" Liv="<<i<<") ";
    for(int j=0; j<X[i]; j++){
      cout<<T[nt+j]<<' ';
    }
    cout<<endl;
    nt=nt+X[i];
  }
  cout<<"end"<<endl;
}
