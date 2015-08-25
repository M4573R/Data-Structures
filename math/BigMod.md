##BigMod algorithm explanation

https://www.youtube.com/watch?v=nO7_qu2kd1Q

https://www.youtube.com/watch?v=VHcZtdp5054

According to modular arithmatic, we can write (x^n)%m as 

(x^n)%m = ((x^n/2)%m * (x^n/2)%m )%m when n is even and 


(x^n)%m = ((x%m) * (x^n-1)%m)%m when n is odd.

This property helps us to create a recursive function for arbitrarily big integers of the form (x^n).

###Example :
 
3^5%5 = (3%5 * 3^4%5)%5
      = (3%5 * ((3^2%5)*(3^2%5))%5)%5
      = (3%5 *  (((3%5)*(3%5)%5)*((3%5)*(3%5)%5))%5)%5
      
![Image](https://golammostaeen.files.wordpress.com/2012/10/bigmod1.png)

### Recursive function : 

```C++
int BigMod(int x,int n,int m){
if(n==0)
    return 1%m;
else if(n%2==0)
{
    return (BigMod(x,n/2,m)*BigMod(x,n/2,m))%m;
}

else

{
    return (BigMod(x,n-1,m)*(x%m))%m;
}
}
```

Solved problem : [UVA BigMod(374)](https://github.com/M4573R/Data-Structures/blob/master/math/BigMod.cpp)

