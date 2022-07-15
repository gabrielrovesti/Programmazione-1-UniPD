#include<iostream>
#include<climits>
#include<fstream>
using namespace std;
struct M {int lung, inizioP, inizioT; M(int a=0, int b=0, int c=0){lung=a; inizioP=b; inizioT=c;}};
main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int T[200], P[20], dim, dimP;
   IN>>dim;
   for(int i=0; i<dim;i++)
     IN>>T[i];
   IN>>dimP;
   for(int i=0; i<dimP;i++)
     IN>>P[i];
   M x=match(T,dim, P, dimP, 0);// funzione ricorsiva da fare
   OUT<<"[lung="<<x.lung<<" inizioP="<<x.inizioP<<" inizioT="<<x.inizioT<<']'<<endl; // e' l'occasione di ridefinire << per M
    
   IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
 }
