#include <iostream>
using namespace std;

int find(int x[], int st, int dr, int y)
{
    if(st >= dr)
        if(x[st] == y)
            return 1;
        else return 0;
    else
    {
        int m = ( st + dr ) / 2;
        int f1 = find(x , st, m, y);
        int f2 = find(x, m + 1, dr, y);
        return f1 + f2; 
    }
}


int main()
{
    
    int x[100001] , y[200001], n, m, ok = 0, ok2 = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> x[i];
    cin >> m;
    for(int i = 1; i <= m; i++)
        cin >> y[i];
    for(int i = 1; i <= m; i++)
        {
            int aux = y[i];
            if(y[i] % 2 == 0)
              ok += find(x, 1, n / 2, aux); 
            else
              ok2 += find(x, n / 2 + 1, n, aux);     
        }
        cout << ok << ' ' << ok2;
}