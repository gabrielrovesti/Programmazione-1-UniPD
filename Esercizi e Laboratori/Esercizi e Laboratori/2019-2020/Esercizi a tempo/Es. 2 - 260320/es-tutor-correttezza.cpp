#include<iostream>
using namespace std;
//PRE = (X è un array vuoto, n_ele, lim1, lim2 e lim3 sono >0
//&&(n_ele <= lim1*lim2*lim3) && (cin contiene almeno n_ele valori)
void leggiV(int* X, int n_ele, int lim1, int lim2, int lim3) {
	/*
	PRE=(i==0) && (n_ele <= lim1*lim2*lim3) &&
         (cin contiene almeno n_ele valori)
	*/
	for (int i = 0; i < n_ele; i++) {
    /*R=(0<=i<=n_ele)
     *&& (inseriti lim1*lim2 elementi in v-fette 0..i/(lim1*lim2)-1)
     *&& (inseriti i % lim1*lim2 elementi in v-fetta indice i/(lim1*lim2))
     */
		cin >> X[i/(lim2*lim1) + (i%(lim1*lim2))*lim3];
	}
	/*PROVA DI CORRETTEZZA
   1.PRE =>R  (Inizializzazione)
	i==0 => (0<=i<=n_ele) banalemente vero, così
	come risulta banalmente vero che sono state riempite completamente v-fette 0..-1
	e sono stati inseriti 0 elementi in v-fettta di indice 0

   2.INV && cond => INV (Invarianza)
	(0<=i<=n_ele) && i < n_ele => (0<=i+1<=n_ele)
= (0<=i<=n_ele) in valutazione successiva (con i incrementato)


	assumendo che ad inizio iterazione siano stati inseriti i%lim1*lim2 elementi in v-fetta indice i/(lim1*lim2)
	ricordando i%lim1*lim2 compreso in [0, lim1*lim2-1]
	assegnando il valore in input a X + i/(lim2*lim1) + (i%(lim1*lim2))*lim3 si va
	ad assegnare l'elemento nella posizione i%(lim1*lim2) della v-fetta di indice i/(lim1*lim2).
	A questo punto la suddetta v-fetta contiene i%(lim1*lim2) + 1 elementi , ovvero un numero di elementi
	compreso in [1, lim1*lim2].
	Nella valutazione successiva i%(lim1*lim2)==0 sse il valore di i/(lim1*lim2)
	(=l'indice della v-fetta)è aumentato

	Se nella valutazione successiva i%(lim1*lim2)>0, significa che la v-fetta non è ancora piena e il valore di i/(lim1*lim2)
	(l'indice della v-fetta) non è aumentato
	quindi si continua a considerare la stessa v-fetta che ha i%(lim1*lim2) elementi
		(il ciclo è stato eseguito e i  è stato aumentato)
= (parte 2 di R)
		dunque non è piena,
		e le v-fette 0..i/(lim1*lim2)-1 continuano ad
		essere tutte e sole le fette che hanno lim1*lim2 elementi (=sono piene)
= (parte 3 di R)


	Se nella valutazione successiva i%(lim1*lim2)==0, significa che l'iterazione precedente ha inserito l'elemento
	numero lim1*lim2 nella v-fetta che stava considerando (=l'ha riempita completamente).
	Poiché il valore di i/(lim1*lim2) è aumentato di 1 rispetto all'iterazione precedente (valutata con i prima di essere incrementato)
	e si ha una v-fetta piena in più rispetto all'iter. precedente, vale ancora (inseriti lim1*lim2 elementi in v-fette 0..i/(lim1*lim2)-1).
=(parte 3 di R)

	poiché i/(lim1*lim2) è aumentato nella valutazione successiva di R si andrà a verificare se sono stati inseriti
	i%(lim1*lim2)==0 elementi nella v-fetta successiva a quella appena considerata, nessuna istruzione ha ancora modificato tale
	parte dell'array.
=(parte 2 di R)

	Dunque se vale (R && cond) viene eseguito il ciclo e qualunque sia il risultato di i%(lim1*lim2) in valutazione successiva,
	valgono ancora la parte 2 e 3 di R, oltre alla parte 1 che abbiamo dimostrato all'inizio della dimostrazione dell'invarianza, dunque

	vale R in iterazione successiva

	3. R && !cond => POST (Terminazione)
		R && i>=n_ele => (0<=i<=n_ele) && i>=n_ele => i== n_ele
		dunque sostituendo i con n_ele in parti 2 e 3 di R

		(inseriti lim1*lim2 elementi in v-fette 0..n_ele/(lim1*lim2)-1)
	 && (inseriti n_ele % lim1*lim2 elementi in v-fetta indice n_ele/(lim1*lim2))

	 poiché se una v-fetta ha lim1*lim2 vuol dire che è piena ed i "restanti elementi" sono
	 i _ele % lim1*lim2 elementi inseriti in ultima v-fetta, si ottiene esattamente il testo dellla POST
	*/
	/*POST = (riempite v-fette 0..n_ele/(lim1*lim2)-1)
	 && (inseriti restanti elementi in v-fetta di indice n_ele/(lim1*lim2))*/
}
//POST=(in X vista come int[lim1][lim2][lim3] sono stati letti gli n_ele valori di cin per V-fette)



//PRE_StampaS= (n_ele <= lim1*lim2*lim3) && (0<= strato < lim1)&& (X contiene almeno n_ele valori ed è rimepito per v-fetta)
void stampaS(int* X, int n_ele, int lim1,int lim2, int lim3, int strato) {
	bool emptyRow = false;
//PRE = PRE_StampaS && row == strato*lim2
    for (int row = strato*lim2; row < (strato+1)*lim2 && !emptyRow; row++) {
/* R1=(strato*lim2 <= row <= (strato+1)*lim2)
&& (emptyRow è vero sse è stata stampata riga precedente dello strato)
&& (emptyRow è falso => tutte le righe con indice >= row-1 sono vuote)
*/
	    int* beginRow = X + row*lim3;     //puntatore al primo elemento della riga row dell'ARRAY
		if (n_ele > row) {
			cout << 'r' << row-(strato*lim2) << ':'; //oppure cout << 'r' << row % lim2 << ':';
			for (int col = 0; col<lim3 && col*lim1*lim2 + row < n_ele; col++) {
				//R2 = (0<= col <= lim3)
				//&& (stampati col elementi nella riga separati da ' '
				//&& (col*lim1*lim2 + row < n_ele sse esiste elemento di indice col+1 nella riga)
				cout << beginRow[col] << ' ';
			}
            cout << endl;
		} else {
            emptyRow = true;
		}
	}
/*	POST(Stampate le righe con almeno un elemento di strato si indice strato)
	&& (emptyRow sse non tutte le righe di strato hanno almeno un elemento)
*/
	}
//POST_StampaS= Stampate tutte le righe con almeno un elemento di strato di indice

int main()
{
	int A[400], n_ele;		//array e n° di elementi da inizializzare
	int	lim1, lim2, lim3;	//n° di strati, righe, colonne
	int strato;				//indice dello strato da stampare
	cin >> n_ele >> lim1 >> lim2 >> lim3 >> strato;
	if (n_ele > lim1*lim2*lim3) {
        n_ele = lim1*lim2*lim3;
	}
	leggiV(A, n_ele, lim1, lim2, lim3);
	stampaS(A, n_ele, lim1, lim2, lim3, strato);
	return 0;
}
