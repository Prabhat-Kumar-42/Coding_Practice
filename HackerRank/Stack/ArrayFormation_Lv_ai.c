#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<math.h>
 
int is_prime(int num)
{
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num%i == 0)
        {
            return 0;
        }
    }
    return 1;
}
 
 
void push(int* arr, long long int* size, int num)
{
    arr[*size] = num;
    (*size)++;
}
 
void queue_and_stack (int* A , long long int n)
{
    int* stack = (int*)malloc(sizeof(int)*1000005);
    int* queue = (int*)malloc(sizeof(int)*1000005);
    long long int size1 = 0, size2 = 0;
    
    // for(int i = 0; i < n; i++)
    // {
    //     printf("%d ", A[i]);
    // }
    //printf("\n");
    
    for(long long int i = 0; i < n; i++)
    {
        int z = is_prime(A[i]);
        //printf("A[%d] is %d, z = %d\t", i, A[i], z);
        if(z)
        {
            push(queue, &size2, A[i]);
            //printf("%d pushed to queue , queue_size = %d\n", A[i], size2);
        }
        else
        {
            push(stack, &size1, A[i]);
            //printf("%d pushed to stack , stack_size = %d\n", A[i], size1);
        }
    }
    
    for(long long int i = 0; i < size2; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
    for(long long int i = size1-1; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
}
 
int main() {
    long long int n;
    scanf("%lld", &n);
    int A[1000005];
    for(long long int i = 0; i < n; i++)
    	scanf("%d", &A[i]);
 
    queue_and_stack(A, n);
 
}