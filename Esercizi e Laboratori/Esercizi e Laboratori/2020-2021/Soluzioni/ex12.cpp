#include<iostream>
using namespace std;

int lung(char F, int righe, int colonne, int nelemA, int indFetta){
    int cCorrente;		//dichiaro la colonna corrente
    if(F == 'H'){		//se la fetta è orizzontale
        int rc    = righe*colonne;		//calcolo le righe complete
        int nsp   = nelemA / rc;		//numero strati da considerare
        int nrus  = (nelemA % rc) / colonne;	//numero righe riempite
        int resto = (nelemA % rc) % colonne;	//numero righe non riempite
        cCorrente = colonne * nsp;
        if(indFetta < nrus) {		//se l'indice della fetta di riferimento è minore rispetto alle righe utilizzate
            cCorrente = cCorrente + colonne;			//allora sommo le colonne presenti alla colonna attuale per prendere in considerazione quelle riempite
        }else{
            cCorrente = cCorrente + resto;				//altrimenti sommo le colonne riempite parzialmente con dei valori alla colonna attuale
        }
    }else{
        cCorrente = nelemA / colonne;
        int resto = nelemA % colonne;
        if(indFetta < resto){
            cCorrente++;
        }
    }
    return cCorrente;
}

int FETTE(int (*X)[6][5],int strati, char F, int indf,int k) {
    if(F == 'H'){
        int ns = k/5, resto = k%5;
        return X[ns][indf][resto];
    }else{
        int ns = k/6, resto = k%6;
        return X[ns][resto][indf];
    }
}

void leggi(int*X, int& nelem)
{
    cin >>nelem;
    for(int i=0; i < nelem; i++)
        cin >> X[i];
}

void stampaB(bool (*B)[5], int nelem, int righe){
    if(nelem < 5){									//se il numero di elementi della matrice risulta essere minore di 5
        for(int i = 0; i < nelem; i++){				//alora stampo la prima riga
            cout << B[0][i] << ' ';
        }
        cout << endl;
    }else{
        int nr = righe;								//calcolo il numero di righe
        if((nelem/5) < righe){						//se vedo che gli elementi diviso 5 sono minore rispetto alle righe
            nr = nelem/5;							//anche il numero di righe sarà diviso per 5 e, se c'è una riga
            if(nelem%5 > 0)							//con dei valori rimanenti, sommo 1 per poter effettivamente stampare correttamente
                nr++;
        }
        for(int i = 0; i < nr; i++){				//proseguo altrimenti con una normalissima stampa della matrice
            for(int j = 0; j < 5; j++){
                cout << B[i][j] << ' ';
            }
            cout << endl;
        }
    }
}

//PRE = (A è un puntatore a array [6][5] di interi)
//   && (nelem è il numero di elementi puntati da A)
//   && (LH è la lunghezza della H-FETTA i)
//   && (i è l'indice della H-FETTA)
//   && (j è l'indice della V-FETTA)
bool presente(int (*A)[6][5], int nelem, int LH, int i, int j){
    int LV = lung('V', 6, 5, nelem, j);
    bool contenuto = true;

	//*** NB=I val. sotto riportati rappresentano come deve essere fatta una dim. di correttezza;
	//in pratica si tratta di dimostrare a livello pratico che il programma faccia ciò che diciamo
	//assumendo per vere pre e postcondizioni e, chiaramente, anche lo stesso invariante
	
    // LH 7
    // LV 7
    // w = 5 < 7
    // contenuto == true
    // H-FETTA[0..5-1] == H_FETTA[0..4] sia contenuta in V-FETTA[0..6]
    
     //PRE1 = (contenuto = true && LV = lunghezza V-FETTA j)
    for(int w = 0; w < LH && contenuto; w++){
        //R1 = (0 <= w <= LH) && (contenuto == false sse la H-FETTA[0..w-1] i non è contenuta nella V-FETTA[0..LV-1] j)
        contenuto = false;
        int elemento = FETTE(A, 3, 'H', i, w);
        //PRE2 = (contenuto = false && elemento = w-esimo elemento della H-FETTA i) && (LV = lunghezza V-FETTA j)
        for(int z = 0; z < LV && !contenuto; z++){
            //R2 = (0 <= z <= LV)
            //  && (contenuto == true se nella j V-FETTA[0..z-1] è presente l'elemento w della H-FETTA i)
            if(elemento == FETTE(A, 3, 'V', j, z))
                contenuto = true;
        }
        //POST2 =(contenuto == true sse nella j V-FETTA[0..LV-1] è presente l'elemento w della H-FETTA i)
    }
    //POST1 = (contenuto == true sse la H-FETTA[0..LH-1] i è contenuta nella V-FETTA[0..LV-1] j)
    return contenuto;
}
//POST = (contenuto == true sse l'H-FETTA i è contenuta nella V-FETTA j)

int main()
{
    int A[3][6][5], nelem;
    bool B[6][5];
    leggi(**A,nelem);

    //PRE1 = (nelem = numero di elementi di A)
    for(int i = 0; i<6 && i < lung('H', 6, 5, nelem, i); i++){
        //R1 = (0 <= i <= lung('H', i) )
        // &&  (B[0..i-1][0..lung('H',i)] è popolato secondo la specifica)

        int LH = lung('H', 6, 5, nelem, i);

        //PRE2 = (LH = lunghezza della H-FETTA i && B[0..i-1][0..5] popolata secondo la specifica)
        for(int j = 0; j < 5 && (lung('V', 6, 5, nelem, j) > 0); j++){
            //R2 = (0<= j <= 5)
            // &&  (V-FETTA j ha lunghezza != 0)
            // &&  (B[0..i-1][0..j-1] popolata secondo la specifica)
            B[i][j] = presente(A, nelem, LH, i, j);
        }
        //POST2 = (B[0..i][0..LH] == true sse H-FETTA i contenuta in V-FETTA j)

    }
    //POST1 = (B[0..i-1][0..lung('H', 0) -1] è popolato secondo la specifica)
    stampaB(B,nelem,6); //da fare
}

//specifica = La generica H-FETTA x è contenuta nella generica V-FETTA y
//A_orig    = La matrice A originale considerata con i valori istanziati e riempiti inizialmente

