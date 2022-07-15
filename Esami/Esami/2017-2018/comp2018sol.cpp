#include <iostream>
using namespace std;

int main(){
    //PRE: cin contiene un valore n contenente l'altezza
    int n;
    cout<<"Inserisci altezza albero"<<endl;
    cin>>n;
    if(n<3)
        cout<<"Altezza non valida"<<endl;
    else{
        int riga=n*2-3;
        int alb=1, punti, i;
        while(alb<=riga){ //R: 1<=alb<=riga && (stampate alb/2 righe)
                        //1) alb=1 e stampate 0 righe (0.5 arrotondato per difetto), vale R
                        //2) il ciclo stampa 1 riga per iterazione, all'ultima ne stampa 2
            i=0;
            punti=(riga-alb)/2;
            while(i<punti){
                cout<<".";
                i++;
            }
            cout<<"x";
            if(alb>1){
                int punti_alb=alb-2;
                i=0;
                while(i<punti_alb){
                    cout<<".";
                    i++;
                }
                cout<<"x";
            }
            i=0;
            while(i<punti){
                cout<<".";
                i++;
            }
            cout<<endl;
            alb+=2;
            //ULTIMA RIGA
            if(alb>riga){
                punti=(riga-1)/2;
                i=0;
                while(i<punti){
                    cout<<".";
                    i++;
                }
                cout<<"x";
                i=0;
                while(i<punti){
                    cout<<".";
                    i++;
                }
                cout<<endl;
            }
        }
        //R && alb>riga -> POST
    }
    return 0;
    //POST: stampato albero di altezza n se n>=3
}