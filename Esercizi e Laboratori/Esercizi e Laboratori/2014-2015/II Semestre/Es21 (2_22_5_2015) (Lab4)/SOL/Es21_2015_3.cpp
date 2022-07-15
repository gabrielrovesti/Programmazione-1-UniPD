
//soluzione by: Luca C.

#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};
struct dueL {nodo* prima, * seconda; dueL(nodo*a=0, nodo* b=0){prima=a; seconda=b;}};

//PRE=(Ho una lista L corretto o vuota)
dueL sgrana(nodo *L){
	if(!L){								//CASO BASE 1: non ho nodi
 		return dueL(NULL, NULL);		//ritorno L1=NULL, L2=NULL
 	}
 	else{
 		if(!L->next){					//CASO BASE 2: ho un solo nodo
 			return dueL(L, NULL);		//ritorno L1=nodo, L2=NULL
 		}
 		else{							//CASO RICORSIVO: ho almeno due nodi, n1,n2::R
 			nodo *L1 = L;				//salvo n1 in L1
 			nodo *L2 = L->next;			//salvo n2 in L2
 			dueL dL;
 			dL = sgrana(L->next->next);	//sgrano R
			L1->next=dL.prima;			//aggancio L1, a L1 sgranatata da R
 			L2->next=dL.seconda;		//aggancio L2, a L2 sgranata da R
			return dueL(L1, L2);		//ritorno la struttura
 		}
 	}
 }
//POST=(restituisce una struttura dueL contente L1 e L2 con SG(L)=(L1, L2)
//		dove L1 e L2 sono liste corrette o vuote, L1 contiene i nodi dispari
//		e L2 contiene i nodi pari)

//PRE=(Ho una lista L corretto o vuota)
nodo * sgrana2(nodo *&L){
 	if(!L){							//CASO BASE 1: non ho nodi
 		return NULL;					//ritorno L1=NULL, L e' gia' NULL
 	}
 	else{
 		if(!L->next){					//CASO BASE 2: ho un solo nodo
 			nodo *L1=L;				//salvo il nodo in L1
 			L=NULL;					//facio puntare L a NULL
 			return L1;				//ritorno L1=nodo
 		}
 		else{						//CASO RICORSIVO: ho almeno due nodi, n1,n2::R
 			nodo *L1 = L;				//salvo n1 in L1
 			L = L->next;				//faccio puntare L a n2
 			L1->next=sgrana2(L->next);		//aggancio L1 alla sgrantura di R
 			return L1;				//ritorno L1
 		}
 	}	
}
//POST=(dato SG(L)=(L1, L2), restituisce L1 e salva L2 in L dove L1 e L2
//		sono liste corrette o vuote, L1 contiene i nodi dispari e L2 contiene i nodi pari)

nodo* crea(int dim, ifstream & INP)
{
 if(dim)
  {
    int x;
    INP>>x;
    return new nodo(x,crea(dim-1,INP));
  }
 return 0;
}

nodo* clona_rov(nodo*L, nodo* rov)
{
  if(L)
   {
    return clona_rov(L->next,new nodo(L->info,rov));
   }
  return rov;

}
void stampa(nodo*L,ofstream & OUT)
{
  if(L)
  {
    OUT<<L->info<<' ';
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
   int dim;
   IN>>dim;
   nodo* L1=crea(dim,IN); //data
   nodo*L2= clona_rov(L1,0);//clone in ordine inverso, data
   dueL W=sgrana(L1); // da fare (a)
   nodo*L3=sgrana2(L2);// da fare (b)
   stampa(W.prima,OUT);//date
   stampa(W.seconda,OUT);
   stampa(L3,OUT);
   stampa(L2,OUT);    
   IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
 }
