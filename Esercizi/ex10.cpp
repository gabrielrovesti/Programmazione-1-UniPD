#include<iostream>
using namespace std;

void leggi(int*X, int nelem)
{
	for(int i=0; i < nelem; i++)
    cin >> X[i];
}

//PRE=(T ha s strati ed è completamente definite, F e indf specificano una fetta esistente in T, k >=0 è un 
//elemento esistente della fetta richiesta)

int& FETTE(int (*A)[6][5], int s, char F, int indf, int k){

	if(F=='H'){
		return A[k/5][indf][k%5];
	}
	else {
		return A[k/6][k%6][indf];
	}
}	
	
	//La funzione Fette è in grado di restituire l'elemento richiesto considerando
	//tutta verticalmente una porzione di array composta da tutto un insieme di colonne/tutto un insieme di righe di uno stesso indice.
	//In virtù dei dati passati come parametri formali, l'indice della fetta e l'altro dato permettono di identificare una fetta e trovarne i dati dal suo interno
	//l'indice k specifica che elemento restituire in output all'utente
	//e indf specifica che fetta e che strato considerare
	//operando con apposite operazioni aritmetiche
	
	//In questo modo si vede come, per poter considerare una fetta orizzontalmente
	//disponendo già dell'elemento cercato e dell'indice della fetta,
	//basti, nel caso della fetta orizzontale, riferirsi come fetta alle righe
	//e dividere per cinque lo strato e operando una divisione intera sul numero di colonne
	//considerando l'effettiva posizione piena;
	//analogamente, per la fetta verticale, basta considerare
	//come indice fetta le colonne e dividendo per 6 lo strato 
	//e per divisione intera il numero di righe, al fine di poter meglio operare
	//sulle colonne
	
	
//POST=(restituisce l'elemento k-esimo della fetta di T specificata da F e indf)


int main()
{
	int A[3][6][5], nelem;
	leggi(**A,90);
	bool stop=false;
	while(!stop)
    {
	char c;
	cin >> c;
		if(c =='S')
		stop=true;
		else
		{
		int f,k;
		cin>>f>>k;
		cout << FETTE(A,3,c,f,k) << endl;
		}
    } 
}

