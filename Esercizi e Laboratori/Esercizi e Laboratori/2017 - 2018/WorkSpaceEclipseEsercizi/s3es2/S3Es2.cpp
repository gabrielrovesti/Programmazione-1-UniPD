
/*

 */
#include <iostream>
#include <iomanip>
using namespace std;

int main(){


	cout<<"start"<<endl;
	int A[3][4][5];
	int *p=&A[0][0][0];// puntatore del tipo di A

	int nElementi;
	cin>>nElementi;


	for(int i=0; i<nElementi; i=i+1)
		// R: 0<i<=nElementi && inseriti primi i elementi.
		cin>>p[i];
	char c;
	int f;
	cin >> c >> f;

	if(c=='H')
	{
		//stampa H fetta



		//Controllo che ci sia almeno un elemento nella fetta-H scelto dall'utente.
		if(nElementi>=20 || nElementi-(f*5)>=1){
            p+= f*5;

			for(int i=0; i<3 && (nElementi-20*i)-(f*5)>=1;i++){


				for(int j=0;j<5 && j<(nElementi-20*i)-(f*5);j++){
					cout<<*p<<" ";
                   p++; // itero gli elementi sulla riga

				}
				cout<<endl;

				p+= (3*5);// mi muovo nello strato successivo
			}




		}else{
			cout<<"fetta richiesta vuota"<<endl;
		}


	}
	else
	{
		//stampa V fetta

//		if(nElement)
		if(nElementi>=5 || f<=nElementi-1){
			int elementi;
			if(nElementi%5>=f)
				elementi=nElementi/5+1;
			else{
				elementi=nElementi/5;
			}
			p+=f;

			for(int j=0;j<elementi;j++){
					cout<<*p<< " ";
					p+=5;
				if(j%4==0)
					cout<<endl;
			}

		}else{
			cout<<"fetta richiesta vuota"<<endl;
		}
	}
	cout<<"end"<<endl;
}

