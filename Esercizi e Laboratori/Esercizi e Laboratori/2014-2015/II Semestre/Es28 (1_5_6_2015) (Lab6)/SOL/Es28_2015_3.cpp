
//soluzione by: Viviana A.

#include<iostream>
#include<fstream>
using namespace std;
 
struct nodo{int info1,info2; nodo* next; nodo(int a=0, int b=0, nodo* c=0){info1=a; info2=b; next=c;}};
struct cop{nodo* N; int num; cop(nodo* a=0, int b=0){N=a; num=b;}};
// così possiamo restituire sia un intero sia un puntatore a lista nelle funzioni saltaF, matchF.
 
 
nodo* costruisci(int n, int dim, ifstream & IN){
  if(n==dim)
    return 0;
  int x;
  IN>>x;
  return new nodo(x,n,costruisci(n+1, dim, IN));
}
 
 
void stampa(nodo*L, ofstream & OUT){
 if(L)
 {
   OUT<<"salta="<<L->info1<<" matcha="<<L->info2<<' ';
   stampa(L->next,OUT);
 }
 else
  OUT<<endl;
}
 
int match(nodo *&L, int *P, int dimP){
  if(!dimP)
    return 0;
  if(!L)
    return 0;
  if(L->info1 == *P){
    L=L->next;
    return 1 + match(L,P+1,dimP-1);
  }
  return 0;
 
}
/*
 * PRE salta = L è una lista corretta, possibilmente vuota. P ha sicuramente il primo
 *              elemento definito.
 */
int salta(nodo *&L, int p){
  if(!L)
    return 0;
  if(L->info1 != p){
    L=L->next;
    return 1 + salta(L,p);
  }
  return 0;  
}
/*
 * POST salta = salta ritorna il numero di nodi che è necessario saltare nella lista L per trovare il
 *              primo match di L con P.
 */
 
// ritorna la lista del match.
nodo* f0(nodo*L, int*P, int dimP){
  if(!dimP || !L)
    return 0; //ritorno lista vuota
   
  int s = salta(L,P[0]);//modifica L  
  int m = match(L,P,dimP);//modifica L
 
  nodo *R = new nodo(s,m,0); // creo un nodo della lista da ritornare
  R->next = f0(L,P+m,dimP-m); // attacco i successivi nodi
  return R;  
 
}
 
main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT)
  {
   int dim,dimP, P[30];
   IN>>dim;
   nodo* L=costruisci(0,dim,IN);//data
   
   
   IN>>dimP;
   for(int i=0; i<dimP; i++)
    IN>>P[i];
   nodo*K=f0(L,P,dimP); //da fare
   stampa(K,OUT); //data
   OUT<<"fine"<<endl;
   
   IN.close(); OUT.close();
  }
  else
   cout<<"errore con i files";
 }
