Key idea: 

Given an array of size n, generate and print all possible combinations of r elements in array. 
For example, if input array is {1, 2, 3, 4} and r is 2, then output should be {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4} and {3, 4}.
It's also similar to generating subsets.

We can represent the elements in an array by binary strings and print the elements if the corresponding bit is 1. For example, 1100
binary string can represent the array element 12 if the array is 1234, we keep 1 and 2 because corresponding elements in 1100 are 1
and exclude 3 and 4 for the later one's are zero.

Here in the recursive solution, we start by considering for each element i we can either keep them(1) or exclude them(0).If we exclude
them, we call the first recursive function with the to consider the subarray from i+1 to N, if we include them i.e a[k] = 1,
we call the second recursive function where we consider the subarray from i+1 to N again, only this time we know that we are keeping
the first element.

From https://www.youtube.com/watch?v=p8SDPaX1wgw 

```C++
#include <stdio.h>

int A[5]= {0};
char B[5]={'V','A','B','C','D'};

void print2(int A[], int N){

    for (int i =1; i <=N; i++){
        if(A[i] ==1){
            printf("%c ",B[i]);
        }
    }
        printf("\n");     
}


void print(int A[], int N){

    for (int i =1; i <=N; i++){
            printf("%d ",A[i]);
    }
        printf("\n");     
}



void combination(int A[], int k, int N) {
    //printf("k=%d\n",k);
    if (k==N) {
        A[k]=0;
        print(A,N);
        A[k]=1;
        print(A,N); 
        return;         
              
    }
    
    
        A[k]=0;
        combination(A,k+1,N);
        A[k]=1;
        combination(A,k+1,N);
         
     
     
}

int main(){
 combination(A,1,4);   
 return 0;
}
```
