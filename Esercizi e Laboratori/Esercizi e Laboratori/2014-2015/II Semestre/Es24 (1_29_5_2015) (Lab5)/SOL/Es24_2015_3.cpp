
//soluzione by: Saverio F.

FIFO togli_primo(FIFO x){
        if(!(x.primo)->next){
                delete x.primo;
                return FIFO();
        }else{
                punt* a=x.primo;
                x.primo=a->next;
                delete a;
                return x;
        }
}
 
FIFO metti_fondo(FIFO x, nodo* a){
        if(!x.fine){
                x.fine=new punt(a);
                x.primo=x.fine;
                return x;
        }else{
                (x.fine)->next=new punt(a);
                x.fine=(x.fine)->next;
                return x;
        }
}
 
FIFO f1(nodo*r){
        //PRE=(albero(r) è corretto, y è definito)
        FIFO x=FIFO();
        x.primo=new punt(r);
        x.fine=x.primo;
        return x;
        //POST=(restituisce il valore FIFO x che è corretto e tale che lista(x) è costituita da un solo nodo che punta a r)
}
 
nodo* f2(FIFO x, int y, ofstream & OUT){
        //PRE=(x è corretto, y definito)
 
        if(((x.primo)->t)->info==y) { //controllo il match, se lo trovo interrompo tutto
                return ((x.primo)->t);
        }
 
        OUT<<"nodo: "<<((x.primo)->t)->info<<endl; //stampo i nodi che guardo
 
        if(((x.primo)->t)->left) //se esistono metto in fondo i vari figli
                x=metti_fondo(x,((x.primo)->t)->left);
        if(((x.primo)->t)->right)
                x=metti_fondo(x,((x.primo)->t)->right);
 
        if(!(x.primo)->next){
                return 0; //se ho finito basta
        }
 
        x=togli_primo(x); //tolgo il primo
 
        nodo* l=f2(x,y,OUT); //ricorsione
 
        //POST=( stampa i campi info di tutti i nodi degli albericon radice in lista(x) attraversati per livelli fino a
		//trovarne uno con campo info=y o fino ad esaurire tutti inodi. Nel primo la lista corrente va deallocata )
}
