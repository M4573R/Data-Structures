#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define M 1000000

bool marked[M];
vector<int> primes;

int gcd(int a, int b) {
 return b == 0 ? a : gcd(b, a % b);
}

void sieve(int n) {
  primes.push_back(2);
  for (int i = 3; i * i <= n; i += 2) {
    if (marked[i] == false) { // i is a prime
      primes.push_back(i);
      for (int j = i * i; j <= n; j += i + i) {
        marked[j] = true;
      }
    }
  }
}


int countDivisor(int N) {
  int PF_idx = 0, PF = primes[PF_idx], ans = 1; // start from ans = 1
while (PF * PF <= N) {
int power = 0; // count the power
while (N % PF == 0) { N /= PF; power++; }
ans *= (power + 1); // according to the formula
PF = primes[++PF_idx];
}
if (N != 1) ans *= 2; // (last factor has pow = 1, we add 1 to it)
return ans;
}

int main()
{       sieve(M);
        int test;
        scanf("%d",&test);
        while(test--)
        { int a,b,result, ans;
          scanf("%d %d",&a,&b);
          result = gcd(a,b);
          printf("%d\n",countDivisor(result));
        }
}
