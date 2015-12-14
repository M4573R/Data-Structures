1.https://www.youtube.com/watch?v=Jdtq5uKz-w4

Key idea : We keep swapping adjacent elements to get the largest element in the unsorted half to 'bubble' up to the largest index
in the unsorted half. For n elements we need n passes. Each pass ensures the largest element in the unsorted half floats up
to it's correct position.

```C++
#include<iostream>
#include<algorithm>
using namespace std;

void bubble_sort(int a[],int n)
{   // We run n passes through the array for n elements
    for(int i=0;i<n-1;i++)
    {int flag = 0;
      // each pass floats the largest element in the unsorted half to the largest index in the 
      // unsorted part of the array. First pass takes the highest element to the last index
      // each pass after that only runs until n-i-1 to avoid comparisons where no swapping will happen
      // flag checks if swapping happens in the scan or not, if no swapping it means the array is already
      // sorted. 
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j+1],a[j]);
                flag = 1;
            }
        }
        if(flag =0)
            break;
    }
}

int main()
{
    int a[] = {3,4,5,6,7,8,9,2,1,0,-1};
    int n = sizeof(a)/sizeof(a[0]);
    bubble_sort(a,n);
    for(int i=0;i<n;i++)
        cout << a[i] << endl;
}
```
