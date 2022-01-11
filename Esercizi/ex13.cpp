#include<iostream>
using namespace std;

void leggi (int*A, int nelem){
	for(int i=0; i<nelem; i++)
	{
		cin >> A[i];
	}
}

//PRE =(T ha LT elementi e P ne ha LP, LT e LP sono >0)
int match(int*T, int LT, int*P, int LP)
{
	bool ok=false;
	int i=0, j=0;
	//PRE1 = (ok = false)
	for(i=0; !ok && i + LP-1 < LT; i++){		//R1 = (0 <= i+LP-1 <= LT) && (ok sse T[i] == P[0] || T[i..i+LP-1] == P[0..LP-1])
		if(T[i]==P[0]){
			j = i + 1;
			ok=true;
			//PRE2 = (j=i+1) && (ok = true)
			for(int k = 1; k < LP && ok; k++){	//R2 = (1 <= k <= LP) && (ok sse T[i..j-1] == P[0..k-1])
				if(T[j] != P[k]){
				ok=false;
				}
				j++;
			}
			//POST2= ok sse T[i...j-1] == P[0..LP-1]
		}
	}
	//POST1 = ok sse T[i-1... i-1+LP-1] == P[0..LP-1]
	if(ok) return i-1;
	return -1;
}
//POST=(se c'è un match di P in T, allora la funzione restituisce l�indice minimo di un tale match, altrimenti 
//restituisce -1)

/*
Dimostrazione di correttezza:
alla prima iterazione, nel ciclo abbiamo j=0;
in un ciclo intermedio, supponendo i=2 e j=3, se c'� un match nel pattern indicato
la funzione entra nel primo condizionale, imposta la variabile di controllo a false perch� � la prima volta
che ha trovato un match e incrementa entrambi gli indici;
se nel ciclo successivo a i+1 e j+1 si trova un altro match (da cui appunto ind_match==i sse T[i]==P[j]), firsttime rimane false,
i e j vengono incrementati;
se non trovassi pi� un match, azzero l'indice j della matrice pi� piccola e ricomincio, reimpostando i contatori
all'ultima posizione di match e anche l'indice stesso di match;
nel caso in cui j fosse uguale a true in un ciclo intermedio ho quindi scorso tutti gli elementi-->Post
*/


int main()
{
	int T[50], P[10], LT, LP;
	cin >> LT >> LP;
	leggi(T,LT);
	leggi(P,LP);
	cout << " inizio match="<<match(T,LT,P,LP)<<endl;  
	
	return 0;
}    
