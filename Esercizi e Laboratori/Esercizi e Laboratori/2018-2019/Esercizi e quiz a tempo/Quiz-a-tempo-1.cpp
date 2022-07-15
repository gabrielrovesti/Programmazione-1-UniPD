/*
Soluzioni copiate e incollate DIRETTAMENTE dal moodle,
secondo quanto indicato dal prof. nella revisione del quiz
la correttezza delle risposte non è dimostrata.
*/




//Dato l'array
	double B[5][6][10]
//quale delle seguenti espressioni ha come valore l'L-valore del secondo elemento
//della terza riga del secondo strato ?
//Le risposte corrette sono:
	(**B+1*60+2*10+1)
	(*(B[1]+2)+1)




//Dato il seguente programma:
void F(int*y){
	for(int i=0; i<10; i++)
		(*(y+i))++;
}
main(){
	int A[]={0,1,2,3,4,5,6,7,8,9};
	F(A);
	cout << A[0] << ' ' << A[1] << ' ' << .... << A[9] << endl;
}
//La risposta corretta è:
//Il programma è corretto e stampa 1,2,3,4,...,10




//Si consideri il seguente stralcio di programma:
int F(int B[][8], int d){
	int x=0;
	for(int i=0; i<d; i++)
		for(int j=0; j<8; j++)
			x=x+B[i][j];
	return x;
}
main(){
	int A[10][7][8]; //immaginate che A contenga valori definiti
	cout << F(A[2],7) << endl;
}
//La risposta corretta è:
//Stampa la somma dei valori del terzo strato di A




//Dato il seguente programma:
void F(int*y){
	for(int i=0; i<10; i++)
		(y+i)++;
}
main(){
	int A[]={0,1,2,3,4,5,6,7,8,9};
	F(A);
	cout << A[0] << ' ' << A[1] << ' ' << A[2] << ' ' << A[9] << endl;
}
//La risposta corretta è:
//La funzione F è sbagliata perché tratta un valore come fosse  una variabile.




//Data la seguente dichiarazione,
	float X[2][3][4][5]
//che valore e che tipo ha la seguente espressione
	(X-2)[2]
//?
//La risposta corretta è:
//valore X e tipo  float (*) [4][5]




//Data la seguente dichiarazione
double Y[2][3][4][5]
//quali di queste espressioni hanno come valore l'indirizzo del quinto elemento
//della seconda riga del terzo strato della prima torta?
//La risposte corrette sono:
*(*(*Y+2)+1)+4
Y[0][2][1][4]
*((**Y)+9) +4




//Si consideri il seguente programma:
void F(int*a, int& b){
	b= *(a+1); }

main(){
	int X[10]={1,2,3,4,5,6,7,8,9,10};
	F(X+2,X[0]);
	cout << X[0] << X[1] << X[2] << X[3] << X[4] << endl;
}
//La risposta corretta è:
//stampa 4 1 2 3 4




//Quali delle seguenti affermazioni sono corrette per il seguente programma?
int F(int x, int y){
	// corpo non dato;
	return somma;
}

main(){
	int v[10];
	for(int i=0; i<10; i++)
		cin >> v[i];
	cout << F(v[0],v[9]) << endl; //vorremmo che stampasse la somma dei valori in v[0..9]
}
//Le risposte corrette sono:
//- E' impossibile scrivere una funzione F che restituisca la somma di v[0..9]
//- E' possibile scrivere una funzione F che restituisca la somma di v[0..9]
//  passando entrambi i parametri per riferimento