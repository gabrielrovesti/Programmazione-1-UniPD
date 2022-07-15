#include<iostream>
using namespace std;

void leggi(int* X, int & nelem)
{
    bool ok=false;
    while(!ok)
    {
        cin >>nelem;
        if(nelem>0 && nelem <=49)
        ok=true;
    }
    
  for(int i=0; i < nelem; i++)
    cin >> X[i];
}

int lenr(int k, int row){
	int comp_r=k/7;
	int resto=k%7;
	
	if(row < comp_r){
		return 7;
	}
		return resto;
	
}

int lenc(int k, int col){
	int num_r=k/7;
	
	if(col>= k%7){
		return num_r;
	}
	else{
		return num_r+1;
	}
}

bool in(int (*A)[7], int row, int col, int k){
	bool trovato=true;
	for(int i=0; i < lenr(k, row) && trovato; i++){
		trovato=false;
		for(int j=0; j < lenc(k, col) && !trovato; j++){
			if(A[row][i]==A[j][col]){
				trovato=true;
			}
		}
	}
	
	return trovato;
}

void stampa(bool (*B)[7], int nelem)
{
  for(int i=0; i<7; i++)
    {
      for(int j=0;j<7; j++)
		cout<<B[i][j]<<' ';
      	cout<<endl;
    }
    
}


int main()
{
  	int A[7][7], nelem;
  	bool B[7][7];
  	leggi(*A,nelem);
 
  	bool defined=true;
  	for(int i=0; i<7 && defined; i++){
  		for(int j=0; j<7 && defined; j++){
  				if(lenr(nelem, i) && lenc(nelem, j)){
  					B[i][j]=in(A, i, j, nelem);
			  	}
			  	else{
			  		defined=false;
				}
		  }
  	}

  	stampa(B,nelem);
  
  	return 0;
}
