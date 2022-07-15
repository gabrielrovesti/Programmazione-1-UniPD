#include<iostream>
using namespace std;

void stampa(int*P,int m,int i)
{
    if(i==m){
        cout<<endl;
        return;
    }
    cout<<'('<<i<<','<<P[i]<<')'<<' ';
    stampa(P,m,i+1);
}

//PRE: N ha almeno m*m elementi definiti, 0<=i<m, j è definito e P ha m-i posizioni
bool trova(bool *N, int m, int i, int j, int* P){
    if(j==m)
        return true;
    bool trovato=false;
    if(j<m){
        if(*(N + j*m + i - 1) && i>0){
            *P=i-1;
            trovato=trova(N, m, i-1 , j+1 , P+1);
        }
        if(*(N + j*m + i) && !trovato){
            *P=i;
            trovato=trova(N, m, i , j+1 , P+1);
        }
        if(i<m-1 && !trovato && *(N + j*m + i + 1)){
            *P=i+1;
            trovato=trova(N, m, i+1 , j+1 , P+1);
        }
    }
    return trovato;
}
//POST: restituisce true sse in N vista come X[m][m] c’è un cammino dalla casella(i,j)
// alla riga m-1 composto da sole caselle bianche

//PRE: N ha m*m valori definiti, 0<=i<=m e P ha m elementi
bool partenza(bool *N, int m, int i, int *P){
    bool trovato=false;
    if(i<m){
        if(*(N+i)){
            *P=i;   //salva primo passo del cammino
            trovato=trova(N, m, i, 1, P+1); //cerca cammino partendo da quella casella
        }
        if(!trovato)    //se non ho trovato un cammino partendo da quella casella passo alla prossima
            trovato=partenza(N, m, i+1, P);
    }
    return trovato;
}
//POST: true sse esiste un cammino di caselle bianche dalla prima all'ultima riga di N

int main()
{
    int m;
    cin>>m;
    int*P=new int[m];
    bool*N =new bool[m*m];
    for(int i=0; i<m*m; i++)
        cin>>N[i];
    bool x=partenza(N,m,0,P);//da fare 
    cout<<"start"<<endl;
    if(x){
        cout<<"esiste un cammino e quello più a sinistra è:"<<endl;
        stampa(P,m,0);
    }    
    else
    cout<<"il cammino non esiste"<<endl;
    cout<<"end"<<endl;
    return 0;
}
/* DIMOSTRAZIONE CORRETTEZZA 
caso base:
        j==m, abbiamo finito di scorrere le righe, allora tutte le chiamate  a trova hanno trovato una cella per il pattern, e quindi ritorniamo true 
    caso j<m 
        verifica della PRE per tutti e tre i casi ricorsivi:
            --> N e m sono sempre definiti in quanto il loro valore non cambia mai in tutta la durata dell'esecuzione
            --> 0<=i<m sempre vero, perche in tutta ''trova'' non si cambia mai il valore di i, e nella prima chiamata di trova dentro
                partenza, si controlla che i<m, e come valore iniziale di i si ha 0, quindi 0<=i<m sempre valido
            --> j è definito sempre in quanto la prima chiamata derivante da partenza ha come valore iniziale 0, 
                 nelle rispettive tre chiamate ricorsive a trova, il paramentro j sarà j+1
            --> P ha m-j posizioni, in quanto alla prima chiamata da partenza si passa P+1 e j=1, quindi P conterrà m-1 elementi, mentre nelle chiamate
                ricorsive, si passa sempre P+1 e j+1, quindi nel caso peggiore, quindi quando j==m, P conterrà 0 celle, infatti abbiamo trovato il pattern, quindi m coordinate
            verifica della POST per tutti e tre i casi ricorsivi:
            trovato vale false di default, sse una delle tre chiamate ritornerà true, trovato vale true e 
            se una delle chiamate ritorna true, l'unico modo è che si sia arrivati ad una chiamata in cui j==m, e che quindi si sia trovato un cammino.

            se restituisce true, allora P contiene le coordinate del cammino piu a sinistra, in quanto nella funzione i tre controlli vanno da sinistra a destra
            quindi da i-1 (se si piò), i, i+1 (se si può), e dato un caso che restituisce true, e che quindi ci sia un cammino per quella via, allora non si tengono in considerazione gli altri casi gli altri casi*/