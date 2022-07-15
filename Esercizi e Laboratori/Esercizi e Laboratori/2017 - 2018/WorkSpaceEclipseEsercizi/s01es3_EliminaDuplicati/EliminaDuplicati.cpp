	#include <iostream>

	/*
	 *Si tratta di leggere n (0<n<100) e poi n interi in un array A di 100 interi.
	 *Si Poi vogliamo eliminare da A[0..n-1] i valori che ripetono, lasciando per
	 *Si ciascun valore solo l’occorrenza più a sinistra (cioè quella con indice minimo).
	 *Si Si vuole anche calcolare il numero di valori che restano in A.
	 *
	 */
	using namespace std;

	int main(){

		cout<<"start"<<endl;
		int array[100], i=0, n,quantitaNumeriNonRipetuti=0;

		cin>>n;

		//PRE:
		while(i<n){
			//R:
			cin>>array[i];
			i++;
		}
		i=0;


		while(i<n){
			int j=0;
			bool esiste=false;
			while(j<quantitaNumeriNonRipetuti && !esiste){
				if(array[i]==array[j]){
					esiste=true;
				}else{
					j++;
				}
			}
			if(!esiste){
				array[quantitaNumeriNonRipetuti]=array[i];
				quantitaNumeriNonRipetuti++;
			}

			i++;
		}


		//stampa ok
		i=0;
		cout<< "m = "<<quantitaNumeriNonRipetuti<<endl;
		cout<<"A = ";
		while(i<quantitaNumeriNonRipetuti){
			cout<<array[i]<<" ";
			i++;
		}
		cout<<endl;

		cout<<"end"<<endl;


	}
