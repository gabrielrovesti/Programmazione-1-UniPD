#include<iostream>
using namespace std;
int F(int i, int lim2, int lim3){
    return (i/lim3)*lim2*lim3+i%lim3;
}

void stampa_fetta(int* x, int l, int lim2, int lim3){
    for(int i=0; i<l; i++)
    cout<<x[F(i, lim2, lim3)]<<" ";
    cout<<endl;
}

int main()
{
    int X[400], P[20], n_ele, nP, lim1, lim2,lim3;
    cin >> n_ele;
    for(int i=0; i<n_ele; i++)
    cin >> X[i];
    cin >> lim1 >> lim2 >> lim3;
    if(lim1*lim2*lim3 < n_ele)
    n_ele=lim1*lim2*lim3;
    cin >> nP;
    for(int i=0; i<nP; i++)
    cin >> P[i];
    int nsp= n_ele/(lim2*lim3); //numero strati completi
    int eus= n_ele%(lim2*lim3); //elementi ultimo strato
    int rpus= eus/lim3;         //numero righe complete ultimo strato
    int ur= eus%lim3;           //numero elementi ultima riga ultimo strato
    cout<<"start"<<endl;
    int hf;
    cin >> hf; // fetta da trattare
    int lung=lim3*nsp; // lunghezza della H-fetta hf
    if(eus>0)
    if(hf<rpus)
        lung+=lim3;
    else
        if(hf==rpus)
            lung+=ur;
    int ip=0;
    //PRE: la h-fetta hf ha lung elementi, il vettore P ne ha nP
    for(int j=0; j < lung-ip && ip<nP; j++) //R: 0<=j<=lung-ip && 0<=ip<=nP && la hf fetta 0..j-1 non contiene valori che matchano con P
        while(P[ip]==*(X+hf*lim3+F(j,lim2,lim3)) && ip<nP){ //lo scorrimento rimane bloccato all'elemento j finche' non matcha piu' con P, dato che j viene rimosso, dopo la rimozione j sara' l'elemento successivo nella hf fetta
            for(int i=j;i<lung-ip;i++)
                X[hf*lim3+F(i,lim2,lim3)]=*(X+hf*lim3+F(i+1, lim2,lim3));
            ip++;
        }
    //POST: la hf fetta 0..lung-ip-1 non contiene il pattern P, sono stati rimossi ip elementi dalla hf fetta
    /*Dimostrazione ciclo
    1) j=0, ip=0, hf 0..0 e' un insieme nullo, quindi non contiene il pattern
    2) 0<j<lung-ip && 0<=ip<nP && la hf fetta da 0 a j-1 non contiene elementi che matchano con P
    3) j>=lung-ip || ip>=nP => POST
        a) j>=lung-ip => la hf fetta e' lunga lung-ip elementi, ovvero sono stati rimossi ip elementi che matchavano con P
        b) ip>=nP => la hf fetta e' lunga lung-np elementi, ovvero tutto il pattern P e' stato trovato e rimosso dalla hf fetta*/
    if(ip<nP){
        cout<<"pattern rimasto: ";
        for(int i=ip; i<nP; i++)
            cout<<P[i]<<" ";
        cout<<endl;
    }
    else
        cout<<"pattern consumato tutto"<<endl;
    cout<<"la H-fetta "<<hf<<" e' diventata:"<<endl;
    stampa_fetta(X+hf*lim3, lung-ip, lim2, lim3);
    cout<<"end"<<endl;
    return 0;
}