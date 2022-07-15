#include<iostream>
#include<fstream>
using namespace std;

main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int T[3][4][4], dim,z, *x=**T;
   IN>>dim;
   int count=dim;
//riempie T per strati e colonne
   for(int i=0; i<3 && count>0;i++)
    for(int  j=0; j<4&&count>0;j++)
      for(int k=0;k<4&&count>0;k++)
       {IN>>T[i][k][j];count--;}
   IN>>z;
   
   stampa(x,dim,OUT);//stampa ricorsiva per strati e per righe, considerando solo elementi definiti
   
   int ne=compattaC(x,dim,z,0,0);//da fare
   
   stampa(x,ne,OUT); //stampa dell'array dopo il compattamento
   OUT<<"fine"<<endl;
   IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
}
