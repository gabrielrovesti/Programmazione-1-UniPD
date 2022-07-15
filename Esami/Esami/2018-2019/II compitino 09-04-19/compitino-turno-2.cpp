#include<iostream>
using namespace std;

	   
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
   cin >>hf;

// ciclo di esame dell’H-fetta hf da fare
    	
  cout<<"end"<<endl;
     
}
