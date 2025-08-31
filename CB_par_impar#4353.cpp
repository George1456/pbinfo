#include <iostream>
using namespace std;

int par_stanga(int x[], int st, int dr, int y)
{
    if(st >= dr)
        if(x[st] % 2 == 0)
            if(x[st] == y)
                return 1;
            else return 0;
        else return 0;
    else
    {
        int m = ( st + dr ) / 2;
        dr = m;
        m = (st + dr) / 2;
        return par_stanga(x , st, m, y) + par_stanga(x, m + 1, dr, y); 
        
    }
    
}

int impar_dreapta(int x[], int st, int dr, int y)
{
    if(st >= dr)
       if(x[st] % 2 == 1)
            if(x[st] == y)
                return 1;
            else return 0;
        else return 0;
    else
    {
        int m = ( st + dr ) / 2;
        st = m + 1;
        m = ( st + dr ) / 2;
        return impar_dreapta(x, st, m, y) + impar_dreapta(x, m + 1, dr, y);
    }
    
}

int main()
{
    int x[100001] , y[200001], n, m, ok , ok2;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> x[i];
    cin >> m;
    for(int i = 1; i <= m; i++)
        cin >> y[i];
    for(int i = 1; i <= m; i++)
        {
            if(y[i] % 2 == 0)
            {
                int aux = y[i];
                 ok = par_stanga(x, 1, n, aux); 
            }
            else
            {
                int aux = y[i];
                ok2 = impar_dreapta(x, 1, n, aux);
            }
                
        }
        cout << ok << ' ' << ok2;
}