#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{char ch;
 while(cin >> ch){
 int ans = 0;
 ans = ch-48;
 while(cin >> ch)
 {   if(ch == '#') break;
     ans = ans << 1;
     ans = ans + ch-48;
     ans = ans%131071;}
 }
 if(ans==0)
    cout << "YES" << endl;
 else
    cout << "NO" << endl;
}
return 0;
}
