Euler's phi function measures the breakablity of a number. Given a number N,
Φ(n)  outputs how many integers are less than or equal to N, that do not share any common factor with N, or
are coprime/relatively prime with 1. Said in another way, Euler’s Totient function Φ(n) for an input
n is count of numbers in {1, 2, 3, …, n} that are relatively prime to n, i.e., the numbers whose 
GCD (Greatest Common Divisor) with n is 1.

Let's say there's 1,2,3,4,5,6,7,8, total 8 numbers up to 8. 1,3,5 and 7 are coprime with 8, so Φ(8) = 4.

Euler's function is described by φ(n). If φ(n)=x it means from 1 to n there's x many numbers where the gcd with those numbers
equal 1. If gcd(a,b) = 1, then we call a and b, co prime or relative prime.

For, n=9  gcd(9,3)=gcd(9,6)=3 and gcd(9,9)=9 
and for the other six numbers   gcd(9,1)=gcd(9,2)=gcd(9,4)=gcd(9,5)=gcd(9,7)=gcd(9,8)=1। So φ(9)=6.

Examples:

Φ(1) = 1  
gcd(1, 1) is 1

Φ(2) = 1
gcd(1, 2) is 1, but gcd(2, 2) is 2.

Φ(3) = 2
gcd(1, 3) is 1 and gcd(2, 3) is 1

Φ(4) = 2
gcd(1, 4) is 1 and gcd(3, 4) is 1

Φ(5) = 4
gcd(1, 5) is 1, gcd(2, 5) is 1, 
gcd(3, 5) is 1 and gcd(4, 5) is 1

Φ(6) = 2
gcd(1, 6) is 1 and gcd(5, 6) is 1, 

Calculating Φ(n) is hard, except when n is prime. Since prime numbers have no factors greater than 1, Φ(n) when
n is prime is simply Φ(n) = n - 1. To see it, Φ(7) = 6 because 1,2,3,4,5,6 are co prime with 7 i.e gcd(7,number) = 1.

Φ(n) is also multiplicative, i.e Φ(n) = Φ(p1) * Φ(p2)
                                      = (p1-1) * (p2 - 1)
if n = p1 * p2 where p1 and p2 are the unique numbers in n's prime factorization.

Notes :

1.Φ(n) = Φ(a)*Φ(b) only works if both a and b are relatively prime.

Why? 

Euler's Phi function is multiplicative, not completely multiplicative.
If a function f is multiplicative, then if (a,b) = 1 (gcd) → f(a*b) = f(a)*f(b)
If a function f is completely multiplicative, then for every a and b → f(a*b) = f(a)*f(b)

2. If you have a number x, and the phi is x-1, is x definitely prime?

Yes. if phi(x) = x-1 it would mean that x doesnt share a factor greater than 1 with any number less than x, 
so no number less than x and greater than 1 divides x. 
Therefore x can only be divided by one or by itself (definition of prime).

Note that phi(1) = 1, so the claim is true.

3. If p is prime and k > 0 then phi(P^k) = P^k -P^k-1. Note that here ^ denotes power. Here all the numbers from 1 to p^k are coprime to p^k except all the multiples of p, which are exactly p^(k -1).
4. If m and n is coprime then phi(mn) = phi(m) * phi(n)

Applications of Euler's function : 

The most famous and important feature of Euler's function is expressed in Euler's theorem:

![i](http://e-maxx.ru/tex2png/cache/dd54e3a4495b866d067e85424d76e0f3.png)

where a and m  are relatively prime.

In the particular case when ma simple, Euler's theorem turns into the so-called Fermat's little theorem:
![i](https://latex.codecogs.com/gif.latex?a%20%5E%20%7Bm-1%7D%20%5Cequiv%201%20%5C%20%28mod%20m%29)


Euler's theorem occurs quite often in practical applications, for example, see. The inverse element in the modulus.

### How to calculate the totient?


A simple solution is to iterate through all numbers from 1 to n-1 and count numbers with gcd with n as 1.
Count the number of positive integers < N that are relatively prime to N. Recall: Two integers a and b are said to be relatively prime (or coprime) if gcd(a, b) = 1, e.g. 25 and 42. A naive algorithm to count the number of positive
integers < N that are relatively prime to N starts with counter = 0, iterates through
i ∈ [1..N-1], and increases the counter if gcd(i,N) = 1. This is slow for large N.

Below is C++ implementation of the simple method to compute Euler’s Totient function for an input integer n.
As every integer is coprime to 1, we are iterating from 2 to n-1 while adding 1 to count of co-prime integers first.

```C++
// A simple C program to calculate Euler's Totient Function
#include <iostream>
#include<cmath>
#include<cstdio>
using namespace std;
 
// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
 
// A simple method to evaluate Euler Totient Function
int phi(int n)
{ 
    int result = 1; // every integer is co-prime to 1 see : https://proofwiki.org/wiki/Integer_is_Coprime_to_1 
    for (int i=2; i<n; i++)
        if (gcd(i, n) == 1)
            result++;
    return result;
}
 
// Driver program to test above function
int main()
{
    int n;
    for (n=1; n<=10; n++)
      printf("phi(%d) = %d\n", n, phi(n));
    return 0;
}
```

Output:

phi(1) = 1
phi(2) = 1
phi(3) = 2
phi(4) = 2
phi(5) = 4
phi(6) = 2
phi(7) = 6
phi(8) = 4 
phi(9) = 6
phi(10) = 4


The above code calls gcd function O(n) times. Time complexity of the gcd function is O(h) where h is number of digits 
in smaller number of given two numbers. Therefore, an upper bound on time complexity of above solution is O(nLogn) 
[How? there can be at most Log10n digits in all numbers from 1 to n]

###According to Euler's product rule :

![i](https://upload.wikimedia.org/math/6/1/9/619a7845480ba7a8a749dc56a6de7c60.png)

For example N = 36 = 22 ×32. ϕ(36) = 36×(1− 1/2 )×(1− 1/3 ) = 12. Those 12 positive
integers that are relatively prime to 36 are {1, 5, 7, 11, 13, 17, 19, 23, 25, 29, 31, 35}

where the product is over the distinct prime numbers dividing n,(remember we count only the unique numbers)

Key idea : We find all the prime factors p and calculate phi by the product rule.

Question : How do we find the prime factors?

For each number from 2 up to sqrt(N), we divide the number n by the number i and remove all occurances of that number.
If the number is even, it will be divided by two first and remove all occurances of two by repeated division. Then we
apply the product rule n*(1-1/2) or update n = n - n/2. After that, n will become odd and again we check if n is divisible by three and again we remove all occurances of 3 and again update n = n - n/3(assuming n is both divisible by 2 and 3) and so 
on.

We can see the idea here : 
[Prime Factorization efficient algorithm](http://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/)


Steps :

1. Initialize result as n
2. Consider every number 'p' (where 'p' varies from 2 to √n). 
   If p divides n, then do following :

   * Remove all occurances of p by repeatedly dividing n by p.
   * After removing all occurances, take p(unique) and use the product rule to get n*(1-1/i) or update n = n - n/i or n-=n/i
3. If n does not become 1 then there's the last prime factor that is greater than sqrt(N) remaining so we should
apply the product rule on that factor too.


A implementation of this idea may look like this :

```C++
int phi (int n) {
  int ret = n; // initialize the answer to n
  for (int i = 2; i * i <= n; i++) { // for each i, if i is a divisor of n, we remove all occurances of i from n by
    if (n % i == 0) {               // repeated division and apply the product rule
      while (n % i == 0) {
        n /= i; // we are removing all occurances of i here. 
      }
      ret -= ret / i; // applying the product rule here.
    }
  }
  // this case will happen if n is a prime number
  // in that case we won't find any prime that divides n
  // that's less or equal to sqrt(n) and there can be only one such factor so we apply product rule on this 
  // factor too.
  if (n > 1) ret -= ret / n;
  return ret;
}
```
From http://e-maxx.ru/algo/euler_function

```C++
int phi (int n) {
	int result = n;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}
```

From http://www.geeksforgeeks.org/eulers-totient-function/

```C++
#include <iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int phi(int n)
{    
    int result = n;   // Initialize result as n
 
    // Consider all prime factors of n and subtract their
    // multiples from result
    for (int p=2; p*p<=n; ++p)
    {
        // Check if i is a prime factor.
        if (n % p == 0)
        {
            // If yes, then update n and result 
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
 
    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result -= result / n;
    return result;
}
 
// Driver program to test above function
int main()
{
    int n;
    for (n=1; n<=10; n++)
      printf("phi(%d) = %d\n", n, phi(n));
    return 0;
```
Output:

phi(1) = 1
phi(2) = 1
phi(3) = 2
phi(4) = 2
phi(5) = 4
phi(6) = 2
phi(7) = 6
phi(8) = 4
phi(9) = 6
phi(10) = 4

Let us take an example to understand the above algorithm.

n = 10. 
Initialize: result = 10

2 is a prime factor, so n = n/i = 5, result = 5
3 is not a prime factor.

The for loop stops after 3 as 4*4 is not less than or equal
to 10.

After for loop, result = 5, n = 5
Since n > 1, result = result - n/result = 4

From CP3 :

```C++
ll EulerPhi(ll N) { // This assumes that we have used Sieve to create a list of primes
ll PF_idx = 0, PF = primes[PF_idx], ans = N; // start from ans = N
while (PF * PF <= N) {
if (N % PF == 0) ans -= ans / PF; // only count unique factor
while (N % PF == 0) N /= PF;
PF = primes[++PF_idx];
}
if (N != 1) ans -= ans / N; // last factor
return ans;
}
```

From http://www.progkriya.org/gyan/basic-number-theory.html#section5

```C++
int phi (int n) {
  int ret = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      ret -= ret / i; 
    }
  }
  // this case will happen if n is a prime number
  // in that case we won't find any prime that divides n
  // that's less or equal to sqrt(n)
  if (n > 1) ret -= ret / n;
  return ret;
}
```

From [Euler's Totient](http://learningarsenal.info/index.php/2015/08/21/eulers-totient-function/)

```C++
#include <stdio.h>
long long int phi(long long int n);
int main(void) {
       long long int n,totient;
       scanf("%lld",&n);
    while(n!=0)
    {
      totient= phi(n);
      printf("%lld\n",totient);
      scanf("%lld",&n);
    }
 return 0;
}
 
long long int phi (long long int n) 
{
   long long int result = n;
   long long int i;
   for (i=2; i*i<=n; ++i)
     if (n % i == 0) 
       {
          while (n % i == 0)
           n /= i;
           result -= result / i;
        }
     if (n > 1)
     result -= result / n;
     return result;
}
```

###Optimized Method :

See Euler with Sieve page.
