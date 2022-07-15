#include<iostream>
using namespace std;

struct nodo{int num, info; nodo* next; nodo(int a=0,int b=0, nodo* c=0){num=a; info=b; next=c;}}; // nodo di lista
struct FIFO{nodo* primo, *ultimo; FIFO(nodo*a=0, nodo*b=0){primo=a; ultimo=b;}};
struct nodoF{FIFO info; nodoF*next; nodoF(FIFO a=FIFO(),nodoF*b=0){info=a; next=b;}}; //nodo di lista con FIFO

FIFO push_end(FIFO a, nodo*b)
{
    b->next=0;
    if(!a.primo)
    {a.primo=a.ultimo=b;}
    else
    {a.ultimo->next=b; a.ultimo=b;}
    return a;
}

FIFO push_begin(FIFO a, nodo* b)
{
    if(!a.primo)
    {a.primo=a.ultimo=b; b->next=0; return a;}
    else
    {
        b->next=a.primo;
        a.primo=b;
        return a;
    }
}

void stampa_L(nodo*L)
{
    if (L)
    {cout<<'['<<L->num<<','<<L->info<<']'<<' '; stampa_L(L->next);}
    else
        cout<<endl;
    
}
void stampa_F(nodoF* x)
{
    if(x)
    {
        stampa_L(x->info.primo);
        cout<<endl;
        stampa_F(x->next);
    }
}

nodo* costruisci(int n, int dim)
{
    if(dim)
    {int x; cin>>x; return new nodo(n,x,costruisci(n+1,dim-1));}
    return 0;
}
nodo* clone(nodo*a)
{
    if(a)
    {return new nodo(a->num, a->info, clone(a->next));}
    return 0;
}


/* FUNZIONI DA FARE PER ESAME */



FIFO eliminaR(nodo *&L, int x){
    // caso base
    if(!L)
        return FIFO();
    if(L->info==x){
        // R-Valore di L, quindi il valore corrente del nodo, viene assegnato al valore tmp, che poi verrà messo nella FIFO.
        nodo* tmp=L;
        // L-Valore di L, alias di next del nodo precedente; R-Valore di L, valore successivo del nodo corrente.
        // quindi questa operazione, va ad eliminare il valore corrente del nodo, andando a collegare il precedente con il successivo.
        L=L->next;
        // non devo deallocare il valore istantaneo perché poi va inserito in una FIFO.
        tmp->next=0;
        FIFO coda= eliminaR(L, x); // questo valore mi ritorna la fifo creata precedentemente.
        coda= push_begin(coda, tmp); // devo metttere all'inizio, perché è un valore di ritorno.
        return coda;
    }//if.
    else{
        return eliminaR(L->next, x);
    }//else.
}//eliminaR.


nodoF* insR(nodoF*Q, FIFO x){
    // Caso Base
    if(!Q){
        return new nodoF(x,0);
    }//if.
    // Q esiste, quindi controllo se la fifo corrente è la più piccola di tutte.
    if(x.primo->info < Q->info.primo->info){
        return new nodoF(x, Q);
    }//if.
    // Non è la più piccola di tutte, quindi controllo se c'è qualcos'altro.
    if(Q->next){ // Per la pre condizione.
        if((x.primo->info > Q->info.primo->info) && (x.primo->info < Q->next->info.primo->info)){
            Q->next= new nodoF(x, Q->next);
            return Q;
        }//if.
    }//if.
    // Se sono arrivato qui vuol dire che non c'era altro prima, e devo inserirlo per ultimo.
    Q->next=insR(Q->next, x);
    return Q;
}//insR.


nodoF* tieni_primo_ric(nodo *& L){
    //caso base
    if(!L)
        return 0;
    FIFO x=eliminaR(L->next, L->info);
    
    if(x.primo){
        nodoF* Que=tieni_primo_ric(L->next);
        Que=insR(Que, x);
        return Que;
    }//if.
    else{
        return tieni_primo_ric(L->next);
    }//else.
}//tieni_primo_ric.



nodoF* insI(nodoF* Q, FIFO x){
    if(!Q){
        return new nodoF(x,0); ; // Se Q è vuota allora x è il primo valore esistente in Q, quindi assengno il valore di x a info, essendo due FIFO.
    }//if.
    if(x.primo->info < Q->info.primo->info){
        return new nodoF(x, Q);
    }//if.
    nodoF* tmp=Q;
    while(tmp->next){
        if((x.primo->info > Q->info.primo->info) && (x.primo->info < Q->next->info.primo->info)){
            Q->next=new nodoF(x, Q->next);
            return Q;
        }//if.
        tmp=tmp->next;
    }//while.
    Q->next=new nodoF(x,0);
}//insI.


/*
 Spiegazione del codice:
 entro nel ciclo, prendo il nodo presente, faccio una ricerca di tutti i nodi presenti nella lista e vedo se è presente o meno il campo info: se non è presente lo metto in una fifo
 questa fifo andrà poi messa in una lista di nodoF in ordine crescente
 */


nodoF* tieni_primo_iter(nodo *& L){
    nodoF* Q=0; //creo la lista nodoF da mandare poi.
    FIFO tenuti;
    while(L){
        FIFO eliminati;
        nodo* tmp=L;
        int info=tmp->info;
        nodo* eliminato;
        
        // devo prendere tutti i nodi che sono presenti in lista che sono uguali a quello temporaneo, e metterli in una FIFO.
        // il ciclo è così costituito :
        // se il nodo è presente lo metto in una FIFO eliminati altrimenti
        // poi devo eliminare dalla lista il valore successivo facendo quindi tmp->next=successivo->next
        
       while(tmp->next){
            if(tmp->next->info==info){
                eliminato=new nodo(tmp->next->num, tmp->next->info); // devo utilizzare questo modo perché se passassi direttamente tmp->next, perché mi si azzererebbe tutto il resto della lista altrienti.
                delete tmp->next;
                tmp->next=tmp->next->next;
                eliminati=push_end(eliminati, eliminato);
            }//if.
            else{
                tmp=tmp->next;
            }//else.
        }//while.
        
        
        //eliminati=eliminaR(L->next, info);
        
        // devo mettere la fifo costruita di quelli eliminati in nodoF, ovviamente devo fare un controllo se la FIFO è vuota o meno
        // se la FIFO è vuota non devo inserire nulla, quindi devo fare un check su eliminati.primo
        
        
        if(eliminati.primo){
            Q=insI(Q,eliminati);
        }//if.
        nodo* tieni=L;
        L=L->next;
        // devo utilizzare questo metodo per i tenuti, perché scorrendo L, vado avanti e non posso tornare indietro, ed essendo un riferimento poi sul main mi si riperquote ciò.
        tenuti=push_end(tenuti, tieni);
    }//while.
    L=tenuti.primo;
    return Q;
    
}//tieni_primo_iter.



int main()
{
    int dim;
    cout<<"start"<<endl;
    cin>>dim;
    nodo*C=costruisci(0,dim);
    nodo*D=clone(C);
    cout<<"Lista costruita"<<endl;
    stampa_L(C);
    nodoF* a =tieni_primo_ric(C); //da fare
    cout<<"soluzione ricorsiva"<<endl<<"nodi tolti:"<<endl;
    stampa_F(a);
    cout<<"lista rimanente:"<<endl;
    stampa_L(C);
    nodoF* b=tieni_primo_iter(D); //da fare
    cout<<"soluzione iterativa"<<endl<<"nodi tolti:"<<endl;
    stampa_F(b);
    cout<<"lista rimanente:"<<endl;
    stampa_L(D);
    cout<<"end";
    return 0;
}



