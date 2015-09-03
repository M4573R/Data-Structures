References :

1.[Low Level Bit Hacks](http://www.catonmat.net/blog/low-level-bit-hacks-you-absolutely-must-know/)
2.[Bitwise Sieve](http://www.shafaetsplanet.com/planetcoding/?p=855)
3.[Bit Operations](http://zobayer.blogspot.com/2009/12/bitwise-operations-in-cc-part-1.html)

Key idea : In a regular array after observing the value of the index we can determine whether a number 
is prime or not. Assume we are dealing with an 32 bit integer array. 

When we generate primes from 1 to 7 the primes look like this in binary representation : 

status[1]=০০০........০০(32 0's)
status[2]=০০০........০১(31 0's and one 1)
status[3]=০০০........০১(31 0's and one 1)
status[4]=০০০........০০(32 0's)
status[5]=০০০........০১(31 0's and one 1)
status[6]=০০০........০০(32 0's)
status[7]=০০০........০১(31 0's and one 1)
Per index 31 bit is being useless so we should use them! 

```
status[০]'s
    >>> 0'th bit indicates 0's primality (right most bit==0th bit)    
    >>> 1st bit indicates 1's primality (right most bit==0th bit)  তম বিট)
    >>> 2nd bit indicates 2's primality
    >>> 3rd bit indicates 3's primality
   .........................
    >>> 31st bit indicates 31's primality
 
status[1]'s
    >>> 0'th bit indicates 32's primality
    >>> 1st bit indicates 33's primality 
   ...............
   
status[2]'s
       >>> 0'th bit indicates 64's primality
      >>> 1st bit indicates 33's primality  
Then 1-7 prime generation makes the array look like : 

status[1]= ০০০০…….১০১০১১০০(total 32 bit, right most bit == 0'th bit)

We get 31 number's primality per index! Now the question is how to get which bit in which index
will indicate a numbers primality?For number = i, i/32nd index's i%32 no. bit will indicate the number's 
primality so we have to check it.
if i=১ we check index 0's bit 1, i=33 means index 1's 1st bit etc. (0 based indexing)


We write two functions. First one to check whether i=posth bit in a number is 0 or 1. 
Second one to set i = posth bit in a number as 1.


```C++
bool Check(int N,int pos){
return (bool)(N & (1<<pos));
}
```
How it works ? 

Bit Hack #2. Test if the n-th bit is set.

if (x & (1<<n)) {
  n-th bit is set
}
else {
  n-th bit is not set
}
In the previous bit hack we saw that (x & 1) tests if the first bit is set. 
This bit hack improves this result and tests if n-th bit is set. 
It does it by shifting that first 1-bit n positions to the left and then doing the same AND operation, 
which eliminates all bits but n-th.

Here is what happens if you shift 1 several positions to the left:

1         00000001    (same as 1<<0)
1<<1      00000010
1<<2      00000100
1<<3      00001000
1<<4      00010000
1<<5      00100000
1<<6      01000000
1<<7      10000000

Now if we AND 'x' with 1 shifted n positions to the left we effectively eliminate all the bits but n-th bit in 'x'. 
If the result after AND-ing is 0, then that bit must have been 0, otherwise that bit was set.

Let's look at some examples.

Does 122 have 3rd bit set? The operation we do to find it out is:

122 & (1<<3)
Now, 122 is 01111010 in binary. And (1<<3) is 00001000.

    01111010
&   00001000
    --------
    00001000
We see that the result is not 0, so yes, 122 has the 3rd bit set.

Note: In my article bit numeration starts with 0. So it's 0th bit, 1st bit, ..., 7th bit.

What about -33? Does it have the 5th bit set?

    11011111      (-33 in binary)
&   00100000     (1<<5)
    --------
    00000000
Result is 0, so the 5th bit is not set.

###Second one : Set the nth bit to 1.

```C++
int Set(int N,int pos)
{ return N=N | (1<<pos);}
```

How it works?

it Hack #3. Set the n-th bit.

y = x | (1<<n)
This bit hack combines the same (1<<n) trick of setting n-th bit by shifting with OR operation.
The result of OR-ing a variable with a value that has n-th bit set is turning that n-th bit on. 
It's because OR-ing any value with 0 leaves the value the same; but OR-ing it with 1 changes it to 1 (if it wasn't already). 
Let's see how that works in action:

Suppose we have value 120, and we wish to turn on the 2nd bit.

    01111000    (120 in binary)
|   00000100    (1<<2)
    --------
    01111100
What about -120 and 6th bit?

    10001000   (-120 in binary)
|   01000000   (1<<6)
    --------
    11001000
    
    
###Sieve Function :

```C++
int N =100,prime[100]; 
int status[100/32];
void sieve()
{
     int i, j, sqrtN; 
     sqrtN = int( sqrt( N ) );
     for( i = 3; i <= sqrtN; i += 2 ) 
     {
         if( check(status[i/32],i%32)==0)
         {
              for( j = i*i; j <= N; j += 2*i )
             {
                 status[j/32]=Set(status[j/32],j % 32)   ;
              }
         }
     }
     puts("2");
     for(i=3;i<=N;i+=2)
         if( check(status[i/32],i%32)==0)
          printf("%d\n",i);
         
}
```
It's written as regular Sieve but instead of checking status[i] we check
status[i/32]'s i%32 no. bit's value. We can efficiently generate up to 10^8th primes by bitwise Sieve.


More optimizations : 

we know multiplying a number by two is same as shifting it's binary 1 position left.
we know dividing a number by two is same as shifting it's binary representation 1 position right.
we know performing mod with 32 is same as performing bitwise AND with 31.

In general : 

Divisibility by power of 2
Use of % operation is very slow, also the * and / operations. But in case of the second operand is a power of 2, we can take the advantage of bit-wise operations.
Here are some equivalent operations:

Here, P is in the form 2X and N is any integer (typically unsigned)


N % P = N & (P-1)
N / P = N >> X
N * P = N << X

A lot faster and smarter...
About the % operation : the above is possible only when P is a power of 2

We can write the code as : 
```C++
int status[(mx/32)+2];
void sieve()
{
     int i, j, sqrtN; 
     sqrtN = int( sqrt( N ) );
     for( i = 3; i <= sqrtN; i += 2 ) 
     {
         if( Check(status[i>>5],i&31)==0)
         {
              for( j = i*i; j <= N; j += (i<<1) )
             {
                 status[j>>5]=Set(status[j>>5],j & 31)   ;
              }
         }
     }
    
     puts("2");
     for(i=3;i<=N;i+=2)
         if( Check(status[i>>5],i&31)==0)
          printf("%d\n",i);
}
```


