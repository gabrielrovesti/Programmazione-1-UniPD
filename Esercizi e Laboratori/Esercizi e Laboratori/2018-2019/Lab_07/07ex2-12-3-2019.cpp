#include <iostream>
using namespace std;

int main(){
    cout<<"start"<<endl;
    int x[2][4][5];
    int n,h=0;
    cin>>n;
    int i=n;
    int strato;
    //INPUT
    while(i>=10 && h<4){//1
        for(strato=0;strato<2;strato++)//2
            for(int v=0;v<5;v++)//3
                cin>>x[strato][h][v];
        h++;
        i-=10;
    }
    if(i>0 && h<4){
        strato=0;
        while(i>=5){//4
            for(int v=0;v<5;v++)//5
                cin>>x[strato][h][v];
            strato++;
            i-=5;
        }
        for(int v=0;v<i;v++)//6
            cin>>x[strato][h][v];
    }
    //OUTPUT
    for(int iStrato=0;iStrato<2;iStrato++){//7
        for(int ih=0;ih<h;ih++){//8
            for(int v=0;v<5;v++)//9
                cout<<x[iStrato][ih][v]<<" ";
            cout<<endl;
        }
        if(iStrato==strato){
            for(int v=0;v<i;v++)//10
                cout<<x[iStrato][h][v]<<" ";
            cout<<endl;
        }else
            if(iStrato<strato){
                for(int v=0;v<5;v++)
                    cout<<x[iStrato][h][v]<<" ";
                cout<<endl;
            }
    }
    cout<<"end"<<endl;
    return 0;
}
/* CORRETTEZZA
R1: 10<=i<=n && h<4 && valorizzate h fette con n-i valori
POST1: valorizzate h fette

R2: 0<=strato<=2 && valorizzati "strato" righe della fetta h
POST2: valorizzata la fetta h

R3: 0<=v<=5 && valorizzati v valori della riga "strato" della fetta h
POST3: valorizzata la riga "strato" della fetta h

R4: 0<=i<10 && letti n-i valori da cin
POST4: valorizzata riga 0 della fetta h

R5: 0<=v<=5 && valorizzati v valori di "strato" riga della fetta h
POST5: valorizzata riga "strato" della fetta h

R6: 0<=v<=i && valorizzati v valori della riga 1 della fetta h
POST6: valorizzata riga 1 della fetta h con i restanti valori da cin <5

R7: 0<=iStrato<=2 && stampati "iStrato" strati della torta
POST7: stampati tutti gli strati

R8: 0<=ih<=h && stampati ih righe dello strato "iStrato"
POST8: stampato strato "iStrato"

R9: 0<=v<=5 && stampati v celle della riga ih dello strato "iStrato"
POST9: stampata riga ih dello strato "iStrato"

R10: 0<=v<=i && stampati v valori della fetta h della riga iStrato
POST10: stampati i restanti "i" valori*/