#include <bits/stdc++.h>
using namespace std;

#define N_MAX 10
#define M_MAX 10
#define NM_MAX (N_MAX * M_MAX)

struct poz
{
    int l, c;
} sol[NM_MAX + 1];

int n, m, k;
int d[NM_MAX + 1], dl[] = {-2, -2, -1, 1, 2, 2, 1, -1}, dc[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int nr_pioni_ramasi, nr_pioni, nr_minim_pasi = INT32_MAX, nr_solutii;
int a[N_MAX + 1][M_MAX + 1];
int vizitat[N_MAX + 1][M_MAX + 1]; // marcăm pozițiile vizitate

void init(int k)
{
    d[k] = -1;
}

int exista_directie(int k)
{
    return (d[k] < 7);
}

void valpos(int k)
{
    sol[k].l = sol[k - 1].l + dl[d[k]];
    sol[k].c = sol[k - 1].c + dc[d[k]];
}

int cont(int k)
{
    int ans = 1;
    if (a[sol[k].l][sol[k].c] == 3)
        ans = 0;
    else if (sol[k].l < 1 || sol[k].l > n || sol[k].c < 1 || sol[k].c > m)
        ans = 0;
    else if (vizitat[sol[k].l][sol[k].c]) // deja vizitat
        ans = 0;

    return ans;
}

int solutie(int k)
{
    return (nr_pioni_ramasi == 0);
}

void bkt()
{
    k++; // urmatoarea pozitie
    init(k);

    while (k > 1)
    {
        if (exista_directie(k))
        {
            // verific directia urmatoare
            d[k]++;
            valpos(k);
            if (cont(k))
            {
                // pozitie valida
                // actualizare pioni ramasi
                if (a[sol[k].l][sol[k].c] == 1)
                    nr_pioni_ramasi--;

                if (solutie(k))
                {
                    nr_solutii++;
                    if (k < nr_minim_pasi)
                        nr_minim_pasi = k;
                    // dupa ce am gasit o solutie:
                    //  trebuie restaurat:
                    // 1. pionii ramasi
                    if (a[sol[k].l][sol[k].c] == 1)
                        nr_pioni_ramasi++;
                    // 2. demarcăm poziția
                    vizitat[sol[k].l][sol[k].c] = 0;
                }
                else
                {
                    // cu toate ca este o pozitie valida, nu este finalizata gasirea unei solutii
                    // marchez pozitia k ca fiind vizitata
                    vizitat[sol[k].l][sol[k].c] = 1;
                    //  si trec la urmatoarea pozitie
                    k++;
                    init(k);
                }
            }
        }
        else
        {
            // nu mai am directii de verificat
            //  si revin la pozitia anterioara
            k--;
            //  trebuie restaurat:
            // 1. pionii ramasi
            if (a[sol[k].l][sol[k].c] == 1)
                nr_pioni_ramasi++;
            // 2. demarcăm poziția
            vizitat[sol[k].l][sol[k].c] = 0;
        }
    }
}

int main()
{
    k = 1; // pozitia de start
    ifstream fin("cal_xi.in");
    if (fin) // read from console if file doesn't exist
        cin.rdbuf(fin.rdbuf());
    ofstream fout("cal_xi.out");
    // citire
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
                nr_pioni++;
            if (a[i][j] == 2)
            {
                sol[k].l = i;
                sol[k].c = j;
            }
        }
    vizitat[sol[k].l][sol[k].c] = 1; // marcăm poziția de start ca vizitată
    nr_pioni_ramasi = nr_pioni;
    // gasire solutii
    bkt();
    // afisare
    if (nr_solutii <= 0)
        cout << "IMPOSIBIL";
    else
        cout << nr_solutii << ' ' << nr_minim_pasi - 1; // pornesc de la 0
    cout << endl;
}