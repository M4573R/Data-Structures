This one is from UVA prime factor. Before Sieving, we observe that we only need to generate primes upto the 
sqrt(upper limit = 2^31), so the marks array is around that limit.

```C++
#include <stdio.h>
#include <math.h>
#include <string.h>
int primes[7000];
bool marks[60000];


int sieve(int n)
{

    int i, j, k;

    memset(marks,true,n);

    marks[0] = marks[1] = false;

    for (i=4 ; i<n ; i+=2) // cross all the even numbers from 4.
        marks[i]=false;

    for (i=3 ; i*i<n ; i+=2) // take all the odd primes upto sqrt(n)
    {
        if (marks[i]==true) // if it's a prime
        {
            for (j=i*i ; j<n ; j+=(2*i)) // cross all the multiples marks[j] starting from j = i*i(because all the smaller one's
                                        // will be crossed already and consider all the odd multiples only by adding j+=2*i per
                                        //iteration
                marks[j]=false;
        }

    }

    for (i=2, j=0 ; i<=n ; i++)
    {
        if (marks[i]==true)
        {
            primes[j++]=i;
        }
    }

    return j-1; //number of primes

}

int main() {

    int i, j, q;
    int mark=sieve(60000);


    while (scanf("%d",&q) && q)
    {

        printf("%d =",q);

        if (q<0)
        {
          printf(" -1 x");
          q=-q;
        }

        if (q==1)
        {
            printf(" 1\n");
            continue;
        }

        for (j=0 ; primes[j]<q && j<mark ; j++)
        {
            while (q%primes[j]==0) // if primes[j] is a divisor
            {
                q/=primes[j]; //remove all the occurances of primes[j] by repeated division
                if (q>1)printf(" %d x",primes[j]);
                else printf(" %d",primes[j]);

            }
        }

        if (q>1)
            printf(" %d",q);

        printf("\n");
    }



    return 0;

}
```
