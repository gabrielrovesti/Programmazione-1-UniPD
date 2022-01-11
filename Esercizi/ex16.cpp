#include<iostream>
using namespace std;

void leggi_ric(int*B, int nelem){
    
	if(nelem!=0){
	cin>>B[0];
    leggi_ric(B+1, nelem-1);
	}
}

//PRE: LP<=LT
bool init_match(int* T, int *P, int LT, int LP){
	if(LP == 0){
		return true;
	}
	if(*T!=*P){
		return false;
	}
	return init_match(T+1, P+1, LT-1, LP-1);
}

int matching(int* T, int* P, int LT, int LP){
	//trovare un matching iniziale (quindi sapere se T[0...LP-1] == P)
	if(LP>LT){		//dimensione maggiore, finisco subito
		return -1;
	}
	bool trovato = init_match(T, P, LT, LP);		//cerco il match iniziale
	if(trovato){
		return 0;
	}
	//PRE_ric: array T+1..LT-1, P..LP ben definiti nei LT e LP elementi
	int index = matching(T+1, P, LT-1, LP);			//la chiamata ricorsiva va avanti e di volta in volta toglie elementi totali, incrementando il contatore verifica l'esistenza e tornando indietro ricorsivamente trova la posizione
	if(index == -1){
		return -1;
	}
	return index+1;		//restituisce l'indice del match
	//POST-ric: index == -1 no match, T[index+1...index+LP] = P 
}
//POST: return index, se index == -1 allora no match. 
//Altrimenti T[index...index+LP-1] = P 

int main()
{
	int T[50], P[10], LT, LP;
	cin >> LT >> LP;
	leggi_ric(T,LT);
	leggi_ric(P,LP);
	cout << " inizio match="<<matching(T, P, LT, LP)<<endl;  
	
	return 0;
}    
