#include<iostream>
#include<cstdio>
using namespace std;
int main()
{ int n;
  while(cin >> n && n!=0)
  {   int real = n;
      cout << n <<  " = ";
      int num_div = 1;
      for(int i=2;i*i<=n;i++)
      {
          if(n%i==0)
            num_div++;
      }

    for (int i = 2; i*i <=n; i = i+1)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {   cout<< i ;
            n = n/i;
            if(n!=1)cout << " * " ;
        }
    }
    if(n==1) cout << endl;
    if(n>1)
        cout << n << endl;
    cout << "With "<<real<< " marbles, "<<num_div<<" different rectangles can be constructed."<<endl;

  }

}

//Another

#include <cstdio>
 
using namespace std;
 
int main( void ) {
  int n;
  while( scanf( "%d", &n ) == 1 ) {
    if( n == 0 ) break;
    printf( "%d =", n );
    int c = 1, v = n, ok = 0;
    for( int i = 2; i*i <= n; ++i )
      if( !( n%i ) ) {
	c++;
	while( !( v%i ) ) {
	  v /= i;
	  if( ok ) printf( " *" );
	  printf( " %d", i );
	  ok = 1;
	}
      }
    if( v > 1 ) {
      if( ok ) printf( " *" );
      printf( " %d", v );
    }
    printf( "\nWith %d marbles, %d different rectangles can be constructed.\n", n, c );
  }
  return 0;
}
