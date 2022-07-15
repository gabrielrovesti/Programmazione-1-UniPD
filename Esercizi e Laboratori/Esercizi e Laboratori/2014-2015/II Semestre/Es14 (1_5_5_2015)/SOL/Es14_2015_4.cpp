
//soluzione by: Nicolò D.

#include <iostream>
#include <climits>
#include <fstream>
using namespace std;
struct M {
  int lung, inizioP, inizioT;
 
  M(int _lung=0, int _inizioP=0, int _inizioT=0)
  {lung=_lung; inizioP=_inizioP; inizioT=_inizioT;}
};
 
M conta(int *T,int * P,int dimP,M _match,int i,int dimT){
  if(dimP == 0 || *T != *P || i==dimT ){
    return _match;
  }
  _match.lung++;
  return conta(T+1,P+1,dimP-1,_match,i+1,dimT);
}
 
M matching(int *T,int dimT,int * P,int dimP,int i, int inizioP, M risultato){
  if(i >= dimT){
    return risultato;
  }
  else{
        cout << i << " " << inizioP << endl;
    M data = conta(T,P,dimP,M(0,inizioP,i),i,dimT);
    if(data.lung >= risultato.lung){
      risultato = data;
    }
    return matching(T+1,dimT,P,dimP,i+1, inizioP, risultato);
  }
}
 
//Scorre T
M match(int *T,int dimT,int * P,int dimP,int inizioP){
  if(dimP > 0){
    M succ = match(T, dimT, P+1, dimP - 1, inizioP + 1);
    M risultato = matching(T, dimT, P, dimP, 0, inizioP, M(0,-1,-1));
 
    if(risultato.lung >= succ.lung){
      return risultato;
    }
    return succ;
  }
  return M(0,-1,-1);
}
 
 
main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT)
  {
   int T[200], P[20], dimT, dimP;
   IN>>dimT;
   for(int i=0; i<dimT;i++)
     IN>>T[i];
   IN>>dimP;
   for(int i=0; i<dimP;i++)
     IN>>P[i];
   M x=match(T,dimT, P, dimP, 0);// funzione ricorsiva da fare
   cout<<"[lung="<<x.lung<<" inizioP="<<x.inizioP<<" inizioT="<<x.inizioT<<']'<<endl; // e' l'occasione di ridefinire << per M
 
   IN.close(); OUT.close();
  }
  else
   cout<<"errore con i files";
 }
