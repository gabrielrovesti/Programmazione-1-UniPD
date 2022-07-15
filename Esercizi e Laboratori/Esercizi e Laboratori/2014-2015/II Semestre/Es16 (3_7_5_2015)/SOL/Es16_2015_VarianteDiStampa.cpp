
//variante 1 di stampa/stamparic by: Daniel D. G.

/*comment:
[..] la funzione stampa ITERATTIVA... se qualcuno riesce/ha voglia di tradurla in ricorsiva... */


void stampa(int *x, int dim, ofstream &OUT)
{
int nsd, eus, ncdus, euc;
nsd=dim/(4*4); //numero strati definiti
eus=dim%(4*4); //elementi ultimo strato
ncdus=eus/4; //numero colonne definite ultimo strato
euc=eus%4; //elementi ultima colonna
                                               
for (int s=0;s<nsd;s++)
{
        for (int r=0;r<4;r++)
        {
                for (int k=0;k<4;k++)
                        OUT<<*(x+s*(4*4)+r*4+k)<<" ";
        OUT<<endl;
        }
OUT<<endl;
}
//ultimo strato:
int nr=4;
if(!ncdus)
        nr=euc; //numero delle righe
for (int r=0;r<nr;r++)
{
        int dimriga=ncdus;
        if (r<euc)
                dimriga++;
        for (int k=0;k<dimriga;k++)
                OUT<<*(x+nsd*(4*4)+r*4+k)<<" ";
OUT<<endl;
}
}





//variante 2 di stampa/stamparic by: Daniel D. G.

/*comment:
la stampa ricorsiva! Probabilmente, anzi sicuramente, è possibile pulire un po' il codice. */


void stampaelem(int *x, int lung, ofstream &OUT)
{
        if (!lung)//caso base: raggiunta la fine della riga
                {OUT<<endl; return;}
        if (!(lung%4))
                OUT<<endl;
        OUT<<*x<<" ";
        stampaelem(x+1,lung-1,OUT);
}
 
void ultimo_strato(int *x, int k,int ncp, int euc,int dim, ofstream &OUT)
{
        if (!dim)//caso base:raggiunta la fine dello strato
                return ;
 
        if (k<euc)
        {
                stampaelem(x,ncp+1,OUT);
                ultimo_strato(x+4,k+1,ncp,euc,dim-(ncp+1),OUT);
        }
        else
        {
                stampaelem(x,ncp,OUT);
                ultimo_strato(x+4,k+1,ncp,euc,dim-ncp,OUT);
        }      
}
 
 
void stampa(int *x, int dim, ofstream &OUT)
{
        if (!dim)//caso base: raggiunto il limite dell'array
                return;
 
        int ncp, euc; //numero colonne piene / elem ultima colonna
        ncp=dim/4;
        euc=dim%4;
 
        if (dim>=16) //c'è uno strato completo
        {
                stampaelem(x,16,OUT);
                stampa(x+16,dim-16,OUT);
        }
 
        else //sono nell'ultimo strato, non completo!
        {
                ultimo_strato(x,0,ncp,euc,dim,OUT);
                stampa(x+dim,dim-dim,OUT);
        }
 
return;
}
