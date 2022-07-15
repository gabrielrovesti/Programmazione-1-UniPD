#include<iostream>
using namespace std;

// PRE p è una matrice, composta da 10 righe e 5 colonne
void stampa(int*p){
    int r=0, i=0;
    while(r<10){
        cout << p[r*5+i] << " "; // stampa per righe, con 0<=r<=10
        i++;      // vado al prossimo elemento della colonna
        if(i==5){ // indice di colonna.. 0<=i<=5
            i=0;
            r++;
            cout << "\n";
        }
    }
    cout << "\n";
}
// POST ho stampato, per righe, 0<=i<=50 elementi

// PRE p è una matrice booleana, composta da 10 righe e 5 colonne
void printb(bool*x){
    int r=0, i=0;
    while(r<10){
        cout << x[r*5+i] << " ";
        i++;
        if(i==5){
            i=0;
            r++;
            cout << "\n";
        }
    }
    cout << "\n";
}
// POST ho stampato, per righe, 0<=i<=50 elementi

void riempi(int*p1, int*p2){
    int n, ri=0, co=0;
    for(int i=0; i<50; i++){
        cin >> n;
        p1[i]=n;       // riempimento per righe
        p2[ri*5+co]=n; // riempimento per colonne
        ri++;
        if(ri==10){
            ri=0;
            co++;
        }
    }
    stampa(p1);
    stampa(p2);
}

bool cntr(int*p1, int i, int j, int*p2){
    int r=0, c=0; // indici di riga e colonna
    bool exit=false;
    while(c<5 && exit==false){
        for(int r=0; r<10; r++){
            if(p1[i*5+c]==p2[j+5*r]){
                exit=true;
            }
        }
        c++;
    }
    return exit;
}


void cross(int*p1, int*p2, bool*x){
 int i=0, j=0; // definisco gli indici di riga e colonna
 while(i<10){  // effettuo un controllo su tutte le 10 righe di p1 (e rispettive righe di p2) R: 0<=i<=10, i e' l'indice che scorre le righe di p1
    for(int j=0; j<5; j++){ //R: 0<=j<=5 j e' l'indice che scorre le colonne della matrice p2
        bool value=false;
        value=cntr(p1, i, j, p2); // controllo se ho elementi in comune con una funzione ausiliaria
        if(value==true){ // gli elementi della riga 0<=i<=10 di p1 hanno almeno un elemento in comune con la colonna 0<=j<=5 di p2
                         // x(i,j)=true
            x[i*5+j]=true; // c=indice di colonna di p2 * #elementi per colonna + i=indice di riga p1
        }
        else{ // se non ho elementi in comune, x(i,j)=false
            x[i*5+j]=false;
        }
    }
    i++; // vado alla prossima riga di p1
 }
 printb(x);   // stampo la matrice booleana
}




main()
{
  int A1[10][5],A2[10][5];
  int*p1=A1[0], *p2=A2[0];
  riempi(p1,p2);
  bool B[10][5];
  bool*x=B[0];
  cross(p1,p2,x);
}
