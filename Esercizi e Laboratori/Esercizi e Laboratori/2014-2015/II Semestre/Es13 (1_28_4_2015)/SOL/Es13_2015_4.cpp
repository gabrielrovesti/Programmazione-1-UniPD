
//soluzione by: Nicolò S.

// Versione 1:
#include <iostream>
#include <fstream>
using namespace std;
 
void stampa(int i, int count_match, ofstream &OUT){
        OUT<< "match n."<<count_match<<" a partire dalla posizione "<< i<< endl;
}
 
bool verifica_match(int *X, int *P, int dimP){
                if (dimP==0)
                        return true;
                else{
                        if(X[0]==P[0])
                                verifica_match(X+1, P+1, dimP-1);
                        else
                                return false;  
                }
}
 
void match(int *X, int*P, int n_el, int dimP, int i, int count_match, ofstream & OUT) {
// i conta posizione in cui mi trovo. count_match il numero di match trovati.
        if(n_el-i < dimP  or dimP==0)
                return;
        else{
                if(X[0] == P[0]) {
                        bool ok;
                        ok=verifica_match(X+1, P+1, dimP-1);
                       
                        if(ok){
                                stampa(i, count_match, OUT);
                                match( X+1, P, n_el, dimP, i+1, count_match+1, OUT);
                        }
                        else
                               match( X+1, P, n_el, dimP, i+1, count_match, OUT);
                }
                else
                        match( X+1, P, n_el, dimP, i+1, count_match, OUT);
        }
}
 
 
 
 
main()
 
{
ifstream IN("input");
ofstream OUT("output");
   
        if(IN && OUT){
                int X[400];
                int P[20];
                int  n_el, dimP;
               
                for(int i=0; i < 400 ; ++i)
                        *(X+i)= 0;
       
                for(int i=0 ; i<dimP ; ++i)
                        *(P+i)= 0 ;
                       
                IN>> n_el;     
                for(int i=0 ; i<n_el ; ++i)
                        IN >>*(X+i);
               
                IN>> dimP;
                for(int i=0 ; i<dimP ; ++i)
                        IN >> *(P+i);
                       
                int i=0, count_match=1;
                match (X, P, n_el, dimP, i, count_match,OUT);
                OUT<< "fine";
       
        }
        else
                OUT<< "errore con i files" <<endl;
}





/* Versione 2:
#include <iostream>
#include <fstream>
using namespace std;
 
void stampa(int i, int count_match, ofstream &OUT){
        OUT<< "match n."<<count_match<<" a partire dalla posizione "<< i<< endl;
}
 
bool verifica_match(int *X, int *P, int dimP){
                if (dimP==0)
                        return true;
                else{
                        if(X[0]==P[0])
                                verifica_match(X+1, P+1, dimP-1);
                        else
                                return false;  
                }
}
 
void match(int *X, int*P, int n_el, int dimP, int i, int count_match, ofstream & OUT) {
// i conta posizione in cui mi trovo. count_match il numero di match trovati.
		bool ok=false;
        if(n_el-i < dimP  or dimP==0)
                return;
        else{
                if(X[0] == P[0]) {
                        ok=verifica_match(X+1, P+1, dimP-1);
                       
                        if(ok){
                                stampa(i, count_match, OUT);
                                match( X+1, P, n_el, dimP, i+1, count_match+1, OUT);
                        }
                }
                if(!ok)
                match( X+1, P, n_el, dimP, i+1, count_match, OUT);
        }
}
 
 
 
 
main()
 
{
ifstream IN("input");
ofstream OUT("output");
   
        if(IN && OUT){
                int X[400];
                int P[20];
                int  n_el, dimP;
               
                for(int i=0; i < 400 ; ++i)
                        *(X+i)= 0;
       
                for(int i=0 ; i<dimP ; ++i)
                        *(P+i)= 0 ;
                       
                IN>> n_el;     
                for(int i=0 ; i<n_el ; ++i)
                        IN >>*(X+i);
               
                IN>> dimP;
                for(int i=0 ; i<dimP ; ++i)
                        IN >> *(P+i);
                       
                int i=0, count_match=1;
                match (X, P, n_el, dimP, i, count_match,OUT);
                OUT<< "fine";
       
        }
        else
                OUT<< "errore con i files" <<endl;
}
*/



/* Versione 3:
#include <iostream>
#include <fstream>
using namespace std;
 
void stampa(int i, int count_match, ofstream &OUT){
        OUT<< "match n."<<count_match<<" a partire dalla posizione "<< i<< endl;
}
 
bool verifica_match(int *X, int *P, int dimP){
                if (dimP==0)
                        return true;
                else{
                        if(X[0]==P[0])
                                verifica_match(X+1, P+1, dimP-1);
                        else
                                return false;  
                }
}
 
void match(int *X, int*P, int n_el, int dimP, int i, int count_match, ofstream & OUT) {
// i conta posizione in cui mi trovo. count_match il numero di match trovati.
		bool ok=false;
        if(n_el-i < dimP  or dimP==0)
                return;
        else{
                if(X[0] == P[0])
                        ok=verifica_match(X+1, P+1, dimP-1);
                       
                if(ok){
                        stampa(i, count_match, OUT);
                    	match( X+1, P, n_el, dimP, i+1, count_match+1, OUT);
                }
                else
                	match( X+1, P, n_el, dimP, i+1, count_match, OUT);
        }
}
 
 
 
 
main()
 
{
ifstream IN("input");
ofstream OUT("output");
   
        if(IN && OUT){
                int X[400];
                int P[20];
                int  n_el, dimP;
               
                for(int i=0; i < 400 ; ++i)
                        *(X+i)= 0;
       
                for(int i=0 ; i<dimP ; ++i)
                        *(P+i)= 0 ;
                       
                IN>> n_el;     
                for(int i=0 ; i<n_el ; ++i)
                        IN >>*(X+i);
               
                IN>> dimP;
                for(int i=0 ; i<dimP ; ++i)
                        IN >> *(P+i);
                       
                int i=0, count_match=1;
                match (X, P, n_el, dimP, i, count_match,OUT);
                OUT<< "fine";
       
        }
        else
                OUT<< "errore con i files" <<endl;
}
*/
