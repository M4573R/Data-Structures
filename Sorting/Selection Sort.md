This algorithm is based on the idea of finding the minimum or maximum element in the unsorted array and then putting it in its correct position for a sorted array.

We have an array A [ ] = {7, 5, 4, 2} and we need to sort it in ascending order.

Let’s find the minimum element in the array i.e., 2 and then replace it with the first position's element, i.e., 7. 
Now we find the second largest element in the remaining unsorted array and put it at the second position and so on.

```C++
#include<iostream>
#include<algorithm>
using namespace std;

void selection_sort(int a[],int n)
{   // We run n passes through the array for n elements
    int minimum;
    for(int i=0;i<n-1;i++)
    {minimum = i; // This stores the index of the minimum value/ith value is considered the current minimum. We
    // assume the first element as the current minimum of the unsorted array.

        for(int j=i+1;j<n;j++)
        // In each pass we check if there's another value less than our current minimum.
        // If there's a minimum we store the index of that value in minimum

        {
            if(a[j]<a[minimum])
            {
                minimum = j;
            }
        }
        // we swap the found minimum with the current minimum. This splits the array into the sorted
        // half in the beginning and the unsorted half at the end.
        swap(a[i],a[minimum]);
    }
}

int main()
{
    int a[] = {3,4,5,6,7,8,9,2,1,0,-1};
    int n = sizeof(a)/sizeof(a[0]);
    selection_sort(a,n);
    for(int i=0;i<n;i++)
        cout << a[i] << endl;
}
```

Monk implementation : 

```C++
void selection_sort (int A[ ], int n) {
        // temporary variable to store the position of minimum element

        int minimum;        
        // reduces the effective size of the array by one in  each iteration.

        for(int i = 0; i < n-1 ; i++)  {

           // assuming first element to be minimum of the  unsorted array .
             minimum = i ;

          // gives the effective size of unsorted  array .

            for(int j = i+1; j < n ; j++ ) {
                if(A[ j ] < A[ minimum ])  {                //finds the minimum element
                minimum = j ;
                }
             }
          // putting minimum element on its proper position.
          swap ( A[ minimum ], A[ i ]) ; 
        }
   }
   ```
