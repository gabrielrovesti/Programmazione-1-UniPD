
//soluzione by:  Gomez E. (Riccardo G. A.)

#include<iostream>
#include<fstream>
using namespace std;
 
 
struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};
 
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
void sc(int*C, ofstream & OUT)
{
  if(*C!=-1)
   {OUT<<*C<<' '; sc(C+1,OUT);}
  else
    OUT<<"fine cammino"<<endl;
}
 
bool leaf(nodo* n) {
  return !(n->left || n->right);
}
 
bool cerca_cam(nodo* r, int k, int y, int* C) {
  if (leaf(r)) {
    *C = -1;
    if (r->info == y) return k == 1;
    return !k;
  }
 
  if (r->info == y) {
    if (!k) return false;
    k--;
  }
 
  if (r->left && cerca_cam(r->left, k, y, C+1)) {
    *C = 0;
    return true;
  }
 
  *C = 1;
  return r->right && cerca_cam(r->right, k, y, C+1);
}
 
 
int main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int dim, k,y;
   IN>>dim;
   nodo* R=rep_ins(0,dim,IN);//data
      
   IN>>k>>y;
   int C[30];
   bool b=cerca_cam(R,k,y,C);//da fare
   if(b)
    {OUT<<"true con cammino="; sc(C,OUT); OUT<<endl;} //sc data
   else
    OUT<<"nessun cammino con "<<k<<" valori="<<y<<endl;
   IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
 }
