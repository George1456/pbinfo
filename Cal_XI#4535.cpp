#include <iostream>
#include <fstream>
#include <limits>
using namespace std;
ifstream fin("cal_xi.in");
ofstream fout("cal_xi.out");


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
}sol[100];



int n, m, k, exista_solutie;    
int nr_pioni , nr_minim_pasi = 2147483647, nr_solutii;
int is, js;
int d[100], nr_pioni_ramasi[100], dl[] = {-2, -2, -1, 1, 2, 2, 1, -1}, dc[] = {-1 , 1, 2, 2, 1, -1, -2, -2};
int a[11][11];

void init(int k)
{
    d[k] = -1;
    nr_pioni_ramasi[k] =  nr_pioni_ramasi[k - 1];
}

int exista_directie(int k)
{
    int ans;
    if(d[k] < 7)
        ans = 1;
    else
        ans = 0;
    return ans;
}

void valpos(int k)
{
    sol[k].l = sol[k - 1].l + dl[d[k]];
    
    sol[k].c = sol[k - 1].c + dc[d[k]];
}

int cont(int k)
{
    int ans = 1;
    if(a[sol[k].l][sol[k].c] == 3)
        ans = 0;

    if(sol[k].l < 1 || sol[k].l > n || sol[k].c < 1 || sol[k].c > m)
        ans = 0;

    for(int i = 1; i <= k - 1; i++)
        if(sol[i].l == sol[k].l && sol[i].c == sol[k].c)
            ans = 0;
    
    return ans;
}

int solutie(int k)
{
    int ans;
    if(a[sol[k].l][sol[k].c] == 1)
        nr_pioni_ramasi[k]--;
    if(nr_pioni_ramasi[k] == 0)
        ans = 1;
    else
        ans = 0;
    return ans;
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

void afisare_raspunsuri(int k)
{
    nr_solutii++;
    if(k < nr_minim_pasi)
        nr_minim_pasi = k;
    exista_solutie = 1;
    
}

void bkt()
{
    k = 2;
    init(k);
    while(k > 1)
    {
        if(exista_directie(k))
        {
            d[k] = d[k] + 1;
            valpos(k);
            if(cont(k))
            {
                if(solutie(k))
                {
                    afisare_raspunsuri(k);
                }
                else
                {
                    
                    k++;
                    init(k);
                }
            }
        }
        else
        {
            k--;
            nr_pioni_ramasi[k] =  nr_pioni_ramasi[k - 1];
        }  
        // aici verific daca am ajuns la pozitia de start
        // voi reinitializa nr_pioni_aux = nr_pioni
        
                     
    }
    
}



int main()
{
    // citire
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            {
                fin >> a[i][j];
                if(a[i][j] == 1)
                    nr_pioni++;
                if(a[i][j] == 2)
                {
                    is = i;
                    js = j;
                }
            }
    nr_pioni_ramasi[1] = nr_pioni;
    sol[1].l = is;
    sol[1].c = js;
    // gasire solutii
    bkt();
    if(exista_solutie == 0)
        fout << "IMPOSIBIL";
    else
        fout << nr_solutii << ' ' <<  nr_minim_pasi - 1;

}
/*
    // aici verific daca am ajuns la pozitia de start
        // voi reinitializa nr_pioni_aux = nr_pioni
        if(sol[k].l == is && sol[k].c == js)
                nr_pioni_aux = nr_pioni; 
*/
