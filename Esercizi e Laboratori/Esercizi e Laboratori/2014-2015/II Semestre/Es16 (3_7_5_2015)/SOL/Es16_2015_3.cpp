
//soluzione by: Matteo F.

#include<iostream>
#include<fstream>
using namespace std;

void stampa(int x[], int dim, ofstream &out){
	if (dim>15){
		for (int r=0; r<4; r++){
			for (int c=0; c<4; c++)
				out<<x[r*4+c]<<" ";
			out<<endl;
		}
		stampa (x+16, dim-16, out);
	}
	else{
		int cp=dim/4, col=cp;
		if (dim%4!=0)
			col++;
		int righe=dim%4;
		if (cp!=0){
			for (int r=0; r<righe; r++){
				for (int c=0; c<col; c++)
					out<<x[r*4+c]<<" ";
				out<<endl;
			}
			for (int r=righe; r<4; r++){
				for (int c=0; c<cp; c++)
					out<<x[r*4+c]<<" ";
				out<<endl;
			}
		}
		else{
			for (int r=0; r<righe; r++)
				out<<x[r*4]<<endl;
		}
	}
}

int compatta(int x[], int dim, int z, int fino, int cur){
	if (cur!=dim){
		int indice=4*fino+cur/4;
		if (x[indice]==z){
			int i=indice, sc=cur/4, s;
			for (int a=0; a<dim-cur-1; a++){
				s=indice/16;
				if (indice==15 || indice==31){
					if (indice==15)
						i=16;
					else
						i=32;
				}
				else{
					i+=4;
					if (i/4>=(4+4*s)){
						sc++;
						if (sc==4 || sc==19){
							if (sc==4)
								sc=17;
							else
								sc=33;
						}
						i=sc;
					}
				}
				x[indice]=x[i];
				indice=i;
			}
			cur=compatta(x, dim-1, z, fino, cur);
		}
		else{
			fino++;
			if (fino==4)
				fino=0;
			cur=compatta(x, dim, z, fino, cur+1);
		}	
	}
	return cur;
}

int main(){
	ifstream IN("input");
	ofstream OUT("output");
	if(IN && OUT){ 
	int T[3][4][4], dim,z, *x=**T;
	IN>>dim;
	int count=dim;
	for(int i=0; i<3 && count>0;i++)
		for(int  j=0; j<4&&count>0;j++)
			for(int k=0;k<4&&count>0;k++){
				IN>>T[i][k][j];
				count--;
			}
	IN>>z;
	stampa(x,dim,OUT);
	int ne=compatta(x,dim,z,0,0);
	stampa(x,ne,OUT);
	OUT<<"fine"<<endl;
	IN.close(); OUT.close(); 
	}
	else
		cout<<"errore con i files";
}
