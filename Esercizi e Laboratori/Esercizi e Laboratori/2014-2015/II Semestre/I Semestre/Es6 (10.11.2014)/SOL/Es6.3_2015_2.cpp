
//soluzione by: Leo M.

#include<iostream>
using namespace std;

int main()
{	//PRE
	int T[10][5], P[10];	//10 righe - 5 colonne
	int rigT, colT, colTplus, dimT, dimP;
	cin >> dimT >> dimP;
	
	colTplus=dimT%5;		//numero di colonne che hanno un elemento in più
	if(colTplus)
		rigT=dimT/5+1;		//ci sono elementi/5 righe se il numero degli elementi è divisibile per 5
	else
		rigT=dimT/5;		//sennò ce n'è una in più (non piena del tutto che ha esattamente colTplus elementi definiti)
	if(dimT<5)
		colT=colTplus;		//se ci sono meno di 5 elementi totali le colonne sono esattamente colTplus ed ognuna da 1 elemento
	else
		colT=5;				//altrimenti le colonne sono sempre 5 (possibilmente lunghe e corte o solo corte).


	int t_col=0, t_rig=0;						//indici per scorrere la matrice T
	while(t_rig<rigT)							//riempio T[0..rigT-1][0..colT-1]
	{
		t_col=0;								//reset indice dell'elemento della riga
		if(rigT==dimT/5+1 && t_rig==rigT-1)		//se esiste l'ultima riga incompleta e ci sono arrivato devo inservici solo colTplus elementi
			while(t_col<colTplus)
			{
				cin >> T[t_rig][t_col];
				t_col++;
			}
		else									//altrimenti continuo come se nulla fosse ad inserire i miei elementi
			while(t_col<colT)
			{
				cin >> T[t_rig][t_col];
				t_col++;
			}
		t_rig++;
	}
	
	int p=0;			//indice per scorrere P
	while(p<dimP)		//riempio P[0..dimP-1]
	{
		cin >> P[p];
		p++;
	}
	
/*
//ciclo che stampa la matrice T con la giusta formattazione, utile per il debug
	cout<<endl<<"Matrice T con: "<<rigT<<" righe e "<<colT<<" colonne."<<endl;
	t_col=0, t_rig=0;					//reset indici per scorrere la matrice T
	while(t_rig<rigT)					//stampo T[0..rigT-1][0..colT-1]
	{
		t_col=0;								//reset indice dell'elemento della riga
		if(rigT==dimT/5+1 && t_rig==rigT-1)		//se esiste l'ultima riga incompleta e ci sono arrivato devo stampare solo colTplus elementi
			while(t_col<colTplus)
			{
				cout << T[t_rig][t_col] << " ";
				t_col++;
			}
		else									//altrimenti continuo come se nulla fosse a stampare i miei elementi
			while(t_col<colT)
			{
				cout << T[t_rig][t_col] << " ";
				t_col++;
			}
		cout<<endl;
		t_rig++;
	}
	cout<<endl;
	
//ciclo che stampa l'array P, utile per il debug
	cout<<endl<<"Array P da: "<<dimP<<" elementi."<<endl;
	p=0;				//reset indice per scorrere P
	while(p<dimP)		//stampo P[0..dimP-1]
	{
		cout << P[p] << " ";
		p++;
	}
	cout<<endl<<endl;;
*/

	t_col=0;								//reset indice per le colonne di T
	int nMatch=0, posiz=-1;
	while(t_col<colT)						//seleziono una ad una le colonne di T
	{
		t_rig=0;							//reset indice per le righe di T
		int tempMatch=0;					//variabile ausiliaria
		if(t_col<colTplus)					//"colTplus && t_col<colTplus" -> se esistono colonne lunghe e quella selezionata lo è, semplificabile in "t_col<colTplus"
			while(t_rig<=rigT-dimP)
			{
				p=0;						//reset indice p per scorrere P
				while(p<dimP && T[p+t_rig][t_col]==P[p])
					{
						p++;
					}
				if(p==dimP)					//è sufficiente perchè p raggiungerà dimP solo se ci sono dimP elementi che matchano
					tempMatch++;
				t_rig++;
			}
		else								//sennò è una di quelle corte
			{
				if(colTplus>0)				//colonna corta ma esistono anche colonne lunghe (rigT=dimT/5+1)
					while(t_rig<=rigT-1-dimP)
					{
						p=0;				//reset indice p per scorrere P
						while(p<dimP && T[p+t_rig][t_col]==P[p])
						{
							p++;
						}
						if(p==dimP)
							tempMatch++;
						t_rig++;
					}
				else						//colonna corta e NON esistono colonne lunghe (rigT=dimT/5)
					while(t_rig<=rigT-dimP)
					{
						p=0;				//reset indice p per scorrere P
						while(p<dimP && T[p+t_rig][t_col]==P[p])
						{
							p++;
						}
						if(p==dimP)
							tempMatch++;
						t_rig++;
					}
			}
		
		if(tempMatch>nMatch)
			{
				nMatch=tempMatch;
				posiz=t_col;
			}
			
		t_col++;
	}

	if(posiz==-1)
		cout<<"Nessuna colonna contiene match."<<endl;
	else
		cout<<nMatch<<" nella colonna "<<posiz<<" di T."<<endl;

}	//POST



/*
PRE=().

R=().

R1=().

POST=().
*/
