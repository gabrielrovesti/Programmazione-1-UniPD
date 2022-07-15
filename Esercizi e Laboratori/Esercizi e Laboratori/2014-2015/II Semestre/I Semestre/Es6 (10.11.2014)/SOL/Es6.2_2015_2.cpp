
//soluzione by: Leo M.

#include<iostream>
using namespace std;

int main()
{	//PRE
	int T[3][2], P[3];
	const int rigT=3, colT=2, dimT=rigT*colT, dimP=3;

	int t_col=0, t_rig=0;				//indici per scorrere la matrice T
	while(t_rig<rigT)					//riempio T[0..rigT-1][0..colT-1]
	{
		t_col=0;						//reset indice dell'elemento della riga
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
		t_col=0;						//reset indice dell'elemento della riga
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

	t_col=0;						//reset indice per le colonne di T
	int tempMIS, bestMIS=dimP, posiz=-1;
	while(t_col<colT)		//R		//seleziono una a una le colonne di T
	{
		t_rig=0;					//reset indice per le righe di T
		p=0;						//reset indice p per scorrere P
		tempMIS=0;					//reset contatore ausiliario per ogni singola colonna
		while(t_rig<rigT)	//R1
		{
			if(T[t_rig][t_col]!=P[t_rig])
				tempMIS++;
			t_rig++;
		}
		
		if(tempMIS<bestMIS)
			{
				posiz=t_col;
				bestMIS=tempMIS;
			}
			
		t_col++;
	}

	cout<<"La colonna "<<posiz<<" ha il minor numero di mis: "<<bestMIS<<"."<<endl;

}	//POST



/*
PRE=().

R=().

R1=().

POST=().
*/
