the maximum subarray problem is the task of finding the contiguous subarray within a one-dimensional 
array of numbers (containing at least one positive number) which has the largest sum. For example, 
for the sequence of values −2, 1, −3, 4, −1, 2, 1, −5, 4; the contiguous subarray with the largest sum 
is 4, −1, 2, 1, with sum 6.

Here's the explanation : 

1.http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
2.https://en.wikipedia.org/wiki/Maximum_subarray_problem





```C++
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

//This version returns maximum sum of subarrays, but it can't handle all negative elements.
int kadane_algorithm(int a[],int n)
{
 int max_ending_here = 0;
 int max_so_far = 0;
 for(int i=0;i<n;i++)
 {
     max_ending_here = max(0,max_ending_here+a[i]);
     max_so_far = max(max_ending_here, max_so_far);
 }
 return max_so_far;
}

// This version can handle all negative elements and returns maximum sum of subarray
int kadane_algorithm_negative(int a[],int n)
{
 int max_ending_here = a[0];
 int max_so_far = a[0];
 for(int i=1;i<n;i++)
 {
     max_ending_here = max(a[i],max_ending_here+a[i]);
     max_so_far = max(max_ending_here, max_so_far);
 }
 return max_so_far;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int b[] = {-2,-3,-4,-5,-1,-6,-8,-9};
    int n = sizeof(a)/sizeof(a[0]);
    cout << kadane_algorithm(a,n) << endl;
    cout << kadane_algorithm_negative(b,sizeof(b)/sizeof(b[0])) << endl;

}
```
