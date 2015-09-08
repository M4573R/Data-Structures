### LCM :

LCM (Least Common Multiple) of two numbers is the smallest number which can be divided by both numbers.
For example LCM of 15 and 20 is 60 and LCM of 5 and 7 is 35.
LCM of two numbers ‘a’ and ‘b’ can be calculated using following formula.

   a x b = LCM(a, b) * GCD (a, b)

   LCM(a, b) = (a x b) / GCD(a, b) 
   
Using GCD, we can find LCM.

```C++
#include <bits/stdc++.h>

int gcd(int a, int b) {
    if(b == 0) return a; // base case
    else return gcd(b, a % b);
}

// Function to return LCM of two numbers
int lcm(int a, int b)
{
    return (a*b)/gcd(a, b);
}
 
// Driver program to test above function
int main()
{
    int a = 15, b = 20;
    printf("LCM of %d and %d is %d ", a, b, lcm(a, b));
    return 0;
}
```
Output:

LCM of 15 and 20 is 60

From : [LCM](http://geeksquiz.com/c-program-find-lcm-two-numbers/)

Brute force implementation : 


```C++
int lcm(int a, int b) {
  for (int i = 1; ; i++) {
    if (i % a == 0 && i % b == 0) {
      return i;
    }
  }
}
```

To avoid overflow we can also write LCM Like this :

```C++
int lcm(int a, int b) {
  return (a / gcd(a, b)) * b;
}
```




