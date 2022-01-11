#include<iostream>
using namespace std;
void leggi(bool*B, int nelem)
{
	for(int i=0; i<nelem; i++)
    cin >> B[i];
}

//PRE=array booleano p definito e dim > 0
int firstTrue(bool(*p), int dim){
	int i=0;
	//PRE= i==0 && dim>0
	while(i < dim && !p[i]){
		//R = 0<= i <=dim && p[0..i-1]=false
		i++;
	}
	//POST=(p[i] && p[0...i-1]=false || i==dim
	return i;
}
//POST= ritorna i t.c. (p[i] && p[0..i-1] = false) || i==dim

//PRE= ogni elemento di Palude � vero sse � raggiungibile dalla prima riga &&
//esiste un percorso valido
void build_path(bool(*Palude)[8], int nr, int *path){
	path[nr - 1]=firstTrue(Palude[nr-1], 8);
	//PRE1= ogni elemento di Palude � vero sse � raggiungibile dalla prima riga &&
	//&& path[nr-1] � l'indice della colonna del percorso alla riga nr-1 && r = nr-2
	for(int r = nr - 2; r >= 0; r--){
	//R1=per ogni k t.c r < k<= nr, path[k] � l'indice della colonna 
	//del percorso alla riga k && -1 <= r <= nr - 2
	
	//le mie coordinate sono (r+1, path[r+1])
	//verifico se posso andare in (r, path[r+1]-1)
		if(path[r + 1] > 0 && Palude[r][path[r + 1] - 1]){
		path[r]=path[r + 1] - 1;
		//verifico se posso andare in (r, path[r+1])
		}
		else if(Palude[r][path[r+1]]){
		path[r]=path[r + 1];
		}
		else{
		path[r]=path[r + 1] + 1;
		}
	}
	//POST1=per ogni k t.c 0 <= k <= nr, path[k] � l'indice della colonna nel percorso alla riga k
}
//POST=per ogni k t.c 0 <= k <= nr, path[k] � l'indice della colonna nel percorso alla riga k

void print_path(int*X, int righe){
	for(int i=0; i<righe; i++)
    cout<<'('<<i<<','<<X[i]<<')'<<' ';
	
	cout <<endl;
}

int main()
{
	bool Palude[8][8];
	leggi(*Palude,64);
	bool stop=false;

  	//PRE1= r==1 && !stop
	for(int r=1; r < 8 && !stop; r++){
		//R = ogni elemento di Palude [0..r-1] 
		stop=true;
		//PRE = c==0 && stop==true
		for(int c = 0; c < 8; c++){
		// R = ogni elemento di Palude[r][0..c-1] � true sse raggiungibile dalla prima
		//riga && stop non esiste elemento in Palude [r][c-1] raggiungibile dalla prima riga
		//&& 0 <= c <= 8
		if(Palude[r][c]){
			if(!((c>0 && Palude [r - 1][c - 1]) || Palude [r - 1][c] || (c<7 && Palude [r - 1][c + 1]))){
				Palude[r][c]=false;
			}
			else{
				stop=false;
			}
		}
	}
	//POST2=ogni elemento di Palude[r] � true sse raggiungibile dalla prima
  	//riga && stop sse non esiste elemento in Palude[r] raggiungibile dall'ultima riga
}
  	//POST1=ogni elemento di Palude � true sse raggiungibile dalla prima
  	//riga && stop sse non c'� cammino dalla prima riga all'ultima
	if(!stop)
	{
	int Path[8];//da riempire
	build_path(Palude,8,Path);//la dovete fare
	print_path(Path,8); 
    }
	else
    cout<<"nessun cammino"<<endl;
}

/*Dimostrazione di correttezza:

partendo dal main; nel ciclo pi� interno 
alla prima iterazione c=0 e stop=true;
in un ciclo intermedio, se non viene trovato un cammino
percorribile, stop==true e si esce dal ciclo;
se stop==false per tutto il ciclo, gli elementi
di Palude diventano true solo se raggiungibile per mezzo
di un cammino, mantenendo vero R;
all'ultima iterazione, c=8 && R-->Post2

per il ciclo pi� esterno, alla prima iterazione
i=1 e stop=false;
ad una iterazione intermedia, stop=true e vengono esaminati gli elementi di
Palude[0..r-1], a meno che stop==true (coerentemente alla dimostrazione avvenuta del ciclo interno).
Vengono altrimenti esaminati tutti gli elementi di Palude [0..r-1]
all'iterazione finale, quindi, r=8 && !stop-->Post1

Per la funzione Build_Path:
k=r e path[k] identifica l'indice della colonna attuale.
In un ciclo intermedio, scorriamo l'indice r, che varia tra la riga i-esima-1
e n-esima-1, esaminando la posizione della colonna attuale
con quella delle righe successive, verificando se
esiste un valore nelle posizioni di colonna j-1, j e j+1
a seconda che siano a true.
Quando k=nr && R-->Post1

per il secondo ciclo,  path[nr-1] rappresenta l'indice ad 1
dell'ultima riga, preso dalla funzione FirstTrue
Procediamo a dimostrarla;
nella suddetta funzione, assumendo vero come al solito
PRE, nel ciclo abbiamo i=0 e dim>0 perch� passati come 
parametro e valorizzati
Il ciclo scorre finch� non si trova un elemento ad 1 (quindi quando p[0..i-1] ha un i true), che viene quindi
restituito-->Post1

Proseguendo con il ciclo esterno di Build_Path
r==nr-2 allo stato iniziale e k=indice colonna di partenza.
Ad un ciclo intermedio, path[k]==posizione attuale nella colonna
di interesse ed r compreso tra nr-2 e 0; quando path[k]=nr-2
e r==0-->Post

*/
