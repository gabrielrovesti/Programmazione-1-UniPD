	#ifndef BST_H
	#define BST_H
struct nodo {
	int info;
	nodo* left, *right;

	nodo(int chiave=0, nodo* l=0, nodo* r=0){
		info=chiave;
		left=l;
		right=r;
	};

};

nodo* inserisciRicorsiva(nodo*, int);
nodo* inserisciIterativa(nodo* r, int chiave);

nodo* cerca(nodo*, int);

nodo* cerca2(nodo* r, int chiave);
nodo* trova_min(nodo*);


nodo* trova_max(nodo*);

nodo* del(nodo*, int);

//PRE fisso
void pre_order(nodo* root);
//infisso
void in_order(nodo* root);
//post fisso
void post_order(nodo* root);
#endif /*BST_H*/
