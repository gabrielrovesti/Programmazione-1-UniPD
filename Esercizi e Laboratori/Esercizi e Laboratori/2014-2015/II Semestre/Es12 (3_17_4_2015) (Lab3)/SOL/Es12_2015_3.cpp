
//soluzione by: Nicolò S.

#include<iostream>
#include<fstream>
using namespace std;

int calcola_dist(int f, int e, int lim2, int lim3, int n_el){
	bool ok = true;
	int riga, indice;
	int lim1 = (n_el / (lim2*lim3)) + 1;

	
	if(f>=lim3)
		return -1;
		
	else{ 
		if (e == 0)
			return f;

		else {
				for (int rig = 0; rig<lim2 && ok; rig++){
				int conta_strato = 0;
					for (int s = 0; s<lim1 && ok; s++){
						if ((s*lim2*lim3 + rig*lim3 + f) < n_el)
						e--;

						if (e == -1)
							ok = false;
							riga = rig;
							indice = conta_strato;

							conta_strato++;
					}
				}

				int x = indice*lim2*lim3 + riga*lim3 + f;

				if (x > n_el)
					x = -1;
				return x;
			}
	}
}

main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int X[400], n_el, lim1,lim2,lim3;
   IN>>lim1>>lim2>>lim3;
   IN>>n_el;
   for(int i=0; i<n_el; i++)
     IN >> X[i];
   if(n_el>lim1*lim2*lim3)
    n_el=lim1*lim2*lim3;
    
 
    
   for(int q=0; q<3; q++)//legge le tre quadruple
    {
     int f, e[3];
     IN>>f>>e[0]>>e[1]>>e[2];
	
 
		for(int j=0;j<3;j++)
		 {
		  int d=calcola_dist(f,e[j],lim2,lim3,n_el);
		  
		  if(d==-1)
			OUT<<e[j]<<" elemento inesistente della V-fetta "<<f<<' '; 
		  else
			OUT<<d<<' ';
		 }
		 
		OUT<<endl;
		}
     
   

   IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
 }

 
 /*SOLUZIONI DI TEORIA

(1)

a.  La dichiarazione di a va bene, mentre la dichiarazione di b e' sbagliata perche' non c'e' il costruttore con i parametri.
    Come soluzione si puo' introdurre un costruttore con parametri.

b. Dara' un messaggio di errore perche' il compilatore non sa come stamparlo essendo un tipo definito dall'utente.

c. Uguale alla b.


(2)

X entra nel case bianco/nero, esegue X=giallo e X=nero -> X diventa nero.
A questo punto salta i test dei casi successivi e, uno alla volta, esegue le varie istruzioni, fino a che non trova un break.
Alla fine dunque, X sara' nuovamente bianco.


(3)

a.  E' necessario che ogni programmatore possa compilatre indipendentemente la sua parte dalle altre parti, e che ciascuna parte sia in grado di usare
le cose che sono dichiarate e definite nelle altre parti. C'e' dunque un caso di esportazione delle variabili globali.

b.  Ciascuno dei 4 programmatori deve produrre un file header.h e un file nel quale sono contenute le definizioni delle cose, che sara' cpp.
Il file .h dovra' contenere i prototipi delle funzioni e tipi dichiarati nella parte di ciascun programmatore.
L'idea e' che ciascun programmatore abbia il proprio header e gli header di tutti gli altri programmatore, e che faccia l'include di tutti e 4 gli header.

c.  La variabile globale deve essere dichiarata solamente in uno degli header.
Negli header degli altri dovra' dunque esserci la dichiarazione della variabile globale preceduta da extern.

d.  Try, cath e throw.
Try e' sempre seguita da un blocco, alla fine del quale c'e' l'istruzione di catch che serve a prendere le eccezioni sollevate all'interno del try.
L'istruzione di throw serve per sollevare l'eccezione ed e' accmpagnata da un valore.
Se vi fossero diversi catch a disposizione di una throw verra' eseguito l'ultimo tra quelli sollevati.*/
