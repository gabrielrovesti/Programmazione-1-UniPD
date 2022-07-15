#include<iostream>
using namespace std;

struct nodo{
	int info;
	nodo*next;

	nodo(int a=0, nodo* b=0){
		info=a;
		next=b;
	}
};

nodo* leggi ();
void fai_ricerche(nodo*, int );
int ricerca(nodo*, int);


int main()
{
  nodo* L=leggi();
  int n;
  cin>>n;
  cout<<"start"<<endl;
  fai_ricerche(L,n);
  cout<<"end"<<endl;
}

nodo* leggi(){
	int num;
	cin>>num;
	nodo* start=0;

	if(num != -1)
	{
		nodo* secondo= leggi();
		start= new nodo(num,secondo);
	}
	return start;
}
void fai_ricerche(nodo* L, int n){

	if(n>0){
		int num;
		cin>>num;
		int rispo=ricerca(L,num);
		if(rispo!=-1)
			cout<<"il valore "<<num<<" e' in posizione "<<rispo<<endl;
		else

			cout<<"il valore "<<num<<" non si trova nella lista"<<endl;

		fai_ricerche(L, n-1);

	}
}

int ricerca(nodo* L, int x){

	if(!L) return -1;
	if(L->info == x){
		int res= ricerca(L->next, x);
		if(res!= -1){
			return 1+res;
		}else{
			return -1;
		}
	}

	return ricerca(L->next,x);


}
