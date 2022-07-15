
//soluzione by: Nicolò S.

#include<iostream>
#include<climits>
#include<fstream>
using namespace std;
struct M {int lung, inizioP, inizioT; M(int a=0, int b=0, int c=0){lung=a; inizioP=b; inizioT=c;}};

int calcola_lung(int *T,int *P, int dimP, int indiceT, int i, int dim)
{
	if (indiceT==dim)
		return 0;
	
	if (i==dimP) 
		return 0;

	if (T[indiceT]==P[i])
		return 1+calcola_lung(T,P,dimP, indiceT+1, i+1,dim);

return 0;
}


M temp_match(int *T, int *P, int dimP, int i, int indiceT, int dim)
{
M var=(0,-1,-1);

	if (i==dimP)
		return var;

	M bestm=temp_match(T,P,dimP,i+1,indiceT,dim);

	int lung_match=calcola_lung(T,P,dimP,indiceT,i,dim);

	if (lung_match>=bestm.lung && lung_match)
		{
			var.lung=lung_match;
			var.inizioP=i;
			var.inizioT=indiceT; 
			return var;
		}

return bestm;
}

M match(int *T, int dim, int *P, int dimP, int indiceT)
{
M var(0,-1,-1);

	if (indiceT==dim) 
		return var;


	M max=match(T,dim,P,dimP,indiceT+1); 

	M temp=temp_match(T,P,dimP,0,indiceT,dim);

	if (temp.lung>max.lung)
		max=temp;
	else
		if (temp.lung==max.lung && temp.inizioP<max.inizioP)
			max=temp;

return max;
}


main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int T[200], P[20], dim, dimP;
   IN>>dim;
   for(int i=0; i<dim;i++)
     IN>>T[i];
   IN>>dimP;
   for(int i=0; i<dimP;i++)
     IN>>P[i];
   M x=match(T,dim, P, dimP, 0);// funzione ricorsiva da fare
   OUT<<"[lung="<<x.lung<<" inizioP="<<x.inizioP<<" inizioT="<<x.inizioT<<']'<<endl; // e' l'occasione di ridefinire << per M
    
   IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
 }
