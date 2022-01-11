#include<iostream>
using namespace std;

void leggi(int* X, int & nelem)
{
    bool ok=false;
    while(!ok)
    {
        cin >>nelem;
        if(nelem>0 && nelem <=49)
        ok=true;
    }
    
	for(int i=0; i < nelem; i++)
	cin >> X[i];
}

//PRE=(k==num. di elementi presenti) && (row=riga attuale)

int lenr(int k, int row){		//calcolo la lunghezza della riga
	int comp_r=k/7;				//calcolo il numero di righe complete
	int resto=k%7;				//e le righe con solo alcuni elementi
	
	if(row < comp_r){			//se il numero di riga � minore del numero di righe complete
		return 7;				//ritorno 7
	}
		return resto;			//altrimenti ritorno quelle restanti
	
}

//POST=viene ritornata la lunghezza di riga, considerando valori riempiti o parzialmente riempiti

//PRE=(k==num. di elementi presenti) && (col=colonna attuale)

int lenc(int k, int col){		//calcolo la lunghezza della riga
	int num_r=k/7;				//ricalcolo il numero di righe complete e 
	
	if(col>= k%7){				//se la colonna attuale � maggiore o uguale al num. di elementi%7
		return num_r;			//ritorno la riga perch� completa
	}	
	else{
		return num_r+1;			//aggiungo 1 per visualizzare l'ultima riga effettivamente completa
	}
}

//POST=ritorno la lunghezza della colonna, considerando quanto sono state riempite le righe

//PRE=(A puntatore ad array intero 7*7) && (row=riga attuale)
//&& (col=colonna attuale) && (k==num. di elementi presenti)

bool in(int (*A)[7], int row, int col, int k){
	bool trovato=true;
	for(int i=0; i < lenr(k, row) && trovato; i++){
		trovato=false;
		for(int j=0; j < lenc(k, col) && !trovato; j++){
			if(A[row][i]==A[j][col]){
				trovato=true;
			}
		}
	}
	
	return trovato;
}

//POST=trovato restituisce un valore vero o falso a seconda se la riga I contiene la colonna J

void stampa(bool (*B)[7], int nelem)
{
	for(int i=0; i<7; i++)
	{
		for(int j=0;j<7; j++)
		cout<<B[i][j]<<' ';
		cout<<endl;
	}
}


int main()
{
	int A[7][7], nelem;
	bool B[7][7];
	leggi(*A,nelem);

	bool defined=true;
	for(int i=0; i<7 && defined; i++){
		for(int j=0; j<7 && defined; j++){
			if(lenr(nelem, i) && lenc(nelem, j)){
				B[i][j]=in(A, i, j, nelem);
			}
			else{
				defined=false;
			}
		}
	}

	stampa(B,nelem);

	return 0;
}
