#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo* c=0){info=a; left=b; right=c;}};
struct punt{nodo* t; punt* next; punt(nodo*a=0, punt*b =0){t=a; next=b;}};
struct FIFO{punt* primo, *fine; FIFO(punt* a=0, punt*b=0){primo=a; fine=b;}};
nodo* f2(FIFO x, int y, ofstream & OUT);
FIFO togli_primo(FIFO x);
FIFO metti_fondo(FIFO x, nodo*a);

void stampa_l(nodo *r)
{
  if(r)
    {
      cout<<r->info<<'(';
      stampa_l(r->left);
      cout<<',';
      stampa_l(r->right);
      cout<<')';
    }
  else
    cout<< '_';
}
int conta_n(nodo*r)
{
   if(!r) return 0;
     else
    return conta_n(r->left)+conta_n(r->right)+1;
}

nodo* insert(nodo*r, int y)
{
  if(!r) return new nodo(y);
   
  if(conta_n(r->left)<=conta_n(r->right))
    r->left=insert(r->left,y);
   else   
    r->right=insert(r->right,y); 
  return r;
}

nodo* rep_ins(nodo*r, int dim, ifstream & INP)
{
  if(dim)
   {
    int z;
    INP>>z;
    nodo*x=insert(r,z);
    return rep_ins(x,dim-1,INP);
   }
  return r;
}



main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int dim,y;
   IN>>dim;
   nodo* R=rep_ins(0,dim,IN);//data
   
   IN>>y;
   FIFO x=f1(R); //da fare
   nodo* a=f2(x,y,OUT); //da fare
   if(a)
   OUT<<"trovato"<<a->info<<endl;
   else
   OUT<<"non trovato"<<endl;
   
   IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
 }


