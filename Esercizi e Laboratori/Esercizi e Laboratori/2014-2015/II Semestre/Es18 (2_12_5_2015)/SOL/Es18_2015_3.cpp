
//soluzione by: Nicolò S.

#include<iostream>
#include<fstream>
using namespace std;
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

void stampa_rov(nodo *x, ofstream & OUT){
	if(x){
		stampa_rov(x->next, OUT);
		OUT<<x->info<<"->";
	
	}
}

nodo* crea(int dim, ifstream & IN){
	if (dim==0)
		return 0;
	else{
		int k;
		IN>>k;
		new nodo(k,0);
		return new nodo(k, crea(dim-1, IN));
	}
	
}



main()
{
	ifstream IN("input");
	ofstream OUT("output");
    
	if(IN && OUT){
		int dim;
		IN>> dim;
		
		nodo *x=crea(dim,IN);
		stampa_rov(x,OUT);
		
		OUT<<" fine";
	}
	else 
		OUT<< "errore con i files" <<endl;

}
