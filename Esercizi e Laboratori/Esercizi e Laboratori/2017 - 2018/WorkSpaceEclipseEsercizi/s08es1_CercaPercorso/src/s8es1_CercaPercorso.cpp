#include<iostream>
using namespace std;

bool partenza(bool*, int, int);
bool trova(bool* , int , int , int );
int main()
{
  int m;
  bool N[400];
  cin>>m;
  cout<<"start"<<endl;
  for(int i=0; i<m*m;i++)
    cin>>N[i];



  if(partenza(N,m, 0))

   cout<<"c'e' un cammino"<<endl;
  else
   cout<<"non c'e' un cammino"<<endl;
  cout<<"end"<<endl;
}

bool partenza(bool* N, int m, int j){


if(j==m ) return false;
if(trova(N,m,0,j))
return true;
else
return partenza (N+1,m,j+1);



}
bool trova(bool* N, int m, int j, int i) {

	if(! *N) return false;
	if(j == m-1) return true;

	bool risposta=false;

	if(*(N+m-1) && i-1 >0 )
		risposta= risposta || trova(N+m-1,m,j+1,i-1);
	else
		risposta= risposta  || false;

	if(*(N+m) && ! risposta)
		risposta= risposta || trova(N+m,m,j+1,i);

	else
		risposta= risposta  || false;


	if(*(N+m+1) && i+1 < m  && !risposta)
		risposta= risposta || trova (N+m+1,m,j+1,i+1);
	else
		risposta= risposta  || false;

	return risposta;

}
