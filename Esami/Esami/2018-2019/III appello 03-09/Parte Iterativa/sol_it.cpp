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

//FUNZIONE ITERATIVA
void perlar(nodo*R, int x, int*T, int& nt) {
	//Creao un nuovo nodoEX
    nodoEx *a = new nodoEx(R, 0, 0);
    //Salvo il puntatore iniziale della lista da costruire
    nodoEx *inizio = a;
    coda Q = coda();
    //Metto a in testa alla coda
    Q = push_end(Q, a);
    //Esco dal ciclo quando non ho più elementi in coda, ciò significa che ho estratto tutti i nodi
    //dell'albero
    while(Q.inizio) {
    	//Se sono al nodo radice, estrailo (Serve più che altro per passare la condizione iniziale del while)
        if(!a->liv) a = pop(Q);
        //Se esiste il nodo sinistro
        if(a->info->left) {
        	//Crea un nodoEx left e mettilo in cima alla coda, il livello del nodo
        	//si ottiene sommando 1 al valore del nodo precedente
            nodoEx *left = new nodoEx(a->info->left, a->liv + 1, 0);
            Q = push_end(Q, left);
        }
        //Se esiste il nodo destro
        if(a->info->right) {
        	//Crea un nodoEx right e mettilo in cima alla coda il livello del nodo
        	//si ottiene sommando 1 al valore del nodo precedente
            nodoEx *right = new nodoEx(a->info->right, a->liv + 1, 0);
            Q = push_end(Q, right);
        }
        //Assegno ad a->next il nodo che estraggo dalla coda
        a->next = pop(Q);
        //Mi sposto al nodo successivo
        a = a->next;
    }
    //Posizione del nodo i
    int pos = 1;
    int liv = inizio->liv;
    for(int i = 0; inizio; i += 2) {
        liv = inizio->liv;
        //Se il nodo che cerco esiste
        if(inizio->info->info == x) {
        	//Assegna il livello del nodo
            T[0] = inizio->liv;
            //E la sua posizione nel livello
            T[1] = pos;
            //Incrementa il numero di nodi trovati
            nt += 1;
            //Spostati a destra di due posizioni sull'array
            T += 2;
        }
        //Spostati al prossimo elemento della lista
        inizio = inizio->next;
		//Se la lista è ancora definita
        if(inizio) {
        	//Controlla se ho cambiato livello
            if(liv != inizio->liv) pos = 0; //Quindi azzera la variabile posizione
        }
        pos += 1;
    }
}

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
