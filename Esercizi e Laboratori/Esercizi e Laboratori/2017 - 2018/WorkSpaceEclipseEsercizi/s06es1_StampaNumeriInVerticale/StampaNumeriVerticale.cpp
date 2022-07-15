#include <iostream>

using namespace std;

// PRE = n >= 0
void stampa_verticale(int n);
// POST = stampa il numero n in verticale, con ogni cifra decimale in una riga diversa



int main()
{
    cout << "start" << endl;

    int n;
    cin>>n;
    stampa_verticale(n);
    cout << "end" << endl;

}

//PRE: n >=0
void stampa_verticale(int n){

	// caso base: se <=9 allora basta stampare il numero normalmente
	if(n<=9) cout<<n<<endl;
	else{
		int ultimaCifra=n%10;
		n-=ultimaCifra;

		//Caso ricorsivo: n/10 >=0
		stampa_verticale(n/10);
		//
		cout<<ultimaCifra<<endl;
	}

	/*
	 * DImostrazione di Correttezza:
	 *
	 * caso base: se il numero e' minore uguale a 9, allora si stampa il numero che e' in colonna
	 *
	 * caso ricorsivo: l'operazione che viene effettuato sul numero restituisce
	 * due risultati, il nuovo n con il quale facciamo l'invocazione ricorsiva,
	 * e mentre con ultimaCifra che e' il resto della divisione per 10, ed e'
	 * ultima cifra del n originale quindi basta stamparlo.
	 *
	 * La stampa viene fatto al ritorno dalla chiamata ricorsiva in modo da mantenere le cifre nell'ordine corretta.
	 *
	 * poi ha fatto lo stesso esercizio usando il ciclo  for, direi useless
	 *
	 *
	 * Ricorsione terminale== tail recursive== ricorsione che non fa nulla al ritorno
	 *
	 */

}
//POST: stampato il numero n in colonna come richiesto dalla consegna.




//SOl
