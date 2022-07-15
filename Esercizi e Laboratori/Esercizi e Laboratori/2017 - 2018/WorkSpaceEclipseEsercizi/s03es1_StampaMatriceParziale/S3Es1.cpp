#include <iostream>
using namespace std;


//Pre: il cin contiene 60 numeri, una lettera e
//un altro numero che se lettera e' uguale a H allora 0<numero<3
//e se lettera e' uguale a V allora 0<numero<4
int main(){

	cout<<"start"<<endl;

	int torta[3][4][5],numeroFetta;
	char scelta;
	int i,j,k;

	//Pre: i=0 & j=0 & k=0 & cin contiene 60 numeri.
	for( i=0; i<3; i++){
		/*
		 * 0<i<=3
		 * inserito lo strato numero i della torta.
		 */
		for( j=0; j<4; j++){
			for( k=0; k<5; k++){
				cin>>torta[i][j][k];
			}
		}
	}
	// POST: i>=3 && sono stati inseriti i strati della torta.

	cin>>scelta;
	cin>>numeroFetta;

	if(scelta =='H'){
		for( i=0; i<3; i++){
				for( j=0; j<4; j++){
					if(j==numeroFetta){

						for( k=0; k<5; k++){
							cout<<	torta[i][j][k] <<" ";
							}
						cout<<endl;
					}
				}
		}

	}else{
		for( i=0; i<3; i++){
			for( j=0; j<4; j++){
				for( k=0; k<5; k++){
					if(k==numeroFetta){
					cout<<torta[i][j][k] <<" ";
				    }
			    }
			}
			cout<<endl;
    	}

	}


	cout<<"end"<<endl;

}
//il cout contiene la fetta della torta richiesta dall'utente.
