### Fibonacci numbers

The formula for Fibonacci
Computing for Fibonacci is simple. The formula is below.

Fibonacci (n) = Fibonacci(n-1) + Fibonacci(n-2);

To computer for Fibonacci of 7, simply add the values of Fibonacci of 6 and Fibonacci of 5. 
In other words, the sum of the previous two values.

Fibonacci(7) = Fibonacci(6) + Fibonacci(5);
Fibonacci(7) = 8 + 5;
Fibonacci(7) = 13

###Iterative Fibonacci : 

```C++
int fib(int n) {
    if ( n == 0 || n == 1 ) 
        return n;
 
    int fib1 = 0; 
    int fib2 = 1;
    int fib = 0;
 
    for ( int i = 2; i <= n; i++ ) 
    {
        fib = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib;
    }
 
    return fib;
```

or DP version

```C++
int fib(int n){
    if(n==0 || n==1)
        return n;
        
    int fn[n+1];
    fn[0] = 0;
    fn[1] = 1;
    for(int i = 2; i<=n; i++)
    {   fn[i] = fn[i-1] + fn[i-2]; }
    
    return fn[n];
    
}
```

###Recursive Fibonacci : 

```C++    
int fib(int n)
{
     if ( n == 0 ) return 0;
     if ( n == 1 ) return 1;
 
     return fib(n-1) + fib(n-2);
} 
```

### DP + Vector :

```C++
vector <int> fib;
fib.push_back(0);
fib.push_back(1);
 
int n; //N is the number of fibonacci numbers we are going to compute. 
 
for ( int i = 2; i < n; i++ ) 
{
      fib.push_back( fib[i-1] + fib[i-2] );
}
```

###Matrix Version : 

Incomplete : See [here](http://www.geeksforgeeks.org/program-for-nth-fibonacci-number/)



From [this post](http://talkbinary.com/programming/c/fibonacci-in-c/)
