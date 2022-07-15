
//soluzione by: Nicol� S.

#include<iostream>
#include<fstream>
using namespace std;

/* Funzione di stampa ricorsiva per righe dell'array x */
void stampa(int *x, int dim, ofstream & OUT){
    
    if(dim < 1){
        
        return;
        
    }
    
    
    stampa(x, dim-1, OUT);
  
    OUT << x[dim-1] << " ";
    
    if((dim-1)%4 == 3){
        
        OUT<<endl;
        
    }
    
    OUT<<endl;
    
}


/* Funzione di compattazione dell'array */

//PRE=(x ha dim elementi, 0<dim<=54, 0<=fino<=cur<=dim)
int compatta(int* x, int dim, int z, int fino, int cur){

    //Condizioni di uscita
    if(dim<1){      //Se la dimensione è 0 non devo continuare, quindi fino sarà il numero massimo di elementi presenti nell'array compattato
        
        return fino;
        
    }
    
    
    //Elaborazione
    int k;  //Variabile da ritornare
    
    if(x[cur]==z){                      //Se il valore di x[] è uguale a z, non voglio averla nell'array compattato...
        
        k = compatta(x, dim-1, z, fino, cur+1);     //...quindi cerco il prossimo valore di x[] diverso da z, memorizzando su "fino" la cella successiva all'ultima riempita con un valore di x[] diverso da z
        
    }
    
    else{                               //Se invece il valore di x[] è diverso da z, allora lo voglio nell'array compattato, perciò...
        
        x[fino]=x[cur];                             //...lo memorizzo in x[fino] che era la cella successiva a quella all'ultima usata per memorizzare un valore di x[] diverso da x...
        k = compatta(x, dim-1, z, fino+1, cur+1);   //...e cerco il prossimo valore di x[] diverso da z considerando la prossima cella di x[]

    }
 
    return k;       //Ritorna la lunghezza massima dell'array compattato
    
}
//POST=(se k è restituito dalla funzione, allora x[fino..(fino+k)-1] contiene gli elementi contenuti in x[cur..dim-1] diversi da z (che sono k))




main(){
    
    ifstream IN("input");
    ofstream OUT("output");
    if(IN && OUT){
        
        //Inizializzazione
        int T[3][4][4], dim, z;
        
        IN>>dim;
        
        int* x=**T;
        
        for(int i=0; i<dim;i++){
            
            IN>>x[i];
            
        }
        
        stampa(x, dim, OUT);    //Stampa l'array originario per righe in modo ricorsivo
        
        OUT<<endl;
        
        IN>>z;
   
        int ne = compatta(x, dim, z, 0, 0);     //Compatta l'array eliminando tutti i valori uguali a z
        
        stampa(x, ne, OUT);     //Stampa l'array compattato per righe in modo ricorsivo
        
        OUT<<endl;
        
        OUT<<"fine"<<endl;
        
        IN.close();
        OUT.close();
        
    }
    else{
      
        cout<<"errore con i files";
        
    }
}
