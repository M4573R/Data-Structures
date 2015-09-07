### Prime Number :

A number n is a prime number if and only if it's divisible by only 1 and n, otherwise it's called composite. To check
whether a number is a prime number or not , we can use the trial division method.

#### Trial Division method for primality testing : 

We divide number n by all numbers from 2 up to n - 1. If it's divisible by any of those numbers, it's a composite number,
otherwise prime. This algorithm's complexity is roughly O(N)

```C++
bool isPrime(int n) {
  if (n < 2) return false;
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true; }
```
