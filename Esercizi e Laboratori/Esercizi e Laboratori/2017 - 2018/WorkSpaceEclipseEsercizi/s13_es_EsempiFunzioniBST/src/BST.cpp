	#include<iostream>
	#include "BST.h"
	using namespace std;

	nodo* inserisciRicorsiva(nodo* r, int chiave){
		if(!r) return new nodo(chiave);
		if(r->info > chiave)
			r->left= inserisciRicorsiva(r->left, chiave);
		else
			r->right= inserisciRicorsiva(r->right, chiave);
		return r;
	}
	nodo* inserisciIterativa(nodo* r, int chiave){
		nodo *p= 0, *root= r;
		while(root){
			p=root;
			if(root->info > chiave)
				root= root->left;
			else
				root= root->right;
		}
		if(p->info>chiave)
			p->left= new nodo(chiave);
		else
			p->right= new nodo(chiave);
		return p;
	}
	nodo* cerca(nodo* r, int chiave){
		if(!r) return 0;
		if(r->info== chiave)
			return r;
		if(r->info> chiave)
			return cerca(r->left,chiave);
		else
			return cerca(r->right,chiave);
	}
	nodo* cerca2(nodo* r, int chiave){
		nodo * tmp=r;
		while(tmp && tmp ->info!=chiave){
			if(tmp->info>chiave)
				tmp=tmp->left;
			else
				tmp=tmp->right;
		}
		return tmp;
	}

	nodo* trova_min(nodo* r){
		if(!r) 	 return 0;
		nodo* tmp= r;
		while(tmp->left)
			tmp=tmp->left;
		return tmp;
	}


	nodo* trova_max(nodo* r){
		if(!r) 	 return 0;
			nodo* tmp= r;
			while(tmp->right)
				tmp=tmp->right;
			return tmp;
	}

	nodo* del(nodo* root, int chiave){
		//caso base:
		if(!root) return root;
		//se il campo info del nodo correte e' maggiore della chaive da cancellare
		if(root->info > chiave){
	//		assegno al sottoalbero sx il risultato della chiamata ricorsiva
			root->left= del(root->left, chiave);
		}else if(root->info < chiave){
	//		assegno al sottoalbero destro il risultato della chaiamta ricorsiva
			root->right= del(root->right, chiave);
		}else{
			//se il campo info del nodo correte e' uguale alla chiave da cancellare il nodo correte e' proprio quello da cancellare
			if(!root->left){	// il nodo correte non ha sottoalbero SX
				nodo* temp = root->right;// salvo il puntatore al figlio destro
				delete(root); // cancello il nodo corrente.
				return temp;// restituisco il nodo figlio
			}else if(!root->right){//il nodo corrente non ha sottoalbero DESTRO
				nodo* temp = root->right; // salvo il figlio destro
				delete(root);//elimino il nodo corrente.
				return temp;	//restituisco il nodo figlio

			/*
			 * Se siamo giunti qui, il nodo corrente ha due figli:
			 * recuperiamo il nodo successore del nodo corrente che , per costruzione
			 * e' il nodo con il campo info piu' piccolo nel sottoalbero DX
			 */}
			nodo* temp= trova_min(root);
	//		copiamo il contenuto del nodo successore nel nodo corrente
			root->info= temp->info;
	//		cancelliamo il nodo successore
			root->right= del(root->right, temp->info);
		}
		return root;
	}

	//PRE fisso
	void pre_order(nodo* root){
		if(!root){
			cout<<root->info<<endl;
			pre_order(root->left);
			pre_order(root->right);
		}
	}
	//infisso
	void in_order(nodo* root){
		if(!root){
			pre_order(root->left);
			cout<<root->info<<endl;
			pre_order(root->right);
		}
	}
	//post fisso
	void post_order(nodo* root){
		if(!root){
			pre_order(root->left);
			pre_order(root->right);
			cout<<root->info<<endl;
		}
	}

