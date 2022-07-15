	#include<iostream>
	using namespace std;

	int Sric(int*,int,int);

	int main()
	{
	   int X[400];
	   cin>>X[0];
	   for(int i=1; i<400 && X[i-1]!=-2; i++)
	   cin >>X[i];

		int n;
		cin>>n;
		cout<<"start"<<endl;
		int b=Sric(X,0,n);
		if(b==-2)
		 cout<<"sottosequenza "<<n<<" non presente"<<endl;
		else
		 cout<<"inizio sottosequenza "<<n<<" indice="<<b<<endl;
		cout<<"end"<<endl;
	 }


	int Sric(int* puntatore,int posizione,int n){
	//PRE: 	posizione<=400 && n>=0 && *(puntatore) e' definito &&
	//		da *puntatore in poi deve contenere un -2 e delle sottosequenze contenenti -1
	//


		if(*puntatore==-2)  return -2;
		if(n==0) return posizione;
		if(*puntatore == -1)
				return Sric( puntatore, posizione+1, n-1);
		else
				return Sric( puntatore, posizione+1, n);

//		if(*puntatore==-2){
//			return -2;
//		}else{
//			if(*puntatore==-1){
//				n--;
//			}
//			if(n==0 && *(puntatore+1)!=-2)
//				return posizione+1;
//			return Sric(puntatore+1,posizione+1,n);
//
//
//		}

	//POST: restistuisce -2 <==> non e' stato trovato il numero di sequenza richiesta dall'utente ||
	// 		restituisce la posizione del primo elemento della sequenza richiesta <==> n == 0 && *(puntatore) != -2
}

	/* PROVA DI CORRETTEZZA:
	 *
	 * 1: considerare i casi basi: dimostrare che i casi vasi si applichino:
	 *     -1: quando l'elemento puntatore dal puntatore e' uguale a -2, vuol dire che non c'e' la sottosequenza nell'array,
	 *     		quindi si restituisce -2.
	 *     -2: quando n==0 quindi si cerca la prima sottosequenza nell'array, e siccome il primo elemento e' diverso da -2,
	 *      	quindi essa inizia nella prima posizione dell'array puntato dal puntatore.
	 * 2: consideriamo i casi ricorsivi:
	 * 	   1: PRE_ric_1: da puntatore in poi contiene una sequenza di meno sequenza con meno e che i+1 deve essere posizione+1>=0 e che n-1>=0
	 * 	   	POST_ric_1: se a[i+1] contiene la sottosequenza n-1 ed essa inizia in posizione restituisce posizione altrimenti restituisce -2.
	 *
	 * 	   2: Pre_ric_2:
	 * 	      POST_ric_2:
	 *
	 *
	 */
