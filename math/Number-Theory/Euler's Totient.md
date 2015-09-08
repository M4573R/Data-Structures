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

### How to calculate the totient?


A simple solution is to iterate through all numbers from 1 to n-1 and count numbers with gcd with n as 1.

Below is C++ implementation of the simple method to compute Euler’s Totient function for an input integer n.

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
    int result = 1;
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


