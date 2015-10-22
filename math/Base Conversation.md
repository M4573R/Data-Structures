Idea : Divide the number by the base and take the remainder to get the digits. Repetedly divide the quotient and keep taking the
remiander until the quotient becomes zero.

http://www.cs.utsa.edu/~wagner/CS3343/recursion/bases.html


Number Base Conversion: The example below converts a given base 10 number to base 8. (The same technique will work for conversions to any desired base.)
n = 93.  Repeatedly divide by 8 and take the remainder.
         Then repeat with the quotient by 8. Stop at 0 quotient.

93%8 == 5 (remainder) and 93/8 == 11 (quotient)
11%8 == 3 (remainder) and 11/8 ==  1 (quotient)
 1%8 == 1 (remainder) and  1/8 ==  0 (quotient)
The numbers  (the remainders) are the base 8 digits of 93,
generated backwards (least significant digit first). We want to write them forwards, 
to get 135 (base 8), and for this purpose, we can push them on a stack, and pop them off, as in the following code:


With stack :
 
 
```C++
#include<iostream>
#include<stack>
using namespace std;
void writebase(int n,int base) {
  stack<int> s;
   while (n > 0) {
      s.push(n%base);
      n = n/base;
   }
   while (!empty())
      printf("%i", s.pop());
}
int main() {
   int n = 93;
   int base = 8;
    
   writebase(n,base);
}
```

Recursive conversation : 

```C++
#include <stdio.h>

void writebase(int n,int base) {
   if (n != 0) {
      writebase(n/base);
      printf("%d", n%base);
   }
}

int main() {
   int n = 93;
   int base = 8;
    
   writebase(n,base);
   printf(" = %d (base %d)\n", n,base); 
}
```
