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
        // Inizializzo n_spazi (conterrà il numero di caratteri ' ' da stampare ad ogni livello dell'albero [0, n-1])
        int n_spazi = 0;
        // Inizializzo n_stelle (conterrà il numero di caratteri '*' da stampare ad ogni livello dell'albero [0, n-1])
        int n_stelle = 2*n - 3;
        int i = 0, j = 0;
        // Prima del ciclo più esterno, occorre stampare il tronco (un unico carattere '*' preceduto da n-2 spazi ' ')
        /*
        * R1=(0<=j<=n_spazi) && (stampati j spazi al livello corrente)
        */
        while (j < n-2) {
            cout << ' ';
            j++;
        }
        cout << '*' << endl;
        /* R2=(0<=i<=n-1)
         * && (n_spazi = n. di spazi iniziali e n_stelle = n. di successive stelle nella prossima riga)
         * && (stampati correttamente i primi i livelli [righe] dell'albero)
         */
        while (i < n-1) {
            // Ad ogni livello i, stampa il numero corretto di spazi seguiti dal numero corretto di stelle
            j = 0;
            /*
             * R2.1=(0<=j<=n_spazi) && (stampati j spazi al livello corrente)
             */
            while (j < n_spazi) {
                cout << ' ';
                j++;
            }
            j = 0;
            /*
            * R2.2=(0<=j<=n_stelle) && (stampate j stelle al livello corrente)
            */
            while (j < n_stelle) {
                cout << '*';
                j++;
            }
            cout << endl;
            // Al termine della stampa della riga corrispondente al livello i-esimo, aggiorno le variabili n_spazi e n_stelle
            // Secondo quanto visto a lezione: n_spazi viene decrementato di 1 e n_stelle incrementato di 2
            n_spazi += 1;
            n_stelle -= 2;
            // Incrementiamo il contatore che tiene traccia del livello a cui siamo giunti
            i++;
        }

    }

    cout << "end" << endl;
}