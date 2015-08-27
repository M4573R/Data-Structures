#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
bool p[1000000];
vector<int> P;

void GeneratePrime()
{
 fill(p,p+1000000,true);
 p[0]=p[1]=false;
 for(int i=1;i<500000;i++) p[2*i]=false;
 for(int i=2;i<=sqrt(1000000);i++)
 {if(p[i]==true)
    {
        for(int j=2;j*i<=1000000;j++)
        {
            p[i*j] = false;
        }
    }
 p[2] = false;
}
}
void Addprime()
{
    for(int i=0;i<1000000;i++)
    {
      if(p[i])
            P.push_back(i);
    }

}

int main()
{   GeneratePrime();
    Addprime();
    int n;
    int a,b;
    while(cin >> n && n!=0){
    for(int i=0;;i++)
    {
        a = P[i];
        b = n-a;
        if(p[b])
        {
            cout << n << " = " << a << " + " << b << endl;
            break;
        }
    }
    }
    return 0;
}
