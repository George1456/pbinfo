#include <iostream>
using namespace std;

int main()
{
    int n, curent, curent_urmator = 0, ok = 0, nr_siruri = 0, primul_curent_urmator = 0;
    int sir[1001];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> sir[i];
    curent = sir[1];
    sir[1] = -1;
    while (ok == 0)
    {
        ok = 1;
        for (int i = 2; i <= n; i++)
        {
            if (curent < sir[i] && sir[i] > -1)
            {
                curent = sir[i];
                sir[i] = -1;
                ok = 0;
            }
            else
            {
                if (primul_curent_urmator == 0 && sir[i] > -1)
                {
                    curent_urmator = sir[i];
                    sir[i] = -1;
                    primul_curent_urmator++;
                }
            }
        }
        if (primul_curent_urmator > 0 || ok == 0)
        {
            nr_siruri++;
            primul_curent_urmator = 0;
            curent = curent_urmator;
        }
    }
    cout << nr_siruri;
}
