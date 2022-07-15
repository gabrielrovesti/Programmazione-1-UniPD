/*

Si chiede di costruire una libreria di funzioni ricorsive per alberi BST. Le 
funzioni della libreria sono le seguenti:
1)Stampa in formato lineare dell’albero: void stampa_l(nodo*r)
2)Inserimento di un nodo con info=x mantenendo la proprietà BST: 
nodo* insert(nodo*r, int x)
3)Ricerca di un nodo con info=x: bool search(nodo*r, int x)
4)Calcolo del campo info massimo e minimo : nodo*max(nodo*r), 
nodo*min(nodo*r)
5)Calcolo dell’altezza dell’albero: int altezza (nodo*r)
6)Calcolo della lunghezza minima tra i cammini che collegano la radice ad 
una foglia: int altMin(nodo*r)
La libreria consiste di un file “BST.h” con la dichiarazione del tipo nodo e i 
prototipi delle funzioni elencate prima e di un file “BST.cpp” con le 
implementazioni delle funzioni stesse. Tutte le dichiarazione in BST.h vannor
acchiuse in un namespace che si chiama BST. Il file BST.cpp deve includere
“BST.h” seguito dall’istruzione “using namespace BST;”. Inoltre ogni 
definizione di funzione in BST.cpp deve specificare che si sta definendo una 
funzione del namespace BST e quindi il nome della funzione deve essere 
preceduta da “BST::”. Per esempio per la funzione search, la prima riga deve 
essere: bool BST::search(nodo*r, int x). Non importa specificare BST per le 
invocazioni ricorsive. Nel file “BST.cpp” ogni funzione deve essere 
accompagnata dalla sua PRE e POST e ovviamente le funzioni devono 
obbedire alle PRE e POST specificate. Il programma “main.cpp”, che è dato, 
inizia con le opportune istruzioni di include e using e contiene un main da 
completare che costruisce un piccolo albero BST e dopo deve iterativamente 
leggere degli interi ed eseguire le corrispondenti operazioni della libreria BST.
Il ciclo da inserire nel main è spiegato nel seguente esempio.
Esempio: supponiamo che l’albero corrente sia 3(1(_,_), 5(_,_)) e che si 
voglia inserire in quest’albero un nodo con info= 4. L’istruzione che 
corrisponde a questa richiesta viene rappresentata dai 2 interi: 2 4. Il valore 2 
fa riferimento al punto (2) della precedente lista (che infatti corrisponde alla 
funzione di inserimento) e 4 è il valore da inserire. Dopo aver eseguito 
l’inserimento, verrà stampato il nuovo albero (con la funzione di stampa_l del 
punto(1)) che è: 3(1(_,_), 5(4(_,_),_)). Il punto (4) corrisponde a 2 funzioni, 
quindi, se dopo il 4 si legge 1 allora è richiesta la funzione max, se si legge 2 
è richiesta la funzione min. Dopo aver eseguito queste funzioni, va stampato il campo info del nodo restituito. Lo stesso vale per le funzioni (5) e (6). Per la 
funzione (3) di ricerca, si stamperà “valore x presente/non presente”. In
corrispondenza dell’input 1 va semplicemente invocata stampa_l. Per 
terminare le operazioni il main deve leggere 0.
Correttezza: scrivere la prova induttiva della funzione (2)
Suggerimenti: Provate a vedere cosa succede se togliete l’operazione di
“using namespace BST;” dal main.cpp. Invece di “using namespace BST;”
potete invocare ogni funzione specificando BST:: prima del nome, ma 
attenzione che nodo è definito nel namespace. Provate.

*/

#include<iostream>
#include "BST.h"

using namespace std;
using namespace BST;

//Stampa in formato lineare dell’albero
void BST::stampa_l(nodo*r){
if (r) {
        cout << r->info << '(';
        stampa_l(r->left);
        cout << ',';
        stampa_l(r->right);
        cout << ')';
    } else
        cout << '_';
}

//Inserimento di un nodo con info=x mantenendo la proprietà BST

//PRE=Albero ben formato e x>0
nodo* BST::insert(nodo*r, int x){
    if(!r) return new nodo(x);
    if(r->info >= x)
    //PRE_RIC=Albero ben formato e non vuoto 
    r->left=insert(r->left, x); 
    //POST_RIC=Mi sposto nel sottoalbero sx (stessa cosa vale per il dx)
    else 
    r->right=insert(r->right, x); 
    return r;
}
//POST=restituisce albero BST ben formato secondo la proprietà BST

//Prova induttiva della funzione 2:

/*

Dato un albero ben formato, si distinguono subito i vari casi base:
se l'albero è vuoto, si ritorna un nuovo nodo e si ritorna l'albero,
coerentemente con POST.
Ora si guarda l'albero seguendo la proprietà BST.
Se il campo info del nodo attuale risulta maggiore/uguale ad x,
mi sposto sul sottoalbero sx. La PRE_RIC mi garantisce l'esistenza
dell'albero e la POST_RIC è sempre verificata, poiché l'albero esiste.
Se invece il campo info del nodo attuale risulta minore di x,
vado a dx, ripetendo di fatto la stessa operazione di prima.
Coerentemente con POST, l'intera funzione restituisce un albero ben formato
*/

//Ricerca di un nodo con info=x

//PRE=Albero ben formato
bool BST::search(nodo*r, int x){
    if(r->info==x)
    return true;
    if(r->left)
    return search(r->left, x);
    if(r->right)
    return search(r->right, x);
}
//POST=La funzione restituisce true sse trova un nodo r con info==x,
//false sse non trova un campo con info==x

bool BST::search_bst(nodo*r, int x){
    if(r->info==x)
        return true;
    if(r->left && r->info > x)
        return search(r->left, x);
    if(r->right && r->info < x)
        return search(r->right, x);
    return false;
}

//Calcolo del campo info massimo e minimo
nodo* maggiore(nodo*a, nodo*b){
    if(a->info>=b->info)
    return a;
    else
    return b;
}

nodo* minore(nodo*a, nodo*b){
    if(a->info<=b->info)
    return a;
    else   
    return b;
}

//Calcolo del campo info massimo e minimo

//PRE=Albero ben formato
nodo* BST::max(nodo*r)
{
    if(r->right)
    return max(r->right);

    return r;
}
//POST=La funzione restituisce il nodo maggiore in tutto l'albero
//(essendo BST, basta cercare a dx per il maggiore; 
//lo stesso per sx per il minore)

//PRE=Albero ben formato
nodo* BST::min(nodo*r)
{
    if(r->left)
    return min(r->left);

    return r;
}
//POST=La funzione restituisce il nodo minore di tutto l'albero

//Calcolo dell’altezza dell’albero
int BST::altezza(nodo *r)
{
    if(!r) return -1; 
    else {
    int a=altezza(r->left);
    int b=altezza(r->right); 
    if(a>b) return a+1; 
    return b+1;
    } 
}
//POST=La funzione restituisce l'altezza di un nodo non vuoto, tra a & b

bool foglia(nodo *r) 
{return (!r->left && !r->right);}

//Calcolo della lunghezza minima tra i cammini che collegano la radice ad 
//una foglia

//PRE=Albero ben formato
int BST::altMin(nodo*r){
    if(!r) return -1;
    if(foglia(r)) return 1;
    else{
        int a=altMin(r->left);
        int b=altMin(r->right);
        if(a!=-1 && b!=-1){
            if(a<=b)
            return a;
            else
            return b;
        }
        if(a!=-1) return a;
        return b;
    }
}
//POST=Restituisce l'altezza minima dell'albero, nel caso in cui siano diverse da -1