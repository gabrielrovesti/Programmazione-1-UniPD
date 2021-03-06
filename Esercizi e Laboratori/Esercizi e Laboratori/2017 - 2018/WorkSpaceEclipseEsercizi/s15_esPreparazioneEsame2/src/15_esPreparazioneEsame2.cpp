#include<iostream>
using namespace std;
struct nodo{
	int info;
	nodo* next;

	nodo(int a=0, nodo*b=0){
		info=a;
		next=b;
	}

};
struct nodoD{
	int lascia,togli;
	nodoD* next;

	nodoD(int a=0, int b=0,  nodoD*c=0){
		lascia=a;
		togli=b;
		next=c;
	}

};
struct doppioN{
	nodo*  La, *To;

	doppioN(nodo*a=0,nodo*b=0){
		La=a;
		To=b;
	}

};

nodo* build(int n);
nodoD* buildD(int n);
void stampaL(nodo*L);
void stampaD(nodoD*L);
nodo* conc(nodo*L1, nodo*L2);
nodo* concric(nodo*L1, nodo*L2);
nodo* tagliaric(nodo*& L,  int n);
doppioN Fric(nodo*L,nodoD*D);
doppioN Fric(nodo*L,nodoD*D);
nodo* taglia(nodo*&L, int n);
void Fiter(nodo*L, nodoD* D, nodo*& lasciati, nodo*& tolti);
nodo*clone(nodo*L);

int main()
{
  int dimL, dimD;
  cin>> dimL>>dimD;
  nodo* L= build(dimL);//data
  nodoD* D=buildD(dimD);//data
  nodo*L1=clone(L);//data
  cout<<"start"<<endl;
  stampaL(L); //data
  stampaD(D);//data
  nodo* lasciati=0, *tolti=0;
  Fiter(L,D, lasciati, tolti); //da fare
  stampaL(lasciati);
  stampaL(tolti);
  doppioN y=Fric(L1,D); //da fare
  stampaL(y.La);
  stampaL(y.To);
  cout<<"end"<<endl;
}
nodo*clone(nodo*L)
{
  if(!L) return 0;
  return new nodo(L->info,clone(L->next));
}
nodo* build(int n)
{
  if(n)
    {
      int x;
      cin>>x;
      return new nodo(x,build(n-1));
    }
  return 0;
}
nodoD* buildD(int n)
{
  if(n)
    {
      int x,y;
      cin>>x>>y;
      return new nodoD(x,y,buildD(n-1));
    }
  return 0;
}
void stampaL(nodo*L)
{
  if(L)
    {
      cout<<L->info<<' ';
      stampaL(L->next);
    }
  else
    cout<<endl;
}
void stampaD(nodoD*L)
{
  if(L)
    {
      cout<<'['<<L->lascia<<','<<L->togli<<']'<<' ';
      stampaD(L->next);
    }
  else
    cout<<endl;
}
nodo* conc(nodo*L1, nodo*L2)
{
  if(!L1) return L2;
  if(!L2) return L1;
  nodo* x=L1;
  while(x->next)
    x=x->next;
  x->next=L2;
  return L1;
}
//PRE=(Lista(L), Lista(D), Lista(lasciati) e Lista(tolti) sono corrette, vL=L,vlasciati=lasciati e vtolti=tolti)
void Fiter(nodo*L, nodoD* D, nodo*& lasciati, nodo*& tolti){



	while(D && L){
		if(!lasciati)
			lasciati= taglia(L,D->lascia);
		else
			lasciati= conc(lasciati,taglia(L,D->lascia));

		if(!tolti)
			tolti = taglia(L,D->togli);
		else
			tolti = conc(tolti,taglia(L,D->togli));

		D=D->next;
	}


}
//POST=(lasciati e tolti sono  vlasciati e vtolti a cui sono state appese
//(alla fine) le liste ottenute dalla smembramento di vL come indicato dai nodi di D)


//PRE=(Lista(L) ? corretta, n>=0, vL=L)
nodo* taglia(nodo*&L, int n) {

	nodo* temp=L;
	for(int i=0; i<n && L->next; i++){
		L=L->next;
	}
	temp->next=0;
	return temp;
}
//POST=(la funzione restituisce col return i primi n nodi di vL se ci sono e altrimenti restituisce quello che c??,
//L diventa quello che resta di vL una volta tolto il prefisso restituito col return)


//PRE=(Lista(L) e Lista(D) sono corrette, vL=L)
doppioN Fric(nodo*L,nodoD*D){
	doppioN *rest=new doppioN();
	nodo* lasciati, *tolti;
	if(D){
		lasciati= tagliaric(L,D->lascia);
		tolti = tagliaric(L,D->togli);

		doppioN risultato= Fric(L,D->next);
		rest->La= concric(lasciati,risultato.La);
		rest->To= concric(tolti, risultato.To);
	}

	return *rest;

}
//POST=(restituisce col return un valore struttura doppioN che ? una coppia di valori nodo*
//che sono le liste lasciati e tolti (rispettivamente, nel campo La e To del valore doppioN)
//in cui viene smembrata vL secondo quanto prescritto da D)

//PRE=(Lista(L) ? corretta, n>=0, vL=L)
nodo* tagliaric(nodo*& L ,  int n){

	if(!L) return 0;

	if(n>0){
		L=L->next;
		return  tagliaric(L, n-1);
	}
	return 0;
}
//POST=(la funzione restituisce col return i primi n nodi di vL se ci sono e altrimenti restituisce quello che c??,
//L diventa quello che resta di vL una volta tolto il prefisso restituito col return)



nodo* concric(nodo*L1, nodo*L2){

	if(!L1){
			return L2;
	}else{
		L1->next=concric(L1->next,L2);
		return L1;
	}
}
//POST: restituisca col return la concatenazione di L1 ed L2.
