#include <iostream>
using namespace std;

// PRE = A è un array di interi && i < j
void inverti(int *A, int i, int j){
    if(i<j){
        A[i]=A[i]^A[j];
        A[j]=A[i]^A[j];
        A[i]=A[i]^A[j];
        inverti(A, i+1, j-1);
    }
}
//POST: A viene modificato invertendo l’ordine degli elementi nel sottoarray A[i..j]
/*Dimostrazione correttezza funzione inverti
caso base (i>=j): il sottoarray è vuoto o ha dimensione 1, quindi non succede nulla
caso ricorsivo (i<j):
    PRE_ric: A è un array di interi && i<j => PRE
    POST_ric: A viene modificato invertendo l'ordine degli elementi nel sottoarray A[i+1..j-1]
    ho swappato A[i] con A[j] e applicando l'ipotesi induttiva so che A[i+1..j-1] sono stati adeguatamente swappati ==> A[i..j] sono swappati ==> POST*/

//PRE: A è un array di interi && i>=0
void stampa(int* A, int i){
    if(i>0){
        stampa(A, i-1);
        cout<<A[i-1]<<" ";
    }
}
//POST: stampato A
/*Dimostrazione correttezza funzione stampa
caso base (i<=0): il sottoarray da stampare ha dimensione nulla, quindi non stampo nulla
caso ricorsivo (i>0):
    PRE_ric: A è un array di interi e i>=0 -> PRE
    POST_ric: stampato A[0..i-1] -> POST*/

int main() {
    int lung, primo, ultimo;
    int A[100];
    cin >> lung >> primo >> ultimo;
    for(int i = 0; i < lung; i++)
        cin >> A[i];
    cout << "start" << endl;
    inverti(A, primo, ultimo);
    stampa(A, lung);
    cout <<endl<<"end" << endl;
    return 0;
}