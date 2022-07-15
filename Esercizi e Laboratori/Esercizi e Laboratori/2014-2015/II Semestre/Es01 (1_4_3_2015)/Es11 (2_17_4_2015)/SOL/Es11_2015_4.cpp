
//soluzione by: Viviana A.

#include<iostream>
#include<fstream>
using namespace std;

int contaMatch(int *X, int fetta, int lim2, int lim3, int *P, int dimP, int lunghezza){
  int i=0, conta=0, inizio;
  int pezzi=lunghezza/lim3;
  int eur=lunghezza%lim3;
  if(eur)
    pezzi++;
  int lungPezzo=lim3;
  while(i<lunghezza){
    bool match=false;
    bool ok=true;
    int p=0;
    for(int j=i/lim3;j<pezzi && ok && !match;j++){
      if(eur && j==pezzi-1)
	lungPezzo=eur;
      if(p!=0)
	inizio=0;
      else
	inizio=i%lim3;
      for(int k=inizio;k<lungPezzo && ok && !match ;k++){
	  if(X[j*(lim2*lim3)+fetta*lim3+k]!=P[p])
	    ok=false;
	  else{
	    if(p==dimP-1){
	      match=true;
	      conta++;
	    }
	    else
	      p++;
	  }
	 
      }
    }
    //incremento i
    if(match)
      i=i+dimP;
    else
      i++;
    
  }
  return conta;
}

main(){
  ifstream INP("input");
  ofstream OUT("output");
  int X[400],lim1,lim2,lim3,ele,P[50],dimP;
  
  for(int i=0;i<400;i++)
    X[i]=-1;
  
  INP>>lim1>>lim2>>lim3>>ele;
  for(int i=0;i<lim1;i++)
    for(int j=0;j<lim2;j++)
      for(int k=0;k<lim3 && i*(lim2*lim3)+j*lim3+k<ele;k++)
	INP>>X[i*(lim2*lim3)+j*lim3+k];
      
  if(ele>lim1*lim2*lim3){
    int o=ele-lim1*lim2*lim3;
    int s;
    while(o>0){
      INP>>s;
      o--;
    }
  }
      
  INP>>dimP;
  for(int i=0;i<dimP;i++)
    INP>>P[i];
  
  
  int sp=ele/(lim2*lim3);
  int eus=ele%(lim2*lim3);
  int rp=ele/lim3;
  int eur=ele%lim3;
//   quante fette
  int fette;
  if(ele<lim2*lim3){
    if(eur)
      fette=rp+1;
    else
      fette=rp;
  }
  else
    fette=lim2;
//   lunghezza fetta
  int righe;
  if(eur)
    righe=rp+1;
  else
    righe=rp;
  
  int UltimaRiga=lim2+1;
  if(eus)
    UltimaRiga=eus/lim3;
  
  int lung;  
  if(eus)
    lung=lim3*(sp+1);
  else
    lung=lim3*sp;
  
  for(int i=0; i<fette; i++){
    int lunghezza=lung;
    if(i==UltimaRiga)
      lunghezza=sp*lim3+eur; 
    if(i>UltimaRiga)
      lunghezza=sp*lim3;
//       cout<<"FETTA "<<i<<"  FUNZIONE "<<lunghezza<<endl;
    int quanti=contaMatch(X,i,lim2,lim3,P,dimP,lunghezza);
    OUT<<"H-fetta "<<i<<"="<<quanti<<" match"<<endl;
  }
}
