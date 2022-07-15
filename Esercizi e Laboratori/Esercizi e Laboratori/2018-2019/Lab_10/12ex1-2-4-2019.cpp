#include <iostream>
using namespace std;

// PRE = (P e' un pattern che termina con '\0' && S e' una sequenza di char che termina con '\0')
bool match(char* P, char* S, int lp){
    bool found=true;
    for(int i=0; i<lp && found;i++) //R: 0<=i<=lp && found sse S[0..i-1]=P[0..i-1]
        if(P[i]!=S[i] && P[i]!='?')
            found=false;
    return found;
}
// POST = (la funzione ritorna true se e solo se P occorre in S a partire dalla posizione 0)
/*Dimostrazione funzione match
1) i=0 && found, ho controllato due insieme vuoti, dunque sono uguali
2) 0<i<lp, found sse sse S[0..i-1]==P[0..i-1]
3) i>=lp || !found => POST
    a) !found => S[0..lp-1]!=P[0..lp-1] => i<lp
    b) i>=lp => S[0..lp-1]=P[0..lp-1] => found*/
    
int lung_r(char* x){
    int i=0;
    while(x[i]!=0) i++;
    return i;
}
// PRE = (cin contiene un pattern P, seguito un intero n_righe, seguito da un testo T lungo n_righe righe)
int main() {
    char P[100], T[100][100];
    int n_righe = 0;
    cin.getline(P, 100);
    cin >> n_righe;
    cin.ignore();       // ignora il carattere "a capo" dopo la lettura del numero di righe 
    for(int i = 0; i < n_righe; i++) 
        cin.getline(T[i],100);
    cout << "start" << endl;
    bool found=false;
    int lp=lung_r(P);
    for(int r=0;r<n_righe;r++){
        int lr=lung_r(&T[r][0]);
        for(int c=0; c<lr-lp+1; c++)
            if(match(P, &T[r][c], lp)){
                found=true;
                cout<<"riga: "<<r<<" colonna: "<<c<<endl;
            }
    }
    if(!found)
        cout<<"Pattern non trovato"<<endl;
    cout << "end" << endl;
    return 0;
}
// POST = (stampa "riga: i colonna: j" per ogni occorrenza i,j di P in T, oppure "Pattern non trovato" se P non occorre in T)
