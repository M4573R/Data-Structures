/* Logic  : x^n%m can be written as ((x^n/2)%m*(x^n/2)%m)%m when n is even and ((x%m)*(x^n-1))%m when it's odd.
Base case is when n = 0. Classic Modular exponentiation problem. Uva ID 374 

Link : https://uva.onlinejudge.org/external/3/374.html  */

#include<iostream>
using namespace std;

long BigMod(long x,long n,long m){
if(n==0)
    return 1%m;
else if(n%2==0)
{
    return (BigMod(x,n/2,m)*BigMod(x,n/2,m))%m;
}

else

{
    return (BigMod(x,n-1,m)*(x%m))%m;
}
}

int main()
{
    long x,n,m;
    while(cin >> x>>n>>m){

        cout << BigMod(x,n,m) << endl;
    }
return 0;
}




