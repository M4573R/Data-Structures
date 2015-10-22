#include<iostream>
#include<vector>
#include<string>
using namespace std;

int val(char n)
{
    if(n>='0'&&n<='9')
        return n - '0';
    if(n>='A' && n <= 'Z')
        return n - 'A' + 10;
}

int main()
{
 int n ; // smallest possible base for 1st integer
 int m; // smallest possible base for 2nd int
 string s1,s2;
 vector<long long> v1; // values in different bases for 1st int
 vector<long long> v2; // values in different bases for 2nd int
 int q;

 while(cin >> s1 >> s2)
 {   bool flag = false;
     int n = 0;
     int m = 0;
     // Find the numbers maximum digit and add 1 to it as a digit n can be represented in a minimum base of n + 1
     for(int i=0;i<s1.size();i++)
        n = max(n,val(s1[i])+1);
     for(int i = 0; i<s2.size();i++)
        m = max(n,val(s2[i]+1));

     v1.clear();
     v2.clear();

     // store the values of the first integer

     for(int base = n; base <= 36 ; base++)
     {
         q = 0;
         for(int i=0;i<s1.size();i++)
         {
             q = q*base + val(s1[i]);
         }
         v1.push_back(q);
     }


     // store the values for the 2nd int

     for(int base = m; base <= 36 ; base++)
     {
         q = 0;
         for(int i=0;i<s2.size();i++)
         {
             q = q*base + val(s2[i]);
         }
         v2.push_back(q);
     }

     for(int i=0;i<v1.size();i++)
     {
         for(int j = 0; j<v2.size();j++)
         {
             if(v1[i]==v2[j])
                {flag = true;
                cout<<s1<<" (base "<<i+n<<") = "<<s2<<" (base "<<j+m<<")"<<endl;
                break;}
         }
         if(flag == true)
            break;
     }

    if(flag==false)
        cout<<s1<<" is not equal to "<<s2<<" in any base 2..36"<<endl;

 }

 return 0;

}
