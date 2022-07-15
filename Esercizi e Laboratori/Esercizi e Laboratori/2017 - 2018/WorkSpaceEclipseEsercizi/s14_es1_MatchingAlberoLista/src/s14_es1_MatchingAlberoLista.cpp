#include<iostream>
using namespace std;
struct nodoA{int info; nodoA* left,*right; nodoA(int a=0, nodoA*b=0,nodoA*c=0){info=a; left=b; right=c;}};
struct nodo{nodoA* info; nodo* next; nodo(nodoA* a=0, nodo*b=0){info=a; next=b;}};

void stampa_l(nodoA *r);
int conta_n(nodoA*r);

nodoA* insert(nodoA*r, int y);

nodoA* buildtree(nodoA*r, int dim);


void riempi(int*P,int m);
void stampaL(nodo*a);
nodo*match(nodoA*r, int*P, int dimP);
int main()
{
  int  n,m;
  cout<<"start"<<endl;
  cin>> n;
  nodoA*R=buildtree(0,n);
  stampa_l(R);
  cout<<endl;
  int P[50];
  cin>> m;
  riempi(P,m);
  nodo*a=match(R,P,m);
  if(a){
      stampaL(a);
    // cout<<"a"<<endl;
      }

    else
      cout<<"no match found"<<endl;
  cout<<"end"<<endl;
}

nodoA* buildtree(nodoA*r, int dim)
{
  if(dim)
   {
    int z;
    cin>>z;
    nodoA*x=insert(r,z);
    return buildtree(x,dim-1);
   }
  return r;
}
void riempi(int*P,int m)
{
  if(m)
    {
      cin>>*P;
      riempi(P+1,m-1);
    }
}
void stampaL(nodo*a)
{
  if(a)
    {
      cout<<a->info->info<<' ';
      stampaL(a->next);
    }
  else
    cout<<endl;
}
nodoA* insert(nodoA*r, int y)
{
  if(!r) return new nodoA(y);

  if(conta_n(r->left)<=conta_n(r->right))
    r->left=insert(r->left,y);
   else
    r->right=insert(r->right,y);
  return r;
}
void concatena(nodo*& l1, nodo* l2){
	if(!l1)
		l1= l2;
	else{
		concatena(l1->next, l2);
	}
}
int conta_n(nodoA*r)
{
   if(!r) return 0;
     else
    return conta_n(r->left)+conta_n(r->right)+1;
}
void stampa_l(nodoA *r)
{
  if(r)
    {
      cout<<r->info<<'(';
      stampa_l(r->left);
      cout<<',';
      stampa_l(r->right);
      cout<<')';
    }
  else
    cout<< '_';
}
//PRE=(albero(r)ben formato, P ha dimP elementi con dimP>0)
nodo*match(nodoA*r, int*P, int dimP){

// caso base 1:albero e' vuoto, e quindi e' giusto restituire 0 come puntatore alla lista dei nodi del match.
	if(!r) return 0;

	nodo* newNodo=0;
	// trovato il match nel nodo corrente
	if(r->info == P[0]){
		newNodo= new nodo(r,0);
		P+=1;
		dimP-=1;
	}
	if(dimP>0){

		//CASO RICORSIVO 1
	    //PRE_ric:(albero(r->left)ben formato, P ha dimP elementi con dimP>0)
		nodo* nodoSucc= match(r->left, P, dimP);
		//POST_ric:
//		   (se esiste su un cammino di albero(r->left)un match di P (se non e' stato trovato il match corrente) e P+=1
//		   (se e' stato trovato il match), allora, restituisce una lista concatenata con dimP (se non e' stato trovato
//		   il match corrente) e dimP-=1 (se e' stato trovato il match), nodi ciascuno dei quali punta ad un nodo
//		   di albero(r->left) che partecipa al match trovato) &&(altrimenti restituisce 0)
		if(!nodoSucc)
		//PRE_ric:
//			(albero(r->right)ben formato, P ha dimP elementi con dimP>0)
			nodoSucc= match(r->right, P, dimP);
		//POST_ric:
//		(se esiste su un cammino di albero(r->right)un match di P+1,
//	   allora, restituisce una lista concatenata con dimP-1 nodi ciascuno dei quali punta ad un nodo
//	   di albero(r->right) che partecipa al match trovato) &&(altrimenti restituisce 0)

		if(nodoSucc && newNodo){
			// controllo che il nodo corrente e' un match e il nodo restituito dai casi ricorsivi sia il puntatore ad un nodo
			//quindi concateno il nodo restituito al nodo corrente.
			newNodo->next= nodoSucc;
		}else if(nodoSucc)
//			altrimenti se esiste solo il nodo successivo, ma il nodo corrente non e' un match,
//			quindi devo restituire solo il nodo restituito dalle chiamate ricorsive.
     		return nodoSucc;
    		else // il nodo corrente non e' un match & nodo restituito dalle chiamate ricorsive e' NULL, quindi restituisco 0.
    		return 0;
	}
	return newNodo;
/***************************  Prova di Corettezza ***************************
 *
 * caso base 1: il nodo corrente e' nullo, e se si e' arrivato a questo punto dell'esecuzione, vuol dire che dimP !=0
 * 				il che vuol dire che non ho trovato il match, quindi restituisco il puntatore NULL.
 *
 * nell'if dopo il primo caso base, si verifica se e' stato trovato il match nel nodo corrente, se si aumento il puntatore dell'array
 * all'elemento successivo, e diminuisco il dimP di uno, il che indica che ho un elemento dell'array in meno da matchare.
 *
 * caso base 2: dimP<=0 ma siccome all'inizio il dimP dal PRE e' dimP>0, quindi potra' solo essere pari a 0, quindi se
 * dimP>0 e' falso, vuol dire che abbiamo esaurito gli elementi dell'array da matchare, quindi abbiamo trovato il match completo.
 * 	Quindi restituisco il newNodo= new nodoA(r,0).  Se questo nodo non e' un match quindi non effettuo nessuna operazione su dimP,
 * 	allora dimP>0.
 *
 * 	caso ricorsivo 1:
 *
 * 	Dal Pre abbiamo che: (albero(r)ben formato, P ha dimP elementi con dimP>0), se arriviamo a questa chiamata ricorsiva vuol dire che
 * 	dimP o dimP-1 (nel caso del match del nodo corrente) e' >0, il che significa che ci sono altri elementi da matchare,
 * 	quindi faccio la chiamata ricorsiva sul ramo sinistro, con seguente pre_ric:
 * 		 (albero(r->left)ben formato, P ha dimP elementi con dimP>0)
 *  che e' vera perche' garantita dal PRE, nel caso in cui dimP passato dalla funzione chiamante sia 1, allora se viene trovato il match
 * allora dimP-1 non e' piu >0, allora e' corretto restituire direttamente il nodo corrente, mentre se non viene trovato il match, allora
 * dimP>1 e' vera, quindi si effettua la chiamata ricorsiva. Mentre per la varibile P, se e' stato trovato il match, P+1 e' sempre valida,
 * mentre se non e' stata trovata il match allora P e' piu' che corretto perche' garantito dal PRE.
 *
 * Grazie al passo induttivo, possiamo affermare che il POST_ric sia vera, perche' se e' stato trovato il match, allora abbiamo P+1 e dimP-1
 * mentre se non e' stata trovata il match abbiamo sempre P e dimP, mentre se il nodo restituito dalla chiamata ricorsiva e' nullo, allora non
 * e' stato trovato il match nel ramo sinistro, allora la ricerca va effettuata sul ramo destro che e' il secondo caso ricorsivo.
 * se il esiste il nodoSucc contemporaneamente al newNodo (che e' il nodo che contiene r in caso del match del nodo corrente) allora
 * concateno il nodoSucc al newNodo. altrimenti se uno dei due nodi e' nullo, allora controllo se nodoSucc e' diverso da nullo, se si
 * allora restituisco il nodoSucc che e' il risultato della chiama ricorsiva. oppure restituisco 0 se il nodoSucc e' nullo.
 *
 * Quindi possiamo affermare che il POST e' vera, perche' con l'insieme dei nodi restituiti dalle chiamata ricorsive, si forma una lista che
 * contiene i nodi dell'albero. Mentre se in un ramo non viene trovato il match completo, allora vengono restituiti NULL a cascata, quindi
 * al chiamante viene restituito il NULL, il che soddisfa il POST.
 *
 *
 * caso ricorsivo 2:
 * per la dimostrazione della  correttezza di questa chiamata ricorsiva e' analoga al primo. Con l'unica differenza che viene invocata sul
 * r(r->right) sse l'invocazione sinistra fallisce.
 *
 */

}
//POST=(se esiste su un cammino di albero(r)un match di P,
//allora, restituisce una lista concatenata con dimP nodi ciascuno dei quali punta ad un nodo
//di albero(r) che partecipa al match trovato) &&(altrimenti restituisce 0)


