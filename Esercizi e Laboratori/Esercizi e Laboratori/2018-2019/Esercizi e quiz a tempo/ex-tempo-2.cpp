#include <iostream>
using namespace std;

//PRE match: x punta all'inizio della sequenza da controllare, x[0..np] è valorizzato, p[0..np-1] è il pattern da matchare
bool match(int *x, int *p, int np){
    bool ok=true;
    for(int i=0;i<np && ok;i++) //R1: 0<=i<=np && ok sse x[0..i-1]=p[0..i-1]
        if(x[i]!=p[i])
            ok=false;
    return ok;
}
//POST match: ritorna true sse x[0..np-1]=p[0..np-1]

int main(){
    int X[400], n_ele, nP, P[20];
    cin>> n_ele;
    for(int i=0; i<n_ele; i++)
        cin >> X[i];
    int lim1,lim2,lim3;
    cin>> lim1>>lim2>>lim3;
    cin >> nP;
    for(int i=0; i<nP; i++)
        cin>>P[i];
    cout<<"start"<<endl;
    bool trovato=false;
    int nsp=n_ele/lim2*lim3;
    int resto;
    if(nsp>=lim1){
        nsp=lim1;
        resto=0;
    }
    else
        resto=n_ele%lim2*lim3;

    //PRE: X contiene nsp strati valorizzati completamente
    for(int s=0;s<nsp && !trovato;s++)  //R2: 0<=s<=nsp && trovato sse pattern P trovato in X[0..s*lim2*lim3-1]
        for(int i=0;i<lim2*lim3-nP+1 && !trovato;i++) //R3: 0<=i<=lim2*lim3-nP+1 && trovato sse pattern P trovato in X[s*lim2*lim3..s*lim2*lim3+i-1] && sse  trovato allora stampato l'indice dello strato in cui è stato trovato il match
            if(match(X+s*lim2*lim3+i,P,nP)){
                trovato=true;
                cout<<"Lo strato "<<s<<" di T contiene un match"<<endl;
            }
        //POST3: trovato sse pattern P trovato nello strato s di x
    //POST2: trovato sse (pattern P trovato in uno strato pieno di x && stampato l'indice dello strato in cui è stato trovato il match)
    for(int i=0;i<resto-nP+1 && !trovato;i++) //R4: 0<=i<=resto-nP+1 && trovato sse P trovato in X[nsp*lim2*lim3..nsp*lim2*lim3+i-1]
    //bisogna dimostrare che valga la pre della funzione
        if(match(X+nsp*lim2*lim3+i,P,nP)){
            trovato=true;
            cout<<"Lo strato "<<nsp<<" di T contiene un match"<<endl;
        }
    //POST: trovato sse (P trovato nello strato nsp, stampato nsp)
    if(!trovato)
        cout<<"Nessun match trovato"<<endl;
    cout<<"end"<<endl;
    return 0;
}

/*
Inizializzazione:
    R1) i==0 && ok inizializzato a true poiché non è ancora stato controllato nessun elemento di x
    R2) s==0 && trovato inizializzato a false poiché non è ancora stato controllato nessuno strato
    R3) i==0 && trovato inizializzato a false poiché non è ancora stato controllato nessun elemento dello strato

Invarianza:
    R1) 0<i<np && ok sse x[0..i-1]=p[0..i-1]
    R2) 0<s<nsp && trovato sse pattern P trovato in X[0..s*lim2*lim3-1]
    R3) 0<i<lim2*lim3-nP+1 && trovato sse pattern P trovato in X[s*lim2*lim3..s*lim2*lim3+i-1]

Terminazione:
    R1) 0<=i<=np && ok sse x[0..i-1]=p[0..i-1] && (i>=np || !ok)
    a) !ok da R1 X[0..nP-1]
*/