//PRE: T albero

nodoE* concat(nodeE* F, nodoE* S){
	if(!F){
		return S;
	}
	F->next = concat(F->next,S);
	return F;
}

nodoE* listLeafs(nodo* T){
	if(!T){
		return null;
	}
	nodoE* l = listLeafs(T->left);
	nodeE* r = listLeafs(T->right);
	nodeE* tot = concat(l,r);
	if(!tot){
		return new nodoE(T);
	}
	return tot;
}
//POST: return lista foglie in ordine


bool isBST(node* T, int& prec){
	if(T->info<prec){
		prec = T->info
		if(T->left){
			isBST(T->left, prec)
		}
		//prec???
	}
	return false;
}

bool isBST(nodo* T){
	if(!T)
		return true;	
	bool sx=false,dx=false;
	if(!T->left || T->info>T->left)	
		sx=true;
	if(T->info<T->right || !T->right)
		dx=true;
	return sx && dx && isBST(T->left) && isBST(T->right);
} 

bool isBST(nodo* T, int l1, int l2){
	if(!T){
		return true;
	}
	if(T->info<l1 || T->info>l2){
		return false;
	}
	return isBST(T->left,l1,T->info) && isBST(T->right,T->info,l2);
}




//PRE: T albero bilanciato, vT = T
int n_nodes(nodo* T){
	if(!T)
		return 0;
	return 1 + n_nodes(T->left) + n_nodes(T->right);
}
nodo* balance_insert(nodo* T, int y){
	if(!T)
		return new nodo(y);
	if(n_nodes(T->left)==n_nodes(T->right))
		T->left = balance_insert(T->left,y);
		return T;
	else
	T->right = balance_insert(T->right,y);
	return T;
} 
//POST: T risultante bilanciato e = vT + nodo(y)







nodeE* PMCOMP(nodo*T, int*&P, int &dimP){
	nodeE* match =PM(T,P,dimP);
	if(!dimP){
		deleteall(match);
		return null;
	}
	return match;
}



nodoE* PM(nodo*T, int*&P, int &dimP){
	if(!T || !dimP){
		return null;
	}
	if(T->info==*P){
		P=P+1;
		dimP-=1;
		nodoE* prima = PM(T->left, P, dimP);
		nodoE* seconda = PM(T->left, P, dimP);
		
		return new nodoE(T, conc(prima,seconda))
	}
	nodoE* prima = PM(T->left, P, dimP);
	nodoE* seconda = PM(T->right, P, dimP);
	return conc(prima,seconda);
}
