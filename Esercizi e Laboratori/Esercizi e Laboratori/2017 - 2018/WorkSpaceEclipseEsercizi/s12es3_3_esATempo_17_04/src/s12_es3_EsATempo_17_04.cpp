#include<iostream>
using namespace std;
struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};

nodo* buildtree(nodo* r, int n);
 nodo* alberobil (nodo*r, int k) ;
 int contaFoglie(nodo*);
void stampa_l(nodo *r);
int main()
{
  int n;
  cin>>n;
  nodo* R=buildtree(0,n);//da fare
  cout<<"start"<<endl;
  stampa_l(R); //da fare, vista in classe

  cout<<endl<<"end";
}
//PRE=(albero(r) è corretto e bilanciato, n>=0, valbero(r)=albero(r))
nodo* buildtree(nodo* r, int n) {
      if(n){
         int info;
         cin>> info;

         r = alberobil(r,info);

         buildtree(r,n-1);
     }
     return r;
}
//POST=(restituisce valbero(r) con n nodi aggiuntivi inseriti in modo da conservare il bilanciamento)



// PRE=(albero(r) è corretto e bilanciato nel senso spiegato nell’Esempio 1, valbero(r)=albero(r))
 nodo* alberobil (nodo*r, int k) {


    if(!r) return new nodo(k,0,0);
    //caso base 1: il nodo e' vuoto, percio' il nodo va inserito nella posizione corrente.



    if(r->left && r->right){
        int contaLeft= contaFoglie(r->left);

        int contaRight= contaFoglie(r->right);

        if(contaLeft>contaRight )
        //esistono sia nodo dx che sx quindi devo verificare su quale ramo devo inserire il nuovo nodo
        //caso ricorsivo 1:ramo sinistro ha piu' foglie del ramo dx percio' il nodo nuovo va sul ramo destro


        //pre_ric:albero(r->left) è corretto e bilanciato nel senso spiegato nell’Esempio 1, valbero(r)=albero(r)
            r->right= alberobil(r->right,k);
        //post_ric:albero(r->right) è corretto e ancora bilanciato ed è ottenuto da valbero(r) aggiungendogli  una nuova foglia  con info=k

        else

        //caso ricorsivo 2: ramo sinistro non ha piu' foglie del ramo dx, percio' il nodo nuovo va sul ramo sinistro
        //pre_ric:albero(r->left) è corretto e bilanciato nel senso spiegato nell’Esempio 1, valbero(r->left)=albero(r->left)
            r->left= alberobil(r->left,k);
        //post_ric:albero(r->left) è corretto e ancora bilanciato ed è ottenuto da valbero(r) aggiungendogli  una nuova foglia  con info=k

         return r;

    }


    if(r->left ){

        //caso ricorsivo 3: esiste il ramo sx quindi il nuovo nodo va inserito nel ramo destro
        //pre_ric:albero(r->right) è corretto e bilanciato nel senso spiegato nell’Esempio 1, valbero(r)=albero(r)
        r->right= alberobil(r->right,k);
        //post_ric:albero(r->right) è corretto e ancora bilanciato ed è ottenuto da valbero(r) aggiungendogli  una nuova foglia  con info=k


        return r;
    }else{


        //caso ricorsivo 4: non esiste il ramo sx quindi il nuovo nodo va inserito nel ramo sinistro
        //pre_ric:albero(r) è corretto e bilanciato nel senso spiegato nell’Esempio 1, valbero(r)=albero(r)
         r->left= alberobil(r->left, k);
        //post_ric:albero(r) è corretto e ancora bilanciato ed è ottenuto da valbero(r) aggiungendogli  una nuova foglia  con info=k

        return r;
    }

    /**
     *
     * caso ricorsivo 1 e 2:
     *
     *  esistono sia il ramo sx che dx, quindi secondo la richiesta della consegna, il nuovo nodo va inserito nel ramo dx se il ramo sx ha un nodo in piu',
     *  nel ramo sinistro se hanno il numero di nodi uguali.  quindi dal sottoalbero successivo, si verifica di nuovo il numero dei nodi sx e dx se esistono
     *  a loro volta.
     *
     * se il pre e' vera, allora e' giusto anche il pre_ric poiche' si tratta dello sottoalbero sinistro o sottoalbero destro. Quindi per il passo induttivo
     *  e' giusto anche il post_ric. '
     *
     *
     *
     * caso ricorsivo 3 e 4:
     *
     * Se esiste il ramo sx del nodo ma non quello dx, allora la foglia nuova va inserito nel ramo destro bilanciando cosi albero.
     *
     * mentre se non esiste quello sx, vuol dire che una nuova foglia deve essere inserito nel ramo sx.
     *
     *
     *
     * Dopo inserito del nuovo nodo, se albero iniziale era bilanciato, e il nodo nuovo e' stato inserito secondo le regol esplicitate della consegna,
     * il sotto albero modificato e' bilanciato a sua volta, quindi albero originale con il nuovo nodo e' bilanciato.
     *
     **/





 }


// POST=(albero(r) è corretto e ancora bilanciato ed è ottenuto da valbero(r) aggiungendogli  una nuova foglia  con info=k)


int contaFoglie(nodo* r){


    if(!r) return 0;

    return 1+contaFoglie(r->left)+contaFoglie(r->right);
}

void stampa_l(nodo *r)
{
    if(r){
        cout<<r->info<<'(';
        stampa_l(r->left);
        cout<<',';
        stampa_l(r->right);
        cout<<')';
    }
    else
        cout<< '_';
}
