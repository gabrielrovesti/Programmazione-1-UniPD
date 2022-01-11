#include <iostream>
using namespace std;

struct stringa{int lung; char S[20];
  stringa(int a =0, char* b=0)
  {
  lung=a; 
    for(int i=0; i<lung; i++) 
    S[i]=b[i];
  }
  bool operator<=(const stringa &);
};

bool stringa::operator<=(const stringa& Z){
    int i=0;
    bool stop=true;

    //finché l'indice è minore della dimensione totale
    //e l'indice è minore della lunghezza della stringa
    //e il carattere è uguale alla stringa
    //le due stringhe sono uguali e, per l'algoritmo di confronto, devo
    //incrementare l'indice
    while(i < lung && i < Z.lung && S[i]==Z.S[i]){
    i++;
    }
    if (i==lung) //quando l'indice è uguale alla lunghezza della parola
    //significa che la stringa iniziale è minore, perciò ritorno true
    return true;

    if (i == Z.lung)   //se invece l'indice è uguale alla lunghezza del parametro stringa, ritorno false
    return false;


    return S[i] <= Z.S[i];   //in ogni caso, ritorno i due valori confrontati, quindi carattere<=stringa iniziale
}

istream& operator>>(istream& is, stringa& Z){ 
	is >> Z.lung >> Z.S;
	return is;
}

ostream& operator<<(ostream& os, const stringa& Z) {
	os << "la stringa e': "<< endl;
	os<<Z.S<<endl;
    return os;
}

int main()
{
  stringa X, Y, Z, W;
  cin >> X >> Y >> Z >> W;
  if(X <= Y)
    cout << X;
  else
    cout << Y;
  if(Y <= X)
    cout << Y;
  else
    cout << X;
  if(X <= Z)
    cout << X;
  else
    cout << Z;
  if(X <= W)
    cout << X;
  else
    cout << W;
  if(!(Z<=W))
    cout << Z;
  else
    cout << W;
    
    return 0;
}





