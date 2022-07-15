#include<iostream>
using namespace std;


void stampa(int A[10][5]) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 5; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void stampaB(bool A[10][5]) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 5; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int riempi(int A1[][5], int A2[][5]) {

    int temp;
    for(int i = 0; i < 50; i++) {
        cin >> temp;

        A1[i/5][i%5] = temp;
        A2[i%10][i/10] = temp;
    }

    stampa(A1);
    stampa(A2);
}

void cross(int A1[][5],int A2[][5], bool B[][5])
{
    /// A[10][5]
    /// B[i][j]=true sse la riga i di A1
    /// ha qualche elemento in comune con la colonna j di A2

    for(int i=0; i<10; i++) // per ogni riga
    /// R1=(0<=i<=10)&&(riempite correttamente le righe 0..i-1 di B)
    {
        for(int j=0; j<5; j++) // per ogni colonnna
        /// R2=(0<=j<=5)&&(riempito correttamente B[i][0..j-1])
        {
            // stiamo considerando la cella B[i][j]
            bool trovato=false;

            for(int k=0; k<5 && !trovato;k++)
            /// R3=(0<=k<=5)&&(trovato sse A1[i][k-1] è in A2[0..9][j])
            {
                for(int z=0; z<10 && !trovato; z++)
                /// R4=(0<=z<=10)&&(trovato sse A1[i][k] = A2[z-1][j])
                    if(A1[i][k]==A2[z][j])
                        trovato=true;
            }
            /// POST3=(trovato sse la riga i ha elementi in comune con la colonna j)
            B[i][j]=trovato;
        }
     }

    stampaB(B);
}

int main() {
  int A1[10][5],A2[10][5];
  riempi(A1,A2);

  bool B[10][5];
  cross(A1,A2,B);
}
