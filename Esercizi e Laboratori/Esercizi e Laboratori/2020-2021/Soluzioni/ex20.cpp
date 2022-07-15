/*
Esercizio 2 del 10/5/2021 
Si tratta di modificare la funzione match3 dell’Esercizio 1 in modo tale che restituisca P’ attraverso il 
parametro T passato per riferimento e restituisca quello che resta di T col return. Ovviamente se non c’è 
match, il parametro T avrà valore 0 e la T originale verrà restituita col return.
La nuova funzione deve avere prototipo: nodo* match3b(nodo*& T, nodo*P):
Correttezza: scrivere PRE e POST della funzione match3b e dimostrare la sua correttezza rispetto ad esse.
Nota: l’esercizio non è semplice (come se gli altri lo fossero, no?)
*/

#include<iostream>
using namespace std;
struct nodo{
  int info; 
  nodo* next; 

    nodo(int a=0, nodo* b=NULL){      
    info=a; next=b;
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
    int s;
    cin >>s;
    return new nodo(s,build1(m-1));
}

nodo* funzione_di_match(nodo* T, nodo* P, bool &mt){
    if(!P->next){
      if(P->info==T->info){
          mt=true;
          return T;
      }
      else{
          mt=false;
          return 0;
      }
    }
    else{
        if(P->info==T->info){
          return funzione_di_match(T->next, P->next, mt);
        }
        else{
          mt=false;
          return 0;
        }
    }
}

//PRE=T e P ben formate
nodo* match3b(nodo*& T, nodo*P){
    if(length(T) < length(P) || !P){
        nodo *x=T;
        T=0;
        return x;
    }
    //assunzione che può esserci un match dato se |t| >= |p| e !p|>0
    bool match_trovato=false;
    nodo* fine_match=funzione_di_match(T, P, match_trovato);
    if(match_trovato){
        nodo* resto=fine_match->next;
        fine_match->next=0;
        return resto;
    }
    else{
        nodo* q = T;
        T = T->next;
        //PRE_RIC=T e P liste ben formate e definite e L(P->next) definita e diversa da 0
        q->next=match3b(T, P);
        //POST_RIC=vT=T->next e vP=P
        return q;
    }
}
//POST=(se c’è match restituisce il primo match di P' attraverso il parametro
//T, se non ci sono match T=0 e vT restituita col return)

///---Correttezza---
/*
Per questa funzione, abbiamo la funzione di match (discussa nell'esercizio es19)
e il caso base precedentemente visto, il quale controlla sempre se le lunghezze di T e P siano l'una minore dell'altra
e se P sia valido. In questo caso, però, come richiede il testo, si azzera l'elemento corrente di T.
Si verifica poi quale sia effettivamente l'ultimo nodo in cui si ha avuto un match;
come prima distinguiamo il caso in cui si ha avuto un match, in cui si punta al nodo successivo rispetto alla fine
e si restituisce il resto dei nodi, dal caso in cui non si ha avuto un match, caso nel quale si punta all'elemento successivo
rispetto alla lista T, ritornandolo.
In questo modo, risulta coerente con la consegna, 
*/

int main()
{
  int m,z;
  cin >> m>>z;
  nodo*L=build1(m);
  stampa_LR_iter(L);
  nodo*P=build1(z);
  stampa_LR_iter(P);
  
  nodo* q= match3b(L,P);  
  stampa_LR_iter(q);
  stampa_LR_iter(L);

  return 0;
}
