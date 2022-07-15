
//soluzione by: Nicolò S.

#include<iostream>
#include<fstream>
using namespace std;

void stampa (int c, int indice, ofstream &OUT)
    {OUT<< "H-fetta "<<c<<"="<<indice<<" match"<< endl;}

bool conta_lunghezza(int* A, int* P, int lim3, int i, int indice, int dimP){
    bool ok= true;
	for(int j=0; j<dimP  && ok; j++)
    {
		if((*(A+indice*lim3+j*lim3 )) !=P[j])
			ok=false;
    }
  return ok;
}


int cerca_su_riga(int* A, int* P, int lim1, int lim2, int lim3, int dimP, int indice_r){
    int n=0;
    for(int i=0; i < lim3*lim1  ; ++i){ // per ogni colonna della riga... vedo se c'e' il match
            if(*(A+indice_r*lim3+i) != -1){
				if(*(A+indice_r*lim3+i) == P[0]){
					if(conta_lunghezza(A,P,lim3,i,indice_r,dimP)){
						n++;
						i=i+dimP-1; // non proprio ortodosso ed etico
					}
				}
			}
    }
    return n;

}

void conta_match(int* A, int* P, int lim1, int lim2, int lim3, int dimP, ofstream &OUT){
    
    for(int ind_riga=0 ; ind_riga < lim2 ; ++ind_riga){
       int match_riga = cerca_su_riga(A,P,lim1,lim2,lim3,dimP,ind_riga); // scorre solo colonna di indice i;
       stampa(ind_riga,match_riga,OUT);
    }
}

main()
{
    ifstream IN("input");
    ofstream OUT("output");

    if(IN && OUT){
        int A[400];
        int P[50];
        for(int i=0; i < 400 ; ++i){
            *(A+i)=-1;
        }
        int lim1,lim2,lim3,n_l,dimP;
        IN >> lim1 >> lim2 >> lim3 >>n_l;
        for(int i=0 ; i<n_l ; ++i){
            int x;
            IN >> x;
            *(A+i)=x;
        }
		IN>> dimP;
        for(int i=0 ; i<dimP ; ++i){
            IN >> *(P+i);
        }
		if(n_l< lim2*lim3)
			lim2=(n_l/lim2) +1;
			
        conta_match(A,P,lim1,lim2,lim3,dimP,OUT);
    }
    else
		cout<<"errore con i files";

}
