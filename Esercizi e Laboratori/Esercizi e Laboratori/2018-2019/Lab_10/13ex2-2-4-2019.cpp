#include <iostream>
using namespace std;

bool checkP(int* S0, int* S1, int* S2){
    //2:45=165s a km, tra 0 e 1 11km = 165*11, tra 1 e 2 11 km = 165*11
    int h=*(S0+2), min=*(S0+3), sec=*(S0+4);
    int diff1=0;
    while(h!=*(S1+2) || min!=*(S1+3) || sec!=*(S1+4)){
        diff1++;
        sec++;
        if(sec==60){
            sec=0;
            min++;
            if(min==60){
                min=0;
                h++;
            }
        }
    }
    int diff2=0;
    h=*(S1+2); min=*(S1+3); sec=*(S1+4);
    while(h!=*(S2+2) || min!=*(S2+3) || sec!=*(S2+4)){
        diff2++;
        sec++;
        if(sec==60){
            sec=0;
            min++;
            if(min==60){
                min=0;
                h++;
            }
        }
    }
    return (diff1>165*11 && diff2>165*11) ? true : false;
}
//POST: return true sse tempi regolari
int main(){
    cout<<"start"<<endl;
    int n_part;
    cin>>n_part;
    int h,m,s;
    cin>>h>>m>>s;
    int dati[n_part*3*5];
    int x=0, k;
    for(k=0;k<n_part*3*5 && x!=-1;k++){
        cin>>x;
        if(x!=-1)
            dati[k]=x;
    }
    int n_righe=k/5;
    bool ok=true;
    for(int i=0; i<n_part; i++){  
        int s0=-1, s1=-1, s2=-1;
        for(int r=0; r<n_righe; r++)
            if(*((dati+r*5)+1)==i && *(dati+r*5)==0)
                s0=r;
            else
                if(*((dati+r*5)+1)==i && *(dati+r*5)==1)
                    s1=r;
                else
                    if(*((dati+r*5)+1)==i && *(dati+r*5)==2)
                        s2=r;
        if(s0<0 || s1<0 || s2<0){
            ok=false;
            cout<<i<<": salto sensore"<<endl;
        }
        else
            if(!checkP(dati+s0*5, dati+s1*5, dati+s2*5)){
                ok=false;
                cout<<i<<": tempo sospetto"<<endl;
            }
    }
    if(ok)
        cout<<"gara regolare"<<endl;
    cout<<"end"<<endl;
    return 0;
}
