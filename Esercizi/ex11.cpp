#include<iostream>
using namespace std;

void leggi(int*X, int nelem)
{
	for(int i=0; i < nelem; i++)
    cin >> X[i];
}

int& FETTE(int (*A)[6][5], int s, char F, int indf, int k){

	if(F=='H'){
		return A[k/5][indf][k%5];
	}
	else {
		return A[k/6][k%6][indf];
	}
}

//PRE=A puntatore ad array di 2 dimensioni && i=riga di riferimento nella matrice && j=colonna di riferimento nella matrice
bool presente(int (*A)[6][5], int i, int j){		
	bool contenuto=true;							//variabile per uscire
	//PRE1=contenuto==true
	for(int w = 0; w < 15 && contenuto; w++){		//ciclo per poter scorrere tutte le colonne 
		//R1=(0<=w<=15) && (contenuto==false sse la H-fetta i non � contenuta nella V-Fetta j)
		contenuto=false;
		int elemento=FETTE(A, 3, 'H', i, w);		//passo alla funzione Fette l'elemento attuale per poter calcolare la H-Fetta
		//PRE2= contenuto==false && elemento==elemento w-esimo della H-fetta
		for(int z = 0; z < 18 && !contenuto; z++){	//ciclo per poter scorrere tutte le righe
			//R2=(0<=z<=18) && (contenuto==true sse elemento==V-Fetta)
			if(elemento == FETTE(A, 3, 'V', j, z)){	//confronto la H-Fetta con la V-Fetta
				contenuto=true;						//imposto la variabile che valorizza la matrice
			}
		}//POST2= (contenuto == true sse nella j V-FETTA[0..LV-1] � presente l'elemento w della H-FETTA i)
	}
	//POST1=contenuto == true sse la H-FETTA[0..LH-1] i � contenuta nella V-FETTA[0..LV-1] j
	return contenuto;
}

void stampa(bool (*B)[5], int righe)
{
	for(int i=0; i<righe; i++)
	{
		for(int j=0;j<5; j++ )
		cout<<B[i][j]<<' ';
		cout<<endl;
    }
    
}

int main()
{
	int A[3][6][5];
	bool B[6][5];
	leggi(**A,90);

	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 5; j++){
			B[i][j]=presente(A, i, j);
		}
	}

	stampa(B, 6);

	return 0;
}
