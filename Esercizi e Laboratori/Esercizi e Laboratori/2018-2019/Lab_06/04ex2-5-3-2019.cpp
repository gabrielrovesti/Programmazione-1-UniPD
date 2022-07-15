#include<iostream>
using namespace std;
int main()
{
  int n, a[100];
  cin>>n;
  for(int i=0; i<n; i++)
    cin >> a[i];
  cout<<"start"<<endl;
  int count[10]={0};
  //PRE: 0<=a[i]<10
  for(int i=0;i<n;i++) //R1: 0<=i<n && count[a[i]] contiene il numero delle ripetizioni di a[i] fino ad a[i-1]
    count[a[i]]++;
  //POST1: count è valorizzato con il numero delle ripetizioni di ogni cifra da 0 a 9

  int max=0;
  for(int i=0;i<10;i++) //R2: 0<=i<=10 && max contiene il valore massimo di count fino a count[i-1]
    if(count[i]>max)
      max=count[i];
  //POST2: max contiene il valore massimo del vettore count

  for(int i=max;i>0;i--){ //R3: 0<=i<=max && stampate max-i righe
    for(int k=0;k<10;k++) //R4: 0<=k<=10 && stampati k caratteri della riga
      if(count[k]>=i)
        cout<<"*";
      else
        cout<<" ";
    //POST4: stampata 1 riga
    cout<<endl;
  }
  //POST3: stampate max righe
  for(int i=0;i<10;i++)
    cout<<i;
  cout<<endl<<"end"<<endl;
  return 0;
}