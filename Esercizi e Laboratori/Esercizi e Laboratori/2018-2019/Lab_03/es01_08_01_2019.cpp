#include <iostream>

using namespace std;

int main() {

    cout << "start" << endl;

    int n;
    cin >> n;

    if (n < 3) {
        cout << "Altezza non valida" << endl;
    }
    else {
        // Inizializzo n_spazi (conterrà il numero di caratteri ' ' da stampare ad ogni livello dell'albero [1, n-1])
        int n_spazi = n-2;
        // Inizializzo n_stelle (conterrà il numero di caratteri '*' da stampare ad ogni livello dell'albero [1, n-1])
        int n_stelle = 1;
        int i = 0, j = 0;
        /* R=(0<=i<=n-1)
         * && (n_spazi = n. di spazi e n_stelle = n. di successive stelle nella prossima riga)
         * && (stampati correttamente i primi i livelli [righe] dell'albero)
         */
        while (i < n-1) {
            // Ad ogni livello i, stampa il numero corretto di spazi seguiti dal numero corretto di stelle
            j = 0;
            /*
             * R1=(0<=j<=n_spazi) && (stampati j spazi al livello corrente)
             */
            while (j < n_spazi) {
                cout << ' ';
                j++;
            }
            j = 0;
            /*
            * R2=(0<=j<=n_stelle) && (stampate j stelle al livello corrente)
            */
            while (j < n_stelle) {
                cout << '*';
                j++;
            }
            cout << endl;
            // Al termine della stampa della riga corrispondente al livello i-esimo, aggiorno le variabili n_spazi e n_stelle
            // Secondo quanto visto a lezione: n_spazi viene decrementato di 1 e n_stelle incrementato di 2
            n_spazi -= 1;
            n_stelle += 2;
            // Incrementiamo il contatore che tiene traccia del livello a cui siamo giunti
            i++;
        }
        // Al termine del ciclo più esterno, occorre stampare il tronco (un unico carattere '*' preceduto da n-2 spazi ' ')
        j = 0;
        /*
        * R3=(0<=j<=n_spazi) && (stampati j spazi al livello corrente)
        */
        while (j < n-2) {
            cout << ' ';
            j++;
        }
        cout << '*' << endl;
    }

    cout << "end" << endl;
}