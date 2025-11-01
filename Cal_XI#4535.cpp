#include <iostream>
using namespace std;

// ideea de rezolvare:
/*
    numar cati pioni am pe tabla.
    imi iau o valoare auxiliara la nr pionilor.
    atunci cand nr_pioni_aux = 0 inseamna ca am gasit o solutie.
    problema apare atunci cand:
    dupa ce am gasit o solutie trebuie sa imi reinitializez nr_pioni_aux. 
    Rezolvarea acestui impediment se face atunci cand:
    sol[k].l ajunge la linia de unde am plecat (sol[k].l == is) si cand sol[k].c ajunge la coloana de unde am plecat (sol[k].c == js)
    Vom scrie acest lucru in else de la if(exista(k)). 
    De ce?
    Pai cand sol[k].l && sol[k].c ajung la is, js?
    Atunci cand se scade valoarea lui k pana la k = 2.

*/


struct poz
{
    int l, c;
}sol[11];

int n, m, k, ok;    
int nr_pioni, nr_pioni_aux, nr_minim_pasi = INT_MAX, nr_solutii;
int is, js;
int d[101], dl[] = {-2, -2, -1, 1, 2, 2, 1, -1}, dc[] = {-1 , 1, 2, 2, 1, -1, -2, -2};
int a[11][11];

void init(int k)
{
    d[k] = -1;
}

int exista(int k)
{
    if(d[k] < 7)
        return 1;
    else
        return 0;
}

void valpos(int k)
{
    sol[k].l = sol[k - 1].l + dl[d[k]];
    
    sol[k].c = sol[k - 1].c + dc[d[k]];
}

int cont(int k)
{
    if(a[sol[k].l][sol[k].c] == 3)
        return 0;

    if(sol[k].l < 1 || sol[k].l > n || sol[k].c < 1 || sol[k].c > m)
        return 0;

    for(int i = 1; i <= k - 1; i++)
        if(sol[i].l == sol[k].l && sol[i].c == sol[k].c)
            return 0;
    
    return 1;
}

int solutie(int k)
{
    if(a[sol[k].l][sol[k].c] == 1)
        nr_pioni_aux --;
    if(nr_pioni_aux == 0)
        return 1;
    else
        return 0;
}

/*
void tipar(int k)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
   cout << endl;
}
*/
void bkt()
{
    k = 2;
    init(k);
    while(k > 1)
    {
        if(exista(k))
        {
            d[k] = d[k] + 1;
            valpos(k);
            if(cont(k))
            {
                if(solutie(k))
                    {
                        nr_solutii++;
                        if(k < nr_minim_pasi)
                            nr_minim_pasi = k;
                        ok = 1;
                    }
                else
                {
                    k++;
                    init(k);
                }
            }
        }
        else
            k--;
        // aici verific daca am ajuns la pozitia de start
        // voi reinitializa nr_pioni_aux = nr_pioni
        if(sol[k].l == is && sol[k].c == js)
                nr_pioni_aux = nr_pioni;      
    }
}



int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                if(a[i][j] == 1)
                    nr_pioni++;
                if(a[i][j] == 2)
                {
                    is = i;
                    js = j;
                }
            }
    nr_pioni_aux = nr_pioni;
    sol[1].l = is;
    sol[1].c = js;
    bkt();
    if(ok == 0)
        cout << "IMPOSIBIL";
    else
        cout << nr_solutii << ' ' <<  nr_minim_pasi;

}
