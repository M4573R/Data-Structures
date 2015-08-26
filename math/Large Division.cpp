/*#Key idea:  

Perform Long Division. Problem ID : LightOJ Large Division.
Input is too big to fit in int/long long etc so we take it as a string. 
Basic long division looks like this : 4|2256|564
                                        20
                                        ____
                                         25
                                         24
                                         ___
                                           16
                                           16
                                          ____
                                            0
  Compare it to :
  
  long rem = 0;
  for(int i=0;i<a.size();i++){
        if(a[i]== '-') continue;
        rem = rem*10 + (a[i]-'0');
        rem = rem%d;
        }
        
  First rem is 0. We add the first digit and try to divide. If not possible we enter the second iteration where rem = first 
  digit * 10 + second digit. If this rem is bigger than the divisor, we divide and keep the remainder in rem. This remainder 
  will always be smaller than the divisor according to the properties of divisibility. So we again use rem = remainder
  *10 + next digit. The process repeats until we reach the last digit. */
  
#include<iostream>
#include<string>
using namespace std;

int main(){
int test;
string a; //dividend
int d;  // divisor
cin >> test;
for(int j=1;j<=test;j++){
    cin >> a;
    cin >> d;
    long rem = 0;
    for(int i=0;i<a.size();i++){
        if(a[i]== '-') continue;
        rem = rem*10 + (a[i]-'0');
        rem = rem%d;
        }
    cout << "Case " << j << ": ";
    if (rem!=0) cout << "not divisible" << endl;
    else cout << "divisible" << endl;

}

return 0;
}





