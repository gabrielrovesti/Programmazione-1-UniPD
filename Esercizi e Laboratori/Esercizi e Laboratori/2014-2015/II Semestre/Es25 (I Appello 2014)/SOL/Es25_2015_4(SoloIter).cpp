
//soluzione by: Viviana A. (SOLO FUNZIONE ITERATIVA)

void add_iter(int* C, nodo*& r, ifstream & INP, ofstream & OUT){
  // se l'albero è proprio vuoto aggiungo subito il nodo senza fare controlli inutili
  if(!r){ 
    int x; INP>>x;
    r = new nodo(x,0,0);
    return;
  }
  nodo *scorri = r; // per salvarmi il puntatore alla radice
  nodo *padre = 0;
  bool fine_albero = false, sx;
  
  while( *C != -1 && !fine_albero){
    if(!scorri)
      fine_albero = true;
    else{
      if(*C == 0){
	sx = true;
	padre = scorri;
	scorri = scorri->left;
      }
      else if(*C == 1){
	sx = false;
	padre = scorri;
	scorri = scorri->right;
      }
      C++;
    }
  }
  
  int x; INP>>x; //consumo un input qualsiasi cosa succeda
  if(fine_albero)
    OUT << "cammino troppo lungo " << x <<endl;
  else if(!fine_albero && !scorri){ //significa che sono uscita dal while perchè *C=-1. posso aggiungere il nodo perchè ho scorri vuoto
    nodo *X = new nodo(x,0,0);
    if(sx)
      padre -> left = X;
    else
      padre -> right = X;
  }
  else // sono uscita dal while perchè *C=-1, ma scorri ha ancora qualche nodo
    OUT << "cammino troppo corto " << x <<endl;
}
