#include <iostream>
using namespace std;

// PRE = n >= 0
void stampa_verticale(int n){
    if(n<10)
        cout<<n;
    else{
        stampa_verticale(n/10);
        cout<<n%10;
    }
    cout<<endl;    
}
// POST = stampa il numero n in verticale, con ogni cifra decimale in una riga diversa
/*Correttezza stampa_verticale
caso base: n<10 -> n ha una cifra, stampa solo quella
caso ricorsivo: n>=10
PRE_ric: n/10>=0 -> vale la pre
POST_ric: stampa n/10 in verticale*/
int main() 
{
    cout << "start" << endl;
    int num;
    cin>>num;
    stampa_verticale(num);
    cout << "end" << endl;
    return 0;
}