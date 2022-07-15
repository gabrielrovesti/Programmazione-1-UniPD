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
  	
//PRE= ogni elemento di Palude è vero sse è raggiungibile dalla prima riga &&
//esiste un percorso valido
void build_path(bool(*Palude)[8], int nr, int *path){
	path[nr - 1]=firstTrue(Palude[nr-1], 8);
	//PRE1= ogni elemento di Palude è vero sse è raggiungibile dalla prima riga &&
//&& path[nr-1] è l'indice della colonna del percorso alla riga nr-1 && r = nr-2
	for(int r = nr - 2; r >= 0; r--){
	//R1=per ogni k.t.c r < k<= nr, path[k] è l'indice della colonna 
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
	
	//POST1=per ogni k.t.c 0 <= k <= nr, path[k] è l'indice della colonna nel percorso alla riga k
}
//POST=per ogni k.t.c 0 <= k <= nr, path[k] è l'indice della colonna nel percorso alla riga k

void print_path(int*X, int righe)
{
  for(int i=0; i<righe; i++)
    {
      cout<<'('<<i<<','<<X[i]<<')'<<' ';
    }
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
		// R = ogni elemento di Palude[r][0..c-1] è true sse raggiungibile dalla prima
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
	//POST2=ogni elemento di Palude[r] è true sse raggiungibile dalla prima
  	//riga && stop sse non esiste elemento in Plaude[r] raggiungibile dall'ultima riga
}
  	//POST1=ogni elemento di Palude è true sse raggiungibile dalla prima
  	//riga && stop sse non c'è cammino dalla prima riga all'ultima
  	if(!stop)
    	{
      	int Path[8];//da riempire
      	build_path(Palude,8,Path);//la dovete fare
      	print_path(Path,8); 
    	}
  	else
    cout<<"nessun cammino"<<endl;
}
