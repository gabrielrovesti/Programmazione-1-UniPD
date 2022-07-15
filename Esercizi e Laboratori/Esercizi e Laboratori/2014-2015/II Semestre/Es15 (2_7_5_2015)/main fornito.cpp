#include<iostream>
#include<fstream>
using namespace std;

main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int T[3][4][4], dim,z;
   IN>>dim;
   int* x=**T;
   for(int i=0; i<dim;i++)
    IN>>x[i];
   stampa(x,dim,OUT);//stampa ricorsiva per righe da fare
   OUT<<endl;
   IN>>z;
   
   int ne=compatta(x,dim,z,0,0);//da fare
   stamparic(x,ne,OUT);//stampa quello che resta
   OUT<<"fine"<<endl;
   IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
}
