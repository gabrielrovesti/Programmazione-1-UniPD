#include<iostream>

#include "Code.h"

using namespace std;

void push (int c, coda &Q){

    nodo* n = new nodo(c,0);

    if(!Q.inizio){
        Q.inizio=n;
	    Q.fine=n;
    }else{

    	Q.fine->next= n;
    	Q.fine=n;

    }

}

char pop (coda &Q){

	nodo* n= Q.inizio;

	int c=n->chiave;

	Q.inizio= (*Q.inizio).next;
	delete(n);

	return c;
}
bool e_vuota(coda Q){

         return !Q.inizio;
}

void elimina(coda& Q, nodo &node,int k, int i){

	if(node.next == & node){
		int c= node.chiave;
		cout<<c<< " sopravvive"<<endl;
	}else if(k==1){

        // cout<<"Elimino il primo nodo"<<endl;
    	nodo* nodoDaEliminare= Q.fine->next;

    	Q.fine->next= Q.inizio->next;
    	Q.inizio=Q.inizio->next;

		cout<<nodoDaEliminare->chiave<<" eliminata"<<endl;
		delete(nodoDaEliminare);
		elimina(Q,*Q.inizio,k,0);


    }else {

		if(k-2!=i){
            // cout<<"Elimino il secondo nodo"<<endl;
			elimina(Q, *(node.next),k,i+1);
		}
		else{

	        nodo* nodoDaEliminare= node.next;

    		node.next= nodoDaEliminare->next;

    		cout<<nodoDaEliminare->chiave<<" eliminata"<<endl;
    		delete(nodoDaEliminare);

			elimina(Q,*node.next,k,0);


		}


}
}
