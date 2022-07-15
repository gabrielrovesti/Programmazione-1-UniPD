
//soluzione by: Gilberto File' (prof)

//pre = x è il primo elemento del pattern (definito), L corrretta (anche vuota). m = nodi saltati
cop saltaF(nodo *L, int x, int m){
  if(!L)
    return cop();
  if(L->info1 != x)
    return salta(L->next,x,m+1);
  else
    return cop(L,m); se L->info1 == x finiamo in questo caso quindi dobbiamo ritornare proprio L.
}
/* post = restituisce z di tipo cop. se z.N è 0 allora ho finito la lista senza trovare match di x.
        altrimenti z.N è un puntatore tale che z.N -> info1 == x e z.num = quanti nodi sono da saltare dall'
        inizio di L per avere z.N.
        prima di z.N nessun nodo matchava. */

 
 
 //pre = lista L corretta, P[0..dimP-1] definito, m definito, m=vm.
cop matchF(nodo *L, int *P, int dimP, int m){
   if(!dimP || !L)
     return cop(L,m);
   if(L->info == *P)
     return match(L->next,P+1,dimP-1,m+1);
   else
     return cop(L,m);
}
//post = restituisce z di tipo cop. z.num ci dice quanti elementi hanno matchato dall' inizio di L matchiamo in pratica P[0..z.num-vm]

 
 
 nodo * F0F(nodo *L, int *P, int dimP){
   if(!dimP || !L)
     return 0;
   cop x = saltaF(L,P[0],0);
   if(!x.N)
     return 0;
   cop m = matchF(x.N,P,dimP,0);
   nodo *z = F0F(m.N,P+m.num,dimP-m.num);
   return new nodo(x.num,m.num,z);
}
