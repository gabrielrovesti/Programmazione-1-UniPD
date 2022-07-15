#include <iostream>
using namespace std;

int main(){
    int n, a[100];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"start"<<endl;
    bool finito=false;
    for(int i=0;(i<n) && !finito;i++)   //R1: 0<=i<=n && a[0...i-1] contiene 0
        if(a[i]==1){
            bool trovato=false;
            for(int k=i+1;(k<n) && !trovato;k++)    //R2: i+1<=k<=n && controllate k-(i+1) celle dopo a[i]
                if(a[k]==0){
                    int temp=a[i];
                    a[i]=a[k];
                    a[k]=temp;
                    trovato=true;
                }
            //POST2: trovato sse a[i+1..n-1] contiene uno 0
            if(!trovato)
                finito=true;
        }
    //POST1: a[0...i-1] contiene 0 && a[i...n] contiene 1
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl<<"end"<<endl;
    return 0;
}