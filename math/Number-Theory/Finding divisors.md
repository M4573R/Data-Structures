## Find all the factors of a given natural number.

####Method : Trial division.

We can divide n by all the numbers from 1 to N and find out the factors.

```
A = empty list
for(int i=1;i<=N;i++)
  {if(N%i ==0)
      Add i to list A
  }
return A
```
Complexity  : O(N)

```C++
int countDivisor(int n) {
  int divisor = 0;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      divisor++;
    }
  }
  return divisor;
}
```

Observation : Apart from 1 and N itself, smallest factor of N is 2 and largest factor is N/2.
Let 
```
A = {1,N}
for i = 2 to N/2:
      if(N%i==0)
         Add i to list A
```         

Complexity : O(N/2) = O(N)

Second observation : According to number theory, if there is a number a that divides N, then there
is also another number b = N/a that divides N. If a < b, then a < sqrt(N) and b > sqrt(N). And if
a > b, then a > sqrt(N) and b < sqrt(N)

```
A = empty list
for i = 1 to sqrt(N):
      if(N%i ==0)
          {add i to list A
           if(i!=sqrt(N))
              add N/i to list A
          }
```
Complexity : O(sqrt(N))

Basically since we are going to get divisors in pair, we can count them by 2 here as we are considering both i and n/i.
Only if i = sqrt(N) we are going to add two to disisor count.

```C++
int countDivisor(int n) {
  int divisor = 0;
  for (int i = 1; i * i <= n; i++) {
    if (i * i == n) {
      divisor += 1;
    } else if (n % i == 0) {
      divisor += 2;
    }
  }
  return divisor;
}
```

### Optimized solution :



References : [Finding divisors](https://www.youtube.com/watch?v=dolcMgiJ7I0&index=5&list=PL2_aWCzGMAwLL-mEB4ef20f3iqWMGWa25)
