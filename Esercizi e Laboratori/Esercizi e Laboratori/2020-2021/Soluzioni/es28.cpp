//Consegna:
//eliminare i nodi con info==y all'inizio e alla fine della lista concatenata

#include<iostream>
using namespace std;

struct nodo{int info; nodo*next; nodo(int a =0, nodo*b=0){info=a; next=b;}};

nodo* faiL(int arr[],int dim)
{
    if(dim)
    {return new nodo(*arr, faiL(arr+1,dim-1));}
    else
    return 0;
}

nodo* clone(nodo*L)
{
    if(!L) return 0;
    return new nodo(L->info,clone(L->next));
    }
    void stampaL(nodo*L)
    {
    if(!L) cout <<endl;
    else
    {
        cout << L->info<<' ';
        stampaL(L->next);
    }

}

//PRE=(L(L) ben formata, k>=y), vL=L)
nodo* elimI(nodo*L, int &n, int k, int y){
    /*
    Altra idea (usata poi nel caso dopo):

    I primi due casi base servono per non arrivare fino alla fine
    ed eliminare solo i nodi che mi servono

    if(n == k)  return L;
    if(!L){
        n = 0;
        return 0;
    }
    if(L->info == y){
        n++;
        nodo*x=elimI(L->next, n, k, y);
        if(n > 0){
            delete L;
            n--;
            return x;
        }
        else{
            L->next = x;
            return L;
        }
    }

    Si noti che l'else rispetto ad L->info == y rimane identico+
    Appunti:
    importante l'ordine dei casi base, altrimenti dealloca
    i nodi sbagliati.
    L'esempio è possibile anche usando un'altra variabile, come sotto, ma non cambia se la usi o meno.
    */

    if(!L) return 0;
    if(!L->next && n<k) return L;
    if(L->info == y){
        int w = n;  //indica la posizione in cui ci troviamo in quel momento
        n++;       //uso n come contatore, sapendo quanti nodi ho all'andata della ricorsione
        nodo* x = elimI(L->next, n, k, y);
        if(n >= k && w < k){    //il controllo w < k permette, essendo variabile locale, permette di eliminare solo i nodi con info==y alla fine;
        delete L;               //serve quindi a capire che siamo alla fine 
        return x;
        }
        else{
        L->next = x;
        return L;
        }
    }
    else{
        L->next = elimI(L->next, n, k, y);
        return L;
    }
}
    
//POST=(se vL contiene almeno k nodi con info=y, allora L è ottenuta da vL eliminando i primi k nodi con
//info=y di vL, altrimenti, L=vL) &&( se nodi di vL vengono cancellati, essi vanno deallocati)


nodo* elimF(nodo*L, int &n, int k, int y){
    if(!L){
        if(n >= k){
            n = k;          //dobbiamo distruggere k nodi
            return 0;
        }  
        else{
            n = 0;          //dobbiamo distruggere 0 nodi
            return 0;
        }
    }
    if(L->info == y){
        n++;
        nodo* x = elimF(L->next, n, k, y);
        if(n > 0){          //abbiamo ancora un numero n di nodi da eliminare
            delete L;       //cancelliamo L (nodo attuale)
            n--;            //decremento n
            return x;       //ritorno i nodi eliminati
        }
        else{
            L->next = x;    //altrimenti vado avanti
            return L;       //e restituisco normalmente
        }
    }
    else{
        L->next = elimF(L->next, n, k, y);
        return L;
    }
}

int main()
{
    int dim;
    cin >> dim;
    int*arr= new int [dim];
    for(int i=0; i<dim; i++)
    cin >>arr[i];
    nodo*L=faiL(arr, dim);
    nodo*L1=clone(L);

    int n=0, k, y;
    cin >> k >> y;

    L=elimI(L,n,k,y);
    L1=elimF(L1,n,k,y);
    stampaL(L);
    stampaL(L1);
}