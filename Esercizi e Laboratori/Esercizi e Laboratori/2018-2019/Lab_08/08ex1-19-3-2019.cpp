#include<iostream>
using namespace std;
//PRE=(n>0 e A[0..(n-1)*step] è definito)
int colonna(int* A,int n, int step){
    int vSomma=0;
    for(int i=0;i<n;i++) //R: 0<=i<=n && vSomma=A[0]+A[step]+..A[(i-1)*step]
        vSomma+=A[i*step];
    return vSomma;
}
//POST=(restituisce il valore di A[0]+A[step]+A[2*step]+A[3*step]+...+A[(n-1)*step])
/*Dimostrazione funzione colonna
1) i=0 && vSomma=0 (insieme nullo)
2) 0<i<n && vSomma=A[0]+A[step]+..A[(i-1)*step]
3) i>=n => vSomma=A[0]+A[step]+...+A[(n-1)*step]
*/
//PRE=(cin contiene n_ele, 0<n_ele<=400, seguito da n_ele interi qualsiasi)
main()
{
  int A[10][5][8], *p=A[0][0];
  int n_ele;
  cin>>n_ele;
  for(int i=0; i<n_ele; i++)
    cin>>p[i];
  
  cout<<"start"<<endl;
  int resto=n_ele%8;
  int n=n_ele/8;
  if(resto>0)
    n++;
  int bestfetta=0;
  int bestvalue=colonna(*A[0],n,8);
  for(int i=1;i<8;i++){
      n=n_ele/8;
      if(i<resto)
        n++;
      int valueI=colonna(*A[0]+i,n,8);
      if(valueI>=bestvalue){
          bestvalue=valueI;
          bestfetta=i;
      }
  }
  cout<<"V-fetta massima= "<<bestfetta<<" con somma= "<<bestvalue<<endl;
  cout<<"end"<<endl;
}
//POST=(stampa l'indice della V-fetta a somma massima seguito dalla sua somma e in caso di parità, stampa l'indice massimo)

