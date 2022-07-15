#include <iostream>
using namespace std;
//PRE: S[0..lim2][0..lim3] è valorizzato correttamente
void stampaS(int* S, int lim2, int lim3){
    for(int r=0;r<lim2;r++){ //R1: 0<=r<=lim2 && stampate r righe dello strato
        cout<<"r"<<r<<":";
        for(int c=0;c<lim3;c++) //R2: 0<=c<=lim3 && stampati c elementi della riga r
            cout<<*(S+r*lim3+c)<<" ";
        //POST: stampata riga r
        cout<<endl;
    }
}
//POST: stampato S[0..lim2][0..lim3]
/*Dimostrazione correttezza funzione stampaS
Ciclo 1 (esterno):
1) r=0 => stampate 0 righe, ovvero nessun elemento
2) 0<r<lim2 && stampate r righe dello strato
3) r>=lim2 => stampate lim2 righe dello strato
Ciclo 2 (interno):
1) c=0 => stampati 0 elementi della riga r
2) 0<c<lim3 && stampati c elementi della riga r
3) c>=lim3 => stampati lim3 elementi della riga r, ovvero stampata riga r*/
int main(){
    cout<<"start"<<endl;
    int x[400], n_ele;
    cin>>n_ele;
    for(int i=0;i<n_ele;i++)
        cin>>x[i];
    int lim1,lim2,lim3;
    cin>>lim1>>lim2>>lim3; //assumiamo lim1*lim2*lim3<=400
    int s_comp=n_ele/(lim2*lim3);
    int resto=n_ele%(lim2*lim3);
    if(s_comp>=lim1){
        s_comp=lim1;
        resto=0;
    }
    for(int i=0;i<s_comp;i++){
        cout<<"strato"<<i<<endl;
        stampaS(x+i*lim2*lim3, lim2, lim3);
        cout<<endl;
    }
    if(resto>0){
        int r_comp=resto/lim3;
        cout<<"strato"<<s_comp<<endl;
        stampaS(x+s_comp*lim2*lim3, r_comp, lim3);
        int rr=resto%lim3;
        if(rr>0){
            cout<<"r"<<r_comp<<":";
            for(int i=0;i<rr;i++)
                cout<<*(x+s_comp*lim2*lim3+r_comp*lim3+i)<<" ";
            cout<<endl;
        }
    }
    cout<<"end"<<endl;
    return 0;
}