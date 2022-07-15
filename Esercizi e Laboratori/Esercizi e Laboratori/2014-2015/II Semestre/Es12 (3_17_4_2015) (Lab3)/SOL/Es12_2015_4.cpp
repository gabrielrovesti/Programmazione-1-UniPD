
//soluzione by: Robertino B.

#include<iostream>
#include<fstream>
using namespace std;
// PRE riceve il numero della f-fetta e la r riga per determinare gli elementi definiti della v-fetta di r
int El_Def(int fetta,int r,int lim2,int lim3,int n_el)
{
int conta=0, i=0,el;bool fine=true;
while (fine)
{
el=r*lim3+fetta+i*lim2*lim3;

i++;
if (el>=n_el)
fine= false;
else
conta++;

}
return conta;
}
// POST restituisce il nuneri degli elementi definiti della v-fetta di r partendo dalla f-fetta

// PRE calcola_dist riceve il numero della f-fetta da esaminare e il valore e1.e2..e3 per calcolare da distanza dall'inizio di y
// inoltre riceve:
// lim2 utile per scorrere le r righie 
//ricevere lim3 per calcolare la "posizione" in X
// n_el utile per verificare che si è andati oltre gli elementi definiti
int calcola_dist(int fetta,int e,int lim2,int lim3,int n_el)
{
int pos=-1,cont=0;
bool fine=false;
if (fetta<lim3)
{
for (int r=0;fine ==false && r<lim2;r++) //R1
{ 
int conta=El_Def(fetta,r,lim2,lim3,n_el);//R2
for (int i=0;fine == false && i<conta;i++) 
{ 
if (cont==e)
{
if (pos>n_el)
pos=-1;
else
pos=r*lim3+fetta+i*lim2*lim3;
fine=true;cont=0;
}

cont++;
} //R2 && (fine=true & i>=conta)
}// R1 && (fine=true && r>=lim2)
}

return pos;
//R1 (0<r<lim2 && fine=false ) scorre le r Righe sino a che r è minore uguale a lim2 (numero righe array)
// o sino a che fine=true. Fine diviene true quanto ho contato tanti 'e' elementi dei tasselli 

// R2 (0<i<conta && fine==false) leggo i 0.1....conta elementi dei tasselli V-fetta (fetta). 
// Fine diviene true quanto ho contato tanti 'e' elementi dei tasselli
}

// POST restituisce la distanza tra l'inizio di Y e l'emenento 'e' Nel caso l'elemento 'e' si trova in una posizione >n_el restituisce -1
main()
{
ifstream IN("input");
ofstream OUT("output");
if(IN && OUT) 
{ 
int X[400],P[50], n_el, dimP, lim1,lim2,lim3;
for(int i=0; i<400;i++)
X[i]=-1;
IN>>lim1>>lim2>>lim3;
IN>>n_el;
for(int i=0; i<n_el; i++)
IN >> X[i];
if(n_el>lim1*lim2*lim3)
n_el=lim1*lim2*lim3;
for(int q=0; q<3; q++)//legge le tre quadruple
{
int f, e[3];
IN>>f>>e[0]>>e[1]>>e[2];

for(int j=0;j<3;j++)
{
int d=calcola_dist(f,e[j],lim2,lim3,n_el); // questa e' da fare (restituisce -1 a indicare che l'elemento e[j] non c'e' nella V-fetta f)

if(d==-1)
OUT<<e[j]<<" elemento inesistente della V-fetta "<<f<<' '; 
else
OUT<<d<<' ';
}
OUT<<endl;
}



IN.close(); OUT.close(); 
}
else
cout<<"errore con i files";
}
