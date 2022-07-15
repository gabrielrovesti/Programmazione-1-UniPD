
//soluzione by: Leo M.

// Versione 1:
#include<iostream>
using namespace std;

main()
{
    int A[20], i=0, x1, x2, x3;
	bool continua=true;

	cin >> x1 >> x2 >> x3;
	while(i<20 && continua)
	{
		if(x1==1 && x2==0 && x3==2)
		{
			continua=false;
		}
		else
		{
			A[i]=x1;
			x1=x2;
			x2=x3;
			if(i<17)
				cin >> x3;
			i++;
		}
	}
	cout << "N=" << i << endl;
}



/* Versione 2:
#include<iostream>
using namespace std;

main()
{
    int A[20], i=0, x1, x2, x3;
	bool continua=true;

	cin >> x1 >> x2 >> x3;
	while(i<20 && continua)
	{
		if(x1==1 && x2==0 && x3==2)
		{
			continua=false;
		}
		else
		{
			if(i==17)
			{
				A[i]=x1;
				i++;
				A[i]=x2;
				i++;
				A[i]=x3;
				i++;
			}
			else
			{
				A[i]=x1;
				i++;
				x1=x2;
				x2=x3;
				cin >> x3;
			}
		}
	}
	cout << "i=" << i << endl;
}
*/



/* Versione 3:
#include <iostream>
using namespace std;

main()
{
   int A[20], x1=0, x2=0, x3=0, i=0;
   cin>>x1>>x2>>x3;
   while((x1!=1 || x2!=0 || x3!=2) && i<20)
   {
       A[i]=x1;
       x1=x2;
       x2=x3;
       if(i<17)
           cin>>x3;
       i++;
   }
    cout<<"N="<<i;
}



//PRE=(cin contiene almeno 20 interi) || (cin contiene la sentinella 1 0 2 preceduta da n>=0 valori).

//R=()

//POST=(se i primi 20 valori di cin non contengono 1 0 2, allora A[0..19] contiene i primi 20 valori di cin e N=20) && (se i primi 20 valori di cin contengono 1 0 2 preceduti da n valori, allora A[0..N-1] contiene i primi n valori di cin e N=n)
*/
