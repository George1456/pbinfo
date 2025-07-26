#include <iostream>
using namespace std;

long long nroot(int n, long long x)
{
    long long  ans = 0; 
    if( x == 0 ) ans = 0;
    else if( x == 1 ) ans = 1;
    else if( n > x) ans = 1;
    else if( x < 0) x = 0 - x;
    else if( n == 1 ) ans = x;
    // taking out special cases.
    else 
    {
      // start of binary search.
      int st = 1;
      int dr = x/2;
      int mij , i;
      while (dr - st > 0)
      {
        mij = (st + dr) / 2;
        long long aux = mij;
        if(mij * mij > x) // if the middle's pow to 2 is greater than x we move downwards.
          {
            cout << "ma duc in stanga 1 " << st << ' ' << mij << ' ' << dr <<' ' << aux << endl;
            dr = mij - 1;
          }
        // add a new if statement if the mij * mij gets past of long long range.
        else // (mij * mij <=x)  we found a number which might be good.
        {
          for( i = 1; i < n && aux <= x; i++) // we check if the middle times n itself goes close or equal to x.
          {
            aux = aux * aux;
            cout << " dupa inmultire: " << aux << endl;
          }
           cout << " dupa inmultire: " << aux << endl;
          if(aux == x)
          {
            cout << "este egal " << st << ' ' << mij << ' ' << dr <<' ' << aux << endl;
            dr = st;
          } 
          // now we try to get as much as possible to the number x.
          else if (aux < x)
          {
            cout << "ma duc in dreapta " << st << ' ' << mij << ' ' << dr << ' ' << aux << endl;
            st = mij + 1;
          }
          else
          {
            cout << "ma duc in stanga 2 " << st << ' ' << mij << ' ' << dr <<' ' << aux << endl;
            dr = mij - 1;
          } 
        }
      }
      ans = st;
    }
    
    return ans;
}

int main()
{
  int n;
  long long x;
  cin >> n >> x;
  cout << nroot(n , x);

}

// we can place a number between 2 perfect squares, and the return will be the highest 
// perfect square which is smaller than x 

// pbinfo #2653 nroot