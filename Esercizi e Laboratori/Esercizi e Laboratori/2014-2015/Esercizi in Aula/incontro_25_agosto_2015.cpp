//Secondo appello.14-7-15
0->1->0->1->0->1->0->0->1
//Prima funzione, ricorsiva.
void F0(nodo*L, bool & b){
	if(!L) b=false;
	else{
		F0(L->next,b);
		if(!b){
			if(L->info==0){
				L->info=1;
				b=true;
			}else L->info=0;
		}
	}
}
//Primo compitino
/* Abbiamo un array int A[400] che vogliamo vedere come X[lim1][lim2][lim3]
 * Ipotesi: X è sempre completamente pieno
 * 
 * Strato 0   Strato 1   Strato 2
 * 1 2|1 0|0  0 2|2 3|1  1 2|0 1|1 
 * 0 0|4 1|1  1 0|2 1|0  0 0|0 1|1
 * 1 1|0 1|0  2 1|2 2|0  1 2|3 1|2 
 * 1 2 3 2 2  2 2 1 2 1  5 1 2 0 0
 * 
 * Individuare il sotto-array che è caratterizzao dalla quadrupla (r, c , H , L) dove r e c sono le coordinate di inizio del sottoarray, H è l'altezza
 * e L è la sua larghezza. Il sottoarray attraversa tutti gli strati. Dobbiamo cercarne il pattern per V-fette(o H-fette).
 * prima V-fetta: 140 22|2| 003
 * seconda V-fetta 011 312 111
 * 
 * oppure
 * 
 * prima H-fetta 10 41 01
 * seconda H-fetta 23 21 22
 * terza H-fetta 01 01 31
 * 
 * È utile avere una funzione che dato un sotto-array (r,c,H,L) e dato un qualsiasi elemento, ci dica esattamente dove si trova l'elemento che cerchiamo in X
 * esempio: se voglio l'elemento di indice 5 rispetto l'ordine delle V-fette  sarà il 2. Quali sono le coordinate nel SOTTO-ARRAY? Strato 1, riga 2, colonna 0.
 * Con questa tripla riesco a trovare la tripla di coordinate in X. Strato=1, riga=2+r=2, colonna=0+c=2
 * Rispetto l'ordine delle H-fette invece abbiamo rispetto al sotto-array strato 0, riga 2, colonna 1.
 * Troviamo quindi la tripla di coordinate in X. Strato=0,riga=2+r=2,colonna 1+c=3.
 * Il prof consiglia che, indipendentemente dall'ordine nel quali è richiesto di trovare il sotto-array e il pattern, di fare sempre una funzione che
 * calcola la nuova tripla
 *  */

//definiamo la struttursa tripla
struct tripla{int prof,riga,colonna; tripla(int a=0,int b=0,int c=0){prof=a;riga=b;colonna=c}};

tripla calcola_dist(int H,int L,int e, int lim1){//e=indice visto per V-fette
	//V-fette
	int col=e/(H*lim1),rem=e%(H*lim1),prof=rem/H,rig=rem%H;
	return tripla(prof,riga,col);
}