// My_code_school implementation

#include<algorithm>
#include<iostream>
using namespace std;
// it's supposed to return the index of first occurance of the value x in the given array otherwise returns -1
int binarySearch_first(int a[],int n,int x)
{
    int low = 0;
    int high = n-1;
    int index = -1;
    while(low<=high)
    {
        int mid = (low+high)/2; // low + (high-low)/2 for big numbers
        if(a[mid] == x)
        {
            index = mid;
            high = mid - 1; // if we find the element, we search the left sub-array to see if there are duplicates
        }
        else if(x < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return index;

}

// it's supposed to return the index of last occurance of the value x in the given array otherwise returns -1
int binarySearch_last(int a[],int n,int x)
{
    int low = 0;
    int high = n-1;
    int index = -1;
    while(low<=high)
    {
        int mid = (low+high)/2; // low + (high-low)/2 for big numbers
        if(a[mid]==x)
        {
            index = mid;
            low = mid + 1; // if we find the element, we search the right sub-array to see if there are duplicates
        }
        else if(x < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return index;

}

int main()
{
    int a[12] = {5,2,3,4,5,6,6,3,2,1,3};
    sort(a,a+12);
    int firstIndex = binarySearch_first(a,12,5);
    if(firstIndex==-1)
        cout << "No such element in the array" << endl;
    else
    {int lastIndex = binarySearch_last(a,12,5);
        cout << "Count is " << lastIndex-firstIndex + 1 << endl;
    }
    return 0;
}
