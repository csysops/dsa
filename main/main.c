#include <stdio.h>

#include "../src/algo/linear_search/linear_search.h"

int main() {
	int arr[] = {1,2,3,4,5,6};
	int target = 12;

	int index = linear_search(arr, 6, target);

	index >= 0 ? printf("%d at %d\n", target, index) : printf("%d not found\n", target); 

}
