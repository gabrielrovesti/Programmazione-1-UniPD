#include <iostream>
using namespace std;

int main(){
    //PRE: n è compreso tra 1 e 100, cin contiene almeno n elementi int
    cout<<"start"<<endl;
    int n;
    cin>>n;
    int biglietti[n];
    for(int i=0;i<n;i++)
        cin>>biglietti[i];
    bool regolare=true;
    int i=0;
    int duplicati[n];
    int nDup=0;
    while(i<n){ //R1: 0<=i<n && duplicati[nDup] contiene i numeri doppi controllati fino a biglietti[i]
        int k=0;
        bool doppio=false;
        while(k<nDup && !doppio){  //R2: 0<=k<nDup && doppio sse biglietti[i] è contenuto nei primi k duplicati
            if(biglietti[i]==duplicati[k])
                doppio=true;
            k++;
        }
        //POST 2: doppio sse biglietto[i] è contenuto in duplicati
        k=0;
        while(k<i && !doppio){  //R3: 0<=k<i && controllato biglietti[0..k-1]
            if(biglietti[k]==biglietti[i]){
                cout<<biglietti[i]<<endl;
                regolare=false;
                doppio=true;
                duplicati[nDup]=biglietti[i];
                nDup++;
            }
            k++;
        }
        //POST 3: cout contiene biglietti[i] se è doppio
        //        duplicati[nDup] contiene biglietti[i] se questo è doppio
        i++;
    }
    //POST 1: duplicati contiene i valori doppi di biglietti
    //        regolare indica se ci sono valori duplicati
    //        cout contiene i numeri dei biglietti duplicati

    if(regolare)
        cout<<"Tutto regolare"<<endl;
    cout<<"end"<<endl;
    return 0;
}