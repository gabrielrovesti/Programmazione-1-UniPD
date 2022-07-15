
//soluzione by: Nicolò S.

/* esercizi di teoria
	1) il tipo Ã¨ X(*)[5][5][10] e la dimensione 4*5*10*4
	2) int (*)[5][10] e valore X+ 2*5*10*4
	3) int (*)[10] e valore *(*(X-8)+8)
	*/ 
	 
	 #include <iostream>
     #include <fstream>
     #include <climits>
     
     using namespace std;
     
     int sommaRighe(int* X, int lung)
     {
     	int somma = 0;
    	for (int i = 0; i < 8 && i < lung; ++i)
    	{
    		somma += *(X+i);
    	}
    	return somma;
    }
    
    main()
    {
    	ifstream IN("input");
    	ofstream OUT("output");
    
    	if(IN && OUT)
    	{
    		int X[10][5][8], n_el, *p = **X, somma_max = INT_MIN, somma, index;
   
			IN >> n_el;
    		for (int i = 0; i < n_el; ++i)
    		{
    			IN >> p[i];
    		}
    
    		for (int i = 0; i < 5; ++i)
    		{
    			somma = 0;
    			for (int s = 0; s < 10; ++s)
    			{
    				somma += sommaRighe(**X+s*40+i*8, n_el-s*40-i*8);
    			}
    			if(somma >= somma_max)
    			{
    				index = i;
    				somma_max = somma;
    			}
    		}
    
    		OUT << "H fetta massima=" << index;
    		
    		IN.close();
    		OUT.close();
    	}
    	else
    		cout << "errore con i file" << endl;
    }
