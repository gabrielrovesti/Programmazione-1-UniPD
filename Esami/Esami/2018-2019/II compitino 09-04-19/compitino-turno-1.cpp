#include<iostream>
using namespace std;

//qualche funzione ausiliaria
	   
main()
{
  int X[400], P[20], n_ele, nP, lim1, lim2,lim3;
  cin >> n_ele;
  for(int i=0; i<n_ele; i++)
    cin >> X[i];
  cin >> lim1 >> lim2 >> lim3;
  if(lim1*lim2*lim3 < n_ele)
    n_ele=lim1*lim2*lim3;
  cin >> nP;
  for(int i=0; i<nP; i++)
    cin >> P[i];
  int nsp= n_ele/(lim2*lim3), eus= n_ele%(lim2*lim3), rpus= eus/lim3, ur= eus%lim3;
  cout<<"start"<<endl;
  int hf;
  cin >> hf; // fetta da trattare
  int lung; // lunghezza della H-fetta hf
  
  for(int j=0; j < lung; j++)
	{
	    //ciclo che trasforma la H-fetta hf
	}
	
  //stampa quello che resta di P e la H-fetta risultante
  
  // o  cout<<"pattern rimasto: "<<endl;
    
 // o    cout<<"pattern consumato tutto"<<endl;
    cout<<"la H-fetta "<<hf<<" e' diventata:"<<endl;
  stampa_fetta(........); // funzione che stampa la H-fetta hf modificata
  cout<<"end"<<endl;
}
