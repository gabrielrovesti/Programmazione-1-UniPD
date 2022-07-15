
#include <iostream>
using namespace std;

struct nodo {
    char info;
    nodo *left, * right;
    nodo(char c='\0', nodo* n=0, nodo* n1=0){
        info =c;
        left=n;
        right= n1;
    };
};

//PRE:

nodo* trova (nodo* x, char y){
if(!x) return 0;

if(x->info == y )return x;

nodo& z = trova(x->left, y);

if(z) return z;

return trova(x->right, y);

}

//PRE: albero(x) e' ben formato
int altezza(nodo* x)
{
	if(!x) return -1;
	else{
		int a= altezza(x->left);
		int b = altezza(x->right);
		if(a>b) return a+1;
		return b+1;
	}
}
//POST: restitiosce ;'altezza di albero

//PRE: albero(x) e' ben formato e non vuoto
int altezza2(nodo* x)
{
	if(!x->left && !x->right)
		return 0;
	int a=-1, b=-1;

	if(x->left) a = altezza2(x->left);
	if(x->right) b= altezza2(x->right);
	if(a>b) return a+1;
	return b+1;

}
//POST: restitiosce l'altezza dell'albero

//PRE Alberto x ben formato, lung>=0, C[0...lung-1]
 nodo* trovaCammino(nodo* x, int*C, int lung){
if(!x) return 0; //fallito

if(lung==0) return x;// trovato

if(*C == 0 ) return trovaCammino(x->left, C+1, lung-1);

else
	return trovaCammino(x->right, C+1, lung-1);

 }


int main() {


	return 0;
}
