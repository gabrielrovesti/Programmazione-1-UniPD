
//soluzione by: Andrey P.

#include <iostream>
#include <fstream>
void match(int *X  ,
           int* P  ,
           int dim ,
           int dimP,
           int i   ,
           int c_m ,
           std::ofstream& OUT);
int main() {
  try {
    std::ifstream INP("input");
    std::ofstream OUT("output");
    if(!INP) throw(0);
    if(!OUT) throw(1);
    int X[400] ={0}, P[20] = {0};
    int n_el, dimP;
    INP >> n_el;
    for(int i =0; i < n_el; i++)
      INP >> X[i];
    INP >> dimP;
    for(int i =0; i < dimP; i++)
      INP >> P[i];
    match(X, P, n_el, dimP, 0, 0,  OUT);
    OUT<< "fine" << std::endl;
  } catch (int x) {
    switch(x) {
    case 0:
      std::cout << " problemi di input " << std::endl;
      break;
    case 1:
      std::cout << " problemi di output " << std::endl;
      break;
    }
  }
}
 
bool M1(int* X  ,
        int* P  ,
        int dim ,
        int dimP,
        int i   ) {
  if(!dimP) return true;
  if(i == dim) return false;
  return (X[i] == *P)? M1(X,P+1,dim,dimP -1,i+1): false;
  }
 
void match(int *X  ,
           int* P  ,
           int dim ,
           int dimP,
           int i   ,
           int c_m ,
           std::ofstream& OUT) {
  /*
    Pre: dim >= 0, dimP >= 0, X[0..dim-1] && P[0..dimP-1]
         sono def., i >= 0, c_m >= 0  
   
    Post: trova tutti i match di P[0..dimP-1] in X[0..dim-1]
          ed esegue le corrispondenti stampe dove il numero dei match
          parte da c_m, poi c_m +1, ecc
   */
 
  if(!dim||!dimP) return;
  if(i > dim - dimP) return;
  bool b = M1(X,P,dim,dimP,i);
  if(b) {
    c_m+=1;
    OUT << " match n." << c_m << " a partire dalla posizione " << i;
    OUT << std::endl;
  }
  match(X, P, dim, dimP, i+1, c_m, OUT);
}
