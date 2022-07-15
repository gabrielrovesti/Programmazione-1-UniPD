
//soluzione by: Leo M.

#include<iostream>
#include<fstream>

using namespace std;

main()
{	//PRE=("input" contiene 14 interi per inizializzare B)
	ifstream INP("input.txt");
	ofstream OUT("output.txt");
	if(INP && OUT)
	{
		int B[2][7];
		
		//riempie B da "input"
		for(int i=0; i<2; i++)
			for(int j=0; j<7; j++)
				INP>>B[i][j];
		
		//stampa B su "output"
		for(int i=6; i>=0; i--)
			OUT<<B[0][i]<<" ";
		for(int j=0; j<7; j++)
			OUT<<B[1][j]<<" ";
					
		//stampa B "formattato" su cout
		cout<<"       5    4    3    2    1    0"<<endl;
		cout<<"     ";
		for(int i=5; i>=0; i--)
		{
			if(B[0][i]<10)
				cout<<"|"<<" "<<B[0][i]<<"|"<<" ";
			else
				cout<<"|"<<B[0][i]<<"|"<<" ";
		}
		cout<<endl;
		cout<<"tot"<<endl;
		if(B[0][6]<10)
			cout<<" "<<B[0][6];
		else
			cout<<B[0][6];
		cout<<" --------------------------------- ";
		if(B[1][6]<10)
			cout<<" "<<B[1][6]<<endl;
		else
			cout<<B[1][6]<<endl;
		cout<<"                                     "<<"tot"<<endl;
		cout<<"     ";
		for(int i=0; i<6; i++)
		{
			if(B[1][i]<10)
				cout<<"|"<<" "<<B[1][i]<<"|"<<" ";
			else
				cout<<"|"<<B[1][i]<<"|"<<" ";
		}
		cout<<endl;
		cout<<"       0    1    2    3    4    5"<<endl;
		
		INP.close();
		OUT.close();
	}
	else
		cerr<<"Errore File!"<<endl;
}	/*POST=(
		i) stampare su cout una rappresentazione della situazione rappresentata da B che assomiglia (più che riuscite usando istruzione semplici) al disegno della piattaforma mostrato prima;
		ii) stampare su un file "output" solo i 14 valori di B nello stesso ordine richiesto per (i) e cioè, prima i dati del player 0, in ordine dalla buca grande alla buca piccola di numero 0 e poi i dati del player 1 in ordine dalla buca piccola 0 alla buca grande.*/
