/* LightOJ : Hex-a-bonacci.cpp

Key idea : Iterative fibonacci. 
Reference : 

*/


#include<iostream>
using namespace std;

int main() {
    long long a, b, c, d, e, f;
    int n, caseno = 0, cases;
    cin >> cases;
    while( cases-- ) {

        cin >> a >> b >> c >> d >> e >> f >> n;
        long long fn[10005];
        fn[0] = a;
        fn[1] =b;
        fn[2] = c;
        fn[3] = d;
        fn[4] = e;
        fn[5] = f;

        for(int i = 6; i <=n; i++)
        {
            fn[i] = (fn[i-1] + fn[i-2] + fn[i-3] + fn[i-4] + fn[i-5] + fn[i-6])% 10000007;
        }

        cout << "Case "<< ++caseno << ": " << fn[n]% 10000007 << endl;
    }
    return 0;
}
