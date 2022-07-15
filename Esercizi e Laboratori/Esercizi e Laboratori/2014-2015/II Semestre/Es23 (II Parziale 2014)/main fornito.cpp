#include<iostream>
#include<fstream>
using namespace std;
struct nodo{int info; nodo* left, * right; nodo(int a=0, nodo* b=0, nodo* c=0){info=a;left =b;  right=c;}};

void stampa_l(nodo *r, ofstream & OUT)
{
  if(r)
    {
      OUT<<r->info<<'(';
      stampa_l(r->left,OUT);
      OUT<<',';
      stampa_l(r->right,OUT);
      OUT<<')';
    }
  else
    OUT<< '_';
}

nodo* costruz()
{
 nodo*x2=new nodo(2);
 nodo* x3=new nodo(3);
 nodo* x4=new nodo(4);
 nodo*x1=new nodo(1,x2,x3);
 x2->right=x4;
 return x1;
}



main()
{
  try{
  ifstream INP("input");
  ofstream OUT("output");
  if(!INP) throw(0);
  if(!OUT) throw(1);
  int dim0,dim1,dim2,x;

  INP>>dim0>>dim1>>dim2;
  nodo*X=costruz();
    cout<<endl;
  int z=level(X,dim0,2,INP);// da fare
  stampa_l(X,OUT);
  OUT<<endl<<z<<endl;
  for(int i=0; i<z;i++)//serve per eliminare da input i valori non usati da level
   INP>>x;

  X=costruz();
  X=build(X,dim1,0,INP);  //da fare
  stampa_l(X,OUT);
  OUT<<endl;
  nodo*R=0;
  R=build(R,dim2,0,INP);// da fare
  stampa_l(R,OUT);
  OUT<<end;
 }
 catch(int x)
{
   switch(x)
  {
   case 0: cout<<"problemi con input"<<endl; break;
   case 1: cout<<"problemi con output"<<endl; break;
  }
}
}
