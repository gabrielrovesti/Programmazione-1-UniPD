
//(pseudo)soluzione by: Gilbero Filè (Prof)


//devo scorrere tutte le colonne (sono 5) e contare quante di esse sono = a P
//PRE=(T contiene 50 valori e P 10 valori)
int i=0,conta=0;
while(i<5)//R=(0<=i<=5)&&(considerato le colonne 0..i-1 e conta e' il 
//numero di queste colonne = a P)
{
  int j=0;
  bool mis=false;
  while(j<10 && !mis) //R1=(mis <=> c'e' mis-match tra P[0..j-1] e T[0..j-1][i])&&(0<=j<=10)
   {
    if(T[j][i]!=P[j])
       mis=true;
    j++;
   }
  //POST1=mis dica la cosa giusta mis <=> c'è un mis-match tra P e la colonna i di  T
  if(!mis)
    conta++;
  i++;
}

 cout<<conta<<endl;
//parte (2)
int i=0,conta=0, bestcol=-1, bestmis=11;
while(i<5&& (bestmis>0))//R=(0<=i<=5)&& (sono state considerate le colonne 0..i-1 e la migliore 
//è bestcol che ha bestmis mis-match)
{
  int j=0,mis=0;
  while(j<10 && (mis<bestmis))//R1=(mis è il n. di mis-math tra  P[0..j-1] e T[0..j-1][i]) && (0<=j<=10)
  {
    if(P[j]!=T[j][i])
      mis++;
   j++;
  }
 //POST1=(mis e' il n. di mis-math tra  P[0..9] e T[0..9][i])

  if(mis<bestmis)
      {bestmis=mis; bestcol=i;}
   i++;
}
//POST=(sono state considerate le colonne 0..4 e la migliore 
//e' bestcol che ha bestmis mis-match

//(3)
//input/output: notare la precondizione che 0<dimP<=10 e 0<dimT<=50 (scritta nel testo)
int dimT, dimP, T[10][5], P[10];
cin>>dimT>>dimP;

int rp=dimT/5, eur=dimT%5;
int i=0;
 while(i<rp)
 {
  int j=0;
  while(j<5)
  {cin>>T[i][j];j++;}
  i++;
  }
  i=0;
  while(i<eur)
  {cin>>T[rp][i]; i++;}

  int bestcol=-1, bestmatch=-1;
  i=0;
  while(i<5)//R=(0<=i<=5)&& (considerate le colonne 0..i-1 e bestcol e' la colonna col massimo di match tra quelle considerate
// e bestmatch e' il n. di match della colonna bestcol 
  {
   int lungcol=rp;
   if(i<eur)
     lungcol++;
//P=(la colonna i ha lungcol elementi definiti)
   int j=0, contamatch=0;
    while(j<lungcol-dimP+1)//R1=(considerati i punti d'inizio 0..j-1 e contamatch e' il n. di match trovati a partire dai punti di inizio considerati)
    {
     int k=0;
     bool ok=true; 
     while(k<dimP && ok) //R2=(ok <=>c'e' match tra P[0..k-1] e T[j..j+k-1][i])
      {//.......................da fare}

     //POST2=(ok <=>c'e' match tra P[0..dimP-1] e T[j..j+dimP-1][i])
     //usando ok si mette a posto contamatch 
    //.......................da fare
     }
//POST1=(contamatch è il numero di match presenti nella colonna T[0..luncol-1][i]

  if(contamatch<bestmatch)
      {bestmatch=contamatch; bestcol=i;}
   i++;
}
//POST=(sono state considerate le colonne 0..4 e la migliore 
//e' bestcol che ha bestmatch match)
