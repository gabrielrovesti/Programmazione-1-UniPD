
//soluzione by: Nicolò S.

#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}}; 

nodo* del_z(nodo* n, int z){
	if(!n)
		{return 0;}
	else{
		if(n->info==z){
		    nodo*y=n;
		    n=n->next;
		    delete y;
		    n = del_z(n,z);
		    return n;
	    }
	    else{
		    n->next = del_z(n->next,z);
		    return n;
	    }
    }
}

nodo* crea(int dim,ifstream & IN){
	if(dim==0){
		return 0;
	}
	else{
		int x;
		IN>>x;
		return new nodo(x,crea(dim-1,IN));
	}
}

void stampa(nodo *x,ofstream &OUT){
	if(!x){
		return;
	}
	else{
		if(x->next==0){
			OUT<<x->info<<endl;
		}
		else{
		    OUT<<x->info<<"->";
		}
	stampa(x->next,OUT);
	}
}

main(){
	ifstream INP("input");
	ofstream OUT("output");
	int dim,z;
	INP>>dim;
	nodo*n=crea(dim,INP);
	INP>>z;
	nodo*x = del_z(n,z);
	stampa(x,OUT);
	OUT<<"fine";
}







