#include<iostream>

using namespace std;

int main()
{
    // delimitatore iniziale output del programma (stringa "start")
    // ATTENZIONE! Non cancellare l'istruzione sottostante
    cout << "start" << endl;

    // inserire qui il codice del programma
    char guno, gdue;
    int n;


    cin >> n;
    if (n<1) return 0;

    int c=0, ptUno=0, ptDue=0;

    while(c<n){
        cin >> guno;
        cin >> gdue;

    	switch(guno){
    		case 's':
    			switch(gdue){
    				case 's':
    					break;
    				case 'c':
    					ptDue++;
    					break;
    				case 'f':
    					ptUno++;
    					break;
    			}
			break;

			case 'c':
				switch(gdue){
					case 's':
			            ptUno++;
    					break;
    				case 'c':
    					break;
    				case 'f':
    					ptDue++;
    					break;
				}
			break;

			case 'f':
				switch(gdue){
					case 's':
    					ptDue++;
    					break;
    				case 'c':
    					ptUno++;
    					break;
    				case 'f':
    					break;
    			}
			break;

    	}


        c++;
    }

    if(ptUno == ptDue)
        cout << "Pareggio";
    else
    {
        if(ptUno>ptDue)
            cout<<"Vince il Giocatore 1";
        else
            cout<<"Vince il Giocatore 2"; 

        // oppure forma compressa con operatore ternario -->  (condizione ? valore se condizione vera : valore se cond falsa)
        // cout << ( ptUno>ptDue ? "Vince il Giocatore 1" : "Vince il Giocatore 2");
    }
        

    cout << endl;

    // delimitatore finale output del programma (stringa "end")
    // ATTENZIONE! Non cancellare l'istruzione sottostante
    cout << "end" << endl;
}
