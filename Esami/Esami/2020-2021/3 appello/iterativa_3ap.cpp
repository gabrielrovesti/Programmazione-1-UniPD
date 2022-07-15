#include<iostream>
using namespace std;

struct tripla{
    int inizioT, inizioP, lung;
    tripla(int a=0, int b=0, int c=0){
        inizioT=a;
        inizioP=b;
        lung=c;
    }
};

void inserisci(int* A, int dim){
    for(int i=0; i<dim; i++)
        cin >> A[i];
    cout << endl;
}

void stampa(bool *M, int rig, int col){
    int tot=rig*col;
    for(int i=0; i<tot; i++){
        for(int j=0; j<col; j++){
            cout << M[i] << " ";
            if(j!=col-1)
                i++;
        }
        cout << endl;
    }
    cout << endl;
}

void compute(int* T, int* P, int dimT, int dimP, bool* M){
    for(int j=0; j<dimP; j++){
        for(int i=0; i<dimT; i++){
            if(T[i]==P[j])
                M[i*dimP+j]=true;
            else
                M[i*dimP+j]=false;
        }
    }
}

tripla match(bool*M, int dimT, int dimP){
    tripla aux(0), maggiore(0);
    bool ok=false;
    for(int j=0; j<dimP && !ok; j++){
        for(int i=0; i<dimT && !ok; i++){
            if(M[i*dimP+j]){
                bool stop=false;
                int copia=i+1, lun=1;
                for(int x=j+1; x<dimP && !stop && copia<dimT; x++){
                    if(M[copia*dimP+x]){
                        copia++;
                        lun++;
                    }
                    else
                        stop=true;
                }
                if(lun==dimP)
                    ok=true;
                aux.inizioT=i;
                aux.inizioP=j;
                aux.lung=lun;
                if(aux.lung > maggiore.lung)
                    maggiore=aux;
            }
        }
    }
    return maggiore;
}

int main() {
    //completamento array
    int dimT=0, dimP=0;
    cout << "inserisci lunghezza Testo" << endl;
    cin >> dimT;
    cout << "inserisci lunghezza Pattern" << endl;
    cin >> dimP;
    int T[50], P[10];
    cout << "completa array Testo" << endl;
    inserisci(T,dimT);
    cout << "completa array Pattern" << endl;
    inserisci(P,dimP);

    //creazione matrice M
    bool M[dimT][dimP]={0};
    compute(T,P,dimT,dimP,M[dimP]);

    //verifica matrice M
    stampa(M[dimP],dimT,dimP);

    //tripla con lun max
    tripla val = match(M[dimP],dimT,dimP);
    cout << "inizio su T " << val.inizioT << endl;
    cout << "inizio su P " << val.inizioP << endl;
    cout << "lunghezza " << val.lung << endl;

}

//BD
