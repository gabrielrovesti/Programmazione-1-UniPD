
//soluzione by: Nicol� S.

#include<iostream>
#include<fstream>

using namespace std;

main(){
	ifstream INP("input");
	ofstream OUT("output");
	
	int X[400],n_ele;
	INP>>n_ele;
	
	for(int a=0;a<n_ele;a++)
		INP>>X[a];
	
	int lim1,lim2,lim3,lim4;
	INP>>lim1>>lim2>>lim3>>lim4;
	
	int r,c;
	INP>>r>>c;
	
	if(r>=lim3 || c>=lim4)
		OUT<<"il tassello "<<r<<" "<<c<<" e' vuoto ";
	
	else
	{
		bool ok=false;
		bool b=true;
		bool esci=false;
		
		for(int t=0;t<lim1 && !esci;t++)
		{
			for(int s=0;s<lim2 && !esci;s++)
			{
				if( (t*lim2*lim3*lim4+s*lim3*lim4+r*lim4+c)<n_ele)
				{
					if(b)
						{
							OUT<<"il tassello "<<r<<" "<<c<<" contiene ";
							b=false;  //in modo da entrare solo una volta all'intenro dell'if, senno stampo sempre "il tassello contiene..."
						}
					OUT<<X[t*lim2*lim3*lim4+s*lim3*lim4+r*lim4+c]<<" ";
					ok=true;
				}
				else
				{
					if(ok==false)
						{
							OUT<<"il tassello "<<r<<" "<<c<<" e' vuoto ";
							esci=true;   // in modo da farlo entrare solo una volta e appena entra in questo if esce subito dai due cicli for
						}
				}
			}
		}
	}
}

/* correttezza del ciclo for di riga 33
PREcondizione per entrare nel ciclo: 
s < lim2: vedi la stessa dichiarazione del for, dove s è inizializzato a 0
esci e' falsa : vera, esci è inizializzato a zero

invariante: 
la prima condizione è facile da dimostrare, infatti sarò sempre nel ciclo finchè s non sarà uguale a lim2 e contemporaneamente 
esci è sempre falsa
la seconda condizione si verifica solo se si entra nel ciclo if di riga 47

POST: l'output è corretto e contiene esattamente i valori del tassello oppure la scritta che il tassello è vuoto (in questo caso
esci= true) se il il numero di elementi era minore del posto del tassello sullo strato
*/











