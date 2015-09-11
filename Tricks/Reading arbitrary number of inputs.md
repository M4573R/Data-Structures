Problem name : Maximum GCD.

GCD is not what was giving me trouble here. I got stuck first because I had to read arbitrary amount of inputs 
without a predifined post-condition here. In most problems there's something like read inputs until you hit zero/some
other numbers, so I learnt the sstream library to learn how to use a string stream just like i/ostream.
turns out if I include this library named 'sstream> I can use the methods like istringstream(for reading inputs).
I've to initialize it with a string and then just use it as regular cin >> and read from it.
Example :

```C++
int T,N,a[99],ans;
	string s;

	cin>>T;
	getline(cin,s);

	while(T--){
		getline(cin,s);
		istringstream is(s);
		N = 0;
        ans = 0;
		while(is>>a[N]) ++N;
```

What's really happening? We use getline after cin when reading test cases because cin only reads the integer from
the input stream and leaves the '\n' in the stream, but getline reads everything and terminates when there's a '\n'
here. Without removing the first '\n', the string related getline finds the '\n' from the integer in the stream first 
and terminates without doing anything.

See more here : http://mathbits.com/MathBits/CompSci/APstrings/APgetline.htm





```C++
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int gcd(int a, int b){
	if(a%b==0) return b;
	return gcd(b,a%b);
}

int main(){
	int T,N,a[99],ans;
	string s;

	cin>>T;
	getline(cin,s);

	while(T--){
		getline(cin,s);
		istringstream is(s);
		N = 0;
        ans = 0;
		while(is>>a[N]) ++N;

		for(int i=0;i<N-1;i++)
		{
		    for(int j=i+1;j<N;j++)
            {
                ans = max(ans,gcd(a[i],a[j]));
            }
		}

		cout << ans << endl;
	}
	return 0;
}
```
