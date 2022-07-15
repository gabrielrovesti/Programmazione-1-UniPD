/*
Esercizio a tempo #2 (vers. 1):

Devo creare due funzioni:
                          - void leggiV(int*X, int n_ele, int lim1,int lim2, int lim3)
                          - void stampaS()

La prima, leggiV, legge in input nele e li inserisce verticalmente in array a più dimensioni
La seconda, stampaS, deve stampare lo strato dato da cin per righe.

Gli array multidimensionali devono essere gestiti tramite puntatore e possono essere parzialmente riempiti (nele<lim1*lim2*lim3).


Per esempio: lim1=3, lim2=3, lim3=2 nele=12
cin >> 1 2 3 4 5 6 7 8 9 10 11 12

leggiV                           stampaS

strato 0                         per strato=0

1 10                             r0: 1 10
2 11                             r1: 2 11
3 12                             r2: 3 12

strato 1                         per strato=1
4                                r0: 4
5                                r1: 5
6                                r2: 6

strato 2
7
8
9

*/

#include<iostream>
using namespace std;

void leggiV(int*p, int nele, int lim1, int lim2, int lim3){
  int cp=nele/lim2, rest=nele%lim2, x, el=lim2*lim1, col=0, v=0, n=cp*lim2;
  while(cp){ // ciclo sulle colonne da riempire tutte, sono cp.
  // queste colonne contengono lim2 elementi, percio'
  // col è l'indice di colonna e v e' lo strato
    for(int i=0; i<lim2; i++){
      cin >> x;
      p[v*(lim2*lim3)+col+(i*lim3)]=x; // la posizione di x è data dalla colonna+riga(i*lim3)+strato(v*lim2*lim3)
      el--;
    }
    cp--;
    v++;
    if(!el){ // el == 0
      col++; // ho riempito tutta la colonna col dei lim1 strati, vado alla prossima
      el=lim2*lim1;
      v=0;
    }
  }
  if(rest){ // se ho resto
    int s=(nele/lim2)%lim1, c=col; // strato in cui ho resto !!! attenzione, cp si azzera nel ciclo precedente!
    for(int i=0; i<rest; i++){
      cin >> x;
      p[(i*lim3)+c+(s*lim2*lim3)]=x;
    }
  }
}

void stampaS(int*p, int nele, int lim1, int lim2, int lim3, int strato){
  int col=(nele/lim2)/lim1, cp=nele/lim2, rest=nele%lim2, j=0, s=(nele/lim2)%lim1;
  // col=n colonne piene per strat
  if(!col){
    if(nele<lim1*lim2 && strato==s){
        for(int i=0; i<nele-(s*lim2); i++){
          cout << "r" << i << ":";
          cout << p[(strato*lim2*lim3)+(i*lim3)] << "\n";
        }
    }
    else{
      for(int i=0; i<lim2; i++){
        cout << "r" << i << ":";
        cout << p[(strato*lim2*lim3)+(i*lim3)] << "\n";
      }
    }
  }
  else{
    while(j!=lim2){
      cout << "r" << j << ":";
      for(int i=0; i<col; i++){
        cout << p[(strato*lim2*lim3)+i+(j*lim3)] << " ";
        if(strato<s){
          cout << p[(strato*lim2*lim3)+i+(j*lim3)+1] << " ";
        }
        if(strato==s && rest){
          cout << p[(strato*lim2*lim3)+i+(j*lim3)+1];
          rest--;
        }
      }
      j++;
      cout << "\n";
    }
  }
}


int main(){

  int A[400], n_ele, lim1,lim2,lim3, strato;
  cin >> n_ele>> lim1>>lim2>>lim3>>strato;
  if(n_ele>lim1*lim2*lim3){
    n_ele=lim1*lim2*lim3;
  }
  leggiV(A,n_ele,lim1,lim2,lim3);

  stampaS(A,n_ele,lim1,lim2,lim3,strato);

}
