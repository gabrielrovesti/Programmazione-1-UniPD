#include<iostream>
using namespace std;
int main()
{
  int n, a[100];
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> a[i];
  cout<<"start"<<endl;
  bool palindromo=true;
  int i;
  //PRE: a[0..n-1] contiene valori interi letti da cin
  for(i=0; i<n/2 && palindromo; i++) //R: 0<=i<=n/2 && palindromo sse a[0...i-1]==array[n-1..n-i]
      if(a[i]!=a[n-1-i])
        palindromo=false;
  //POST: palindromo sse a[0...n-1]==a[n-1...0]
  i--;
  if(palindromo)
    cout<<"A è un palindromo"<<endl;
  else
    cout<<"A non è un palindromo e la prima contraddizione riguarda gli elementi di indice "<<i<<" e "<<n-1-i<<endl;
  cout<<"end"<<endl;
  return 0;
}
/*Dimostrazione ciclo
1)i=0 palindromo=true => a[0..i-1](insieme vuoto)==a[n-1..n-i](insieme vuoto)
2)0<i<n/2 && palindromo sse a[0...i-1]==array[n-1..n-i]
3)(i>=n/2 || !palindromo) => POST
  a) !palindromo sse a[0..n-1]!=a[n-1..0]
  b) i>=n/2 => palindromo=true => a[0..n-1]==a[n-1..0]*/