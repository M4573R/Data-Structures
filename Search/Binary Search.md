Reference : 1.[Searching](https://www.hackerearth.com/notes/searching-code-monk/)
            2.[Midpoint](http://www.geeksforgeeks.org/problem-binary-search-implementations/)


A. Introduction

Searching is one of the most fundamental problems in Computer Science. It is the process of finding a particular item in a collection of items. Typically, a search answers whether the item is present in the collection or not. For simplification for all our examples, we will be taking an array as the collection.

B. Linear Search (Sequential Search)

Linear Search is the simplest method to solve the searching problem. It finds an item in a collection by looking for it from the beginning and looks for it till the end. Basically, it checks each item in the sequence until the desired element is found before all the elements of the collection are exhausted.

Code for the linear search is:

```C++
bool linearSearch (int A[], int length, int item) {
    for (int i = 0 ; i < length ; ++i)
        if (item == A[i])
            return true;                // Item is found in array A
    return false;                        // Item is not found in array A
}
```

Consider an example. A = {1, 9, 2, 4, 6, 3, 7, 5, 8, 0} and suppose we need to find 3 in the given array. Linear search starts from the beginning and checks if it matches with the item we are searching.


For i = 5, A[i] = 3 and item is equal to A[i]. So the linearSearch() function will return true showing that the item is found.

If the item = 10, linearSearch() function will iterate over all the elements in the array A and return false (showing that the item is not found), because the ‘if’ condition will never be true.

Now, let us consider the modified search where we need to return the position, where the item is found. To solve this modified search problem, we just need to change 2 lines in the linearSearch() function.

```C++
int linearSearch ( int A[ ], int length, int item) {
    for (int i = 0; i < length ; ++i)
        if (item == A[i])
            return i;            //Returning the index of the element found.
    return -1;                    // Item is not found in array A
}
```
In the above codes -1 denotes that the item is not found.

Note: If there are duplicate elements, the above code will return the first occurrence of the item.

Exercise: Modify linearSearch() function such that it will return the last occurrence of the item, if the item is in the array A, otherwise return -1. (Hint: Store the position of the last found occurrence of the item and update it as soon as the item occurs again)

The time complexity of linear search is O(size of the array).

C. Binary Search

Binary Search is a Divide and Conquer algorithm. In Divide and Conquer, we reduce a larger problem into smaller subproblems recursively until the problem is small enough that the solution is trivial.

A condition for Binary Search is that the array should be a sorted array. If the array is sorted in ascending order, Binary Search compares the item with the middle element of the array. If the item matches, then it returns true. Otherwise, if the item is less than the middle element then it will recurse on the sub-array to the left of the middle element or if the item is greater then it will recurse on the sub-array to the right of the middle element. So, at each step the size of array will be reduced to half. After repeating this recursion, it will eventually be left with a single element.

Pseudocode for Binary Search is

```
Algorithm binarySearch(A, left, right, item) {
    if left is less than or equal to right then :
        mid = (left + right) / 2
        if A[mid] is equal to item then return true
        else if item is less than A[mid] then recurse on the left subarray
        else if item is greater than A[mid] recurse on the right subarray
    else
        return false
}
```

Note: Array has to be sorted for Binary Search to work.

Implementation of Binary search is

1. Recursive Binary Search

```C++
bool binarySearchRecur(int A[], int left, int right, int item) 
{
    if (left <= right) 
    {
        int mid = left + (right - left) / 2;            // finding middle index
        if (A[mid] == item)
            return true;                    // item found
        else if (item < A[mid])
        {
            // recurse on the left sub-array
            return binarySearchRecur(A, left, mid-1, item);        
        }
        else
        {
             // recurse on the right sub-array
             return binarySearchRecur(A, mid+1, right, item);     
        }
   }
   else
        return false;                    // item not found
}
```

2. Iterative Binary Search

```C++
bool binarySearchIter(int A[], int length, int item) 
{
    int left = 0, right = length - 1, mid;
    while (left <= right) 
    {
        mid = left + (right - left) / 2;        // finding middle index
        if (A[mid] == item)
            return true;                // item found
        else if (item < A[mid])
            right = mid - 1;            // recurse on left sub-array
        else
            left = mid + 1;             // recurse on right sub-array
    }
    return false;                        // item not found
}
```

Consider an example. Let array A = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} and we need to find 3 in array A. So item = 3 and length = 10. Let us consider the Iterative Binary Search.

Initially,
left = 0
right = length – 1 = 10 – 1 = 9
In 1st iteration,
mid = left + (right – left) / 2 = 0 + (9 – 0) / 2 = 4
A[mid] ( = 4) is greater than item. Since the array A is sorted we can say that the item must be in the left sub-array.

So, 
left = 0
right = mid – 1 = 4 – 1 = 3
In 2nd iteration,
mid = left + (right – left) / 2 = 0 + (3 – 0) / 2 = 1
A[mid] ( = 1) is smaller than item. Since the array A is sorted we can say that the item must be in the right sub-array.

So,
left = mid + 1 = 1 + 1 = 2
right = 3
In 3rd iteration,
mid = left + (right – left) / 2 = 2 + (3 – 2) / 2 = 2
A[mid] ( = 2) is smaller than item. Since the array A is sorted we can say that the item must be in the right sub-array.


So,
left = mid + 1 = 2 + 1 = 3
right = 3
In 4th iteration,
mid = left + (right – left) / 2 = 3 + (3 – 3) / 2 = 3
A[mid] ( = 3) is equal to the item, so the binarySearchIter() function will return true and the item is found.

Time complexity of both binarySearchRecur() and binarySearchIter() is O(logN) where N is the size of the array. This is because after each recursion or each iteration the size of problem is reduced into half.

Some more examples:

Question 1:
Given a sorted array A with possible duplicate elements and you need to find the first occurrence of a given input item (assuming the element is present in the array).

Solution:
If the item is less than or equal to the middle element we will recurse to the left sub-array, otherwise we will recurse to the right sub-array.

```C++
int firstOccurrence(int A[], int left, int right, int item) {
    int mid;
    while (right - left > 1) {
        mid = left + (right - left) / 2;
        if (A[mid] >= item) 
            right = mid;
        else
            left = mid;
    }
    return right;
}
```

Question 2: Given a sorted array A with possible duplicate elements and you need to find the last occurrence of a given input item (assuming the element is present in the array).

Solution: If the item is greater than or equal to the middle element we will recurse to the right sub-array, otherwise we will recurse to the left sub-array.

```C++
int lastOccurrence(int A[], int left, int right, int item) {
    int mid;
    while (right - left > 1) {
        mid = left + (right - left) / 2;
        if (A[mid] <= item)
            left = mid;
        else
            right = mid;
    }
    return left;
}
```

Question 3: Given a sorted array A with possible duplicate elements and you need to find the number of occurrences of a given input item (assuming the element is present in the array).

Solution: If we can find the first and last occurrence of the item in the array A then number of occurrences of the item will be number of elements from first occurrence to the last occurrence.

```C++
int numberOfOccurrences(int A[], int size, int item) {
    // Note the boundary parameters
    int left = firstOccurrence(A, -1, size - 1, item);
    int right = lastOccurrence(A, 0, size, item);
    if (A[left] == item && A[right] == item)            // If the item is in the array A
        return (right - left + 1);
    else                                                            // If the item is not in the array A
        return 0;
}
```

Binary Search is a simple and a powerful tool for you to keep in your toolbox. But, a problem as easy as searching for a particular element, will rarely be faced by you in your programming career - not directly, at least. So, the task is to identify and reduce a given problem into a problem which can thus be solved by using binary search. This can be done if we reduce the original problem into a Yes/No Problem.

Let me try to clear the grounds by giving an example. Suppose there is a problem in which we have a monotonically increasing function f (i.e. f(i) < f(j) if i < j). We need to find a smallest x such that f(x) > 0.

Can we apply binary search in this problem? Yes, we can. But firstly, we need to reduce the problem into a simpler one. Instead of “finding smallest x such that f(x) > 0”, we will find the answer of “Is there any x such that f(x) > 0 ?”. If we can somehow find the smallest x for which answer to the second question is Yes then that x will be the answer of our original problem. Now, we can apply binary search to find the smallest x such that f(x) > 0.

Initially, we have a range [low, high]. We will check the middle element of this range i.e mid = (low + high) / 2. If f(mid) <= 0 then recurse on the range [mid+1, high] i.e on the right side of the mid element, otherwise recurse on the range [low, mid] i.e on the left side of the mid element. Repeat this algorithm and you will end up with a single value and that will be the answer.

For advanced users who are comfortable with STL: There are a couple of C++ STL functions which are associated closely with Binary Search, and can be used, to ease out a lot of things:

binary_search(): Return true if the item in equal to any element in the range passed as parameter.
lower_bound(): Returns an iterator to the first element which is greater than or equal to the item.
upper_bound(): Returns an iterator to the first element which is greater than the item.
equal_range(): Returns a pair of iterators whose first element is equal to the lower_bound() and second element is equal to the upper_bound().
All these four STL functions are a part of the header in C++.

Example:

```C++
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main() {
    int A[] = {5, 2, 6, 2, 2, 1, 1, 6, 3, 2};        
    vector <int> v(A, A + 10);            // v =  5, 2, 6, 2, 2, 1, 1, 6, 3, 2
    sort (v.begin(), v.end());                // v =  1, 1, 2, 2, 2, 2, 3, 5, 6, 6    
    vector <int>::iterator it;
    if(binary_search(v.begin(), v.end(), 2))
        cout << "2 is in the array" << endl;
    else
        cout << "2 is not in the array" << endl;
    it = lower_bound(v.begin(), v.end(), 2);
    cout << "lower_bound: " << (it - v.begin()) << endl;
    it = upper_bound(v.begin(), v.end(), 2);
    cout << "upper_bound: " << (it - v.begin()) << endl;
    pair < vector <int>::iterator, vector <int>::iterator > p;
    p = equal_range(v.begin(), v.end(), 2);
    cout << "equal_range First: " << (p.first - v.begin()) << endl;
    cout << "equal_range Second: " <<  (p.second - v.begin()) << endl;
    return 0;
}
```

Output:
2 is in the array
lower_bound: 2
upper_bound: 6
equal_range First: 2
equal_range Second: 6

Practice Problems:

https://www.hackerearth.com/problem/algorithm/sherlock-and-numbers/
https://www.hackerearth.com/problem/algorithm/xsquare-and-number-list/


### Part 2 : Midpoints 

A Problem in Many Binary Search Implementations:
Consider the following C implementation of Binary Search function, is there anything wrong in this?

// A iterative binary search function. It returns location of x in
// given array arr[l..r] if present, otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        // find index of middle element
        int m = (l+r)/2;
 
        // Check if x is present at mid
        if (arr[m] == x) return m;
 
        // If x greater, ignore left half
        if (arr[m] < x) l = m + 1;
 
        // If x is smaller, ignore right half
        else r = m - 1;
    }
 
    // if we reach here, then element was not present
    return -1;
}

The above looks fine except one subtle thing, the expression “m = (l+r)/2″. It fails for large values of l and r. Specifically, it fails if the sum of low and high is greater than the maximum positive int value (231 – 1). The sum overflows to a negative value, and the value stays negative when divided by two. In C this causes an array index out of bounds with unpredictable results.

What is the way to resolve this problem?
Following is one way:

        int mid = low + ((high - low) / 2); 
        
        
Probably faster, and arguably as clear is (works only in Java, refer this):

        int mid = (low + high) >>> 1; 
In C and C++ (where you don’t have the >>> operator), you can do this:

        mid = ((unsigned int)low + (unsigned int)high)) >> 1 
The similar problem appears in Merge Sort as well.

The above content is taken from google reasearch blog.

Please refer this as well, it points out that the above solutions may not always work.

The above problem occurs when array length is 230 or greater and the search repeatedly moves to second half of the array. This much size of array is not likely to appear most of the time. For example, when we try the below program with 32 bit Code Blocks compiler, we get compiler error.

```C++
int main()
{
    int arr[1<<30];
    return 0;
}
```
Output:

error: size of array 'arr' is too large
Even when we try boolean array, the program compiles fine, but crashes when run in Windows 7.0 and Code Blocks 32 bit compiler

```C++
#include <stdbool.h>
int main()
{
    bool arr[1<<30];
    return 0;
}
```
Output: No compiler error, but crashes at run time.

Sources:
http://googleresearch.blogspot.in/2006/06/extra-extra-read-all-about-it-nearly.html
http://locklessinc.com/articles/binary_search/

This article is contributed by Abhay Rathi. 
