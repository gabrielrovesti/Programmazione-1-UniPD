
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
       
        OUT<<B[0][i]<<" ";      //Stampa la riga del player 0 da destra a sinistra
     
    }
   
    for(int i=0; i<7; i++){
       
        OUT<<B[1][i]<<" ";      //Stampa la riga del player 1 da sinistra a destra
       
    }
   
    OUT<<endl;
 
}
   
/* Esegui semina */
//PRE=(B contiene 14 valori non negativi, player=0/1, buca in [0..5], fagioli>0. Chiamiamo old_B il valore di B all'invocazione della funzione)
bool semina(int B[][7], int player, int buca, int fagioli){
   
    int p=player, avv;
   
    avv=(p+1)%2;       //Se player=0 => avv=(0+1)%2=1 && se player=1 => avv=(1+1)%2=0
 
    B[player][buca]=0;      //Svuota quella buca
   
    bool end=false;
    int b=buca+1;           //Parti dalla buca successiva a quella svuotata
   
   
    while(fagioli>0 && end==false){       //Partendo dalla buca "b" successiva alla buca "buca"...
       
        if(b>=0 && b<=5 && B[p][b]==0 && fagioli==1){       //Se mi trovo in una buca piccola e ho l'ultimo fagiolo...
 
            B[player][6]=B[player][6]+B[(p+1)%2][5-b]+1;    //...allora devo mettere nella mia buca grande quel fagiolo e il contenuto della buca piccola opposta a quella vuota...
            fagioli--;
            B[(p+1)%2][5-b]=0;                              //...e devo svuotare la buca opposta
           
        }
       
        else{                                   //Se ho più di un fagiolo...
           
            B[p][b]++;                          //...aggiungi 1 ad ogni buca che incontri...
            fagioli--;                          //...diminuisci il numero di fagioli da seminare...
            b++;                                //...e passa alla buca successiva
           
        }
       
        if(b==6 && p==avv && fagioli>0){        //Se ho appena seminato nell'ultima buca piccola dell'avversario e ho ancora fagioli da seminare...
           
            b=0;                                //...allora devo andare alla buca 0...
            p=player;                           //...mia senza seminare niente nella sua buca 6 (grande)
       
        }
 
        if(b==7 && p==player && fagioli>0){     //Se ho appena seminato nella mia buca 6 (grande)...
           
            b=0;                                //...allora devo andare alla buca 0 (prima piccola)...
            p=avv;                              //...dell'avversario
       
        }
 
        if(b==7 && p==player && fagioli==0){    //Se ho appena seminato nella mia buca 6 (grande)...
           
            end=true;                       //...allora tocca di nuovo a me
           
        }
 
    }
   
    return end;
   
}
//POST=(B è ottenuta da old_B eseguendo la mossa (player,buca) secondo le regole del gioco descritte prima. Restituisce true se e solo se alla fine della semina si verifica il caso (iii))
 
int checkwin (int B[][7], int ply){
   
    int avv, contaavv=0, contaply=0, winner=-1;     //avv=avversario, ply=player, contaavv=numero fagioli buche piccole avversario, contaply=numero fagioli buche piccole player, vincitore
   
    avv=(ply+1)%2;
   
    for(int i=0; i<6; i++){
       
        contaply=contaply+B[ply][i];    //Conta i fagioli nelle buche piccole del giocatore
        contaavv=contaavv+B[avv][i];    //Conta i fagioli nelle buche piccole dell'avversario
       
    }
 
    if(contaply==0){                    //Se i fagioli nelle buche piccole del giocatore sono 0...
       
        B[avv][6]=B[avv][6]+contaavv;   //...allora metti tutti quelli nelle buche piccole dell'avversario nella buca grande del giocatore
       
    }
   
    else if(contaavv==0){               //Se i fagioli nelle buche piccole dell'avversario sono 0...
       
        B[ply][6]=B[ply][6]+contaply;   //...allora metti tutti quelli nelle buche piccole del giocatore nella buca grande dell'avversario
       
    }
   
    if(contaavv==0 || contaply==0){     //Se i fagioli nelle buche piccole del player o dell'avversario sono 0...
       
        if(B[ply][6]>B[avv][6]){            //(a)...e i fagioli nella buca grande del giocatore sono maggiori di quelli nella buca grande dell'avversario...
           
            winner=ply;                     //...allora il giocatore ha vinto
           
        }
       
        else if(B[avv][6]>B[ply][6]){       //(b)...e i fagioli nella buca grande dell'avversario sono maggiori di quelli nella buca grande del giocatore...
           
            winner=avv;                     //...allora l'avversario ha vinto
               
        }
       
        else{                               //(c)...e se sono entrambi uguali...
           
            winner=3;                       //...allora finisce in pareggio
           
        }
       
    }
   
    return winner;
   
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
        bool fine=false, uguale;            //"fine" determina se è stato letto il terminatore -1 && "uguale" determina se il turno spetta allo stesso giocatore o no
        int p=-1, b=-2, fagioli, winner;
       
        output(B, OUT);
       
        IN>>p;                  //Legge primo giocatore
       
        while(fine==false){
 
            IN>>b;              //Legge buca
           
            if(b==-1){          //Se b=-1 devo fermarmi...
           
                fine=true;
               
            }
           
            else{               //...altrimenti eseguo la mossa partendo dalla buca b del player p
           
                OUT<<"Il giocatore "<<p<<" fa la mossa "<<b<<endl;          //Stampa player e buca              
                fagioli=B[p][b];                                            //Conta i fagioli nella data buca
               
                if(fagioli>0){      //(a) Se ho selezionato una buca con qualche fagiolo dentro...
                   
                    uguale=semina(B, p, b, fagioli);    //...(1) esegui la semina
                    output(B, OUT);                     //...(2) stampa la situazione
                   
                    winner=checkwin(B, p);
                   
                    if(winner==-1){
                   
                        if(uguale==true){
                           
                           
                        }
                       
                        else{
                           
                            p=(p+1)%2;                  //Il turno passa all'altro giocatore
                           
                        }
                       
                    }
                   
                    else if(winner==0 || winner ==1){
                       
                        OUT<<"vince il giocatore "<<winner<<" con "<<B[winner][6]<<" fagioli, mentre il giocatore "<<(winner+1)%2<<" ne ha "<<B[(winner+1)%2][6];
                        fine=true;
                       
                    }
                   
                    else if(winner==3){
                       
                        OUT<<"entrambi i giocatori hanno "<<B[p][6]<<" fagioli, la partita finisce in parità";
                        fine=true;
                       
                    }
                   
                    OUT<<endl;
                }
               
                else{               //(b) Se ho selezionato una buca vuota allora...
                   
                    p=(p+1)%2;      //...tocca all'altro giocatore
                    OUT<<"mossa sbagliata, il turno passa al giocatore "<<p<<endl;
                   
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
