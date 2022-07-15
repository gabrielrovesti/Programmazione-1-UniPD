
//soluzione by: Riccardo M.

#include<iostream>
#include<fstream>
 
using namespace std;
 
    //                               BENVENUTO NEL GIOCO DEL BANTUMI                              
    //
    //                                           Player 0
    //
    //                   5          4          3          2          1          0              
    //   _________________________________________________________________________________________    ____
    //  |             _______    _______    _______    _______    _______    _______             |   |\\
    //  |            /       \  /       \  /       \  /       \  /       \  /       \            |   | \\
    //  |            |  B[0] |  |  B[0] |  |  B[0] |  |  B[0] |  |  B[0] |  |  B[0] |            |      \\
    //  |            |  [5]  |  |  [4]  |  |  [3]  |  |  [2]  |  |  [1]  |  |  [0]  | Realizzo   |       \\        
    //  |            \_______/  \_______/  \_______/  \_______/  \_______/  \_______/ Player 1   |        \\
    //  |    ________                                                                ________    |         ||
    //  |   /        \                                                              /        \   |         ||
    //  |   |  B[0]  |______________________________________________________________|  B[1]  |   |         ||
    //  |   |  [6]   |                                                              |  [6]   |   |         ||
    //  |   \________/                                                              \________/   |         ||
    //  |             _______    _______    _______    _______    _______    _______             |         ||
    //  |  Realizzo  /       \  /       \  /       \  /       \  /       \  /       \            |         //
    //  |  Player 0  |  B[1] |  |  B[1] |  |  B[1] |  |  B[1] |  |  B[1] |  |  B[1] |            |        //
    //  |            |  [0]  |  |  [1]  |  |  [2]  |  |  [3]  |  |  [4]  |  |  [5]  |            |       //
    //  |            \_______/  \_______/  \_______/  \_______/  \_______/  \_______/            |      //
    //  |________________________________________________________________________________________|     //
    //
    //                   0          1          2          3          4          5
    //
    //                                           Player 1
 
 
 /* Stampa piattaforma */
void piattaforma(){
   
    cout<<"                                                                                        "<<endl;
    cout<<"                   BENVENUTO NEL GIOCO DEL BANTUMI                                 "<<endl;
    cout<<"                              Player 0                                                 "<<endl;
    cout<<"               5       4      3      2      1      0                         "<<endl;
    cout<<    "   ______________________________________________________________ "<<"  ___"<<endl;
    cout<<"  "<<'|'<<"            ___    ___    ___    ___    ___    ___   Realizzo "<<'|'<<"  "<<'|'<<"\\"<<endl;
    cout<<"  "<<'|'<<"           /   \\  /   \\  /   \\  /   \\  /   \\  /   \\  Player 1 "<<'|'<<"  "<<'|'<<" \\"<<endl;
    cout<<"  "<<'|'<<"    ____   \\___/  \\___/  \\___/  \\___/  \\___/  \\___/   ____    "<<'|'<<"     \\"<<endl;
    cout<<"  "<<'|'<<"   /    \\                                            /    \\   "<<'|'<<"      "<<'|'<<endl;
    cout<<"  "<<'|'<<"   "<<'|'<<"    "<<'|'<<"--------------------------------------------"<<'|'<<"    "<<'|'<<"   "<<'|'<<"      "<<'|'<<endl;
    cout<<"  "<<'|'<<"   \\____/   ___    ___    ___    ___    ___    ___   \\____/   "<<'|'<<"      "<<'|'<<endl;
    cout<<"  "<<'|'<<" Realizzo  /   \\  /   \\  /   \\  /   \\  /   \\  /   \\           "<<'|'<<"     /"<<endl;
    cout<<"  "<<'|'<<" Player 0  \\___/  \\___/  \\___/  \\___/  \\___/  \\___/           "<<'|'<<"   /"<<endl;
    cout<<"  "<<'|'<<"______________________________________________________________"<<'|'<<" /"<<endl;
    cout<<"                                                                                        "<<endl;
    cout<<"                0      1      2      3      4      5                        "<<endl;
    cout<<"                                                                            "<<endl;
    cout<<"                              Player 1                                                    "<<endl;
   
}
 
/* Stampa Output */
void output (int B[][7], ofstream &OUT){
   
    for(int i=6; i>-1; i--){
       
        OUT<<B[0][i]<<" ";
     
    }
   
    for(int i=0; i<7; i++){
       
        OUT<<B[1][i]<<" ";
       
    }
   
    OUT<<endl;
   
}
 
/* Esegui semina */
bool semina(int B[][7], int player, int buca, int fagioli){
   
    int p=player, avv;
   
    avv=(p+1)%2;       //Se player=0 => avv=(0+1)%2=1 && se player=1 => avv=(1+1)%2=0
 
    B[player][buca]=0;      //Svuota quella buca
   
    bool end=false;
    int b=buca+1;           //Parti dalla buca successiva a quella svuotata
   
    while(fagioli>0 && end==false){       //Partendo dalla buca "b" successiva alla buca "buca"...
       
        B[p][b]++;                          //...aggiungi 1 ad ogni buca che incontri...
        fagioli--;                          //...diminuisci il numero di fagioli da seminare...
        b++;                                //...e passa alla buca successiva
       
        if(b==6 && p==avv && fagioli>0){        //Se ho appena seminato nell'ultima buca piccola dell'avversario e ho ancora fagioli da seminare...
           
            b=0;                                //...allora devo andare alla buca 0...
            p=player;                           //...mia senza seminare niente nella sua buca 6 (grande)
       
        }
 
        if(b==7 && p==player && fagioli>0){     //Se ho appena seminato nella mia buca 6 (grande)...
           
            b=0;                                //...allora devo andare alla buca 0 (prima piccola)...
            p=avv;                              //...dell'avversario
       
        }
 
        if(b==7 && p==player && fagioli==0){    //Se ho appena seminato nella mia buca 6 (grande) e non ho più fagioli...
           
            end=true;                           //...allora tocca di nuovo a me
           
        }
       
        if(b>=0 && b<=5 && B[p][b]==0 && fagioli==1){       //Se mi trovo in una buca piccola e ho l'ultimo fagiolo...
 
            B[player][6]=B[player][6]+B[(p+1)%2][5-b]+1;    //...allora devo mettere nella mia buca grande quel fagiolo e il contenuto della buca piccola opposta a quella vuota
            fagioli--;
           
        }
 
    }
   
    return end;
   
}
 
main(){
   
    ifstream IN ("input");
    ofstream OUT ("output");
   
    if(IN && OUT){
       
        int B[2][7], *P=*B;
       
        for(int i=0; i<14; i++){    //Immagazzina dati: riga 0 = Player 0 e riga 1 = Player 1
           
            IN>>P[i];
           
        }
       
        /* Stampa Piattaforma */
        piattaforma();
       
        /* Gioca */
        bool fine=false, uguale;
        int p=-1, b=-2, fagioli;
       
        output(B, OUT);
       
        while(fine==false){
           
            IN>>p;
            IN>>b;
           
            if(b==-1){          //Se b=-1 devo fermarmi...
           
                fine=true;
               
            }
           
            else{               //...altrimenti eseguo la mossa partendo dalla buca b del player p
           
                OUT<<p<<" "<<b<<endl;       //Stampa player e buca              
                fagioli=B[p][b];            //Conta i fagioli nella data buca
               
                if(fagioli>0){      //Se ho selezionato una buca con qualche fagiolo dentro...
                   
                    uguale=semina(B, p, b, fagioli);        //...(1) esegui la semina
                    output(B, OUT);                         //...(2) stampa la situazione
                     
                    if(uguale==true){
             
                        OUT<<"Il giocatore non cambia";
               
                    }
           
                    else{
               
                        OUT<<"Il giocatore cambia";
             
                    }
 
                    OUT<<endl;
                }
           
            }
        }
       
        OUT<<"fine";
       
        IN.close();
        OUT.close();
       
    }
   
    else{
       
        cout<<"Errore con i files"<<endl;
       
    }
 
}
