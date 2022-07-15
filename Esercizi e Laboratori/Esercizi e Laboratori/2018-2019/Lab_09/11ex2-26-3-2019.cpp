#include<iostream>
using namespace std;
//PRE S: A contiene una sequenza di numeri che termina con -2 e che consiste di una serie di sottosequenze che terminano con -1, inoltre n>=0
int S(int *a, int n){
    int k=0, i; //k contatore sottosequenze
    for(i=0; i<400 && a[i]!=-2 && k<n; i++) //R: 0<=i<=400 && scansionati "i" valori di a && k sottosequenze trovate && a[i]==-2 sse è l'ultimo elemento
        if(a[i]==-1)
            k++;
    return k==n && a[i]!=-2 ? i : -2;
}
//POST S: se A contiene la sottosequenza n ed essa inizia in A[i], allora S restituisce i, altrimenti restituisce -2
/*Dimostrazione S
1) i=0 k=0 => controllato un insieme vuoto, nessuna sottosequenza trovata
2) 0<i<400 && cansionati "i" valori di a && k sottosequenze trovate && a[i]==-2 sse è l'ultimo elemento
3) i>=400 || k>=n || a[i]==-2 => POST
    a) k>=n => raggiunta la sequenza n-esima, return i sse a[i]!=-2 (ovvero esiste la sottosequenza n-esima)
    b) a[i]==-2 => terminata la sequenza, return -2 sse k<n (sottosequenza n-esima non trovata)
    c) i>=400 => terminata la sequenza, return -2 poichè a[399] è necessariamente =-2 per soddisfare la PRE*/
int main()
{
    int X[400];
    cin>>X[0];
    for(int i=1; i<400 && X[i-1]!=-2; i++)
        cin >>X[i];
    int n;
    cin>>n;
    cout<<"start"<<endl;
    int b=S(X,n);
    if(b==-2)
        cout<<"sottosequenza "<<n<<" non presente"<<endl;
    else
        cout<<"inizio sottosequenza "<<n<<" indice="<<b<<endl;
    cout<<"end"<<endl;
    return 0;
 }