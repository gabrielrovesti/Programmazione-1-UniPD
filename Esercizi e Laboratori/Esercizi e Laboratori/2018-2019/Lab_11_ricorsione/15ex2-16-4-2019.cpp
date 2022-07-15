#include <iostream>

using namespace std;

// PRE = S e' una stringa di lunghezza n >= 0
bool palindroma(char *S, int n){
    if(n<=1)
        return true;
    return (*S==S[n-1] && palindroma(S+1, n-2)) ? true:false;
}
// POST = ritorna true se e solo se S e' palindroma
/*Dimostrazione funzione palindroma
caso base (n<=1): S è una stringa vuota oppure contiene un solo carattere, quindi è palindroma: return true => POST
caso ricorsivo (n>1):
    PRE_ric: n-2>=0 ==> PRE
    POST_ric: return true sse la sottostringa con lunghezza n-2 S[1..n-2] è palindroma
    a) se S[0]==S[n-1] e S[1..n-2] è palindroma allora (per ipotesi induttiva) anche S[0..n-1] è palindroma
    b) se S[0]==S[n-1] e S[1..n-2] non è palindroma allora anche S[0..n-1] non è palindroma
    a) o b) => POST*/

int main() {
    int lung;
    char S[100];
    cin.getline(S, 100);        // legge una riga di caratteri da cin
    lung = cin.gcount() - 1;    // ritorna il numero di caratteri letti (compreso il terminatore '\0')
    cout << "start" << endl;
    if(palindroma(S, lung))
        cout<<"la stringa e' palindroma"<<endl;
    else
        cout<<"la stringa non e' palindroma"<<endl;
    cout << "end" << endl;
    return 0;
}