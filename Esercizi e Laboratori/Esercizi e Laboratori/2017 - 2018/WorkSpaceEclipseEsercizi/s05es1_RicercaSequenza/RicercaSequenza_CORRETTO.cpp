#include<iostream>
using namespace std;

int S(int[],int);

int main()
{
   int X[400];
   cin>>X[0];
   for(int i=1; i<400 && X[i-1]!=-2; i++)
	   cin >>X[i];

    int n;
    cin>>n;
    cout<<"start"<<endl;
    int b=S(X,n); // da fare
    if(b == -2)
     cout<<"sottosequenza "<<n<<" non presente"<<endl;
    else
     cout<<"inizio sottosequenza "<<n<<" indice="<<b<<endl;
    cout<<"end"<<endl;
 }


// PRE: A contiene una sequenza di caratteri che contiene -2, e contiene delle sottosequenze che contengono -1, 
// inoltre n>=0

int S(int a[], int   n){
	
	/* 
	 * Si contano i -1 perche' ogni sequenza termina con esso, quindi l'idea e' che ne devo contare n
	 */
	int b=-2;
	int temp=0; // variabile che contiene le volte in cui sono state trovate -1
	bool searching=true;

	// PRE: searching == true, i=0, a[0] != -2, temp=0
	for(int i=0; i<400 && a[i]!=-2 && searching && temp<n; i++)
	{
		//R:
		/*
		 * 0<=i<=400 &&
		 * a[i]!=-2 &&
		 * searching == true &&
		 * quando temp==n, allora b contiene l'inizio della sequenza n se esiste, altrimenti e' uguale a -2
		 * 0<= temp <= n &&
		 * trovato temp volte il carattere di fine seguenza  nell'array ==> temp sequenza &&
		 * searching==false <==> e' stato trovato il numero di sequenza richiesta dall'utente &&
		 *
		 */

		if(a[i]==-1){
			temp++;
			if(temp==n && A[i+1]!= 2){
				b=i+1;
				searching=false;
			}
			else
				b=-2;
		}
		/* POST:
		 * i>=400 || searching == false || a[i] == -2  ||
		 *  searching == false <==> e' stato trovato n sequenza richiesta dall'utente e la sequenza n comincia in posizione b
		 *
		 */
	}

	/**  DIMOSTRAZIONE DI CORRETTEZZA:
	 * 	1. Al primo ciclo, avendo esaminato i =0 elemento, il variabile e' uguale a 0, quindi non ci sono i -2.
	 *     Assumiamo invariana, quindi R, e che la condizione di permanenza sia vera.<==> questa e' vera,
	 *	   viene esaminato il corpo del ciclo per la prima volta.
	 *
	 * 	2.
	 * 	3.
	 *
	 */

	
	/*
	 * Se A contiene la sotto sequenza n allora restituisce l'indice di A in cui inizia la sottosequenza n, altrimenti restituisce -2
	 */

	return b;
}
