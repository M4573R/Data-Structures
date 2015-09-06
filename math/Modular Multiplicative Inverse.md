##Modular Multiplicative Inverse.

Let's assume given two integers a and m, we have to determine modular multiplicative inverse of a 
under modulo m. 

The modular multiplicative inverse is an integer ‘x’ such that.

 a*x ≡ 1 (mod m) 
 
(i.e if we multiply a with x and then divide by m, we are going to get 1 as the remainder).

The value of x should be in {0, 1, 2, … m-1}, i.e., in the ring of integer modulo m.

The multiplicative inverse of “a modulo m” exists if and only if a and m are relatively prime (i.e., if gcd(a, m) = 1).

Example : 

1. if a = 4, m = 7, then x = 2 as 4*2 = 8 and 8 mod 7 = 1.
2. if a = 8, m = 11, then x = 7 as 8*7 = 56 and 56 mod 11 = 1.
3. if a = 3, m = 11, then x = 4 as 4*3 = 12 and 12 mod 11 = 1. One might think, 15 also as a valid output as "(15*3) mod 11" 
is also 1, but 15 is not in ring {0, 1, 2, ... 10}, so it's not valid.

How can we find x and why do we need it?

Let's say a and b are two very large integers and we have to determine (a+b)%m. But (a+b) does not fit in the memory.
So we use the rules of modular arithmatic :

(a + b)%m = ((a%m) + (b%m))%m

This way we don't have to determine a + b first and then divide that by m. And because a%m and b%m are always going to be 
smaller than m(divisibility theorem), we have reduced the problem to a form that we can actually work with.

Similarly, 

(a - b)%m = ((a%m) - (b%m)) % m

and (a*b)%m = ((a%m)*(b%m)) % m

Does this hold for division?

Unfortunately, no.

(a/b)%m != ((a%m)/(b%m))%m

But if we convert (a/b)%m to (a * b^-1)%m, then 

(a * b^-1)%m = ((a%m)*(b^-1 % m)) % m

So this is why we need the inverse to use in cases like (b^-1 % m)

How to find the inverse.

There are different methods for it. Such as Fermat's Little theorem(if m is prime), extended euclidean theorem, 
euler's totient etc.

###Fermat's Little Theorem : 

Fermat's little theorem states that if p is a prime number, then for any integer a, the number a p − a is an integer multiple of p. In the notation of modular arithmetic, this is expressed as

![image](https://upload.wikimedia.org/math/6/9/3/69371e11a96b092eac30a9490cbd9f85.png)

For example, if a = 2 and p = 7, 27 = 128, and 128 − 2 = 7 × 18 is an integer multiple of 7.

If a is not divisible by p, Fermat's little theorem is equivalent to the statement that a p − 1 − 1 is an integer multiple of p, or in symbols

![image](https://upload.wikimedia.org/math/d/9/9/d999506f0d091a358bace3f8568dca2f.png)

For example, if a = 2 and p = 7 then 26 = 64 and 64 − 1 = 63 is a multiple of 7.

We can use the second version :

since if m is prime, we know by fermat's little theorem that 

![image](https://latex.codecogs.com/gif.latex?a%5E%7Bm-1%7D%20%5Cequiv%201%20%5Cpmod%20m)

We use this to find modular multiplicative inverse.

From above,

![image](https://latex.codecogs.com/gif.latex?a*a%5E%7Bm-2%7D%20%5Cequiv%201%20%5Cpmod%20m)

So ![image](https://latex.codecogs.com/gif.latex?a%5E%7Bm-2%7D) is the modular multiplicative inverse.

Example : 

![image](https://latex.codecogs.com/gif.latex?if%20m%20%3D%205%2C%20a%20%3D%204%2C%20then%2C%20a%5E%7Bm-2%7D%20%3D%204%5E3%20%3D%2064.)

and 64*4 = 256 % 5 = 1.

But what if m is not prime?

Here comes the Euler's totient function.

###Euler’s Totient Function

Euler’s Totient function Φ(n) for an input n is count of numbers in {1, 2, 3, …, n} that are relatively prime to n, i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1.

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
gcd(1, 6) is 1 and gcd(5, 6) is 1.

Another way to describe it is by using Euler's product formula. It states

![i](https://upload.wikimedia.org/math/6/1/9/619a7845480ba7a8a749dc56a6de7c60.png)


We can use it to get the modular multiplicative inverse.

###Euler's theorem :

In number theory, Euler's theorem (also known as the Fermat–Euler theorem or Euler's totient theorem) states that if n and a are coprime(i.e gcd(a,b)= 1) positive integers, then


![i](https://latex.codecogs.com/gif.latex?a%5E%7B%5Cvarphi%20%28n%29%7D%20%5Cequiv%201%20%5Cpmod%7Bn%7D)

where φ(n) is Euler's totient function. 

The theorem may be used to easily reduce large powers modulo n. For example, consider finding the ones place decimal digit of 7222, i.e. 7222 (mod 10). Note that 7 and 10 are coprime, and φ(10) = 4. So Euler's theorem yields 74 ≡ 1 (mod 10), and we get 7222 ≡ 74 × 55 + 2 ≡ (74)55 × 72 ≡ 155 × 72 ≡ 49 ≡ 9 (mod 10).


So we can write ![i](https://latex.codecogs.com/gif.latex?a*a%5E%7B%5Cvarphi%20%28m%29-1%7D%20%5Cequiv%201%20%5Cpmod%7Bn%7D)

where ![i](https://latex.codecogs.com/gif.latex?a%5E%7B%5Cvarphi%20%28m%29-1%7D) is the modular multiplicative inverse.


###Brute force algorithm for finding multiplicative inverse.

if we want to find multiplicative inverse of n under modulo m, then we can write 

```C++
int findMMI_bruteforce(int n,int M)
{int i = 1;
 while(i<M) // we try all the numbers from 1....m-1.
 {if(((long long)i*n)%M == 1)
         return i;
  i++;
 }
 return -1;//MMI does not exist
 }
```

### Fermat's little theorem approach:

If we know m is prime, then we can also use Fermats’s little theorem to find the inverse.

am-1 ≡ 1 (mod m)  
If we multiply both sides with a-1, we get

 a-1 ≡ a m-2 (mod m)
Below is C++ implementation of above idea.

```C++
// C++ program to find modular inverse of a under modulo m
// This program works only if m is prime.
#include<iostream>
using namespace std;
 
// To find GCD of a and b
int gcd(int a, int b);
 
// To compute x raised to power y under modulo m
int power(int x, unsigned int y, unsigned int m);
 
// Function to find modular inverse of a under modulo m
// Assumption: m is prime
void modInverse(int a, int m)
{
    int x, y;
    int g = gcd(a, m);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // If a and m are relatively prime, then modulo inverse
        // is a^(m-2) mode m
        cout << "Modular multiplicative inverse is "
             << power(a, m-2, m);
    }
}
 
// To compute x^y under modulo m
int power(int x, unsigned int y, unsigned int m)
{
    if (y == 0)
        return 1; //base case. a^0 = 1
    int p = power(x, y/2, m) % m; 
    p = (p * p) % m;
 
    return (y%2 == 0)? p : (x * p) % m;
}
// See big mod article to see how it works here : 
// [big mod](https://github.com/M4573R/Data-Structures/blob/master/math/BigMod.md)

// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
 
// Driver Program
int main()
{
    int a = 3, m = 11;
    modInverse(a, m);
    return 0;
}

Output:

Modular multiplicative inverse is 4 
```

Complexity of this algorithm is O(LogM)

### Extended Euclidean Algorithm approach :

The idea is to use Extended Euclidean algorithms that takes two integers ‘a’ and ‘b’, finds their gcd and also find ‘x’ and ‘y’ such that

 ax + by = gcd(a, b) 
 
To find multiplicative inverse of ‘a’ under ‘m’, we put b = m in above formula. Since we know that a and m are relatively prime, we can put value of gcd as 1.

ax + my = 1 
If we take modulo m on both sides, we get

ax + my ≡ 1 (mod m)
We can remove the second term on left side as ‘my (mod m)’ would always be 0 for an integer y.

ax  ≡ 1 (mod m) 
 
So the ‘x’ that we can find using Extended Euclid Algorithm is multiplicative inverse of ‘a’

*Still need improvement 

Reference : 

1.http://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
2.http://www.geeksforgeeks.org/basic-and-extended-euclidean-algorithms/
3.http://www.geeksforgeeks.org/eulers-totient-function/'
4.https://www.youtube.com/playlist?list=PLTZbNwgO5ebofXdvHxZm3GmSPhhDeTr_k



