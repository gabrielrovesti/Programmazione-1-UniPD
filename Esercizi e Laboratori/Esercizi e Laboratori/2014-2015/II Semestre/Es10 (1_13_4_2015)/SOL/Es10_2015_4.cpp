
//Soluzione by: Federico Bi.

#include <iostream>
#include <fstream>
using namespace std;
 
 
void scorr_fetta(int *px, int *pp, int lim1, int lim2, int lim3, int dimP, int *pm, int f, int nel)
{
       
        int *temp1=px;
        int *temp2=pp;
        for(int u=0; (u<lim2*lim1) && (lim3*u+f<nel); u++)
        {
               
                px= px+lim3*u;
               
                int v=0;
                for(; (*px==*pp)&& v<dimP ; v++)
                {
                        px=px+lim3;
                        pp=pp+1;
                       
                }
                if(v==dimP)
                {
                        *pm=*pm+1;
                        u=u+v-1;
                }
                px=temp1;
                pp=temp2;
        }
       
       
}
 
main(){
 
ifstream IN("input");
ofstream OUT("output");
int X[400]; for(int i=0; i<400; i++) X[i]=-1;
int P[50];
 
int lim1=0, lim2=0, lim3=0;
IN>>lim1 >>lim2 >>lim3;
 
int nel; IN>>nel;
for(int i=0; i<nel; i++)
{
        IN>> X[i];
       
}
 
 
int dimP; IN>>dimP; if(dimP>50) dimP=50;
for(int u=0; u<dimP; u++) {IN>>P[u];}
 
if(nel>lim1*lim2*lim3) nel=lim1*lim2*lim3;
 
for(int f=0; f<lim3 && f<nel; f++)
{
        int *px=&X[f], *pp=P;
        int M=0, *pm=&M;
       
        scorr_fetta(px, pp, lim1, lim2, lim3, dimP, pm, f, nel );
       
        OUT<<"V-fetta "<<f<<'='<<M<<" match\n";
       
}
 
IN.close(); OUT.close();
}
