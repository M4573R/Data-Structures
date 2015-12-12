With set trick : Set only stores unique element, so if the number of set element is lesser than the actual number of digits
it has duplicate digits.

```C++
bool check (int a){
    set<int> s;
    int digit_count = 0;
    while(a>0)
    {
        s.insert(a%10);
        a = a/10;
        digit_count++;
    }
    if(s.size()<digit_count)
        return true;
    else
        return false;

}
```

Classical : Count how many times each digit appears and if any of them appears more than once it's not unique.

```C++
bool check(long x)
{
 for (int i=0;i<10;i++)
 ar[i]=0; // create a unique digit array, initialize to 0
 for (int i=1;i<=4;i++)
 {
     ar[x%10]++;x/=10; // there's only 4 digits. count how many times each digit apprears.
 }
 for (int i=0;i<10;i++)
 if (ar[i]>1)return true; // if any of the digit comes up more than once, return true as it's not unique.
 return false;
}
```
