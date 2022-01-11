#include<iostream>
using namespace std;
struct nodo{int info; nodo* next; 
    nodo(int a=0, nodo* b=NULL){
    info=a; 
    next=b;
    }
};

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
    int info;
    cin >>info;
    nodo* p=build1(m-1);
    return new nodo(info, p);
}

//PRE_1=(Lista(L) ben formata, vLista(L)=Lista(L))
nodo* del1(nodo* L, int z)    //ricevo la lista iniziale e devo restituire la nuova lista col return
{
    if(!L) return 0;          //idea di base: lavoro sullo stack ed elimino gli elementi che mi servono
    else{
      if(L->info==z){
        nodo* x=L->next;           //crea un nodo sullo stack
        delete L;                 //dealloco il nodo dalla heap
        //Pre-ric_1=(Lista(L->next) ben formata, vLista(L->next)=Lista(L->next)
        return del1(x, z);        //richiamo la funzione e vado avanti
        //Post_ric_1=(restituisce una lista composta dai nodi di vLista(L->next) che non hanno campo info=z nell’ordine che 
        //hanno in vLista(L->next)) && (dealloca gli altri nodi di vLista(L))
      }
      else{
        L->next=del1(L->next, z);    //recuperiamo il nodo successivo ricorsivamente
        return L;                    //ritorniamo il nodo precedente
      }
    }
}
//POST1=(restituisce una lista composta dai nodi di vLista(L) che non hanno campo info=z nell’ordine che 
//hanno in vLista(L)) && (dealloca gli altri nodi di vLista(L))

//PRE_2=(Lista(L) ben formata, non vuota, e L->info != z, sia vLista(L)=Lista(L))
void del2(nodo* L, int z){      //idea di base: grazie ai puntatori, genero dei side effects e cancello l'elemento==z togliendolo dall'heap e tramite lo stack punto agli elementi successivi
  if(L->next){
      if(L->next->info == z){   //controllo l'elemento successsivo a L->next
      nodo* x=L->next;     //creo un altro puntatore al successivo a L->next
      L->next=L->next->next;    //punto all'elemento successivo al puntato 
      delete x;                 //cancello l'elemento successivo
      //Pre-ric_2=(Lista(L->next) ben formata, vLista(L->next)=Lista(L->next)
      del2(L, z);               //richiamo la funzione per poter rifare i controlli sugli elementi;
      //Post-ric_2(Lista(L) è ottenuta da vLista(L) eliminando i nodi con info=z e tenendo gli altri mantenendo il loro 
      //ordine) &&(i nodi con info=z sono deallocati)
      }
      else{
      //Pre_ric_2=(Lista(L->next) ben formata, non vuota, e L->info != z, sia vLista(L->next) = Lista(L->next);
      del2(L->next, z);         //semplicemente punto all'elemento successivo
      }
      //Post_ric_2=(Lista(L->next) è ottenuta da vLista(L->next) eliminando i nodi con info=z e tenendo gli altri mantenendo il loro 
      //ordine) &&(i nodi con info=z sono deallocati)
  } 
}
//POST_2=(Lista(L) è ottenuta da vLista(L) eliminando i nodi con info=z e tenendo gli altri mantenendo il loro 
//ordine) &&(i nodi con info=z sono deallocati)

////
//Appunto alla funzione sopra del2:
//se c'è da cancellare il primo elemento, non viene cancellato
//consideriamo che il primo nodo vada sempre bene!
//eventualmente, si veda il testo dell'esercizio.
////
//Per poter eliminare il primo, mi creo un nodo fantoccio
//nel main, al posto di del2(Y, z) si segua questo:
//nodo* delx=new nodo(Y->next, z);
//del2(delx,z);
////

//PRE_3=(Lista(L) ben formata, vLista(L)=Lista(L))
void del3(nodo*& L, int z){
  if(!L) return;
  else{
    if(L->info == z){
      nodo* x=L;      //puntiamo al nodo attuale
      L=L->next;      //incrementiamo
      delete x;       //cancelliamo il nodo attuale
      //Pre_ric_3=(Lista(L->next) ben formata, vLista(L->next)=Lista(L->next))
      del3(L, z);     //andiamo avanti
      //Post-ric_3=(Lista(L->next) è ottenuta da vLista(L->next) eliminando i nodi con info==z, mantenendo
      //i nodi di Lista(L->next) con info==z, mantenendo l'ordine dato && (i nodi con info==z sono stati deallocati)
    }
    else{
      //Pre_ric_3=(Lista(L->next) ben formata, vLista(L->next)=Lista(L->next))
      del3(L->next, z);
      //Post_ric_3=(Lista(L) è ottenuto da vLista(L) eliminando i nodi con info=z e mantenendo gli altri nello stesso
    //ordine che avevano in vLista(L) && (i nodi eliminati sono deallocati)
    }
  }
}
//POST_3=(Lista(L) è ottenuto da vLista(L) eliminando i nodi con info=z e mantenendo gli altri nello stesso
//ordine che avevano in vLista(L) && (i nodi eliminati sono deallocati)

int main()
{
  int m,z;      
  cin >> m;
  nodo*Y=build1(m);
  stampa_LR_iter(Y);
  cin >> z;
  Y=del1(Y, z);
  stampa_LR_iter(Y);
  cin >> z;
  del2(Y, z);
  stampa_LR_iter(Y);
  cin >> z;
  del3(Y, z);
  stampa_LR_iter(Y);

  return 0;
}