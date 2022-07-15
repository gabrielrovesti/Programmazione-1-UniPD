#include<iostream>
using namespace std;

int leggi(int*X, int dimX)
{
  int k,i=0;
  bool ok=false;
  while(!ok)
    {
      cout<<"dai intero k, 0 < k <"<<dimX<<endl;
      cin >> k;
      if(0<k && k<dimX)
	    ok=true;
    }
  
  while(i<k)
    {
      cin >>X[i];
      i=i+1;
    }
  return k;
}

int K(int *A, int dim)
{
	int i=0, j=0, k=0;
	
	int limite=0;
	
	//PRE=(A ha dim elementi definiti, sia A_orig=A)
	
	for(i=0; i<dim; i++){	//R1=(0<=i<=dim) && (A[0...dim-1] definito con k elementi)	
		for(j=i+1; j<dim; j++){ //R2=(i+1<=j<=dim) && (A[j]==A[i+1])	PRE=A[j..dim-1]==A[i...dim])		POST=A[k]==A[k+1] && dim-- sse A[i]==A[j]
			if(A[i]==A[j]){
				for(k=j; k<dim; k++) //R3=(j<=k<=dim)&&(A[k]==A[k+1] sse A[i]==A[j])	PRE=A[k]==A[j]==A[i])		POST=A[k+1]==A[j]
                {
                    A[k] = A[k + 1];
                }
                dim--;
                j=j-1;
			}
		}
	}
	
	limite=dim;
	return limite;
	
	//POST=(restituisce un intero n tale che A[0..n-1] è ottenuto da A_orig mantenendo per ogni valore solo 
//l’istanza più a sinistra, come descritto nell’esempio)

//Dimostrazione della correttezza:
//per il primo, la prima volta lindice i=0 e l'array A è già definito con un certo numero di elementi;
//per il secondo ciclo, l'indice chiaramente varia tra i+1 e dim e l'array di indice j equivale all'array dell'indice di appoggio k, perché entrambi vuoti
//induttivamente, il primo ciclo rimane giusto e il secondo, in forza del condizionale presente all'interno, diventerà uguale alla condizione fornita dall'invariante
//permettendo lo scambio e l'eliminazione dei duplicati
//R1 & R2--->Post
}


void stampa(int*X, int lim)
{
  int i=0;
  while(i < lim)
    {
      cout<<X[i]<<' ';
      i=i+1;
    }
  cout<<endl;
}


main()
{
  int A[30];
  int elemA=leggi(A,30);
  
  int ok=K(A, elemA);
  
  stampa(A,ok);
}
