
//soluzione by: Leo M.

#include<iostream>
#include<fstream>

using namespace std;



main()
{	//PRE=("input" contiene: i 4 interi str>0, rig>0, col>0 ed 0<n_el<=400, seguiti da n_el interi).
	ifstream INP("input");
	ofstream OUT("output");
	if(INP && OUT)
	{
		int str, rig, col, n_el;
		INP >> str >> rig >> col >> n_el;
		int X[400]; //Y[str][rig][col]
		
		//formatto tutti gli elem dell'array con il valore "-1"
		for(int i=0; i<400; i++)
			X[i]=-1;
		
		//metto in X gli n_el elementi da "input"
		for(int count=n_el, i=0; i<col && count; i++)	//scorro V-Fette
			for(int j=0; j<str && count; j++)	//scorro strati
				for(int k=0; k<rig && count; k++)	//scorro elementi della colonna
				{
					INP >> *( X+k*col + j*rig*col + i);
					count--;
				}
		
		//stampo TUTTO X (compresi i -1) su "output" per strati (ed ogni strato per riga)
		for(int i=0; i<str; i++)
		{
			OUT<<"strato "<<i<<endl;
			for(int j=0; j<rig; j++)
			{
				for(int k=0; k<col; k++)
					OUT<<*(X+k+j*col+i*rig*col)<<" ";
				OUT<<endl;
			}
		}
		
		//stampo la stringa "fine"
		OUT<<"fine"<<endl;
		
		INP.close();
		OUT.close();
	}
	else
		cerr<<"Errore File!"<<endl;
}	//POST=(Y viene riempito completamentemente prima con "-1" e poi con gli n_el elementi per Vfette; poi Y viene stampato su "output" per strati (e righe)).

