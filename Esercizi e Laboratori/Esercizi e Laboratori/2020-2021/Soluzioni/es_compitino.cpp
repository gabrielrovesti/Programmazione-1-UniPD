#include <iostream>

using namespace std;

void leggi(int (*X)[5], int &nelem){
	cin >> nelem;
	for(int i=0; i < nelem; i++){
		cin>>**(X+i);
	}
}

//PRE=( righe = numero di righe matrice, colonne=numero di colonne della matrice
//		nelem = numero di elementi della matrice, ind = indice corrente, X = 'R' oppure 'C'

int lung(int righe, int colonne, int nelem, int ind, char X){
	int nrp=nelem/colonne;
	int resto = nelem%colonne;
	if(X=='R'){
		if(ind < nrp)
		return colonne;	//la lunghezza della riga sarà numero delle colonne
		else
			if(ind==nrp)
			return resto;	//la lunghezza della riga sarà numero delle righe, anche solo riempite parzialmente
		return 0;	//se maggiore stiamo uscendo dal ciclo; siamo sicuri che la riga non ha altri elementi
	}
	else{		
		if(ind < resto)
		return nrp + 1;		//serve per le colonne più lunghe
	}
}

//POST = (ritorna la lunghezza della RIGA con indice ind della matrice se X='R', 
// altrimenti ritorna la lunghezza della colonna con indice ind della matrice)

int main()
{
	int A[10][5];
	leggi(A, nelem);
	bool [10][5];
	
	for(int i = 0; i < 10 && lung(10, 5, nelem, i, 'R'); i++){
		int LR=lung(10, 5, nelem, i, 'R');
		
		for(int j = 0; j < 5 && lung(10, 5, nelem, j, 'C'); j++){
			int LC=lung(10, 5, nelem, j, 'C');
			bool ok=true;
			int inizio=0;		//la colonna mi serve controllarla una volta soltanto
			for(int k=0; k < LC && ok; k++){
				ok = false;		//cerco testimonianza che A[i][k] sia dentro la colonna
				//PRE = (z=inizio && ok = false && LR = lunghezza riga i)
				for(int z=inizio; z < LR && !ok; z++){
					//R= (inizio <= z <= LR) && ok == false sse non ho trovato A[i][k] in A[0..z-1]
					if(A[i][k]==A[z][j]){
						ok=true;
						inizio=z+1;
					}
				}
				//POST= (ok = true sse ho trovato l'elemento A[i][k] nella posizione && inizio = posizione successiva a z, cioè z + 1)
			}
			//POST = (ok = true sse ho trovato tutti gli elementi di A[i][0..LC-1] sono dentro A[0..LR-1][j] mantenendo l'ordine della riga)
			B[i][j] = ok;
		}
		//POST (B[0..i][0..j-1] è popolata secondo la specifica
	}
	//POST (B[0..i][0..j-1] è popolata secondo la specifica
}
