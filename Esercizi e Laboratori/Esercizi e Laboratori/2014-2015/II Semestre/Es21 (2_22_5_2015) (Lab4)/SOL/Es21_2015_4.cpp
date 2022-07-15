
//soluzione by: Riccardo M.

//PARTE a)
dueL sgrana(nodo* L)
{
        if(L == 0)
        {
                return dueL(0, 0);
        }
       
        if(L->next == 0)
        {
                return dueL(L, 0);
        }
       
        dueL V;
       
        V.prima = L;
        V.seconda = L->next;
       
        dueL nextElements = sgrana(L->next->next);
       
        V.prima->next = nextElements.prima;
        V.seconda->next = nextElements.seconda;
       
        return V;
}
//              dove L1 e L2 sono liste corrette o vuote, L1 contiene i nodi dispari
//              e L2 contiene i nodi pari)


//PARTE b)
//(mancante)
