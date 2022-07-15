	#ifndef CODE_H
	#define CODE_H

	struct nodo {
		int chiave;
		nodo *next;
		nodo(int c=0, nodo* n=0){
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

	void push(int c, coda &Q);
	char pop(coda &Q);
	bool e_vuota(coda Q);
	void elimina(coda& Q, nodo &node,int k, int i);

	#endif /* CODE_H */
