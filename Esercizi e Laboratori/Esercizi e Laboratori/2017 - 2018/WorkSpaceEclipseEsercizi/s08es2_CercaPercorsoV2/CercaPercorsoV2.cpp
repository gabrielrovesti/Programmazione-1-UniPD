#include<iostream>
using namespace std;

bool partenza(bool*, int, int, int*);
bool trova(bool* , int , int , int , int *, int);
void stampa(int *, int, int);
void stampaRisposta(int i, bool b){
    if(b)
    cout<<i<<" "<<"T"<<endl;
    else
    cout<<i<<" "<<"F"<<endl;
}
int main()
{
	  int m,P[50];
	  cin>>m;
	  bool N[400];
	  for(int i=0; i<m*m; i++)
	          cin>>N[i];
	  bool x=partenza(N,m,0,P);
	  cout<<"start"<<endl;
	  if(x)
	    {
	        cout<<"esiste un cammino e quello più a sinistra e’:"<<endl;
	        stampa(P,m,0);
	        cout<<endl;

	    }
	  else
	    cout<<"il cammino non esiste"<<endl;
	  cout<<"end"<<endl;
}



void stampa(int *P, int m, int index){
	if(index<m){
		cout<<"("<<index<<","<< P[index]<<") ";
		stampa(P,m, index+1);

	}
}

bool partenza(bool* N, int m, int j, int* P){


	if(j==m ) return false;
	if(trova(N,m,0,j, P, 1)){
		P[0]= j;
		return true;
	}
	else
		return partenza (N+1,m,j+1,P);



}
bool trova(bool* N, int m, int j, int i, int* P, int arrayIndex) {

	if(! *N) return false;
	if(j == m-1 && *N ) return true;




	bool risposta=false;

	if(*(N+m-1) && i-1 >0 ){
		risposta= risposta || trova(N+m-1,m,j+1,i-1, P,arrayIndex+1);
		    stampaRisposta(arrayIndex, risposta);

		if(risposta){
			P[arrayIndex]=i-1;
			cout<<"got it"<<endl;
		}
	}

	if(*(N+m) && !risposta){
		risposta= risposta || trova(N+m,m,j+1,i,P,arrayIndex+1);
		if(risposta){
			P[arrayIndex]=i;
		}
	}


	if(*(N+m+1) && ( i+1 < m ) && (!risposta)){
		risposta= risposta || trova (N+m+1,m,j+1,i+1, P, arrayIndex+1);

		if(risposta){

			cout<<"got it 2"<<endl;
			P[arrayIndex]=i+1;
		}
	}

	return risposta;

}


