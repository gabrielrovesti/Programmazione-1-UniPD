#include<iostream>
using namespace std;


struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};



void stampa(nodo*L);
nodo* crea(int dim);

int delastk(nodo* & Q , int k, int y, int count);



int main()
{
  int dim;
  cin>>dim;
  nodo* L=crea(dim);
  int k, y;
  cin>>k>>y;
  cout<<"start"<<endl;
  stampa(L);
  delastk(L,k,y,0);// da fare
  stampa(L);
  cout<<"end"<<endl;
}



//PRE=(L(Q)è ben formata , k>0, vL(Q)=L(Q))
int delastk(nodo* & Q , int k, int y, int count){
		if(! Q){
            if(count>=k )
                return k;
    	    return 0;

		}
		if(Q->info == y ){
			count ++ ;

			int numeroMatch = delastk(Q->next, k, y, count);

			if(numeroMatch > 0){
				numeroMatch--;
                nodo* nodoDaEliminare = Q;
                delete(nodoDaEliminare);
				Q=Q->next;
			}




			return numeroMatch;
		}else{
			return delastk(Q->next, k, y, count);
		}

}
//POST=(se vL(Q)contiene m>=0 nodi con info=y e m+count>=k, allora vengono eliminati gli ultimi nodi
//di vL(Q)con info=y,fino al massimo dik (se m<k allora vengono eliminati m nodi con info=y)
//e la funzione restituisce il numero di nodi che devono ancora essere eliminati per arrivare a k) && (
//altrimenti,L(Q)=vL(Q))&&(i nodi eliminati sono stati deallocati)

nodo* crea(int dim)
{
 if(dim)
  {
    int x;
    cin>>x;
    return new nodo(x,crea(dim-1));
  }
 return 0;
}
void stampa(nodo*L)
{
  if(L)
  {
    cout<<L->info<<' ';
    stampa(L->next);
  }
 else
    cout<<endl;
}
