#ifndef CODE_H
#define CODE_H

struct nodo {
    char chiave;
    nodo *next;
    nodo(char c='\0', nodo* n=0){
        chiave =c;
        next=n;
    };
};

struct coda {
    nodo *inizio;
    nodo *fine;
    coda(nodo * i=0, nodo * f = 0){
        inizio=i;
        fine=f;
    };
};

void push(char c, coda &Q);
char pop(coda &Q);
bool e_vuota(coda Q);

#endif /* CODE_H */
