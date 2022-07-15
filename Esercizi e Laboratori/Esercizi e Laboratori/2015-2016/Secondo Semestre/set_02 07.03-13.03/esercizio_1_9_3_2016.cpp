//sol by Rando
//stampa di H o V fetta di un torta-array completo

#include <iostream>
#include <fstream>
using namespace std;

main(){

ifstream in("input");
ofstream out("output");
if(in&&out)
{
	int X[2][4][5];
	
	//input
	for(int a=0;a<2;a++){
		for(int b=0;b<4;b++){
			for(int c=0;c<5;c++){
				in>>X[a][b][c];
			}
		}
	}
	
	// ch: 'H' o 'V'
	char ch; in>>ch;
	int val; in>>val;
	
	if(ch=='H')
	{
		
		//R: 0<=a<=2 && stampati strati 0..a-1
		for(int a=0; a<2; a++){
			out<<endl;
			//R: 0<=c<=5 && stampati elem riga da 0..c-1
			for(int c=0; c<5; c++){
				out<< X[a][val][c] <<' ';
			}
		}
	
	}
	
	if(ch=='V')
	{
		//R: 0<=a<=2 && stampati strati 0..a-1
		for(int a=0; a<2; a++){
			out<<endl;
			//R: 0<=b<=4 && stampati el colonna da 0..b-1
			for(int b=0; b<4; b++){
				out<< X[a][b][val] <<' ';
			}
		}
	
	}
	
}

else cout<<"errore con i files\n";

}//END

