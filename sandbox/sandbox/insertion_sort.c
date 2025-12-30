#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

unsigned char* get_bytes(const void* ptr, size_t num_bytes) {
    // Allocate memory for the buffer
    unsigned char* buffer = (unsigned char*)malloc(num_bytes);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL; // Return NULL on allocation failure
    }

    // Copy bytes from the pointer to the buffer
    memcpy(buffer, ptr, num_bytes);
    return buffer; // Return the buffer containing the copied bytes
}

void write_bytes(void* dest, const unsigned char* data, size_t num_bytes) {
    // Copy the bytes from data to the destination address
    memcpy(dest, data, num_bytes);
}

void insertion_sort(void *arr, size_t size, size_t member_size, bool (*compare)(const void*, const void*))
{
    int i, j;
    printf("It works\n");
    for (int i = 0; i < (size / member_size) - 1; i++)
    {
        int max_index = i;
        
        for (int j = i + 1; j < size / member_size; j++)
        {
            if ( compare(arr + j * member_size, arr + max_index * member_size) ) max_index = j; 
        }
        // printf("index: %d, max: %d\n", max_index, arr + max_index * member_size);
        unsigned char* bytes = get_bytes(arr + max_index * member_size, member_size);
        
        write_bytes(arr + i * member_size, bytes, member_size);
    }
    printf("\n");

}

bool compare(const void *a, const void *b) {
    return (*(int*)a > *(int*)b); // Change comparison for ascending order
}

int main()
{
    int nums[] = {4, 2 , 1, 10, 9};
    insertion_sort(nums, 20, 4, compare);
    // insertion_sort(nums, sizeof nums, sizeof nums[0], compare);
    int size = sizeof nums / sizeof(int);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}