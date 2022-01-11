#include<iostream>
using namespace std;

int leggi(int*X, int dimX){
	int n=0; //inizializzo l'intero n che l'utente deve inserire, l'indice i e l'intero array

	cin>>n;	

	while(n<1 || n>dimX){	
	cin>>n;	
	}

	int i=0;

	while(i<n){
		cin>>X[i];
		i=i+1;
	}

	return n;
}

void stampa(int*X, int lim){
	int i=0;

	while(i<lim){
	cout<<X[i]<<" ";
	i++;
}

	cout<<"\n";	//alla fine stampo un newline
};

int main()
{
	int A[10];
	int nelemA=leggi(A,10);
	
	//PRE=(0<nelemA<=30) e (assumiamo che A[0..nelemA-1] contiene solo 2 valori distinti,  il valore iniziale di A  lo chiamiamo A_orig)
		
		int primo=1, secondo=nelemA-1, x=A[0];
		
		while(primo<secondo)		//R1=(primo<=secondo && sec_iniziale<=nelemA-1 (valore iniziale di secondo))
		{
			if(A[primo]!=x)
			{
				while(A[secondo]!=x && secondo>primo)	//R2=(se primo<secondo allora A[secondo]=x, A[sec_iniziale..secondo]!=x )&&(se primo<secondo allora A[0...primo-1]=x, A[secondo..sec_iniziale]!=x)	
					secondo=secondo-1;
					
					if(secondo>primo)
					{
						int z=A[primo];
						A[primo]=A[secondo];
						A[secondo]=z;
						primo=primo+1;
						secondo=secondo-1;
					}
					else
					secondo=secondo-1;
			}
			else 
			primo=primo+1;
		}
	
	stampa(A,nelemA);			//POST=A[primo...secondo-1]!=A[sec_iniziale...secondo] con primo<secondo
			
}
  
  

