/*Esercizio 1 del 17/5/2021
L’esercizio è semplice da spiegare: vogliamo una funzione che riceve una lista L ordinata in modo crescente 
rispetto ai campi info dei suoi nodi e un nodo x e inserisce x in L in modo che la lista risultante sia ancora 
ordinata.
Esempio; se L= 2 -> 10 -> 12 -> 20 -> 30 e x è un nodo con info= 15, allora la funzione deve restituire 
2 -> 10 -> 12 -> 15 -> 20 -> 30. Se invece x avesse campo info= 0, la lista deve diventare,
0 -> 2 -> 10 -> 12 -> 20 -> 30, se invece l’info di x è 51, la lista diventa
2 -> 10 -> 12 -> 20 -> 30 -> 51
L’esercizio chiede di scrivere 2 funzioni che eseguono l’operazione appena descritta, una ricorsiva e una 
iterativa. Esse devono soddisfare la seguente specifica:
PRE=(Lista(L) ben formata e ordinata, x punta ad un nodo)
nodo* insOrd_ric(nodo*L, nodo*x)
nodo* insOrd_iter(nodo* L, nodo*x)
POST=(restituisce vL(L) con x aggiunto in modo che la nuova lista sia ancora ordinata)
Correttezza:
a) Dimostrare in modo induttivo la correttezza di insOrd_ric
b) scrivere un invariante per il ciclo di insOrd_iter*/


#include<iostream>
using namespace std;
struct nodo{
    int info; 
    nodo* next; 
    nodo(int a=0, nodo*b=0)
    {
        info=a; 
        next=b;
    }
};

nodo* faiL(int n)
{
  if(n)
    {
      int x;
      cin >> x;
      return new nodo(x,faiL(n-1));
    }
  return 0;

}

int length(nodo*L)
{
  if(L) return 1 + length(L->next);
  return 0;
}

void stampa(nodo*L)
{
  if(L)
    {
      cout << L->info<<' ';
      stampa(L->next);
    }

  else
    cout<<endl;
}

nodo* clone(nodo*L)
{
  if(L)
    return new nodo(L->info,clone(L->next));
  return 0;
}

//PRE=(Lista(L) ben formata e ordinata, x punta ad un nodo)
nodo* insOrd_ric(nodo*L, nodo*x){
    if(!L) return x;
        if(x->info > L->info){
            //PRE_RIC=Lista(L->next) ben formata e ordinata, q è un nodo che punta ad L, x punta sempre allo stesso nodo
            nodo* q=insOrd_ric(L->next, x);
            L->next=q;
            return L;
        }
        else {
            x->next=L;
            return x;
        }
}
//POST=(restituisce vL(L) con x aggiunto in modo che la nuova lista sia ancora ordinata
////
//Correttezza
/*
All'inizio della funzione, come di solito accade, viene controllata la validità
del nodo; se il nodo è valido, si presentano due casi
Il nodo della lista L è maggiore e/o uguale a x
e in quel momento usiamo un nodo di appoggio che punta al nodo successivo di L,
,permettendo quindi l'inserimento del nodo nell'ordine e
restituendo così la lista ordinata e il nodo P.
Noi assumiamo per vera PRE_Ric; 
al Passo Induttivo, p->next==L->next,
questo per ciascun elemento definito della lista L.

Altro caso, il nodo della lista L è minore di quello di x,
in quel caso si usa sempre il nodo di appoggio p,
facendo puntare X al nodo successivo di L e restituendo p, che ha come elemento x, mantenendo l'ordine della lista.
*/


//PRE=(Lista(L) ben formata e ordinata, x punta ad un nodo)
nodo* insOrd_iter(nodo* L, nodo*x){
    if(!L)
    return x;

    nodo*q=L;
    
    while(L){
        if(!L->next && x->info > L->info){
            L->next=x;
        }
        if(x->info < q->info){
            x->next=q;
            L=x;
        }
        if(x->info < L->info && x->info > L->next->info){
            x->next=L;
            L->next=x;
        }
        L=L->next;
    }
    return q;
}
//POST=(restituisce vL(L) con x aggiunto in modo che la nuova lista sia ancora ordinata


int main()
{
  int m, x;
  cin >> m >> x;
  nodo*L=faiL(m);
  nodo*L1=clone(L);
  
  L=insOrd_ric(L,new nodo(x));
  L1=insOrd_iter(L1, new nodo(x));
  stampa(L);
  stampa(L1);

  return 0;
}