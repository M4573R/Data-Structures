// The bases are loaded!
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
long long int decimal;
string numbers = "0123456789ABCDEF";


int val(char n)
{
    if(n>='0'&&n<='9')

        return n - '0';
    if(n>='A' && n<='F')
        return n-'A'+10;
}

bool base1_to_dec(string num,int base1)
{
    decimal = 0;
    for(int i=0;i<num.size();i++)
    {   int digit = val(num[i]);
        if(digit < 0 || digit >= base1)
        {
            return false;
        }
        decimal = decimal*base1 + digit;
    }
    return true;
}

void dec_to_base2(string num,int base1,int base2)
{
    string ans;
    if(decimal==0)
        ans = "0";
    while(decimal>0)
    {
        ans = ans + numbers[decimal%base2];
        decimal = decimal/base2;
    }
    reverse(ans.begin(),ans.end());
    if(ans == "0")
        cout << num <<" base "<<base1 <<" = " << "0" << " base " << base2 << endl;
    else
        cout << num <<" base "<<base1 <<" = " << ans << " base " << base2 << endl;
}


int main()
{ string num;
  int base1,base2;
 while(cin >> base1 >> base2 >> num)
 {
  if(base1_to_dec(num,base1)==true)
        dec_to_base2(num,base1,base2);
   else
      cout << num << " is an illegal base " << base1 << " number" << endl;

 }

}
