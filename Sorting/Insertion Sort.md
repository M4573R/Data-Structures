Main idea : We pick each element from the array from the beginning. This creates a split of unsorted and sorted in the array.
In each iteration we pick up one element from the unsorted part and insert it into a correct position in the sorted part.
We ensure it's inserted into the correct position by shifting all elements greater than it to the right/forward by one element
and insert it into the position it belongs per iteration.

We maintain the value of the current element at ith position in temp and the index at j for each iteration of i.
Then we find the correct position of temp by shifting all values that lies in the left of it and are greater than temp to
one step forward. We keep taking the index j to left as required. J stores the correct position of temp in the end and
that's where we insert the element.

https://www.youtube.com/watch?v=i-SKeOcBwko

```C++
#include<iostream>
#include<algorithm>
using namespace std;

void insertion_sort(int a[],int n)
{
    int temp,j;

    // in n-1 passes we take each element from the unsorted half and insert it to the correct position in the sorted half.
    for(int i=0;i<n;i++)
    {
        temp = a[i]; // temp stores the value of the current element
        j = i; // j stores the index of the current element

        // find the correct position of the current element and move all elements greater than the
        // current element one step forward.
        while(j>0 && a[j-1]>temp)
        {
            a[j] = a[j-1]; // shift the element which is greater than the current one step forward/right
            j-- ; // shift the index one element left or back.
        }

        //insert the current element in the correct position
        a[j] = temp;
    }

}

int main()
{
    int a[] = {3,4,5,6,7,8,9,2,1,0,-1};
    int n = sizeof(a)/sizeof(a[0]);
    insertion_sort(a,n);
    for(int i=0;i<n;i++)
        cout << a[i] << endl;
}
```

Complexity : O(n^2)
