#include<iostream>

using namespace std;

struct coppia{int salta,prendi; coppia(int a=0,int b=0){salta=a;prendi=b;}};



bool F(char* T, char* P, int dimT, int dimP, coppia *X) ;

int match (char* T, char*P, int dimT, int dimP) ;

int not_matc(char*T, char x, int dimT) ;

void stampa(coppia [50]);


int main()
{
  int dimT, dimP;
  char T[400],P[50];
  coppia X[50];

  for(int i=0; i<50; i++)
    X[i]=coppia(-1,-1);

  cin>> dimT>>dimP;

  for(int i=0; i<dimT; i++)
    cin>>T[i];
  for(int i=0; i<dimP; i++)
    cin>>P[i];
  cout<<"start"<<endl;
  if(F(T,P,dimT,dimP,X))
    stampa(X);
   else
    cout<<"nessun match completo"<<endl;
  cout<<"end"<<endl;
}
//PRE_F=(T ha dimT elementi definiti e P ne ha dimP, X ha gli elementi che ci servono)
bool F(char* T, char* P, int dimT, int dimP, coppia *X) {

	//caso base 1: se ho terminato elementi in P vuol dire che ho trovato il match
	if(  dimP == 0  ) return true ;

	//caso base 2: se ho terminato gli elementi in T e sono arriva a questo if vuol dire che ho esaurito gli elementi in T senza fare lo stesso in P,
	// percio' vuol dire che non ho trovato il mathc quindi restituisco il false.
	if(	dimT == 0 ) return false;


	int notMatchIniziale=0;

    //restituisce il numero degli primi elementi di T che non matchano con il primo elemento di P
	notMatchIniziale= not_matc(T, * (P),dimT);

	T+=notMatchIniziale;    // incremento il puntatore di T di elementi che non matchano, rendendo cosi il primo elementi di T uguale al primo elemento di P
	dimT-=notMatchIniziale; // diminuisco di notMatchIniziale elementi

	int matchIniziale=0;

	// la funzione trova il numero degli elementi di T che corrispondono agli elementi di P.
	matchIniziale= match(T, P, dimT, dimP);
	P+=matchIniziale;
	T+=matchIniziale;
	dimT-=matchIniziale;
	dimP-=matchIniziale;

	X[0].salta  = notMatchIniziale;
	X[0].prendi = matchIniziale;



//	caso ricorsivo:
	return F(T,P,dimT,dimP,X+1);

	/**                      Dimostrazione di correttezza della funzione F
	 *
	 * caso base 1: se la dimensione di P e' uguale a zero, allora significa che sono stati trovati tutti i match per tutti
	 * gli elmenti di P, quindi e' corretta restituire true.
	 *
	 * caso base 2: escluso il caso base 1, allora se dimT ==0, vuol dire che abbiamo esaurito gli elementi dell'array
	 * T, quindi non sono stati trovati tutti i match dell'array. ==> e' giusto restituire false.
	 *
	 *
	 * caso ricorsivo: se si e' arrivato all'esecuzione del caso ricorsivo allora vuol dire che i casi basi non sono stati
	 * soddisfatti, quindi ci sono ancora elementi sia in P che in T.
	 *  supponendo che la Pre sia vera, quindi posso dimostrare che pre_ric sia vera, poiche' P viene incrementato del
	 * numero degli elementi che o sono stati scelti o sono stati saltati, quindi la chiamata ricorsiva avviene su
	 * T+elementi presi + elementi saltati e P+elementi presi (perche' sono stati matchati), quindi per il passo induttivo,
	 *anche il post_ric e' corretta perche' restituisce il valore restituito dai casi su porzioni rimanenti dell'array
	 * che diventa sempre piu' piccola poiche' o si salta di notmatchIniziale elementi o si salta della somma di not match e match elementi.
	 * Quindi il post_ric e' corretta, quindi e' vera anche il post poiche' e' il risultato del match fatto su intero
	 * array.
	 *
	 *
	 *
	*/


}
//POST_F=(restituisce true sse esiste un match completo (con eventuali buchi) d P in T e, se il match c’è, X contiene le coppie che corrispondono al match)

//	PRE_m=( T ha dimT elementi definiti e P ne ha dimP)
int match (char* T, char*P, int dimT, int dimP) {

        //caso base 1: in T non ci sono piu' elementi o in P non ci sono piu' elementi, percio' restituisco 0
        //
		if( !(dimT > 0) || !(dimP >0)) return 0;

		//caso ricorsivo: trovato che T[0] == P[0]  percio' si prosegue la ricerca
		//  degli elementi di T che corrispondono agli elementi di O
		if(T[0]== P[0])
		//PRE_ric: T+1 ha dimT-1 elementi definiti e P+1 ne ha dimP-1 elementi
			return 1+match(T+1,P+1,dimT-1, dimP-1);
		//POST_ric: la funzione restituisce il numero degli elementi di (T+1) che matcha con gli elementi di P+1
		else
		// caso base 2: trovato elemento T[0] diverso da P[0] quindi non deve essere contato ultimo elemento
		// percio' restituisco 0.
			return 0;


	/**                      Dimostrazione di correttezza della funzione match
	 * caso base 1: se in T non ci sono piu' elementi oppure in P non ci sono piu' elementi, allora restituisco 0
	 *  perche' non ci potrai mai esserci il match.
	 *
	 * caso base 2: elemento T[0] e P[0] non sono uguali , quindi restituisco 0
	 *
	 *
	 * caso ricorsivo: supponendo che la PRE sia corretta, allora PRE_ric e' vera, poiche' elemento di posto 0 di T e P
	 *  sono uguali, percio' devo verificare se i successivi elementi ovvero P[1.. dimP-1] e T[1..dimT] ci siano o no
	 * delle corrispondenze, se non c'e' restituisce 0 garantito dal secondo caso base, se e' uguale restituisce 1+ il
	 * risultato della successiva invocazione ricorsiva, quindi per passo induttivo, la PRE_ric e' corretta.
	 * Se la PRE_ric e' corretta, allora lo e' anche il POST_ric, perche' restituisce il numero di match dei singoli
	 * elementi di T[1....dimT-1] e P[1.. dimP-1] sommato a match degli elementi di posto 0, quindi anche POST_ric e'
	 * corretta, il che rende vera anche il POST.
	 *
	*/

}
//	POST_m=(deve restituire la lunghezza del massimo prefisso di P che matcha a partire da T[0] in posizioni contigue, cioè senza buchi) Si osservi che match può restituire 0.

//	PRE_n=(T ha dimT elementi )
int not_matc(char*T, char x, int dimT) {

        // caso base 1: dimT non ha nemmeno un elemento,
        //quindi non puo' esserci un elemento che sia uguale a x, quindi restituisco 0 perche' non ci sono altri elmenti da saltare
		if(! (dimT> 0) ) return 0;


		if(T[0]!= x)
		// caso ricorsivo: abbiamo trovare il primo elemento di T e' diverso da X, percio' lo conto 1 quindi lo sommo al risultato della
		//  chiamata ricorsiva che retistituisce i primi n elementi di (T+1), ed e' corretto perche' contemporaneamente viene decrementato di 1
		// anche il dimT, non sono uguali a x
		// pre_ric: T+1 ha dimT-1 un elemento
			return 1+not_matc(T+1,x,dimT-1);
		// post_ric: restistusce n-1 elementi di T+1 da saltare perche' si trovi un elemento che e' uguale ad x.
		else
		//2: caso base: abbiamo trovato un elemento di T che corrisponde al char x,
		//quindi restituisco 0 perche' gli elementi da restituire non deve comprendere anche elemento che stiamo esaminando
			return 0;

	/**                      Dimostrazione di correttezza della funzione not_matc
	 *
	 * caso base 1: se non ci sono elementi da confrontare con il carattere x allora non c'e' nessuna corrispondenza,
	 * quindi restituisce 0, quindi e' corretta.
	 *
	 * caso base 2: trovato che elemento di posto 0 di T e' uguale al carattere x, quindi abbiamo trovato un match,
	 * ma ci interessa quanti sono i caratteri di non match finora confrontati, quindi devo restituire 0.
	 *
	 * caso ricorsivo:
	 *
	 * supponengo che la Pre sia vera, e deve esserlo, possono dimostra che veridicita' di PRE_ric poiche'
	 * la chiamata ricorsiva viene fatta su T+1  e dimT-1 perche' T[0] e' gia' stato confrontato con il carattere x e siccome non
	 * corrisponde, quindi vale 1 che verra' sommato al risultato dell'invocazione ricorsiva, se non ci sono piu' elementi,
	 * la funzione restituisce il valore corretto, garantito dal primo caso base, mentre se la T[1] e' uguale a x, allora e'
	 * garantito dal secondo caso base.
	 * quindi per il passo induttivo, il post_ric e' corretta, poiche' restituisce la somma degli uni ed eventuale 0
	 * dei due casi base essendo che controlla gli elementi rimasti dell'array T
	 * Se il post_ric e' corretta, allora  lo e' anche il post poiche' mentre la chiamata ricorsiva controllare gli elementi
	 * di posti T[1...dimT-1], la prima chiamata e' fatta su T[0...dimT-1]. quindi anche post_ric e' corretta.
	 *
	 *
	 *
	*/

}
//	POST_n=(restituisce il numero di elementi di T da saltare per arrivare a trovare x in T, partendo da T[0])

void stampa(coppia* coppie){

	if(coppie[0].salta!= -1){
		cout<<"("<<coppie->salta<<","<<coppie->prendi<<")";
		stampa(coppie+1);
	}else{
	    cout<<endl;
	}


}
