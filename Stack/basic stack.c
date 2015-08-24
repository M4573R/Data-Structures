#include<stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;
void Push(int x)
{
    if(top == MAX_SIZE-1)
    {printf("error\n");
     return;}
    else
        A[++top] = x;
}
void Pop()
{
    if(top == -1)
    {printf("error no element to pop\n");
     return;
    }
    else top--;
}

int Top()
{
    return A[top];
}

void Print(){
int i = 0;
printf("Stack : \n");
for(i=0;i<=top;i++)
{
    printf("%d",A[i]);
}
printf("\n");

}
int main(){
Push(2);
Print();
Push(3);
Push(4);
Push(5);
Pop();
Print();

}
