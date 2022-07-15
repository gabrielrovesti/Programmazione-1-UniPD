#include <iostream>
using namespace std;

struct nodo { int info; nodo* left, * right; nodo(int a = 0, nodo* b = 0, nodo* c = 0) { info = a; left = b; right = c; } };
struct nodoE { nodo* info; nodoE* next; nodoE(nodo* a = 0, nodoE* b = 0) { info = a; next = b; } };

void crea_A_RIC(nodo*& albero, int numeroNodi);
void inserisciNodo_A_RIC(nodo*& albero);
int  contaNodi_A_RIC(nodo*& albero);
void stampa_A_Lineare_RIC(nodo* albero);
void stampa_LA_RIC(nodoE* LISTA);

//PRE = L-> info punta alla radice dell'albero
void faiRic(nodoE*& L);
//POST = crea una lista di nNodi = nNodi dell'albero i cui campi info puntano ai nodi dell'albero in larghezza

//PRE = la lista L � definita e A punta al nodo da aggiungere a L->info
void inserisciNodo_E_RIC(nodoE* L, nodo* A);
//POST = alla lista L � stato aggiunto un nuovo nodo con info = A

void filtraIter(nodoE*& L);

//PRE = LISTA punta al nodo il cui campo info->info � da confrontare con i successivi
void controlloL(nodoE* LISTA, int valore);

//PRE = L punta al nodo precedente di quello da deallocare
void deallocaNodoL(nodoE*& L);
//POST = il nodo L->next � stato deallocato tramite il puntatore "segno" e il nodo precedente e successivo di quello da deallocare sono stati uniti

int main()
{
    //----------------------------------------------------------------
    // CREAZIONE ALBERO
    //----------------------------------------------------------------

    int nNodi;
    cout << "NUMERO DI NODI DELL'ALBERO: ";
    cin >> nNodi;
    cout << endl;

    nodo* A = 0;
    crea_A_RIC(A, nNodi);

    cout << "\nSTAMPA LINEARE DELL'ALBERO         : ";
    stampa_A_Lineare_RIC(A); //per controllare che i nodi dell'albero siano stati inseriti correttamente
    cout << endl;

    //----------------------------------------------------------------
    // INIZIO DEL PROGRAMMA EFFETTIVO
    //----------------------------------------------------------------

    nodoE* L = new nodoE(A,0); //L punta ad un nodo che ha come info il puntatore alla radice dell'albero
   
    faiRic(L);
    cout << "\nSTAMPA dei CAMPI INFO della LISTA L: ";
    stampa_LA_RIC(L); //per controllare che la lista sia stata creata correttamente
    cout << endl;

    filtraIter(L);

    cout << "\nSTAMPA SUCCESSIVAMENTE A filtraIter: ";
    stampa_LA_RIC(L); //stampa della lista dopo la deallocazione tramite filtraIter
    cout << endl;
}

void faiRic(nodoE*& L)
{
    if (L)
    {
        if (L->info->left)
            inserisciNodo_E_RIC(L, L->info->left);
        if (L->info->right)
            inserisciNodo_E_RIC(L, L->info->right);
        faiRic(L->next);
    }
}

void inserisciNodo_E_RIC(nodoE* L, nodo* A)
{
    if (L->next)
        inserisciNodo_E_RIC(L->next, A);
    else
        L->next = new nodoE(A, 0);
}

void filtraIter(nodoE*& L)
{
    nodoE* inizioL = L;
    while (L&&L->next)
    {
        controlloL(L, L->info->info);
        if(L&&L->next)
            L = L->next;
    }
    L = inizioL;

    while (LISTA && LISTA->next)
    {
        if (LISTA->next->info->info == valore)
            deallocaNodoL(LISTA);
        else 
        {
            if (LISTA && LISTA->next)
            LISTA = LISTA->next;
        }
    }
    return;
}

void deallocaNodoL(nodoE*& L)
{
    if (L->next->next) 
    {
        nodoE* segno = L->next;
        L->next = L->next->next;
        delete segno;
    }
    else
    {
        nodoE* segno = L->next;
        L->next=0;
        delete segno;
    }
}

//----------------------------------------------------------------
// CODICI PER LA CREAZIONE DELL'ALBERO E STAMPA DI ALBERO E LISTA
//----------------------------------------------------------------

void crea_A_RIC(nodo*& albero, int numeroNodi)
{
    if (numeroNodi)
    {
        inserisciNodo_A_RIC(albero);
        crea_A_RIC(albero, numeroNodi - 1);
    }
}

void inserisciNodo_A_RIC(nodo*& albero)
{
    if (!albero)
    {
        cout << "INFO del nodo: ";
        int infoNodo;
        cin >> infoNodo;
        albero = new nodo(infoNodo, 0, 0);
    }
    else
    {
        if (contaNodi_A_RIC(albero->left) <= contaNodi_A_RIC(albero->right))
            inserisciNodo_A_RIC(albero->left);
        else
            inserisciNodo_A_RIC(albero->right);
    }
}

int contaNodi_A_RIC(nodo*& albero)
{
    if (albero)
        return 1 + contaNodi_A_RIC(albero->left) + contaNodi_A_RIC(albero->right);
    else
        return 0;
}

void stampa_A_Lineare_RIC(nodo* albero)
{
    if (albero)
    {
        cout << albero->info << '(';
        stampa_A_Lineare_RIC(albero->left);
        cout << ',';
        stampa_A_Lineare_RIC(albero->right);
        cout << ')';
    }
    else
        cout << '_';
}

void stampa_LA_RIC(nodoE* LISTA)
{
    if (LISTA)
    {
        cout << LISTA->info->info << ' ';
        stampa_LA_RIC(LISTA->next);
    }
}