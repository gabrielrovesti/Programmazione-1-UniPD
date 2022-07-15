
//soluzione by: Enzo M.

bool cerca_cam(nodo* r,int k,int y,int* C)
{/*PRE=(albero(r)è corretto e non vuoto,k>=0,y definito,C ha almeno tanti elementi quanta è l'altezza di albero r))*/
if(!r->left && !r->right)
        {
        if(k==0)
                {
                if(r->info==y)
                        return false;
                else
                        {
                        *C=-1;
                        return true;
                        }
                }
        }
if(!r->left && !r->right)
        {
        if(k==1)
                {
                if(r->info==y)
                        {
                        *C=-1;
                        return true;
                        }
                else
                        return false;
                }
        }
if(!r->left && !r->right)
        {
        if(k>1)
                return false;
        }
if(r->info==y && k>0)
        {
        if(r->left)
                {
                *C=0;
                bool b=cerca_cam(r->left, k-1, y, C+1);
                if(b)
                        return b;
                }
        if(r->right)
                {
                *C=1;
                return cerca_cam(r->right, k-1, y, C+1);
                }
        }
else
if(r->info!=y && k>=0)
        {
        if(r->left)
                {
                *C=0;
                bool b=cerca_cam(r->left, k, y, C+1);
                if(b)
                        return b;
                }
        if(r->right)
                {
                *C=1;
                return cerca_cam(r->right, k, y, C+1);
                }
        }
else
        return false;
}
