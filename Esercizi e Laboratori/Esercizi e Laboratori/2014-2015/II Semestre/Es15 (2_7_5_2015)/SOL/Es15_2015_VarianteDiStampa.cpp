
//variante 1 di stampa/stamparic by: Marco M.

/*comment:
Facendola cosí diciamo che funziona abbastanza e li divide ogni 4...
ha qualche piccolo problema perché all inizio della stampa c'è una riga vuota e alla fine c'è solo uno spazio peró il resto è giusto. */


void stampa(int *x,int dim,ofstream &out)
 {
     if(dim<=3*4*4){
         if(dim==0)
         {
             return;
         }
         else
         {
             stampa(x,dim-1,out);
             if(((dim-1)%4)==0)
                 out<<endl;
             out<<x[dim-1]<<" ";
         }
        
     }
     else
     {
         stampa(x,3*4*4,out);
     }

    
 }


 
 
 
//variante 2 di stampa/stamparic by: Luca C.

/*comment:
il problema è che all'andata della ricorsione ne ho dim e non rappresentano l'indice del numero che stai stampando ma quanti numeri ancora devi stampare,
quindi non puoi decidere se andare a capo o meno su quello, io l'ho risolto facendo la stampa al ritorno in cui invece dim può essere usato come indice. */


void stamparic(int *x, int dim, ofstream &OUT){
        dim--;
        if(dim==0){
                OUT<<*(x+(dim))<<" ";
        }
        else{
                stamparic(x, dim, OUT);
                if((dim%4)==0){
                        OUT<<endl;
                }
                OUT<<*(x+(dim))<<" ";
        }
}
