#include<iostream>
using namespace std;

struct nodo{int info; nodo*left,*right; nodo(int a=0, nodo*b1=0,nodo*b2=0){info=a; left=b1; right=b2;}};
struct nodoEx{nodo* info; int liv; nodoEx*next; nodoEx(nodo*a=0,int b=0, nodoEx*c=0){info=a; liv=b;next=c;}};
struct coda{nodoEx* inizio, * fine; coda(nodoEx*a=0, nodoEx*b=0) {inizio=a; fine=b;}};
//PRE=(x è una coda che gestisce una lista di nodoEx ben formata e a punta ad un nodoEx)
coda push_end(coda x, nodoEx*a)
{
  a->next=0;
  if(x.inizio)
    {
      x.fine->next=a;
      x.fine=a;
    }
  else
    x.inizio=x.fine=a;

  return x;
}
//POST=(restituisce la coda x che gestisce la lista originale con il nodoEx a aggiunto alla fine della lista) 
//PRE=(C.inizio non è 0)
nodoEx* pop(coda & C)
{
  nodoEx* x=C.inizio;
  C.inizio=C.inizio->next;
  if(C.inizio==0)
    C.fine=0;
  return x;
}
//POST=(modifica C eliminando il suo primo nodoEx e restituendolo col return )

int contanodi(nodo*r)
{
  if(!r) return 0;
  return contanodi(r->left) + contanodi(r->right)+1;
}
nodo* ins(nodo*R,int x)
{
  if(!R) return new nodo(x);
  else
    if(contanodi(R->left) <= contanodi(R->right))
      {
	R->left=ins(R->left,x);
	return R;
      }
    else
      {
	R->right=ins(R->right,x);
	return R;
      }
}

void stampa_lin(nodo*r)
{
  if(r)
    {
      cout <<'['<<r->info<<']'<<'(';
      stampa_lin(r->left);
      cout<<',';
      stampa_lin(r->right);
      cout<<')';
    }
  else
  cout<<'_';
}


// PRE=(albero(R) è un albero binario ben formato, x è definito, T contiene un numero di posizioni pari al doppio del numero deinodi di albero(R))
void perlar(nodo* R, int x ,int* T, int& nt) { 
	nodoEx* t=new nodoEx (R);
	coda C=0;
	C=push_end(C, t);
	int k=0; 
	int pos=1;
	int l=0;
	while (C.inizio) {
		if (C.inizio->info->left) {
			t=new nodoEx(C.inizio->info->left, (C.inizio->liv)+1);
			C=push_end(C, t);
		}
		if (C.inizio->info->right) {
			t=new nodoEx(C.inizio->info->right, (C.inizio->liv)+1);
			C=push_end(C, t);
		}
		// faccio la pop
		nodoEx* y=pop(C);
		if(y->liv > l){
            l=l+1;
            pos=1;
        }
		if (y->info->info==x) {
			nt=nt+1;
			T[k]=y->liv;
			T[k+1]=pos;
			k=k+2;
		}
		pos=pos+1;
	}
}
// POST=(nt è è il numero di nodi con info=x in albero(R) e T contiene il livello e la posizione di ciascuno degli nt nodi nell’ordine del percorso in larghezza)

main()
{
  cout<<"start"<<endl;
  int n, num=0,ntrova=0;
  nodo*R=0;
  cin >>n;
    while (n !=-1)
      {
      R=ins(R,n);
      num++;
      cin>>n;
      }
  stampa_lin(R);
  cout<<endl;
  
  int*T=new int[2*num];
  cin >>n;
  perlar(R,n,T, ntrova);
  if(!ntrova)
    cout<<"nessun nodo con info="<<n<<endl;
  else
    {
      cout<<n<<" compare nei seguenti nodi:"<<endl;
      for(int j=0; j<ntrova; j++)
	cout<<"Livello="<<T[2*j]<<" posizione="<< T[2*j+1]<<endl;
    }
  cout<<"end"<<endl;
}