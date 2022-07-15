#include <iostream>
using namespace std;

int main(){
    cout<<"start"<<endl;
    int a1[10][5];
    int a2[10][5];
    int *y=&a1[0][0];
    //valorizzo a1 per righe
    for(int i=0;i<50;i++)//R1
        cin>>y[i];
    //valorizzo a2 per colonne
    int count = 0;
    for(int col=0;col<5;col++)//R2
        for(int row=0;row<10;row++){//R3
            a2[row][col]=y[count];
            count++;
        }
    //stampo a1
    for(int row=0;row<10;row++){//R4
        for(int col=0;col<5;col++)//R5
            cout<<a1[row][col]<<" ";
        cout<<endl;
    }
    //stampo a2
    for(int row=0;row<10;row++){//R6
        for(int col=0;col<5;col++)//R7
            cout<<a2[row][col]<<" ";
        cout<<endl;
    }

    bool b[10][10];
    for(int i=0;i<10;i++)//R8
        for(int j=0;j<10;j++){//R9
            bool trovato=false;
            for(int col1=0;col1<5 && !trovato;col1++)//R10
                for(int col2=0;col2<5 && !trovato;col2++)//R11
                    if(a2[i][col1]==a2[j][col2])
                        trovato=true;
            if(trovato)
                b[i][j]=false;
            else
                b[i][j]=true;
            
        }
    cout<<endl;
    for(int row=0;row<10;row++){//R12
        for(int col=0;col<10;col++)//R13
            cout<<b[row][col]<<" ";
        cout<<endl;
    }
    cout<<"end"<<endl;
    return 0;
}
/*INVARIANTI
R1: 0<=i<=50 && letti i valori da cin && y[0..i] valorizzati
R2: 0<=col<=5 && a2[0..10][0..col] valorizzati
R3: 0<=row<=10 && a2[0..row][col] valorizzati
R4: 0<=row<=10 && stampate row righe di a1
R5: 0<=col<=5 && stampate col celle di a1
R6: =R4 di a2
R7: =R5 di a2
R8: 0<=i<=10 && b[i-1][0..10] sse a2[i-1][0..5]!=a2[0..10][0..5]
R9: 0<=j<=10 && b[i][j] sse a2[i][0..5]!=a2[j][0..5]
R10: 0<=col1<=5 && a2[i][0..col1-1]!=a2[j][0..5]
R11: 0<=col2<=5 && a2[i][col1]!=a2[j][col2-1]
R12: 0<=row<=10 && stampate row righe di b
R13: 0<=col<=10 && stampate col celle di b*/