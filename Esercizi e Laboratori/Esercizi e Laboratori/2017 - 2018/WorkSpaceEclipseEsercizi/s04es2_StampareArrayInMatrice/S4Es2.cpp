#include<iostream>
using namespace std;

void stampaS(int p[], int nElementi,int numeroStrato,int numeroRighe, int numeroColonne);

int main()
{
	int nElementi, lim1,lim2, lim3, X[400];
	cin>>nElementi;
	for(int i=0; i<nElementi; i=i+1)
		cin>>X[i];
	cin>>lim1>>lim2>>lim3;


	cout<<"start"<<endl;


	stampaS(X,nElementi,lim1,lim2,lim3);

	cout<<"end"<<endl;
}
 void stampaS(int p[], int nElementi,int numeroStrato,int numeroRighe, int numeroColonne){

	 int numeroElementoStampato=0;
	 for(int i=0; i<numeroStrato &&  numeroElementoStampato <nElementi; i++){
		 cout<<"strato"<<i<<endl;

		 for(int j=0; j<numeroRighe &&  numeroElementoStampato <nElementi; j++){
			 cout<<"r"<<j<<":"<<endl;
			 for(int k=0; k< numeroColonne && numeroElementoStampato <nElementi; k++,numeroElementoStampato++){
				 cout<<p[numeroElementoStampato]<<" ";

			 }
			 cout<<endl;
		 }

	 }

}
