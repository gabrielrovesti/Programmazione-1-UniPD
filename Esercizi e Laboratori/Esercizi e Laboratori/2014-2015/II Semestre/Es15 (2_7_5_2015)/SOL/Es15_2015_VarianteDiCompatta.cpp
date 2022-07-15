
//variante di compatta by: Giorgio T.

/*comment:
-cur: Numero di occorrenze di z fino a "fino"
-fino: indice ("fin'ora siamo arrivati qui" questa è stata la mia spiegazione.)*/


int compatta(int *x, int dim, int z, int fino, int cur){
   
    if((fino+cur)>=dim)
        return dim-cur;
   
    x[fino]=x[fino+cur];
   
    if(x[fino]==z)
        return compatta(x,dim,z,fino,cur+1);
    return compatta(x,dim,z,fino+1,cur);   
}
