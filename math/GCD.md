###Euclids algorithm :

Suppose a and b are integers
with a ≥ b > 0.
(1) Apply the division algorithm: a = bq + r, 0 ≤ r < b.
(2) Rename b as a and r as b and repeat until r = 0.
The last nonzero remainder is the greatest common divisor of a and b.
The Euclidean Algorithm depends upon the following lemma.
Lemma 2.1.1. If a = bq + r, then GCD(a, b) = GCD(b, r).

###Proof. 

We will show that if a = bq + r, then an integer d is a common divisor
of a and b if, and only if, d is a common divisor of b and r.
Let d be a common divisor of a and b. Then d|a and d|b. Thus d|(a − bq), which
means d|r, since r = a − bq. Thus d is a common divisor of b and r.
Now suppose d is a common divisor of b and r. Then d|b and d|r. Thus d|(bq +r),
so d|a. Therefore, d must be a common divisor of a and b.
Thus, the set of common divisors of a and b are the same as the set of common
divisors of b and r. It follows that d is the greatest common divisor of a and b if and
only if d is the greatest common divisor of b and r.

###Example : 

Let a = 2322, b = 654.

 	2322 = 654·3 + 360	  	gcd(2322, 654) = gcd(654, 360)
 	654 = 360·1 + 294	  	gcd(654, 360) = gcd(360, 294)
 	360 = 294·1 + 66	  	gcd(360, 294) = gcd(294, 66)
 	294 = 66·4 + 30	  	gcd(294, 66) = gcd(66, 30)
 	66 = 30·2 + 6	  	gcd(66, 30) = gcd(30, 6)
 	30 = 6·5	  	gcd(30, 6) = 6
Therefore, gcd(2322,654) = 6.



###Iterative implementation : 
```C++
int  euclid_gcd(int a,int b)
{ int divident = a >=b ? a : b;
  int divisor = a <= b ? a : b;
  while(divisor!=0){
        int remainder = divident%divisor;
        divident = divisor;
        divisor = remainder;
 }
```
recursive : 
```C++
int gcd(int a,int b)
{if(b==0)
    return a; // when remainder hits zero return the divident
 else
    return gcd(b,a%b) // keep switching the divident into b and the divisor into a%b.
}
```





Reference : 
1. http://www.math.fsu.edu/~pkirby/mad2104/SlideShow/CourseNotesMAD2104.pdf
2. http://www.math.fsu.edu/~pkirby/mad2104/




