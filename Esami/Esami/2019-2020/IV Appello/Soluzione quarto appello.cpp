int conta_match(nodoE*L, int*P, int dimP){
    int n=0;
    if(!L || !dimP){
        return n;
    }
    if(L->info->info==*P){
        n=1+conta_match(L->next, P+1, dimP-1);
        return n;
    }
    else{
        n=conta_match(L, P+1, dimP-1);
        return n;
    }
}
 
int matchRic(nodoE*L, int*P, int dimP){
    int max=0;
    if(!L || max==dimP){
        return max;
    }
    max=conta_match(L, P, dimP);
    int n=matchRic(L->next, P, dimP); 
    if(n>max){
        max=n;
    }
    return max;
}