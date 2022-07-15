#include<iostream>
using namespace std;
//PRE TV: p punta al primo elemento di una V-fetta, gli altri parametri sono ben definiti
int& TV(int *p, int lim1, int lim2, int lim3, int n){
    p+=n*lim3;
    return *p;
}
//POST TV: restituito il riferimento alla cella n della V-fetta
int main()
{
    cout<<"start"<<endl;
    int x[100];
    for(int i=0; i<100; i++)
        cin >> x[i];
    int lim1, lim2, lim3;
    cin >> lim1 >> lim2 >> lim3;
    int i=0,j=0,k=0,z=0;
    //PRE: lim1*lim2*lim3<=100 ==> l'array tridimensionale lim1*lim2*lim3 è completamente valorizzato
    //1) i!=-1 && x valorizzato con 100 elementi
    while(i!=-1){ //R 2) e1 è alias della cella j della V-fetta i && e2 è alias della cella z della V-fetta k sse i!=1
        cin >> i;
        if(i!=-1){
            cin>>j>>k>>z;
            int &e1=TV(x+i, lim1, lim2, lim3, j);
            int &e2=TV(x+k, lim1, lim2, lim3, z);
            e1=e1^e2; e2=e1^e2; e1=e1^e2; //scambio e1 e2
        }
        //3) i==1 => ho terminato le quaterne, sono stati eseguiti tanti scambi quante sono le quaterne
    }
    //POST: invertite cella j della V-fetta i con cella z della V-fetta k per ogni quaterna di numeri
    for(int s=0;s<lim1*lim2*lim3;s++)
        cout<<x[s]<<" ";
    cout<<endl<<"end"<<endl;
    return 0;
}