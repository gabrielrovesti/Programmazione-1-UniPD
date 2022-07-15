
//soluzione by: Valentin G.

#include<iostream>
#include<fstream>
using namespace std;




/*OSSERVAZIONE :   PRE <SOL> POST, indicheremo che SOL è corretto rispetto a PRE e POST, cioè che esiste una dimostrazione del fatto che, se prima
                    dell’esecuzione di SOL vale PRE, allora dopo l'esecuzione di SOL (se termina) vale POST. Più precisamente,la dimostrazione
                    prova che se SOL inizia in un qualsiasi stato del calcolo che soddisfa PRE, allora, se la sua esecuzione termina, lo stato del
                    calcolo al termine soddisfa POST.


    PRE =  (il file "input" contiene le varie dimensioni lim1,lim2,lim3,n_el,f,e[j] con 0=<j<3  , e i numeri dell'array.)&&(tasello==0)&&(posParziale==0)
    */

int calcola_dist(int vfetta,int A,int righe,int colonne,int elementi)
{
    int tasello=0,posParziale=0,posFinale;
//col primo ciclo scorro tutte le righe partendo dalla prima , fino a N . Lui ti da già la v fetta. che in questo caso sarebbe la colonna della matrice tridimensionale
// in pratica , blocco la colonna( v-fette) e scorro le righe , fino all'ultima . ogni volta che scorro una riga , mi trovo la "posParziale" che sarebbe la posizione
//dell'elemento corrente della v-fetta della riga N. la variabile "A" sarebbe la e[j]. se per esempio e[j] fosse 2  allora io mi devo fermare alla riga 2. la variabile
//"tasello " , invece sarebbe l'indice dellla che parte da 0 , e arriva fino a e[j].
    for(int i=0;i<righe && tasello<=A && vfetta<colonne;i++) //R1
    {
        for(int s=0; s<(elementi/(righe*colonne))+1 && tasello<=A && vfetta<colonne;s++ )//R2
        {
            posParziale=s*(righe*colonne)+(i*colonne)+vfetta;
            if(posParziale<elementi)
            {
                posFinale=s*(righe*colonne)+(i*colonne)+vfetta;
                tasello++;
            }
        }
    }

    if(tasello<=A)return -1;
    else
        return posFinale;
        /*
        R && B <C > R (invarianza)

        R1= (0<=i<lim2)&&(0<=tasello<=A)&&(0<=v-fetta<colonna)

        R2= (0<=s<lim3)&& (0<=tasello<=A)&&(0<=v-fetta<colonna) &&( "posParziale" contiene la posizione
            parziale del "tasello" (sempre parziale))&&( posFinale contiene la posizione che interessa a me ,
             ovvero dell'ultimo tasello) &&(il tasello viene incrementato di 1 ogni volta che lo si trova
            nella matrice)
        */

}
main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT)
  {
   int X[400],P[50], n_el, dimP, lim1,lim2,lim3;

   for(int i=0; i<400;i++)//riempio X con -1
    X[i]=-1;

   IN>>lim1>>lim2>>lim3;
   IN>>n_el;

   for(int i=0; i<n_el; i++) //riempio X con i numeri del file "input"
     IN >> X[i];

   if(n_el>lim1*lim2*lim3)
    n_el=lim1*lim2*lim3;

   for(int q=0; q<3; q++)//legge le tre quadruple .   (strati)
    {
     int f, e[3];//e è un array a 3 dimensioni
     IN>>f>>e[0]>>e[1]>>e[2];

     for(int j=0;j<3;j++)//colonne
     {
      int d=calcola_dist(f,e[j],lim2,lim3,n_el); // questa e' da fare (restituisce -1 a indicare che l'elemento e[j] non c'e' nella V-fetta f)
      if(d==-1)
       OUT<<e[j]<<" elemento inesistente della V-fetta "<<f<<' ';
      else
      OUT<<d<<' ';
     }

    OUT<<endl;

    /*
     POST =     il file "output" contiene la distanza "d" del elemento e[j] con 0<=j<3 della v-fetta "f", dalla prima posizione dell'array
                unidimensionale(noi lo vediamo come un array tridimensionale) , nel caso in cui tale distanza fosse -1 , l'elemento e[j] non esiste nell'array.
     */
    }
   IN.close(); OUT.close();
  }
  else
   cout<<"errore con i files";
 }
