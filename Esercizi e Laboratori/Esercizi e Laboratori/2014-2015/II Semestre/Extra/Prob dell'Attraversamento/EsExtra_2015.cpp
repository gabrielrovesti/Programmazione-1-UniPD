
//by: Leo M.

/* NOTA:
programma che espande in maniera sostanziale il "Problema dell'Attraversamento" (presente nel .pdf di Lez13).
di fatto è un semplice risolutore di labirinti:
visualizza il labirinto, chiede un punto d'ingresso (la coordinata della colonna) e poi prova a risolverlo.
il "labirinto" lo carica da file di input, dove è rappresentato da una matrice di 0-1 in cui 1 descrive la strada e 0 gli ostacoli/muri pieni.

PS: dato che ne ho fatte svariate versioni, con successivi accorgimenti, non ricordo in dettaglio questo cosa faccia o meno:
in particolare non ricordo se avevo concluso la questione dei "circuiti/loop" nel cammino...

se vi piace prendetene pure spunto e miglioratelo.
*/

#include <iostream>
#include <fstream>

using namespace std;

bool explore(int S[][10], int j, int i, int prec_j, int prec_i)
{
	cout<<"S["<<j<<"]["<<i<<"]"<<" ";	//stampa la sequenza esatta di passi che fa (anche i percorsi ciechi)
	
	bool trovato;
	if(j==9)	//ho vinto
		return true;
	else
	{
		if( ((j!=9) && S[j+1][i]!=false) && !(j+1==prec_j && i==prec_i) )	//if(giu && !VenutoDaGiu) -> (j!=9) inutile, se j==9 non sarei qui, "&& i==prec_i" inutile
		{	
			S[j][i]=false;
			trovato=explore(S, j+1, i, j, i);	//passo alla posizione SOTTO (giu)
		}
			
		if(!trovato && (i!=0 && S[j][i-1]!=false) && !(j==prec_j && i-1==prec_i) )	//se ancora non l'ho trovato e if(sx && !VenutoDaSx) -> (i!=0) bound, "j==prec_j" inutile
		{	
			S[j][i]=false;
			trovato=explore(S, j, i-1, j, i);	//passo alla posizione a SINISTRA (sx)
		}
			
		if(!trovato && (i!=9 && S[j][i+1]!=false) && !(j==prec_j && i+1==prec_i) )	//se ancora non l'ho trovato e if(dx && !VenutoDaDx) -> (i!=9) bound, "j==prec_j" inutile
		{	
			S[j][i]=false;
			trovato=explore(S, j, i+1, j, i);	//passo alla posizione a DESTRA (dx)
		}
			
		if(!trovato && (j!=0 && S[j-1][i]!=false) && !(j-1==prec_j && i==prec_i) )	//se ancora non l'ho trovato e if(su && !VenutoDaSu) -> (j!=0) bound, "i==prec_i" inutile
		{	
			S[j][i]=false;
			trovato=explore(S, j-1, i, j, i);	//passo alla posizione a SOPRA (su)
		}
		
		if(!trovato)
		{
		S[j][i]=false;	//cemento la strada senza uscita
			
		//stampo il labirinto in modo "figo"
		char c=219;
		cout<<endl;
		cout<<"   0 1 2 3 4 5 6 7 8 9"<<endl;
		cout<<"  +--------------------+"<<endl;
		for(int j=0; j<10; j++)
		{
			cout<<j<<" |";
			for(int i=0; i<10; i++)
				if(S[j][i])
					cout<<"  ";
				else
					cout<<c<<c;
			cout<<"|"<<endl;
		}
		cout<<"  +--------------------+"<<endl;
		cout<<endl;
		}
		return trovato;	//se l'ho trovato NON occorre esplorare altre strade, sennò devo procedere con l'esplorazione dall'ultima posiz che non ho ancora controllato del tutto
	}
}



main()
{	//PRE=().
	ifstream INP("input.txt");
	ofstream OUT("output.txt");
	if( INP && OUT)
	{
		int S[10][10];
		
		for(int j=0; j<10; j++)	//riempio il labirinto
			for(int i=0; i<10; i++)
				INP >> S[j][i];
		
		//stampo il labirinto in modo "figo"
		char c=219;
		cout<<"   0 1 2 3 4 5 6 7 8 9"<<endl;
		cout<<"  +--------------------+"<<endl;
		for(int j=0; j<10; j++)
		{
			cout<<j<<" |";
			for(int i=0; i<10; i++)
				if(S[j][i])
					cout<<"  ";
				else
					cout<<c<<c;
			cout<<"|"<<endl;
		}
		cout<<"  +--------------------+"<<endl;
		cout<<endl;
		
		bool trovata=false;
		int start=0;	//chiedo all'utente da dove partire (solo da che colonna)
		cout<<"start point: ";
		cin>>start;
		if(start>=0 && start<10 && S[0][start]!=false)
			trovata=explore(S, 0, start, -1, -1);
		else
			cout<<"start point NON valido";
		
		cout<<endl<<"trovata="<<trovata<<endl;
	
		INP.close();
		OUT.close();	
	}
	else
		cerr<<"Errore File!"<<endl;	
}	/* POST=(). */

