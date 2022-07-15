#include<iostream>
using namespace std;

main() {
		int limite, somma=0, x, maxLet, maxOver, nLet=0, nOver=0;
        // maxlet e' il massimo di letture che si possono fare
        // maxover e' quante volte si puo' raggiungere o oltrepassare limite
        // nlet e' l'ennesima lettura
        // nover l'ennesima volta che viene oltrepassato o raggiunto il limite
        cin >> limite >> maxLet >> maxOver;
        cout<<"start"<<endl;
        
        // PRE= ((somma==0 && nLet==0) && nOver==0 && (Limite, maxLet e maxOver sono quantità positive lette dal main dato))  
        
        while (nLet<maxLet && nOver<maxOver) {
            cin>>x;
            nLet=nLet+1;
            somma=somma+x;
            if (somma>=limite) {
                nOver=nOver+1;
                somma=somma-limite;
                cout<<"superamento="<<nOver<<" "<<"avanzo="<<somma<<endl;
            }
        }
        
        // POST= (Sono state eseguite maxLet letture || limite e' stato raggiunto o oltrepassato maxOver volte, quindi sono uscito dal ciclo <=> (se e solo se) 
        // ho raggiunto il numero massimo di letture o ho raggiunto il numero massimo di volte che posso raggiungere o oltrepassare limite)
     
     cout<<nOver<<" superamenti e avanzo="<<somma<<endl;
     cout<<"end"<<endl;
 }