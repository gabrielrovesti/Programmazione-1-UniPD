#include <iostream>

using namespace std;

void leggi_ric(bool*B, int nelem){
    
	if(nelem!=0){
	cin>>B[0];
    leggi_ric(B+1, nelem-1);
	}
}

//PRE: P è ben definito, riga e colonna sono validi
bool percorso(bool (*P)[8], int* C, int riga, int col)
{
	//verificare l'esistenza del percorso e costruirlo
	
	if(col < 0 || col >= 8){
		return false;
	}
	if(P[riga][col] == 0){	//se nella prima riga non c'è nulla, ritorno false;
		return false;
	}
	//PRE-ric: P è ben definito, riga+1 valido (assumiamo, una volta dimostrata la validità di PRE-ric, che può cambiare tra le cambiate ricorsive, sia valida POST-ric)
	//POST-ric: true --> da (riga+1,col-1) abbiamo un percorso e C[riga+1...7] riempito
	if(riga == 7){
		C[riga] = col;
		return true;
	}
	if (percorso(P, C, riga+1, col-1) || percorso(P, C, riga+1, col) || percorso(P, C, riga+1, col+1)){
		C[riga] = col;		//mi salvo la posizione della corrispondenza
		//C[riga..7] riempita
		return true;
	}
	return false;
}
//POST: return true sse percorso trovato da (riga, colonna)
//all'ultima riga da soli 1 && C contiene il percorso

void print_path_ric(int*Path, int nelem, int i){
	
	if(i==nelem){
		return;
	}
	else{
	cout<<'('<<i<<','<<Path[i]<<')'<<' ';
	print_path_ric(Path, nelem, i+1);	
	}
	cout<<endl;
}

int main()
{
	bool P[8][8];
	int C[8];
	int i=0;
	
    leggi_ric(*P, 64);
	
	bool trovato=false;
	for(i = 0; i<8 && !trovato; i++){
		trovato=percorso(P, C, 0, i);		//appena trovato un percorso si ferma; passa "i" per indicare la colonna utile
	}
	
	i=0;
	
	if(trovato)
	print_path_ric(C, 8, i);
	else 
	cout << "nessun cammino" << endl;
}
