// sol by Rando
/* 
Stampa di H o V fetta di un torta-array non pieno

NB: File` suggerisce una soluzione diversa, che fa uso di:

nsp: #numero strati pieni
eus: #elem ultimo strato
nrpus: #righe piene ultimo strato
eur: # elementi ultima riga

e arriva alla soluzione considerando tutti i sottocasi.
*/



#include <iostream>
#include <fstream>
using namespace std;

main(){

ifstream in("input");
ofstream out("output");

if(in&&out)
{
	int X[2][4][5];
	int nel; in>>nel;
	
	//input
	
	int *p=&X[0][0][0];
	for(int i=0; i<nel; i++)
		in>>p[i];
	
	// ch: 'H' o 'V'
	char ch; in>>ch;
	int val; in>>val;
	bool exit= false;
	// a*(b*c) == # strati pieni
	// b*c== # righe piene
	// c= # el ultima riga
	
	if(ch=='H')
	{
		
		int b=val;
		//R: 0<=a<=2 && stampati strati 0..a-1
		for(int a=0; a<2 && exit==false; a++){
			out<<endl;
			//R: 0<=c<=5 && x<=nel && stampati elem riga da 0..c-1
			// if x==nel esci
			for(int c=0; c<5 && exit==false; c++)
			{
				if(a==0 && c==0 && a*(4*5) + b*5 + c >= nel)
				{
					out<<"H fetta "<<b<<" vuota\n";
					exit=true;
				}
				if(a*(4*5) + b*5 + c < nel)
					out<< X[a][b][c] <<' ';
				
			}
		}
	
	}
	
	
	//pongo a*(4*5) + b*5 + c = x
	
	if(ch=='V')
	{
		int c=val;
		//R: 0<=a<=2 && stampati strati 0..a-1
		for(int a=0; a<2 && exit==false; a++){
			out<<endl;
			//R: 0<=b<=4 && x<=nel && stampati el colonna da 0..b-1
			// if x==nel esci
			for(int b=0; b<4 && exit==false; b++)
			{
				if(a==0 && b==0 && a*(4*5) + b*5 + c >= nel) 
				{
					out<<"V fetta "<<c<<" vuota\n";
					exit=true;
				}
				if(a*(4*5) + b*5 + c < nel)
					out<< X[a][b][c] <<' ';
				
			}
		}
	
	}
	
}

else cout<<"errore con i files\n";

}//END

