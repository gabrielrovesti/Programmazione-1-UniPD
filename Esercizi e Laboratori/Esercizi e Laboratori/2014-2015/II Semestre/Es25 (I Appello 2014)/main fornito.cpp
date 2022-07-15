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


nodo* build_iter(int*C, nodo*r,ifstream & INP, ofstream & OUT)
{
  bool fine=false;
  for(int i=0; !fine; i++)
  {
    int j=inizio_cam(C,i);
    
    if(j==-2)
      fine=true;
    else
    {
    add_iter(C+j, r, INP, OUT);
    
    }
  }
 return r;
}


nodo* build_ric(int*C, nodo* r, ifstream & INP, ofstream & OUT)
{
  bool fine=false;
  for(int i=0; !fine ; i++)
  {
    int j=inizio_cam(C,i);
    if(j==-2)
      fine=true;
    else
    {
    
    add_ric(C+j, r, INP, OUT);
    
   }
  }
 return r;
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
  int C[200],x;
  INP>>C[0];
 
  for(int i=1; C[i-1]!=-2; i++)
   {INP>>C[i];}
  
  nodo* X=costruz();
  nodo*r = build_ric(C,X,INP, OUT);
  stampa_l(r,OUT);
  OUT<<endl;

  r=build_ric(C,0,INP,OUT);
  stampa_l(r,OUT);
  OUT<<endl;

  X=costruz();
  r=build_iter(C,X,INP,OUT);
  stampa_l(r,OUT);
  OUT<<endl;

  r=build_iter(C,0,INP,OUT);
  stampa_l(r,OUT); 
  OUT<<endl;

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
