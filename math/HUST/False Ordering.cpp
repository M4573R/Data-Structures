/* LightOJ Problem Id : False Ordering. 

Key idea : Create a list 'ans' that is sorted according the to the false order. To sort according to the false order,
we must know the number of divisors for each integer i from 1 to 1000. So we create the list divisors and store the number of 
divisors for each integer and later use cmp to sort it according to the false order.

*/


#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int divisors[1005];
int ans[1005];

bool cmp(int x,int y)
{ if(divisors[x]==divisors[y])
        return x > y;

  return divisors[x]<divisors[y];
}

int main()
{
    for(int i=1;i<=1000;i++)
    {
        ans[i]= i;
        divisors[i] = 0;
        //Get the number of divisors for each i from 1 to 1000.
        for(int j = 1;j<=sqrt(i);j++)
        {
            if(i%j==0 && j!=sqrt(i))
                divisors[i] = divisors[i]+2;
            if(i%j==0 && j==sqrt(i))
                divisors[i]++;
        }
    }


    std::sort(ans+1, ans+1001,cmp);
    int test;
    cin >> test;
    for(int k = 1;k<=test;k++)
    {
        int n;
        cin >> n;
        cout << "Case " << k << ": " << ans[n] << endl;
    }

    return 0;

}




