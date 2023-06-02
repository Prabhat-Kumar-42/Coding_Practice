#include <stdio.h>

void merge(int* arr, int left, int mid, int right)
{
    int size1 = mid - left + 1, size2 = right - mid;
    int temp1[size1], temp2[size2];
    
    int i = 0, j = 0, k = left;
    
    for( i = 0; i < size1; i++)
    {
        temp1[i] = arr[left + i];
    }
    
    for( j = 0; j < size2; j++)
    {
        temp2[j] = arr[mid + j + 1];
    }
    
    i = j = 0;
    while(i < size1 && j < size2)
    {
        if(temp1[i] <= temp2[j])
        {
            arr[k++] = temp1[i++];
        }
        else
        {
            arr[k++] = temp2[j++];
        }
    }
    
    while(i < size1)
    {
        arr[k++] = temp1[i++];
    }
    
    while(j < size2)
    {
        arr[k++] = temp2[j++];
    }
}

void merge_sort(int* arr, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right-left)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int test_case;
    scanf("%d", &test_case);
    
    while(test_case--)
    {
        int size;
        scanf("%d", &size);
        
        int arr[size];
        for(int i = 0; i < size; i++)
        {
            scanf("%d", &arr[i]);
        }
        
        merge_sort(arr, 0, size-1);
        
        int rep = 9999, missing, flag = 0, flag_missing = 1;
        
        for(int i = 0; i < size; i++)
        {
            if(arr[i] == arr[i+1] && flag == 0)
            {
                flag = 1;
                rep = arr[i];
            }
            if(arr[i + 1] - arr[i] == 2 && flag_missing)
            {
                flag_missing = 0;
                missing = arr[i] + 1;
            }
        }
        
        if(flag_missing == 1 && flag == 1)
        {
            missing = rep + 1;
            flag_missing = 0;
        }
        
        if(flag && (!flag_missing))
        {
            printf("%d %d\n", rep, missing);
            flag = 0;
        }
    }
	//code
	return 0;
}
