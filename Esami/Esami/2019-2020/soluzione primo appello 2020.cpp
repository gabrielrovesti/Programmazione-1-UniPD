/*
                        PRIMO APPELLO 2020

    ATTENZIONE: le 2 funzioni da fare (H e H1) sono a riga 78 e 98, tutto il resto
    è stato fatto per rendere possibile che l'appello sia compilabile ed eseguibile
*/
#include <iostream>
using namespace std;

struct nodo {
    int info;
    nodo* left, * right;
    nodo(int a = 0, nodo* c = 0, nodo* d = 0) {
        info = a;
        left = c;
        right = d;
    }
};

int conta_nodi_alberto_tot(nodo* R) {//conta tutti i nodi di un albero
    if (!R)
        return 0;
    int a = conta_nodi_alberto_tot(R->left);
    int b = conta_nodi_alberto_tot(R->right);
    return a + b + 1;
}

void conta_nodi_albero_sx_dx(nodo* R, int& sx, int& dx) {//scrive su sx e dx il numero di nodi a sinistra e a destra di una radice
    dx = conta_nodi_alberto_tot(R->right);
    sx = conta_nodi_alberto_tot(R->left);
}

//built_albero costruisce un albero in modo orizzontale, in questo modo:
/*
            1    |         1      |         1        |             1         |             1            |                1             |               1
                 |     2          |     2       3    |         2       3     |       2          3       |         2             3      |       2               3
                                                     |     4                 |   4       5              |     4       5     6          |   4       5       6       7       e così via...
*/
nodo* built_albero(nodo* R, int x) {
    if(!R)
        return new nodo(x);
    int sx, dx;
    conta_nodi_albero_sx_dx(R, sx, dx);
    if (sx <= dx) {//se ci sono meno nodi a sx o lo stesso numero di nodi a dx e sx
        R->left = built_albero(R->left, x);//si procede a sinistra
    }
    else {
        R->right = built_albero(R->right, x);//altrimenti si va a destra
    }
    return R;
}

nodo* built_bts(nodo* R, int x) {//funzione ricorsiva che crea e aggiunge il nodo con info x all'albero R
    if (!R) 
        return new nodo(x);

    if (x <= R->info) {
        R->left = built_bts(R->left, x);
    }
    else {
        R->right = built_bts(R->right, x);
    }
    return R;
}

void stampa_lin(nodo* r) {//stampa l'albero r
    if (r) {
        cout << '[' << r->info << ']' << '(';
        stampa_lin(r->left);
        cout << ',';
        stampa_lin(r->right);
        cout << ')';
    }
    else cout << '_';
}

//PRE: (r è un albero ben formato, m1 < y < m2, m1 è il valore più basso dell'albero r, m2 è il valore più alto dell'albero r)
void H(nodo* r, int y, int& m1, int& m2) {
    if (!r)//se l'albero di partenza è vuoto, non facciamo niente
        return;
    if (r->info > m1 && r->info <= y)         //se il valore del nodo in cui ci troviamo è maggiore del valore minimo trovato finora ed è comunque più picclo o uguale di y (e quindi è più vicino a y)...
        m1 = r->info;                         // allora il valore di questo nodo diventa il nuovo m1

    if (r->info < m2 && r->info >= y)         //se il valore del nodo in cui ci troviamo è minore del valore massimo trovato finora ed è comunque più grande o uguale di y (e quindi è più vicino a y)...
        m2 = r->info;                         // allora il valore di questo nodo diventa il nuovo m2

    if (r->left) {  //se esiste un nodo a sinistra, proveremo ad andarci (dobbiamo visitare per forza tutto l'albero, dato che non è assicurato che sia BTS)
        H(r->left, y, m1, m2);
    }
    if (r->right) { //se esiste un nodo a destra, proveremo ad andarci (dobbiamo visitare per forza tutto l'albero, dato che non è assicurato che sia BTS)
        H(r->right, y, m1, m2);
    }
}
//POST:(vengono utilizzati m1 e m2 per restituire x1 e x2, infatti: m1 e m2 sono il miglior intervallo per y )

//PRE: (r è un albero ben formato BTS, m1 < y < m2, m1 è il valore più basso dell'albero r, m2 è il valore più alto dell'albero r)

void H1(nodo* r, int y, int& m1, int& m2) {
    if (!r)//se l'albero di partenza è vuoto, non facciamo niente
        return;

    while (r) {//R1      finchè non siamo arrivati su una foglia dell'albero (quindi in fondo all'albero), continuamo il ciclo (e quindi continuamo a scendere)
        if (r->info > m1 && r->info <= y)       //se il valore del nodo in cui ci troviamo è maggiore del valore minimo trovato finora ed è comunque più picclo o uguale di y (e quindi è più vicino a y)...
            m1 = r->info;                       // allora il valore di questo nodo diventa il nuovo m1
      
        if (r->info < m2 && r->info >= y)       //se il valore del nodo in cui ci troviamo è minore del valore massimo trovato finora ed è comunque più grande o uguale di y (e quindi è più vicino a y)...
            m2 = r->info;                       // allora il valore di questo nodo diventa il nuovo m2

        if (y < r->info)    //se y è più piccolo del valore del nodo attuale, dobbiamo andare a sinitra: un nodo di un albero BTS ha alla sua sinistra i valori minori e alla sua destra i valori maggiori. Se y è più piccolo del nodo attuale, è inutile andare a controllare a destra dato che ci sono i valori più grandi, andiamo direttamente a sinistra
            r = r->left;
        else                //ragionamento di 2 righe fa ma invertito, andiamo a destra che ci sono valori più grandi
            r = r->right;
    }
}
//POST:(vengono utilizzati m1 e m2 per restituire x1 e x2, infatti: m1 e m2 sono il miglior intervallo per y 
//R1:(x è un albero ben formato (anche vuoto), m1 rappresenta il nodo con un valore minore di y e più vicino a y dell'albero finora scorso,
//   m2 rappresenta il nodo con un valore maggiore di y e più vicino a y dell'albero finora scorso)


int main()
{/////////////////////////////////////////  PRIMA PARTE: FUNZIONE H
    cout << "Inserisci i nodi dell'albero (-1 per finire):" << endl;
    cout << "PS: (L'albero non viene inserito per essere BTS, segue un criterio equilibrato, ovvero vengono aggiunti nodi in orizzontale)" << endl;
    int n = 0;
    nodo* R = 0;
    int min = 0, max = 0;

    cin >> n;
    if (n != -1) {//inserimento della radice del nodo e assegnamento a min e max il loro valore di base (la radice)
        R = built_albero(R, n);
        min = n;
        max = n;
    }

    while (n != -1) {//si inseriscono tutti i nodi che vuole l'utente, finchè non inserirà -1
        cin >> n;
        if (n != -1) {
            R = built_albero(R, n);
            if (n > max)//aggiorniamo max e min per la funzione H
                max = n;
            if (n < min)
                min = n;
        }
    }
    stampa_lin(R);
    cout<< endl << "Inserisci y:" << endl;
    int y;
    cin >> y;
    H(R, y, min, max);

    cout << "Coppia x1 e x2 della funzione H: " << min << " " << max << endl << endl;

    ////////////////////////////////////////////  SECONDA PARTE: FUNZIONE H1

    cout << "Inserisci i nodi dell'albero BTS (-1 per finire):" << endl;
    cout << "PS: (L'albero questa volta verra' inserito per essere un BTS)" << endl;
    int n2 = 0;
    nodo* R2 = 0;
    int min2 = 0, max2 = 0;

    cin >> n2;
    if (n2 != -1) {//inserimento della radice del nodo e assegnamento a min e max il loro valore di base (la radice)
        R2 = built_bts(R2, n2);
        min2 = n2;
        max2 = n2;
    }

    while (n2 != -1) {//si inseriscono tutti i nodi che vuole l'utente, finchè non inserirà -1
        cin >> n2;
        if (n2 != -1) {
            R2 = built_bts(R2, n2);
            if (n2 > max2)//aggiorniamo max2 e min2 per la funzione H1
                max2 = n2;
            if (n2 < min2)
                min2 = n2;
        }
    }

    stampa_lin(R2);
    cout << endl << "Inserisci y:" << endl;
    int y2;
    cin >> y2;

    H1(R2, y2, min2, max2);

    cout << "Coppia x1 e x2 della funzione H1: " << min2 << " " << max2 << endl;
}

