
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
ifstream IN("input.txt");
ofstream OUT("output");
int X[2][4][5];
if ( IN && OUT)
{
int n_el, idx_el=1;
IN>>n_el;
    for( int i=0; i<2; i++){
        for(int j=0; j<4; j++){
            for(int z=0; z<5; z++){
                while(idx_el<n_el)
                {
                    IN>> X[i][j][z];
                    idx_el++;
                }
            }
        }
    }
    char ch;
    int x;
    IN>> ch;
    cout<<ch;
    if(ch=='H'){ IN>>x;
        for(int i=0;i<2;i++){
            for(int z=0;z<5;z++){
                while(idx_el<n_el){
                OUT<<X[i][x][z]<<" ";
                idx_el++;
                }
            }
        OUT<<"  "<<endl;
        }
    }
        if(ch=='V'){
        int y;
        IN>>y;
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<4;j++)
                {
                OUT<<X[i][j][y]<<" ";
                }
                OUT<<"  "<<endl;
            }
        }
    }

    else{
    cout<<"errore con i files";
    IN.close(); OUT.close();
    }



/*
Questo esercizio è una modifica dell'esercizio 1 di questa stessa settimana. La 
differenza rispetto all'esercizio 1 è che ora il programma deve leggere da "input" un 
intero n_el (numero_elementi) tale che 0<n_el<=40, dopo di che legge n_el interi in 
A per strato (come per l'esercizio 1). In generale quindi dopo questa lettura A non 
sarà completamente definito. Dopo questa lettura, l'esercizio continua come 
nell'esercizio 1: si deve leggere una coppia (carattere, intero) che individua una fetta 
e poi stampare la fetta richiesta avendo cura di stampare solo gli elementi definiti. Si 
deve fare attenzione al fatto che in questo esercizio è possibile che la fetta richiesta 
possa non contenere alcun elemento definito, nel qual caso il programma dovrà 
stampare su "output" la frase: "V/H fetta x/y vuota".

La pre- e post- condizione da, rispettivamente, assumere e rispettare sono le 
seguenti:
PRE=("input" contiene un intero n_el che soddisfa la condizione 0<n_el<=40, seguito 
da n_el interi, seguiti a loro volta o dalla coppia "H" x o dalla coppia 'V' y dove x 
sarà tra 0 e 3 e y tra 0 e 4)
POST=("output" deve contenere gli elementi definiti della fetta specificata dalla 
coppia letta e nel caso la fetta non abbia elementi definiti, deve scrivere la frase 
spiegata prima)
*/


int& magiche_fette(int (*A)[4][5], int i, int n_el)
if(f == 'H'){
    return A[i%5][i][i/5];
}
else{
    return A[i%4][i/4][i];
}

int main(){

    //assumiamo ci sia le lettura delle magiche fette

    int n_el;
    cin >> nel;
    char f;
    cin >> char;
    int x; cin >> x;
    int y; cin >> y;

    int r_com=n_el%lim1*lim3;
    int c_com=n_el%lim1*lim2;
    if(f == 'V'){
        for(int i=0; i<v_com && i<_nel; i++){
            cout << magiche_fette(A, i, n_el, f, x)
        }
    }
    else{
        for(int i=0; i<r_com && i<_nel; i++){
            cout << magiche_fette(A, i, n_el, f, y);
        }
    }
}
