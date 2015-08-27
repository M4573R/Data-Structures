#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
bool p[1000000];
vector<int> P;
void GeneratePrime()
{
fill(p,p+1000000,true);
p[0]=false;
p[1]=false;
for(int i=1;i<500000;i++) p[2*i] = false;
for(int i=3;i<1000000;i+=2){
    if(p[i]){
    if(i<500000) P.push_back(i);
    for(int j = 2;j*i<1000000;j++) p[i*j] = false;
    }
    }

}


int main(){

GeneratePrime();
int n,a,b;
while(cin >> n && n!=0)
{
    for(int i=0;;i++)
    {
        a = P[i];
        b = n - a;
        if(p[b])
            {cout << n << " = " << a << " + " << b << endl;
                break;}
    }
}

return 0;
}
