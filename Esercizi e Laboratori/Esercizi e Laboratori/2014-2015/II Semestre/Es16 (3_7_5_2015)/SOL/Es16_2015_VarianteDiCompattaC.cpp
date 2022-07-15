
//variante di compattaC by: Marco P.

/*comment:
La mia funzione compattaC è come la funzione compatta dell'esercizio precedente, ma ho aggiunto una funzione in più. */


int trad(int e)
{
        int strato = e/(4*4);
        e = e - strato*4*4;
        int riga = e/4;
        int colonna = e%4;
       
        return strato*4*4 + colonna*4 + riga;
}
 
int compattaC(int* x, int dim, int z, int fino, int cur)
{
        if (cur < dim)
        {
                if (x[trad(cur)] != z)
                {
                        x[trad(fino)] = x[trad(cur)];
                        fino++;
                }
                cur++;
               
                return compattaC(x, dim, z, fino, cur);
        }
        else
                return fino;
}
