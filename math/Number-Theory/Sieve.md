If we want to generate prine numbers from 1 to n, a brute force solution may look like this(O(nsqrt(N)) :

```C++
#include <vector>
using namespace std;

vector<int> getPrimes(int n) {
  vector<int> primes;
  for (int i = 2; i <= n; i++) {
    if (isPrime(i)) {
      primes.push_back(i);
    }
  }
  return primes;
}
```

Sieve of Erasthones(time complexity O(nlog(logN)) can make it much faster:

To use Sieve method, we take numbers from 1 to N and list them in increasing order like 1,2,3,4,5,6,7,8...n.
We start picking number i from left and if it's not crossed yet, we cross all of it's multiples from the list as they
are composite. We'll have only prime numbers left as we go to the end of the loop. If a number has not been crossed at the
end of the loop, it means there are no divisors that is smaller than itself which could divide it.

Brute force :
```C++
#define M 1000000
bool marked[M];
void sieve(int n) {
  for (int i = 2; i < n; i++) {
    if (marked[i] == false) { // i is a prime
      for (int j = i + i; j <= n; j += i) {
        marked[j] = true;
      }
    }
  }
}
```

This will mark all of the composite numbers as true in the marked array, only the prime numbers will be false at the end 
of the loop

We can check primality with Sieve :

```C++
bool isPrime(int n) {
  if (n < 2) return false;
  return marked[n] == false;
}
```
But we don't have to run the loop until n. We remember that 

Optimizations:

1.If m is a multiple of i and i is a multiple of p, then m is also a multiple of p. Thus, if i has already been crossed out
when the algorithm reaches it, we need not go crossing out its multiples, because they would have already been crossed out.

2.If a number m is not prime, then it has a factor that is <= sqrt(m).This is because if m=pq, then at least one of p and 
q must be<= sqrt(m).Thus, any number that is ever crossed out will be crossed out first by a number less than or equal 
to its square root.Putting this another way, we need not cross out multiples m of i that are less than i^2, 
because if m<i^2 is composite, it would have already been crossed out by some number smaller than i.

By the above, as we will do nothing for i such that i^{2} exceeds N, we can stop when that happens.

```C++
define M 1000000
bool marked[M];
void sieve(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (marked[i] == false) { // i is a prime
      for (int j = i * i; j <= n; j += i) {
        marked[j] = true;
      }
    }
  }
}
```

Other optimizations[edit]
There is no need to store even numbers, as there is only one even prime number. (2, of course.)
You can use bitmaps to pack the memory. We also observe that we are crossing off the same multiples again and again.
For example when we mark the multiples of 3,we are marking 6,9,12,15,18,...3. at least half of them are multiple's of 2.
Same is true for all other numbers, so we can avoid it by crossing the multiple's of odd numbers only.

```C++
define M 1000000
bool marked[M];

bool isPrime(int n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  return marked[n] == false;
}

void sieve(int n) {
  for (int i = 3; i * i <= n; i += 2) {
    if (marked[i] == false) { // i is a prime
      for (int j = i * i; j <= n; j += i + i) {
        marked[j] = true;
      }
    }
  }
}
```

Bitewise Sieve implementation :

In our implementation we are using boolean arrays to mark primes. A bool objects holds 8 bit in memory. If we can use all the 
bits seperately, it will reduce our memory usage by a factor of 8 and if we discount all the even numbers
we can reduce memory usage by a factor of 16. We are using 'int' here whose value is 32 bit but we are dividing by
64 repeatedly because we are discounting even numbers.

```C++
#define M 100000000
int marked[M/64 + 2];

#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)  marked[x/64] |= (1<<((x%64)/2))

void sieve(int n) {
  for (int i = 3; i * i < n; i += 2) {
    if (!on(i)) {
      for (int j = i * i; j <= n; j += i + i) {
        mark(j);
      }
    }
  }
}

bool isPrime(int num) {
  return num > 1 && (num == 2 || ((num & 1) && !on(num))); 
}
```


Segmented Sieve :

See it's own page.
