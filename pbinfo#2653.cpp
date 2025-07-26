#include <iostream>

long long nroot(int n, long long x)
{
    if( x == 0 ) return 0;
    else if( x == 1 ) return 1;
    else if( n > x) return 0;
    else if( x < 0) x = x - x * 2;
    else if( n == 1 ) return x;
    // taking out special cases.
    // start of binary search.
    int st = 1;
    int dr = x;
    int mij , i;
    int ans = 0; 
    while (dr - st > 1)
    {
      long long aux = mij;
      mij = (st + dr) / 2;
      if(mij * mij > x) // if the middle's pow to 2 is greater than x we move downwards.
        dr = mij - 1;
      // add a new if statement if the mij * mij gets past of long long range.
      else if(mij * mij <= x) // we found a number which might be good.
        {
          for( i = 1; i < n; i++) // we check if the middle times n itself goes close or equal to x.
          aux = aux * aux;
          if(aux == x) return mij; 
          // now we try to get as much as possible to the number x.
          else if ( aux < x )
          {
            ans = aux;
            st = mij + 1;
          }
          else
            dr = mij - 1; 
        }
    }
    return ans;
}

int main()
{
  int n;
  long long x;
  std::cin >> n;
  std::cin >> x;
  std::cout << nroot(n , x);

}

// we can place a number between 2 perfect squares, and the return will be the highest 
// perfect square which is smaller than x 

// pbinfo #2653 nroot

// change test2