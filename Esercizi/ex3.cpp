#include<iostream>
using namespace std;
//Consegna: Vedere se un array di interi di 10 elementi è palindromo
int main()
{

int a[8], i=0, j=0;
bool ok=true; //pre= definisco l'array di 8 elementi, i=j=cont=0, ok=true
while(i<8){	//R=(0<=1<=8) && (a[i..n-1] riempito con gli input)

cin>>a[i];
i++;
	}
	
i=0;	//riporto il contatore a 0 per verificare che se l'array da destra a sinistra e da sinistra a destra ha le cifre uguali
while(i<4){		//R=(0<=i<=4) && (ok sse A[0...i-1]=A[7-i])
	if(a[i]!=a[7-i]){
	ok=false;		
	}
	i++;
	}
	
	//se ok=true, vettore palindromo
  if(ok==true)
    cout << "e' un palindromo"<<endl;
  else
    cout << "non e' un palindromo"<<endl;
    
    //post: determino se a[i] è palindromo e stampo bool	
    
    //Appunti: se dovessi considerare un array di elementi dispari, andrebbe bene comunque il codice, semplicemente l'elemento centrale non lo considero.
    //Inoltre, dovessi considerare un array di n elementi, al posto di 4 (che sarebbe la metà, perché il controllo rischierei di farlo due volte se ne controllo 8)
    //dovrei mettere al posto di 4, n/2, in maniera tale da considerare anche l'elemento centrale e al posto di 7, n, quindi sarebbe n-i.


	//Dimostrazione di correttezza:
	//-la prima volta leggo i=0 e A[0]
	//-i varia tra 0 e 4 e leggo gli elementi tra A[0...i-1]=A[7-i]
	//quando a[i]!=a[n-i]-->post
}

