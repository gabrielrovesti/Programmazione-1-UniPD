#include <iostream>


/**
 Consegna:
Un societ`a organizzatrice di un concerto vuole verificare che non ci
siano biglietti falsi.  Scrivere un programma che acquisisca i numeri di serie dei biglietti e verifichi che non
vi siano numeri duplicati.  Il programma acquisisce innanzitutto il numero di biglietti venduti,
N
(compreso
tra
1
e
100
), ed in seguito acquisisce i numeri di serie degli
N
biglietti.  Il numero di serie di un biglietto `e un
numero decimale a sei cifre (da
100000
a
999999
).
Al termine dell’acquisizione, il programma stamper`a
"Tutto regolare"
se non si sono riscontrati dupli-
cati, altrimenti stamper`a i numeri di serie dei biglietti duplicati
in ordine crescente
.  Ogni numero di serie
duplicato va stampato una volta sola.
Dimostrazione di correttezza.
Scrivere pre-condizione, post-condizione e invarianti dei cicli come com-
menti nel codice.

 */
using namespace std;
//PRE:
int main(){


		cout<<"start"<<endl;
		int serialNumber[100],serialDuplicati[50];
		int numeroBigliettiVenduti,i=0,j=0,numeroBigliettiDuplicati=0;
		bool allOk=true;

		cin>>numeroBigliettiVenduti;
		//PRE: i=0,
		while(i<numeroBigliettiVenduti){
			/*
			 * Invariante:
			 * inseriti i numeri &&
			 * i<numeroBigliettiVenduti
			 *
			 */

			cin>>serialNumber[i];
			i++;
		}
		//POST: inseriti i numeri e i>=numeroBigliettiVenduti

		i=0;
		bool ultima;
		int k=0;

		//pre: i=0
		while(i<numeroBigliettiVenduti-1){
			/*
			 * R:
			 * i<=NumerobigliettiVenduti-1 &&
			 * confrontati i primi i numeri per vedere se ci sono dei numeri uguali
			 *
			 */
			j=i+1;
			while(j<numeroBigliettiVenduti){
				// j<=numeroBigliettiVenduti
				if(serialNumber[i]==serialNumber[j]){
					allOk=false;
					ultima=true;
					k=0;
						while(k<numeroBigliettiDuplicati){
							//k<=0 && confrontati i primi k numeri con il numero serialNumber[i]
							if(serialDuplicati[k]==serialNumber[i])
							{
								ultima=false;
							}

							k++;
						}
						if(ultima){
							serialDuplicati[numeroBigliettiDuplicati]=serialNumber[i];
							numeroBigliettiDuplicati++;
						}
				}
				j++;
			}

			i++;
		}
		// post: ordinati tutti i numeri, e i>=numeroBigliettiVenduti.


		if(allOk){
			cout<<"Tutto regolare"<<endl;
		}else{
			i=0;
			j=0;
			//pre: i=0 && j=0
			while(i<numeroBigliettiDuplicati-1){
				//Invariante: i<=numeroBigliettiDuplicati-1 &&  ordinati i primi i numeri
				j=i+1;
				while(j<numeroBigliettiDuplicati){
				// confrontati j-i-1 numeri con il numero serialNumberDuplicati[i] && j<=numeroBigliettiDuplicati
					if(serialDuplicati[i]>serialDuplicati[j]){
						int temp=serialDuplicati[i];
						serialDuplicati[i]=serialDuplicati[j];
						serialDuplicati[j]=temp;
					}

					j++;
				}
				i++;
			}
			//POST: ordinati i numeri && i>=numeriBigliettiVenduti-1

			i=0;

			//Pre: i=0
			while(i<numeroBigliettiDuplicati){
				//R: i< =numeroBigliettiDuplicati && stampati i primi i numeri
				cout<<serialDuplicati [i]<<endl;;

				i++;
			}
			//POST: stampati i numeri e i >= numeroBigliettiDuplicati.
		}


		cout<<"end"<<endl;


}
//POST:
