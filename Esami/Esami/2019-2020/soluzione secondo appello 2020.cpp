/*
                        SECONDO APPELLO 2020

    ATTENZIONE: le 4 funzioni da fare (gia_presente, filtra, buildBST e butta) 
    sono a riga 89, 100, 114, 161, tutto il resto è stato fatto per fare in modo 
    che l'appello sia compilabile ed eseguibile

    Ps: non sono sicuro delle invaranti di buildBST
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
struct nodoE { 
    nodo* info; 
    nodoE* next; 
    nodoE(nodo* a = 0, nodoE* b = 0) {
        info = a; 
        next = b; 
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

//PRE=(R->nodo non nullo e lista -> lista nodoE ben formata)
bool gia_presente(nodo* R, nodoE* lista) {
    if (!lista)
        return false;
    if (R->info == lista->info->info)
        return true;
    gia_presente(R, lista->next);
}
//POST = (restituisce true se è presente un nodo con il campo info uguale a R 
//        all'interno della lista nodoE. Restituisce false altrimenti)

//PRE=(R->albero ben formato, tenere e buttare liste di nodoE* vuote)
void filtra(nodo* R, nodoE*& tenere, nodoE*& buttare) {
    //la funzione scorre l'albero in modo infisso: sinistra, nodo, destra
    if (R) {
        filtra(R->left, tenere, buttare);
        if (R) {
            if (gia_presente(R, tenere))            //se è già presente questo nodo all'interno di tenere...
                buttare = new nodoE(R, buttare);    //viene aggiunto il nodo R all'inizio della lista buttare (l'ordine dei nodi è irrilevante!)
            else
                tenere = new nodoE(R, tenere);      //altrimenti viene aggiunto il nodo R all'inizio della lista tenere
        }
        filtra(R->right, tenere, buttare);
    }
}
//POST=(tenere contiene i nodi non doppi dell'albero R, buttare contiene i nodi doppi dell'albero R)
nodo* buildBST(nodoE* lista) {
    if (!lista)
        return 0;
    nodo* bts = lista->info;    //creiamo la radice dell'albero
    bts->left = 0;              //togliamo i collegamenti a dx e a sx alla radice
    bts->right = 0;
    lista = lista->next;        //andiamo al prossimo elemento della lista nodoE

    while (lista) {//R1        ciclo che scorre R
        nodo* copia = bts;         //usiamo copia per scorrere tutto bts. Se usassimo bts stesso per scorrere, una volta in fondo non potremmo più tornare indietro! mentre avendo bts che rimane sempre sulla radice, non rischiamo di perderla
        bool stop = false;
        lista->info->left = 0;      //togliamo i collegamenti a dx e a sx del nodo da aggiungere
        lista->info->right = 0;
        while (!stop) { // R2        ciclo che scorre tutto l'albero finchè non raggiunge il posto in cui inserire il nodo
            if (lista->info->info < copia->info) {  //se il valore del nodo da aggiungere è più basso del nodo in cui ci troviamo, dobbiamo andare a sx, altrimenti a dx
                if (copia->left)                //se esiste un nodo a sx, ci andiamo e proseguiamo lo scorrimento
                    copia = copia->left;
                else {          //altrimenti, se non esiste un nodo a sinistra, vuol dire che siamo arrivati e qui dobbiamo aggiungere il nodo
                    stop = true;        //usciamo dal ciclo per scorrere l'albero
                    copia->left = lista->info;      //inseriamo il nodo nell'albero a sinistra
                }
            }
            else {      //altrimenti se il valore del nodo da aggiungere è più alto del nodo in cui ci troviamo, dobbiamo andare a dx
                if(copia->right)        //se esiste un nodo a dx, ci andiamo e proseguiamo lo scorrimento
                    copia = copia->right;
                else {      //altrimenti, se non esiste un nodo a destra, vuol dire che siamo arrivati e qui dobbiamo inserire il nodo
                    stop = true;        //usciamo dal ciclo per scorrere l'albero
                    copia->right = lista->info;     //inseriamo il nodo nell'albero a destra
                }
            }
        }//POST R2
        nodoE* tmp = lista;     //ora che abbiamo inserito il nodo dalla lista tenere all'albero bts, possiamo deallocare il nodoE che puntava al nodo da aggiungere all'albero
        lista = lista->next;    //andiamo al prossimo elemento nodoE della lista ed eliminiamo quello precedente
        delete tmp;
    }//POST R1
    return bts;
}
/*
    R1=(lista è la lista di nodiE ben formata (anche vuota) che contiene i nodi con cui costruire un albero BTS
        copia è un albero ben formato su cui bisogna inserire tutti i nodi di lista.
        Il ciclo R1 scorre tutta la lista nodoE e inserisce tutti i suoi nodi a copia. I nodi verranno inseriti per formare un albero BTS
        Una volta allocato un nodo nell'albero, il nodoE che conteneva quel nodo viene eliminato )
    
    R2=(stop diventerà true quando copia punterà a una foglia dell'albero.
        questo ciclo permette l'inserimento del nodo puntato dal nodoE lista in modo da creare un albero BTS.
    )
*/
void butta(nodoE* lista) {
    while (lista) {
        delete lista->info; //prima elimina il nodo puntato
        nodoE* tmp = lista; 
        lista = lista->next;//poi avanzi al prossimo nodo ed elimini il precedente
        delete tmp;
    }
}
int main()
{/////////////////////////////////////////  PRIMA PARTE: RICORSIVA
    cout << "Inserisci i nodi dell'albero (-1 per finire):" << endl;
    cout << "PS: (L'albero non viene inserito per essere BTS, segue un criterio equilibrato, ovvero vengono aggiunti nodi in orizzontale)" << endl;
    int n = 0;
    nodo* R = 0;

    while (n != -1) {//si inseriscono tutti i nodi che vuole l'utente, finchè non inserirà -1
        cin >> n;
        if (n != -1) {
            R = built_albero(R, n);
        }
    }
    stampa_lin(R);
    nodoE* tenere = 0;
    nodoE* buttare = 0;

    filtra(R, tenere, buttare);

    cout << endl << endl << "Lista TENERE: ";
    nodoE* a = tenere;
    while (a) {
        cout << a->info->info << " ";
        a = a->next;
    }
    cout << endl << endl << "Lista BUTTARE: ";
    a = buttare;
    while (a) {
        cout << a->info->info << " ";
        a = a->next;
    }
    cout << endl << endl;
    ////////////////////////////////////////////  SECONDA PARTE: ITERATIVA

    nodo* tenereBts = buildBST(tenere);

    cout << "Lista tenere in un albero BTS:" << endl;
    stampa_lin(tenereBts);
    cout << endl;
    butta(buttare);
    cout << "Eliminata la lista buttare" << endl;
}

