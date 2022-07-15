#include <iostream>
using namespace std;

struct orario{
    int h, m, s;
    orario(int hx=-1, int mx=-1, int sx=-1){
        h=hx;
        m=mx;
        s=sx;
    }
};
struct player{orario s0, s1, s2;};

bool checkP(orario s0, orario s1, orario s2){
    //2:45=165s a km, tra 0 e 1 11km = 165*11, tra 1 e 2 11 km = 165*11
    //check tratto da 0 a 1
    int diff1=0;
    int h=s0.h, m=s0.m, s=s0.s;
    while(h!=s1.h || m!=s1.m || s!=s1.s){
        diff1++;
        s++;
        if(s==60){
            s=0;
            m++;
            if(m==60){
                m=0;
                h++;
            }
        }
    }
    //check tratto da 1 a 2
    int diff2=0;
    h=s1.h; m=s1.m; s=s1.s;
    while(h!=s2.h || m!=s2.m || s!=s2.s){
        diff2++;
        s++;
        if(s==60){
            s=0;
            m++;
            if(m==60){
                m=0;
                h++;
            }
        }
    }
    return (diff1>165*11 && diff2>165*11) ? true : false;
}//POST: return true sse tempi regolari
int main(){
    cout<<"start"<<endl;
    int n_part;
    cin>>n_part;
    //cin.ignore(2);
    int scart;
    cin>>scart>>scart>>scart;
    player p[n_part];
    int x1=0;
    while(x1!=-1){
        cin>>x1;   //x1 è numero sensore sse x1!=-1
        if(x1>=0){   //x1 e x2 servono per invertire num sensore e num player
            int x2; cin>>x2;
            switch(x1){
                default: cout<<"Something went wrong... "<<x1<<endl; break;
                case 0:
                    cin>>p[x2].s0.h;
                    cin>>p[x2].s0.m;
                    cin>>p[x2].s0.s;
                    break;
                case 1:
                    cin>>p[x2].s1.h;
                    cin>>p[x2].s1.m;
                    cin>>p[x2].s1.s;
                    break;
                case 2:
                    cin>>p[x2].s2.h;
                    cin>>p[x2].s2.m;
                    cin>>p[x2].s2.s;
                    break;
            }
        }
    }
    bool ok=true;
    //check salti sensori
    for(int i=0;i<n_part;i++){
        if(p[i].s0.h<0 || p[i].s1.h<0 || p[i].s2.h<0){
            ok=false;
            cout<<i<<": salto sensore"<<endl;
        }
        else //check tempi sospetti
            if(!checkP(p[i].s0, p[i].s1, p[i].s2)){
                ok=false;
                cout<<i<<": tempo sospetto"<<endl;
            }
    }
    if(ok) cout<<"gara regolare"<<endl;
    cout<<"end"<<endl;
    return 0;
}