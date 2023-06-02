#include <stdio.h>

int pair(int* arr, int size, int key)
{
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(arr[i] + arr[j] == key)
                count++;
        }
    }
    return count;
}

int main()
{
    int test_case;
    scanf("%d", &test_case);
    
    while(test_case--)
    {
        int size, key;
        scanf("%d %d", &size, &key);
        int arr[size];
        
        for(int i = 0; i < size; i++)
            scanf("%d", &arr[i]);
            
        printf("%d\n", pair(arr, size, key));
    }
	return 0;
}
