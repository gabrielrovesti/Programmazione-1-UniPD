
//soluzione by: Federico S. B.

/*Integrazione 6 crediti*/

#include <iostream>
#include <fstream>
using namespace std;

struct nodo{
	int info; 
	nodo* next; 
	nodo(int a=0, nodo* b=0){
		info=a; 
		next=b;}
};

nodo* crea(int dim,ifstream & IN){
	
	if(!dim)
		return NULL;
	
	int x;
	IN >> x;
	return new nodo(x, crea(dim-1,IN));
}

void stampa(nodo* L, ofstream& OUT){
	if(!L)
		OUT << "fine";
	else{
		OUT << L->info << " ";
		stampa(L->next, OUT);
	}
}

main(){
	ifstream IN("input");
	ofstream OUT("output");
	
	if(IN && OUT){
		int dim;
		nodo* L;
	
		IN >> dim;
		L = crea(dim, IN);	
		stampa(L, OUT);
	
		IN.close();
		OUT.close();
	}
	else
		cout << "errore con i file"<< endl;
}
