#include<iostream>

#include "code.h"

using namespace std;

void push (char c, coda &Q){

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

	char c=n->chiave;

	Q.inizio= (*Q.inizio).next;
	delete(n);

	return c;
}
bool e_vuota(coda Q){

         return !Q.inizio;
}
