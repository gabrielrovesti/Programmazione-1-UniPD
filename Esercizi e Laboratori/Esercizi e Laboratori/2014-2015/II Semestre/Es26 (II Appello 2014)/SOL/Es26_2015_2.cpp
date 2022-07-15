
//soluzione by: Riccardo M.

#include<iostream>
#include<fstream>
using namespace std;

/////////////////////////////////////////////////////////////////////////
///////////////////////////  FUNZIONI DATE  /////////////////////////////
/////////////////////////////////////////////////////////////////////////

struct nodo{
    
    int info1, info2;
    nodo* next;
    
    nodo(int a=0, int c=0, nodo* b=0){
        
        info1=a;
        info2=c;
        next=b;
        
    }
    
};

nodo* copia(nodo* X){
  
    if(X){
        
        return new nodo(X->info1, X->info2, copia(X->next));
        
    }
    
    return 0;

}

void crea(nodo* &L, int dim, ifstream & INP, int n){
  
    int x;
    
    if(n<dim){
      
        INP>>x;
        L=new nodo(x,n,0);
        crea(L->next, dim,INP,n+1);
    }
    
    else{
        
        L=0;
        
    }
    
}

void crea1(nodo*&L, int dim, ifstream & INP, int n){
    
    int x,y;
  
    if(n<dim){
      
        INP>>x>>y;
        L=new nodo(x,y,0);
        crea1(L->next, dim,INP,n+1);
      
    }
    
    else{
        
        L=0;
        
    }
}

void stampa(nodo* x, ofstream & OUT){
    
    if(x){
      
        OUT<<'('<< x->info1<<','<<x->info2<<')';
        if(x->next)
        OUT<<"->";
        stampa(x->next, OUT);
        
    }
   
    else{
        
        OUT<<endl;
        
    }
    
}


/////////////////////////////////////////////////////////////////////////
/////////////////////////  FUNZIONI CREATE  /////////////////////////////
/////////////////////////////////////////////////////////////////////////

//PRE_startmatch=(T è lista corretta, indiceP>=0, indiceT>=0)
int startMatch(nodo* T, int *P, int indiceP, int indiceT){
    
    nodo *punt = T;
    
    for(int i=0; i<indiceT; i++){   //Vado all'indice di T che mi serve per iniziare il match
        
        if(punt->next){                 //Se esiste il successivo...
            punt = punt->next;              //...mi muovo
        }
        
        else{                           //Altrimentri...
            return -1;                      //...ritorno -1
        }
        
    }
    
    for(int i=0; true; ){           //Inizio il controllo
        
        if(punt->info1==P[indiceP]){    //Se il campo info1 è uguale a P[indiceP]
            return punt->info2;             //la ricerca si ferma
        }
      
        else{                           //Altrimenti
            
            if(punt->next){                 //se esiste un prossimo
                punt=punt->next;                //mi sposto sul prossimo
                i++;                            //e continuo la ricerca
            }
            
            else{                           //se non esiste
                return -1;                      //non ho trovato il match
            }
            
        }
        
    }
    
    return -1;
    
}
//POST_checklung=(restituisce con il return l'indice di T che ha campo info1 uguale a P[indiceP]) && (restituisce -1 se non esiste tale campo)

//POST_checklung=(T è lista corretta, P contiene dimP elementi, dimP >= 0 e indiceT>=0)
int checkLung(nodo* T, int *P, int indiceP, int indiceT, int dimP){
    
    if(indiceT == -1){
        
        return 0;
        
    }
    
    nodo *punt = T;
    
    for(int i=0; i<indiceT; i++){   //Vado all'indice di T che mi serve per iniziare il match
        
        if(punt->next){                 //Se esiste il successivo...
            punt = punt->next;              //...mi muovo
        }
        
        else{                           //Altrimentri...
            return 0;                      //...ritorno -1
        }
        
    }
    
    for(int i=0; true; ){     //Controllo quanto è lungo il match
        
        if(P[indiceP+i]==punt->info1){  //Se trovo un match tra il campo info1 di T e P[i]
            i++;                            //cerco il prossimo
            
            if(i==dimP){                        //se ho trovato tutto il match
                return i;                           //ritorno la lunghezza
            }
            
            if(punt->next){
                punt = punt->next;
            }
            
            else{
                return i;
            }
            
        }
        
        else{                           //Se non trovo match
            return i;                       //ritorno la lunghezza fin'ora trovata
        }
        
    }
    
    return 0;
    
}
//POST_checklung=(resistuisce con il return la lunghezza del match di P[indiceP..dimP-1] in T a partire dal nodo T(x, indiceT))

//PRE_M1=(T lista corretta, dimP>=0)
nodo* M1(nodo* T, int *P, int dimP){
    
    if(!T){                                     //Se ho una lista vuota
        return 0;                                   //non potrà esserci alcun match
    }
    
    int indiceT=-1, lung=0;                     //Variabili per il controllo dell'indice di T dove inizia il match di P[ ] e la lunghezza del match stesso
    nodo *lista;                                //Lista che descrive il match
    
    indiceT = startMatch(T, P, 0, 0);           //Cerca l'indice di T dal quale inizia il match di P
    lung = checkLung(T, P, 0, indiceT, dimP);   //Cerca la lunghezza del match di P[0..dimP-1] dal nodo T(x, indiceT)
    
    if(indiceT == -1 || !lung){                 //Se il match iniziale non esiste
        return 0;                                   //ritorna la lista vuota
    }
    
    else{                                       //Se il match iniziale
        lista = new nodo(indiceT, lung);            //costruisci il primo nodo
    }
    
    int ultimoT = indiceT + lung;               //Nodo di T dal quale partire per continuare a cercare il match
    nodo *pros = lista;                         //Puntatore di riferimento
    
    while(indiceT!= -1 && lung!=0){             //Se il match esistere
    
        /* R = (il match di P[lung..dimP-1] esiste e inizia in un nodo di T definito <=> indiceT!=-1 && lung!=0) */
       
        indiceT = startMatch(T, P, lung, ultimoT);      //calcola l'indice di T dal quale partire
        lung = checkLung(T, P, lung, indiceT, dimP);    //calcola la lunghezza del match

        if(indiceT!= -1 && lung!= 0){                       //se il match esiste
            
            pros->next = new nodo(indiceT-ultimoT, lung, 0);    //aggiungi un nodo
            pros = pros->next;                                  //sposta il puntatore
            ultimoT = indiceT + lung;                           //modifica l'indice di T dal quale partirà il prossimo match
            lung += lung;                                       //modifica l'indice di P dal quale partirà il prossimo match

        }
        
    }

    return lista;
    
}
//POST_M1=(restituisce col return la lista del match di P in T)

//PRE_saltaNodi=(T è una lista corretta non vuota, info1 è un intero >=0)
nodo *&saltaNodi(nodo *&T, int info1){
	if(T && info1)
		return saltaNodi(T->next,info1-1);
	//o è finita la lista o T è il puntatore al info1-esimo nodo
	return T;
}//POST_saltaNodi=(se all'invocazione la lista aveva nodi sufficienti il puntatore T iniziale punta all'info1-esimo nodo successivo; altrimenti punta al nodo successivo all'ultimo della lista)

//PRE_togliNodi=(T è una lista corretta non vuota, info2 è un intero >0)
nodo *togliNodi(nodo *&T, int info2){
	if(!T || !info2)
		return T;
	nodo *aux=T; //mi ricordo il puntatore per deallocare il nodo
	T=T->next;
	delete aux;
	return togliNodi(T,info2-1);
}//POST_togliNodi=(se all'invocazione T era vuota o info2=0 allora ritorna T (che è vuoto o altrimenti non ci siamo spostati); altrimenti se all'invocazione la lista aveva nodi sufficienti il nodo successivo al puntatore T iniziale punta all'info2-esimo nodo successivo (o a quello successivo all'ultimo della lista) e i nodi tolti sono deallocati)

//PRE_TB=(T e X sono liste corrette, i campi info1 e info2 dei nodi di X (se ci sono nodi) sono tutti maggiori o uguali a 0, T=vT)
void TB(nodo*&T, nodo*X){

	if(!T || !X)
		return ;
	nodo *&aux1=saltaNodi(T,X->info1);
	if(aux1){ //risparmio una chiamata di funzione
		nodo *aux2=togliNodi(aux1,X->info2);
		aux1=aux2; //aux1 è uno dei nodi da togliere!
		if(X->next) //risparmio una chiamata di funzione
			TB(aux1,X->next);
	}

}//POST_TB=(T=(vT-X), i nodi di (X di vT) sono deallocati)

//PRE_TC=(T e X sono liste corrette, i campi info1 e info2 dei nodi di X (se ci sono nodi) sono tutti maggiori o uguali a 0, T=vT)
nodo* TC(nodo*&T, nodo*X){
	if(!T || !X)
		return 0;
	if(X->info1){ //salto i nodi
		X->info1--;
		return TC(T->next,X);
	}else{ //stacco i nodi
		if(X->info2){
			X->info2--;
			nodo *aux=T;
			T=T->next;
			return new nodo(aux->info1,aux->info2,TC(T,X));
			delete aux; //pulizia
		}else return TC(T,X->next);
	}
}//POST_TC=( T=(vT-X), e restituisce (X di vT) con il return)


main(){
    
    try{
        
        ifstream INP("input");
        ofstream OUT("output");
        
        if(!INP){
            
            throw(0);
            
        }
        
        if(!OUT){
            
            throw(1);
            
        }
        
        int P[100], dim, dimP, dimX;
        INP>>dim>>dimP>>dimX;
  
        nodo*L=0;
        crea(L,dim,INP,0);
  
        for(int i=0;i<dimP ; i++){
            
            INP>>P[i];
            
        }
        
        nodo *z = M1(L, P,dimP);
     
        if(!z){
            
            OUT<<"nessun match"<<endl;
            
        }
        
        else{
            
            stampa(z,OUT);
            
        }

        OUT<<endl;
        nodo* X=0;
        crea1(X,dimX,INP,0);
        nodo*L1=copia(L);
        TB(L1,X);               //da fare
        nodo* z1=TC(L,X);       //da fare 
        stampa(L,OUT);
        stampa(z1,OUT);
        
    }
    
    catch(int x){
        
        switch(x){
            
            case 0: cout<<"problemi con input"<<endl; break;
            case 1: cout<<"problemi con output"<<endl; break;
            
        }
        
    }
    
}
