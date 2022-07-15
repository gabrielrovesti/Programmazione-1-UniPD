#include<iostream>

using namespace std;

int main()
{
	// delimitatore iniziale output del programma (stringa "start")
	// ATTENZIONE! Non cancellare l'istruzione sottostante
	cout << "start" << endl;

	// inserire qui il codice del programma
    char in;
    int c=0;

    while(in!='0' && c>=0)
    {
        cin >> in;

        if(in=='(') c++;
        else if(in==')') c--;
    }

    if(c==0)
        cout << "la sequenza e' bilanciata";
    else
    {
        if(c>0)
            cout<<"la sequenza non e' bilanciata: ci sono parentesi aperte senza match";
        else
            cout<<"la sequenza non e' bilanciata: ci sono parentesi chiuse senza match";

        // oppure forma compressa con operatore ternario -->  (condizione ? valore se condizione vera : valore se cond falsa)
        // cout << ( c>0 ? "la sequenza non e' bilanciata: ci sono parentesi aperte senza match" : "la sequenza non e' bilanciata: ci sono parentesi chiuse senza match");
    }
        
    

    cout << endl;

	// delimitatore finale output del programma (stringa "end")
	// ATTENZIONE! Non cancellare l'istruzione sottostante
	cout << "end" << endl;
}
