#include <iostream>
#include "BST.h"
using namespace std;


nodo* ricercaConEccezione(nodo* x, int info ){
	 if(x){
		 if(x->info) return x;
		 else{
			 try{
				 return ricercaConEccezione(x->left, info);
			 }catch(int a ){
				 return ricercaConEccezione(x->right, info);
			 }
		 }
	 }else
		 throw(1);

}



int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!


	nodo* r= inserisciRicorsiva(r,5);//albero
	int f=10;//valore

	try{
		cout<<"trovato "<<ricercaConEccezione(r,f)->info<<endl;
	}catch(int a ){
		cout<<"il valore: "<<f<<" non e' stato trovato "<<endl;

	}


	return 0;
}
