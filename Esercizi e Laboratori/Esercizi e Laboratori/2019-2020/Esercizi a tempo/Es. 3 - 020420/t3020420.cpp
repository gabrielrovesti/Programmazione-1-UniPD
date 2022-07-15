#include<iostream>
using namespace std;

void leggi(bool(*X)[6]){
  bool*y=*X;
  for(int i=0; i<36;i++)
  cin>>y[i];
}

void stampa_r(bool*p1, int r){
  cout<<"riga:"<<r<<'=';

  for(int i=0; i<6;i++)
  cout<<p1[(r*6)+i]<<' ';
  cout << endl;
}

void stampa(bool*p1,int r){
  for(int i=0; i<r; i++)
    stampa_r(p1,i);
}

void cntr(bool*p, bool*p1, int row, int i){
  if(i==0){
    if(p[((row+1)*6)+i]==1){
      p1[((row+1)*6)+i]=1;
    }
    if(p[((row+1)*6)+(i+1)]==1){
      p1[((row+1)*6)+(i+1)]=1;
    }
  }
  if(i==5){
    if(p[((row+1)*6)+i]==1){
      p1[((row+1)*6)+i]=1;
    }
    if(p[((row+1)*6)+(i-1)]==1){
      p1[((row+1)*6)+(i-1)]=1;
    }
  }
  if(i>0 && i<5){
    if(p[((row+1)*6)+i]==1){
      p1[((row+1)*6)+i]=1;
    }
    if(p[((row+1)*6)+(i-1)]==1){
      p1[((row+1)*6)+(i-1)]=1;
    }
    if(p[((row+1)*6)+(i+1)]==1){
      p1[((row+1)*6)+(i+1)]=1;
    }
  }
}

// PRE= (0<=r<=6) && le righe di p e p1 sono definite
void newriga(bool*p, bool*p1, int row){
  if(!row){ // se sono alla riga 0, devo copiare tutti gli elementi di p in p1
    for(int i=0; i<6; i++){
      p1[i]=p[i];
      if(p[i]==1){
        cntr(p, p1, 0, i);
      }
    }
  }
  else{
    for(int i=0; i<6; i++){
      if(p1[(row*6)+i]==1){ // controllo la riga successiva
        cntr(p, p1, row, i);
      }
    }
  }
}
// POST= calcola, nel modo descritto, la nuova riga r+1 di p1 usando la riga r+1 di p e la riga r di p1

bool tutta_false(bool*p1, int row){
  int n=0;
  for(int i=0; i<6; i++){
    if(p1[(row*6)+i]==1){
      n++;
    }
  }
  if(!n){ // n==0
    return true;
  }
  return false;
}

int main(){

  bool B[6][6],B1[6][6], exit=false;

  leggi(B);
  bool*p=B[0], *p1=B1[0];
  for(int i=0; i<36; i++){
    p1[i]=0;
  }
  int row;
  for(int i=0; i<6 && exit==false; i++){
    row=i;
    newriga(p, p1, i);
    exit=tutta_false(p1, row);
  }

  stampa(p1,row+1);

  if(exit==true)
    cout<< "non c'e' cammino"<<endl;
  else
  cout<<"c'e' cammmino"<<endl;

}
