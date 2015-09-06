##Modular Multiplicative Inverse.

Let's assume given two integers a and m, we have to determine modular multiplicative inverse of a 
under modulo m. 

The modular multiplicative inverse is an integer ‘x’ such that.

 a*x ≡ 1 (mod m) 
 
(i.e if we multiply a with x and then divide by m, we are going to get 1 as the remainder).

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


