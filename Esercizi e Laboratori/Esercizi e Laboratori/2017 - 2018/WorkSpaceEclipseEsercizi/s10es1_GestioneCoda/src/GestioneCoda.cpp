
#include "code.h"
#include<iostream>

using namespace std;



int main(){

	char c;
	cout<<"start"<<endl;

	coda*  list = new coda();
	while(cin>> c || c != '.'){

		if(c == '*'){
			if(!e_vuota(*list)){
				char chiave= pop(*list);
			    cout<<chiave<<" ";
			}else{
		    	cout<<"VUOTA ";
			}

		}else{
			push(c,*list);
		}

	}
	cout<<c<<endl;

	cout<<"end"<<endl;
}

