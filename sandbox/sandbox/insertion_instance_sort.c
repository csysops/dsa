
#include <stdio.h>


void swap(int *a, int *b)
{
    int temp = *a;
    
    *a = *b;
    *b = temp;
}

void insertion_sort(int nums[], int size)
{
    int i, j;
    
    for (int i = 0; i < size; i++)
    {
        j = i;
        
        while (j > 0 && nums[j] < nums[j - 1])
        {
            swap(&nums[j], &nums[j - 1]);
            j--;
        }
        print_arr(nums, size);
    }
}

void print_arr(int arr[], int size)
{
    for (int i=0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main()
{
    // int arr[] = {4, 3, 2, 1};
    int arr[] = {4, 2, 3, 1, 9, 8, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, sizeof(arr) / sizeof(arr[0]));
    
    printf("\nover all: ");
    print_arr(arr, size);
}