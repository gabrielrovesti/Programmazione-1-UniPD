/*Si tratta di un esercizio di pattern matching nel quale sia il testo T che il pattern P sono liste concatenate. 
Diremo che in P c’è un match di P quando T=T1@P’@Resto. con P’ tale che ha la stessa lunghezza di P e i 
campi info dei nodi di P’ sono uguali a quelli dei corrispondenti nodi di P. Nel caso ci sia un match di P in T, 
vogliamo restituire P’ e anche la parte di T che resta dopo che P’ è stata estratta da T.
Vogliamo fare questa operazione in 2 modi, seguendo le tipologie 1 e 3 delle funzioni ricorsive che abbiamo 
già discusso la settimana scorsa.
Per quanto riguarda la tipologia 1, useremo la struct: 
struct doppiaL{nodo*L,*S; doppiaL(nodo*a=0,nodo*b=0){L=a; S=b;}}; e si richiede la funzione match1 che 
soddisfa le seguenti specifiche:
PRE= (T e P sono liste ben definite)
doppiaL match1(nodo*T, nodo*P)
POST=(se in T c’è un match P’ di P, la funzione restituisce un valore doppiaL q, con q.S=P’ e q.L=quello che 
resta di T una volta tolto P’, si considera il match P’ che inizia più a sinistra in T)&&( se in T non c’è match di 
P, allora la funzione restituisce un valore doppiaL q con q.L=T e q.s=0)
La seconda funzione segue la tipologia 3 e restituisce P’ con il return e quello che resta di T usando il 
parametro passato per riferimento. match3 deve soddisfare le seguenti specifiche:
PRE=(T e P sono ben formate)
nodo* match3(nodo*&T, nodo*P)
POST=(se c’è match restituisce il primo match P’ col return e quello che resta di T nel parametro T) &&(se 
non c’è match T resta invariata e ritorna 0 col return).
Correttezza: dimostrare la correttezza delle 2 funzioni rispetto alle PRE e POST date*/

#include<iostream>
using namespace std;
struct nodo{
int info; nodo* next;
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
	for(int i=0; i<k; i++){
  cout<<L->info<<' '; L=L->next;
  }
	cout<<endl;
}

nodo* build1(int m)
{
  if(m==0) return 0;
  int s;
  cin >>s;
  return new nodo(s,build1(m-1));
}

struct doppiaL{
nodo*L,*S; doppiaL(nodo*a=0,nodo*b=0)
  {
    L=a; 
    S=b;
  }
};

nodo*clone(nodo*L)
{
	if(!L) return 0;
	return new nodo(L->info,clone(L->next));
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

///---Correttezza---
/*
Partendo dalla funzione match1,
si considerano le liste T e P.
Essendo una funzione ricorsiva, è presente subito un caso base (controllo sulla lunghezza di T rispetto a P pattern) per fermare la ricorsione
nel caso in cui la lunghezza non corrisponda o non basti P.
Viene poi chiamata la funzione di match, per poter trovare l'ultimo nodo in cui si sa per certo che c'è stato un match
In questa ultima, viene controllato se esiste l'elemento P->next; 
se non esiste, se c'è un match viene restiuito e anche il punto in cui si ha avuto un match in T, altrimenti se non c'è match, match=false e si termina;
se esiste, si controlla se c'è un match e, se ci fosse, si punta agli elementi successivi delle due liste, altrimenti non c'è e si termina
Fatto ciò, si torna al main e si hanno due casi:
-match_trovato==true, in quel caso si crea un nodo che ha come collegamento l'ultimo in cui si ha avuto un match
e si torna la lista comprendente la parte iniziale e il resto dei nodi possibili
-match_trovato==false, in quel caso si va avanti e si controllano gli elementi successivi, salvandosi i nodi successivi T in L e ritornando la doppia lista

Per la funzione match3, si invoca sempre la funzione di match discussa poc'anzi e:
-nel caso in cui ci sia un match, T viene linkata con i nodi iniziali e restituita la doppia lista così formata.
-nel caso non ci sia un match, semplicemente si punta all'elemento dopo della lista originale
*/

//PRE= T e P sono liste ben definite, P non vuoto
doppiaL match1(nodo*T, nodo*P)
{
    //Il caso base considera che:
    //se T<P o P=0, nel primo caso, lista uguale, nel secondo rimane vuoto   
    if(length(T) < length(P) || !P){
        return 0;
    }
    bool match_trovato=false;
    nodo *fine_match=funzione_di_match(T, P, match_trovato);
    if(match_trovato){
      nodo* resto=fine_match->next;
      fine_match->next=0;
      return doppiaL(resto, T);
    }
    else{
      doppiaL q=match1(T->next, P);
      T->next=q.L;
      q.L=T;
      return q;
    }
}
//POST=(se in T c’è un match P’ di P, la funzione restituisce un valore doppiaL q, con q.S=P’ e q.L=quello che 
//resta di T una volta tolto P’, si considera il match P’ che inizia più a sinistra in T)&&( se in T non c’è match di 
//P, allora la funzione restituisce un valore doppiaL q con q.L=T e q.s=0

//PRE=(T e P sono ben formate)
nodo* match3(nodo*&T, nodo*P)
{
    if(length(T) < length(P) || !P){
        return 0;
    }

    bool match_trovato = false;
    nodo* fine_match=funzione_di_match(T, P, match_trovato);
    if(match_trovato){
        nodo *resto=fine_match->next;
        nodo *p=T;
        fine_match->next=0;
        T=resto;
        return p; 
    }else{
      return match3(T->next, P);
    }
}
//POST=(se c’è match restituisce il primo match P’ col return e quello che resta di T nel parametro T) &&(se 
//non c’è match T resta invariata e ritorna 0 col return).

int main()
{
  int m,z;
  cin >> m>>z;
  nodo*L=build1(m);
  stampa_LR_iter(L);
  nodo*P=build1(z);
  stampa_LR_iter(P);
  nodo*L1=clone(L);
  nodo* P1=clone(P);
  doppiaL D= match1(L,P);  
  stampa_LR_iter(D.L);
  stampa_LR_iter(D.S);
  nodo* q= match3(L1,P1);  
  stampa_LR_iter(L1);
  stampa_LR_iter(q);

  return 0;
}