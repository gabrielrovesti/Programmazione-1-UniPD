#include<iostream>
using namespace std;


struct nodo{
  int info;
  nodo* left, *right;
  nodo(int a=0, nodo*c=0, nodo*d=0){
    info=a;
    left=c;
    right=d;
  }
};

struct nodoP{
  nodo* info;
  int prof;
  nodoP*next;
  nodoP(nodo*a=0, int b=0, nodoP* c=0){
    info=a; // punta al nodo di match
    prof=b; // profondita'
    next=c; // prossimo nodoP
  }
};

void build_BST(nodo*&r, int x){ // funzione costruzione albero BST
  if(!r)
    r=new nodo(x);
  else {
    nodo*q=r;
    bool continua=true;
    while (r && continua){
    if(r->info >=x)
      if(r->left)
        r=r->left;
      else {
        r->left=new nodo(x);
        continua=false;
      }
      else
        if(r->right)
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
    cout <<'['<<r->info<<']'<<'(';
    stampa_lin(r->left);
    cout<<',';
    stampa_lin(r->right);
    cout<<')';
  } else cout<<'_';
}

//PRE=(a e b sono liste ben formate, quindi anche 0)
nodoP* conc(nodoP*a, nodoP*b){
  if(!a) return b;
  a->next=conc(a->next,b);
  return a;
}
//POST=(restituisce col return la lista composta  da a seguita da b)

void stampa(nodoP*L){
  if(L){
    cout<<"nodo con info="<<L->info->info<<" profondità="<< L->prof<<endl;
    stampa(L->next);
  }
}

nodoP*match_aux(nodo*r, int h, int*p){
  nodoP*b=0;
  if(!r){
    return 0;
  }
  if(*p==r->info){ // se ho match
    return new nodoP(r, h);
  }
  if(*p<r->info){
    if(r->left){
      return match_aux(r->left, h+1, p);
    }
  }
  if(*p>r->info){
    if(r->right){
      return match_aux(r->right, h+1, p);
    }
  }
  return b;
}

// visita prefissa (radice, sinistra, destra)

// PRE=(albero(R) è benformato, profondita>=0,  dimP>=0 e P ha dimP elementi)
nodoP*match(nodo*r, int h, int*&p, int&dimP){ // in val ho il numero di elementi di p
  nodoP*a=0;
  if(!r) return 0;
  int n=0;
  if(dimP){
    nodoP*b=match_aux(r, h, p); // mi ritorna un nodo
    if(b){
        a=conc(a,b);
    }
    if(!b){
      return a;
    }
    p=p+1;
    dimP-=1;
    a->next=match(r, h, p, dimP);
  }
  return a;
}

/*POST=(restituisce una lista di nodoP che corrisponde al massimo match di P
       nei nodi di R esaminati in ordine prefisso, la lista, P e dimP sonocome descrittiprima)
 */

int main(){
  int x, dimP;
  cin>>x;
  nodo*R=0;
  while(x !=-1){
    build_BST(R,x);
    cin>>x;
  }
  cout<<"start"<<endl;
  stampa_lin(R);
  cin >> dimP;
  int*P=new int[dimP];
  for(int i=0; i<dimP; i++)
    cin>>P[i];
  int vdimP=dimP;
  nodoP*L=match(R,0,P,dimP);
  if(dimP<vdimP){
    stampa(L);
    if(dimP){
    cout<<"Resta da matchare:";
    for(int j=0; j<dimP;j++)
       cout<<P[j]<<' ';
    cout<<endl;
    }
  }
  else
     cout<<"nessun match"<<endl;
  cout<<"end"<<endl;
}
