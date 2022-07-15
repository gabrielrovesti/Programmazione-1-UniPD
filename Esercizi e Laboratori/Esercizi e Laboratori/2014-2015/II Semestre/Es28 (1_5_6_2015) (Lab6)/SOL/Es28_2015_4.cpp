
//soluzione by: Luca D.

#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info1,info2; nodo* next; nodo(int a=0, int b=0, nodo* c=0){info1=a; info2=b; next=c;}};
struct cop{nodo* N; int num; cop(nodo* a=0, int b=0){N=a; num=b;}};
nodo* f0(nodo *L, int*P, int dimP);
nodo* calcsalta(nodo* L, int *P, int n);
int calcsalta1(nodo* L, int *P, int n);
int quantocontinua(nodo *L,int *P,int n, int dimP);
nodo* quantosaltare(nodo *L,int n, int info3);
nodo* costruisci(int n, int dim, ifstream & IN)
{
  if(n==dim)
    return 0;
  int x;
  IN>>x;
  return new nodo(x,n,costruisci(n+1, dim, IN));
}


void stampa(nodo*L, ofstream & OUT)
{
 if(L)
 {
   OUT<<"salta="<<L->info1<<" matcha="<<L->info2<<' ';
   stampa(L->next,OUT);
 }
 else
  OUT<<endl;
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
nodo* f0(nodo*L, int *P, int dimP){
	if (L==0 || calcsalta(L,P,0)==0){
		return 0;
		cout<<"fine";
	}
	
	else {
		nodo* j=new nodo;
		j->info1=calcsalta1(L,P,0);
		
		
		L=calcsalta(L,P,0);
		
		j->info2=quantocontinua(L,P,0,dimP);
		cout<<"info2= "<<j->info2;;
		L=quantosaltare(L,0,j->info2);
		
		
		
		j->next=f0(L,P+(j->info2),dimP-(j->info2));
		return j;
	
	}
	
	

	
	
}
nodo* calcsalta(nodo* L, int *P,int n){
	if(L==0 || L->info1==*P ){
		return L;
	}
	
	return calcsalta(L->next,P,n+1);
	
}
int calcsalta1(nodo* L, int *P,int n){
	if(L->info1==*P || L==0){
		return n;
	}
	
	return calcsalta1(L->next,P, n+1);
	
}
int quantocontinua(nodo *L,int *P,int n,int dimP){
	if(L==0 || L->info1!=*P || dimP==0)
		return n;
	return quantocontinua(L->next,P+1,n+1,dimP-1);
	
}
nodo* quantosaltare(nodo *L,int n, int info3){
	if(n==info3)
		return L;
	
	return quantosaltare(L->next,n+1,info3);	

}
