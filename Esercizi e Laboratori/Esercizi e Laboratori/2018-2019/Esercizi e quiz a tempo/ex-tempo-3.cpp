#include <iostream>
using namespace std;
//PRE: x[0, lim3, 2*lim3..lim3*(np-1)] correttamente valorizzato
bool match(int* x, int* p, int np, int lim3){
    bool match=true;
    for(int i=0; i<np && match; i++) //R: 0<=i<=np && match sse x[0, lim3, 2*lim3...(i-1)*lim3]=p[0..i-1]
        if(x[i*lim3]!=p[i])
            match=false;
    return match;
}
//POST: return true sse x[0, lim3, 2*lim3,..(np-1)*lim3]=p[0..np-1]
/*Dimostrazione correttezza funzione match
1) i=0, match=true poiché ho confrontato due insiemi nulli, dunque uguali
2) 0<<i<np && match sse x[0, lim3, 2*lim3...(i-1)*lim3]=p[0..i-1]
3) i>=np || !match => POST
    a) !match => x[0, lim3. 2*lim3,...(np-1)*lim3]!=p[0...np-1] => i<np
    b) i>=np => x[0, lim3. 2*lim3,...(np-1)*lim3]=p[0...np-1] => match=true*/
    
int main(){
    cout<<"start"<<endl;
    int x[100], n_ele, lim1, lim2, lim3, nP;
    cin>>n_ele;
    for(int i=0;i<n_ele;i++)
        cin>>x[i];
    cin>>lim1>>lim2>>lim3>>nP;
    int p[nP];
    for(int i=0;i<nP;i++)
        cin>>p[i];
    bool found=false;
    for(int v=0;v<lim3 && !found;v++){ //R: 0<=v<=lim3 && found sse trovato match in v-fette 0..v-1
        int kv=n_ele/lim3;
        int resto=n_ele%lim3;
        if(kv>=lim1*lim2){
            kv=lim1*lim2;
            resto=0;
        }
        if(v<resto)
            kv++;
        for(int i=0; i<kv-nP+1 && !found; i++) //R: 0<=i<=kv-nP+1 && found sse la v-fetta v contiene un match da 0..i-1
            if(match(x+v+i*lim3,p,nP,lim3)){
                found=true;
                cout<<"La V-fetta "<<v<<" contiene un match che inizia nell'elemento "<<i<<endl;
            }
    }
    if(!found)
        cout<<"nessun match trovato"<<endl;
    cout<<"end"<<endl;
    return 0;
}