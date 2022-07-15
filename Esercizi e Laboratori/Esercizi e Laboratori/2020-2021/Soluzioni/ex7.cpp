#include<iostream>
using namespace std;
void leggi(int*X, int k)
{
  int i=0;
  while(i<k)
    {
      cin >>X[i];
      i=i+1;
    }
}

void calcB(int (*X)[8], bool (*Y)[8], int righe)
{
    int i=0, j=0, r=0, c=0;
    bool trovato=true;
    
    for(i=0; i<righe; i++)	//ciclo sulle righe		//R1=(0<=i<=righe) && A[0...i-1]
	{	
    	for(j=0; j<8; j++)	//ciclo sulle colonne	//R1=(0<=i<=8) && A[0...j-1]
		{	
    		c=0;
    		trovato=true;
    		while(c<8 && trovato==true)	//ciclo per controllare che tra tutte le colonne abbia trovato un elemento
			{								//R3=(0<=c<=8) && (trovato==true sse tutti i valori tra A[i][0...c-1]==A[0...righe-1]
    			r=0;
    			trovato=false;
    			while(r<7 && trovato==false)		//R4=(0<=c<=7) && (trovato==true sse tutti i valori tra A[i][c]==A[r][j]
				{
    				if(X[i][c]==X[r][j])
					{
    					trovato=true;
					}
    				r=r+1;
				}
				c=c+1;
			}
			if(trovato==true){
				Y[i][j]=true;
			}
			else{
				Y[i][j]=false;
			}
		}
	}
}

void stampaMat(bool (*X)[8], int righe)
{
  for(int i=0; i<righe; i++)
    {
      for(int j=0; j<8; j++){
      	cout<<X[i][j]<<' ';
	  }
	  	cout << endl;
    }
}


int main()
{
  int A[7][8];
  bool B[7][8];
  
  leggi(*A,56); //lo leggiamo come se avesse 1 dimensione
  calcB(A, B, 7);
  stampaMat(B,7);
  
