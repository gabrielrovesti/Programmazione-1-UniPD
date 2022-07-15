#include <iostream>
using namespace std;
//SOLUZIONE COMPITINO 2018
int main()
{
    int n;
    cin >>n;
    if(n<3)
        cout<<"Altezza non valida";
    else
    {//Costruisco l'albero
        int tot=0,i=0,npti_est=n-2,npti_int=0;
        while(i<n)  //R=(0<=i<=n)&&(stampate i righe)
        //1) i=0 && stampate 0 righe, vale r
        {
            int i2=0;
            if(i==n-1)
                npti_est=n-2;
            while(i2<npti_est)//stampo la prima serie di punti esterni
            {
                cout<<".";
                i2++;
            }
            cout<<"x";
            if(i>0 && i!=(n-1))             //2) stampata una riga in più
            {
                i2=0;
                while(i2<npti_int)
                {
                    cout<<".";
                    i2++;
                }   
                cout<<"x";
                npti_int+=2;
            }
            else
                npti_int++;
            i2=0;
            while(i2<npti_est)
            {
                cout<<".";
                i2++;
            }
            if(i<n-2)
                npti_est--;
            i++;
            cout<<endl;
        }
        //3)R&&(i==n)==>POST
    }
    return 0;
}