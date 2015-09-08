/*Uva Id : 11417. 
https://uva.onlinejudge.org/external/114/p11417.pdf

*/




#include<iostream>
using namespace std;

int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main()
{
    int N,result;
    while(cin >> N && N!=0){
        result = 0;
        for(int i=1;i<N;i++)
            {for(int j=i+1;j<=N;j++)
                {
                    result = result + gcd(i,j);
                }
            }
       cout << result << endl;
    }
}
