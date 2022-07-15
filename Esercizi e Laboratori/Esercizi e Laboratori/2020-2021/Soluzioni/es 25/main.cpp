#include <iostream>
#include "BST.h"
using namespace std;
using namespace BST;
int main()
{
    //prepara un albero iniziale non triviale
    nodo* r=new nodo(15, new nodo(7), new nodo(19));
    r->left->right=new nodo (9, new nodo(8));
    r->right->right=new nodo(25, new nodo(22));
    
    bool stop=false;
    int valore=0, da_inserire=0;
    while(!stop)
    {
        cin>>valore>>da_inserire;
        
        if(valore==0)
        stop=true;
        
        if(valore==1)
        BST::stampa_l(r);
        
        if(valore==2){
            BST::insert(r, da_inserire);
            BST::stampa_l(r);
            cout<<endl;
        }
        if(valore==3){
            bool scelta=BST::search(r, da_inserire);
            if(scelta)
            cout<<"valore "<<da_inserire<< "presente"<<endl;
            else
            cout<<"valore "<<da_inserire<<" non presente"<<endl;
        }
        if(valore==4){
            if(da_inserire==1){
                nodo* p=BST::max(r);
                cout<<p->info;
            }
            if(da_inserire==2){
                nodo* p=BST::min(r);
                cout<<p->info<<endl;
            }
        }
        if(valore==5){
            int altezza=BST::altezza(r);
            cout<<altezza<<endl;
        }
        if(valore==6){
            int altezza_min=BST::altMin(r);
            cout<<altezza_min<<endl;
        }
    }

    return 0;
}