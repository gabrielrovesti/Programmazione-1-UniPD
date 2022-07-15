#include <iostream>
using namespace std;

int F(int i, int lim2, int lim3){
    return ((i/lim3)*(lim2*lim3)+i%lim3);
}
//PRE: T punta all'inizio di una h-fetta che inizia in T, gli elementi 
bool match(int* T, int inizio, int *P, int nP, int lim2, int lim3){
    bool found=true;
    for(int i=0;i<nP && found;i++) //R: 0<=i<=nP && found sse T[inizio...inizio+i-1]=P[0..i-1]
        if(P[i]!=T[F(inizio+i,lim2,lim3)])
            found=false;
    return found;
}
//POST: return true sse nella h-fetta che inizia in T gli elementi inizio, inizio+1,..inizio+nP-1 sono identici a P[0..nP-1]
/*Dimostrazione correttezza ciclo:
1) i=0, found=true poichè confrontati due insiemi vuoti
2) 0<i<nP && found sse T[inizio...inizio+i-1]=P[0..i-1]
3) i>=nP || !found => POST
    a) !found => T[inizio..inizio+nP-1]=P[0..nP-1] => i<nP
    b) i>=nP => T[inizio..inizio+nP-1]!=P[0..nP-1] => found=true*/

int main(){
    int X[400], P[20], n_ele, nP, lim1, lim2, lim3;
    cin >> n_ele;
    for(int i=0; i<n_ele; i++)
        cin >> X[i];
    cin >> lim1 >> lim2 >> lim3;
    if(lim1*lim2*lim3 < n_ele)
        n_ele=lim1*lim2*lim3;
    cin >> nP;
    for(int i=0; i<nP; i++)
        cin >> P[i];
    int nsp= n_ele/(lim2*lim3); //numero strati valorizzati correttamente
    int eus= n_ele%(lim2*lim3); //numero elementi ultimo strato non completo
    int rpus= eus/lim3;         //numero righe ultimo strato complete
    int ur= eus%lim3;           //numero elementi ultima riga non completa ultimo strato
    cout<<"start"<<endl;
    bool trovato= false;
    for(int i=0; i<lim2 && !trovato; i++){  //scorre h-fette
        int nh=nsp*lim3;
        if(i<rpus)
            nh+=lim3;
        else
            if(i==rpus)
                nh+=ur; 
        for(int k=0; k<nh-nP+1 && !trovato; k++){ //scorre h
            if(match(X+i*lim3, k, P, nP, lim2, lim3)){
                trovato=true;
                cout<<"match trovato a partire dalla posizione "<<k<<" della H-fetta "<<i<<endl;
            }
        }
    }
    if(!trovato)
        cout<< "nessun match trovato"<<endl;
    cout<<"end"<<endl;
    return 0;
}