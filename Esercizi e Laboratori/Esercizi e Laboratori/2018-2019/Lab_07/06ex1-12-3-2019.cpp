#include <iostream>
using namespace std;

int main(){
    cout<<"start"<<endl;
    int a[3][4][5];
    int *y=&a[0][0][0];
    for(int i=0;i<60;i++)//1
        cin>>y[i];
    char c;
    cin>>c;
    switch(c){
        case 'H':
            int h;
            cin>>h;
            for(int i=0;i<3;i++){//2
                for(int k=0;k<5;k++)//3
                    cout<<a[i][h][k]<<" ";
                cout<<endl;
            }
            break;
        case 'V':
            int v;
            cin>>v;
            for(int i=0;i<3;i++){//4
                for(int k=0;k<4;k++)//5
                    cout<<a[i][k][v]<<" ";
                cout<<endl;
            }
            break;
        default: break;
    }
    cout<<"end"<<endl;
    return 0;
}
/* CORRETTEZZA
R1: 0<=i<=60 && y[0..i-1] valorizzato
POST1: y[0..59] valorizzato

R2: 0<=i<=3 && stampate i righe della fetta h
POST2: stampata fetta h

R3: 0<=k<=5 && stampati k valori della riga i della fetta h
POST3: stampata riga i della fetta h

R4: 0<=i<=3 && stampate i righe della fetta v
POST4: stampata fetta v

R5: 0<=k<=4 && stampati k valori della riga i della fetta v
POST5: stampata riga i della fetta v

Dimostrazione ciclo 3:
1) k=0 stampato a[i][h][0..-1](insieme nullo)
2) 0<k<5 stampato a[i][h][0..k-1]
3) k>=5 => stampato a[i][h][0..4], ovvero la riga i della fetta h
*/