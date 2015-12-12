the maximum subarray problem is the task of finding the contiguous subarray within a one-dimensional 
array of numbers  which has the largest sum. For example, 
for the sequence of values −2, 1, −3, 4, −1, 2, 1, −5, 4; the contiguous subarray with the largest sum 
is 4, −1, 2, 1, with sum 6.

Here's the explanation : 

1.http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
2.https://en.wikipedia.org/wiki/Maximum_subarray_problem
3.https://www.youtube.com/watch?v=ohHWQf1HDfU

Inefficient method 1 : Calculate sum of all possible subarrays, return the maximum.

```C++
#include<climits>
int Maximum_Sum_Subarray(int a[],int n)
{int ans = INT_MIN;
 for(int sub_array_size = 1; sub_array_size <=n;sub_array_size++)
 { for(int start_index = 0; start_index < n; start_index++)
      { if(start_index + sub_array_size > n)
              break;
        int sum = 0;
        for(int i= start_index; i<(start_index + sub_array_size); i++)
            sum = sum + a[i];
        ans = max(ans,sum);
     }
 }
 return ans;
}
```

Complexity : O(n^3)

Inefficient method 2 : For each start index, we are calculating the subarray sum from the beginning for each subarray size.
To make it faster, instead of starting from the subarray size, we can start from start index and we also should notice that
for each subarray, the sum is the sum of the previous subarray starting from the same start index + new element. So we change the order of things this way.

```C++
#include<cmath>
#include<iostream>
#include<climits>
using namespace std;

int Maximum_Sum_Subarray(int arr[],int n)	//Overall Time Complexity O(n^2)
{
	int ans = INT_MIN;
	for(int start_index = 0;start_index < n; ++start_index)					//O(n)		
	{
		int sum = 0;
		for(int sub_array_size = 1;sub_array_size <= n; ++sub_array_size)	//O(n)	
		{
			if(start_index+sub_array_size > n)	//Subarray exceeds array bounds
				break;
			sum+= arr[start_index + sub_array_size - 1];	//Last element of the new Subarray
			ans = max(ans,sum);
		}
	}
	return ans;
}

int main()
{
	int a[] = {3,-2,5,-1};
	cout<<Maximum_Sum_Subarray(a,4)<<"\n";
	return 0;
}
```
Complexity : O(n^2)

Kadane's Algorithm : 

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
