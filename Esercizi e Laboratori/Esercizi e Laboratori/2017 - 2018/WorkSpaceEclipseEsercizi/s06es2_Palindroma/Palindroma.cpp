#include <iostream>

using namespace std;

// PRE = S e' una stringa di lunghezza n >= 1
bool palindroma(char *S, int n);
// POST = ritorna true se e solo se S e' palindroma

int main()
{
    int lung;
    char S[100];
    cin.getline(S, 100);        // legge una riga di caratteri da cin
    lung = cin.gcount() - 1;    // ritorna il numero di caratteri letti (compreso il terminatore '\0')
    cout << "start" << endl;

    if(palindroma(S,lung))
        cout<<"la stringa e' palindroma"<<endl;
    else
        cout<<"la stringa non e' palindroma"<<endl;

    cout << "end" << endl;
}


// S contiene n interi, n >=0
bool palindroma(char *S, int n){


	//caso base: se non ci sono elementi o c'e' ne uno solo l'array
	//e' palindromo per definizione
    if(!n || n==1) return true;


    //Caso ricorsivo:  se il numero di posizione 0 e' uguale
    //al numero di posizione n-1 allora si continua la ricorsione,
    //invocando la funzione  con l'array che punta all'elemento
    //successivo mentre si diminuisce di 2 la dimensione dell'array.

	if(S[0]==S[n-1])
		return palindroma(S+1,n-2);
    else
    	return false;

	/* Dimostrazione
	 *
	 *
	 * S[0...n-1] e' palindromo sse
	 * S[0]==S[n-1] && S[1...n-2] e' palindroma
	 *  Pre_ric: S+1 contiene n interi, n-2>=0
	 *  Post_ric:
	 *
	 *
	 */


//POST la funzione restituisce true <==> ha A[0... n-1] e' palindroma
}
