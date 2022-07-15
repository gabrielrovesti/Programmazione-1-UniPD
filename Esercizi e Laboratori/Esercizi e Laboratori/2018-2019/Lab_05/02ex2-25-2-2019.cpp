#include <iostream>
using namespace std;

int main(){
    //PRE=(cin contiene n (0<n<=100) seguito da n interi)
    cout<<"start"<<endl;
    int n;
    cin>>n;
    int array[100];
    for(int i=0;i<n;i++)//R1: 0<=i<n && valorizzato l'array fino alla cella i-1
        cin>>array[i];
    //POST 1: array e' valorizzato con i primi n valori presi da cin
    int good=0;
    //PRE 2: array[0..n-1] contiene valori possibilmente alcuni doppi
    for(int i=0;i<n;i++){   //R2: 0<=i<n && array[0..good-1] non contiene doppi && controllati valori array[0..i-1]
        bool doppio=false;
        //PRE 3: array[0..good-1] non contiene doppi
        for(int k=0;k<good && !doppio;k++)  //R3: 0<=k<good && doppio sse array[i] è contenuto in array[0..k-1]
            if(array[k]==array[i])
                doppio=true;
        //POST 3: doppio sse array[i] è contenuto in array[0..good-1]
        if(!doppio){
            array[good]=array[i];
            good++;
        } 
    }
    //POST 2: array[0..good-1] non contiene valori doppi
    cout<<"m="<<good<<endl;
    cout<<"A=";
    for(int i=0;i<good;i++)
        cout<<array[i]<<" ";
    cout<<endl;
    cout<<"end"<<endl;
    return 0;
}
/*DIMOSTRAZIONE CORRETTEZZA
Ciclo 3:
1)k=0 doppio=false, array[i] non è contenuto nell'insieme array[0..k-1] (insieme nullo) R3 vero rispetto al primo passo
2)0<k<good doppio sse array[i] è contenuto in array[0..k-1]                             R3 vero rispetto ad ogni iterazione intermedia
3)k>=good || doppio                                                                     R3 && (k>=good || doppio) => POST
    a)doppio sse array[i] è contenuto in array[0..good-1]
    b)k=good sse array[i] non è contenuto in array[0..good-1]

Ciclo 2:
1)good=0 i=0, array[0..good-1] non contiene doppi (insieme nullo)
2)0<i<n && 0<good<=i && array[0..good-1] non contiene valori doppi && scansionato array[0..i-1]
3)i>=n && array[0..good-1] non contiene doppi*/