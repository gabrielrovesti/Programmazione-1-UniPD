#include <iostream>

using namespace std;

int main(){

	cout<<"start"<<endl;

	int matrice[6][6]= {
			{6,  32, 3,   34,  35,  1},
			{7,  11, 27,  28,  8,  30},
			{19, 14, 16,  15,  23, 24},
			{18, 20, 22,  21,  17, 13},
			{25, 29, 10,  9,   26, 12},
			{36, 5,  33,  4,   2,  31},
	};
	int i=0,j=0, sommaDiagonalePrimaria=0,sommaDiagonaleSecondaria=0,parzialeRiga=0,parzialeColonna=0;
	bool sommeUguali=true;
//
//	for (i = 0; i < 6; i++)
//		for(j=0; j<6;j++)
//			cin>>matrice[i][j];
//


	int costanteDelQuadrato=0;
	for(i=0; i<6;i++)
		costanteDelQuadrato+=matrice[0][i];


	cout<<"costante: "<<costanteDelQuadrato<<endl;

	for(i=0; i<6&& sommeUguali; i++){
		for(j=0; j<6;j++){
			parzialeColonna+=matrice[j][i];
			parzialeRiga+=matrice[i][j];
			if(i==j){
				sommaDiagonalePrimaria+=matrice[i][j];
			}

			if((i+j)==5)
				sommaDiagonaleSecondaria+=matrice[i][j];
		}
		cout<<i<<" Riga: "<<parzialeRiga<<endl;
		cout<<i<<" Colonna: "<<parzialeColonna<<endl;

		if(!(costanteDelQuadrato==parzialeColonna&& costanteDelQuadrato==parzialeRiga)){
			sommeUguali=false;
		}
		parzialeColonna=0;
		parzialeRiga=0;


	}
	cout<<"Diagonale Primaria: "<<sommaDiagonalePrimaria<<endl;
	cout<<"Diagonale secondaria: "<<sommaDiagonaleSecondaria<<endl;
	if(sommeUguali  && costanteDelQuadrato==sommaDiagonalePrimaria && costanteDelQuadrato==sommaDiagonaleSecondaria){
		cout<<costanteDelQuadrato<<endl;
	}else{
		cout<<"Non e' un quadrato magico"<<endl;
	}


	cout<<"end"<<endl;

}
