#include<cstdio>
#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int countdivisors(int a,int b)
{
    int get_gcd = gcd(a,b);
    int count = 0;
    for(int i = 1;i*i<=get_gcd;i++)
    {
        if(get_gcd%i==0)
            count+=2;
        if(i*i==get_gcd)
            count--;
    }
    return count;
}

int main()
{
    int test;
        scanf("%d",&test);
        while(test--)
        { int a,b,result, ans;
          scanf("%d %d",&a,&b);

          printf("%d\n",countdivisors(a,b));
        }
}
