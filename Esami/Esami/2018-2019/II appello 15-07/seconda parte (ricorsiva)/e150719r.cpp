#include<iostream>
using namespace std;

struct nodo {
  int info, num;
  nodo* left,*right;
  nodo(int a=0,int b=1, nodo*c=0, nodo*d=0){
    info=a;
    num=b;
    left=c;
    right=d;
  }
};

void build_BST(nodo*&r, int x){
  if(!r)
    r=new nodo(x);
  else {
    nodo*q=r;
    bool continua=true;
    while (r && continua){
  	  r->num=r->num+1;
  	  if(r->info >=x)
  	    if(r->left)
  	      r=r->left;
        else {
          r->left=new nodo(x);
          continua=false;
        }
      else if(r->right)
  	   r=r->right;
      else {
        r->right=new nodo(x);
        continua=false;
      }
    }
    r=q;
  }
}

void stampa_lin(nodo*r){
  if(r){
    cout <<'['<<r->info<<','<<r->num<<']'<<'(';
    stampa_lin(r->left);
    cout<<',';
    stampa_lin(r->right);
    cout<<')';
  }
  else
  cout<<'_';
}

// PRE = albero(p) e' ben formato
nodo*trova(nodo*p, int n){
  if(p->num<n){ // se non ho abbastanza elementi,
    return 0;   // termino
  }
  if(p->num>=n){
    if(p->left){ // se ho elementi nel sottoalbero sx
      if(p->left->num>=n){
        return trova(p->left, n); // chiamata ricorsiva sul sottoalbero sx
      }
      if(p->left->num+1==n){ // controllo la radice
        return p;
      }
      if(p->right){ // se ho elementi nel sottoalbero dx
        return trova(p->right, n-(p->left->num)-1); // chiamata ricorsiva sul sottoalbero dx con n aggiornato
      }
    }
    // controllo la radice
    if(n==1){   // ho trovato n
      return p; // ritorno il puntatore a quel nodo
    }
    if(p->right){
      return trova(p->right, n-1);
    }
  }
  return 0;
}
/** POST = (se albero(p) contiene almeno n nodi, restituisce il puntatore al nodo numero n
 *          nell’ordinamento determinato dalla visita infissa, altrimenti restituisce 0)
 *
 */
int main(){
  cout<<"start"<<endl;
  int n;
  nodo*R=0;
  cin >>n;
  while (n !=-1){
    build_BST(R,n);
    cin>>n;
  }
  stampa_lin(R);
  cout<<endl;
  cin >>n;
  while(n!=-1){
    nodo*x=trova(R,n);
    if(x)
      cout<<"nodo n."<<n<<" info= "<<x->info<<endl;
    else
      cout<<"nodo n."<<n<<" non c'è"<<endl;
    cin>>n;
  }
  cout<<"end"<<endl;
}
