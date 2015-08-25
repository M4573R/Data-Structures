##BigMod algorithm explanation

[Modular Exponentiation Algorithm](https://www.youtube.com/watch?v=nO7_qu2kd1Q)

[Time Complexity](https://www.youtube.com/watch?v=VHcZtdp5054)

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

References : 

* https://golammostaeen.wordpress.com/2012/10/20/big-mod-algorithm/
* [Second blog](https://imranshabijabi.wordpress.com/2012/11/24/%E0%A6%AC%E0%A6%BF%E0%A6%97-%E0%A6%AE%E0%A7%8B%E0%A6%A1-%E0%A6%85%E0%A7%8D%E0%A6%AF%E0%A6%BE%E0%A6%B2%E0%A6%97%E0%A7%8B%E0%A6%B0%E0%A6%BF%E0%A6%A6%E0%A6%AEbig-mod-algorithm/)
* 

