#include <stdio.h>

#include "linear_search.h"

int main() {
	int arr[] = {1,2,3,4,5,6};
	int target = 0;

	int index = linear_search(arr, sizeof(arr)/sizeof(arr[0]), target);

	index >= 0 ? printf("%d at %d\n", target, index) : printf("%d not found\n", target); 

}
