#include <iostream>
#include "Code.h"

using namespace std;

int main()
{
    coda* Q= new coda();

    cout << "start" << endl;

    int n,k;
    cin>>n>>k;

    for(int i=0; i<n; i++){
    	push(i,*Q);
    }

    (*Q).fine->next= Q->inizio;
    elimina(*Q,*(Q->inizio),k,0);


    cout << "end" << endl;
}
