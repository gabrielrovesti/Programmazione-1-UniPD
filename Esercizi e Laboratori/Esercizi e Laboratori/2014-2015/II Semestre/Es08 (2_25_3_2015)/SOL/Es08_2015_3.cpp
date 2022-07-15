
//soluzione by: Nicolò S.

#include<iostream>
#include<fstream>
using namespace std;

main()
{
  int X[400], lim1,lim2,lim3,n_el;
  ifstream IN("input");
  ofstream OUT("output");
  IN>>lim1>>lim2>>lim3>>n_el;
  int y_it,y_el=lim1*lim2*lim3,y_fetta=0;

  while (y_fetta<lim3)
    {
      y_it=y_fetta;
      while (y_it<y_el)
        {
          IN>>X[y_it];
          y_it+=lim3;
        }
      y_fetta++;
    }
  IN.close();

  int c=0,s=0,r=0;

  while (s<lim1)
    {
      r=0;
      OUT <<"strato "<<s<<endl;
      while (r<lim2)
        {
          c=0;
          while (c<lim3)
            {
              if ((r+s*lim2+c*(lim1*lim2))<n_el) //indice di inserimento dell'elemento secondo la politica a "V-fette"
                OUT <<X[s*lim2*lim3+r*lim3+c]<<" "; //coordinate dell'elemento nella forma (fetta (s),riga (r), colonna (c))
              c++;
            }
          OUT <<endl;
          r++;
        }
      s++;
    }
  OUT<<"fine"<<endl;
  OUT.close();
}
