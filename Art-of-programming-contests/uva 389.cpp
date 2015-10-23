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

//converts num from some arbitrary base1 to a decimal
bool base1_to_dec(string num,int base1)
{
    decimal = 0;
    for(int i=0;i<num.size();i++)
    {   int digit = val(num[i]);
        if(digit < 0 || digit >= base1) //check if the number is valid in that base or not
        // a number's digits should be base-1 maximum to be valid in a base
        {
            return false;
        }
        decimal = decimal*base1 + digit;
    }
    return true;
}
//converts decimal to some arbitrary base2
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
    cout.width(7); // set width precision to 7
    cout.setf(ios :: right); // set cout as right justified
    if(ans.size()>7)
        cout << "ERROR" << endl;
    else
        cout<< ans << endl;

}
int main()
{ string num;
  int base1,base2;
 while(cin >> num >> base1 >> base2)
 {
  if(base1_to_dec(num,base1)==true)
        dec_to_base2(num,base1,base2);


 }

}
