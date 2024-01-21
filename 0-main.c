#include "sort.h"
#include <stddef.h>
#include <stdio.h>

void print_test_case(int *array, size_t size, const char *message)
{
	printf("%s\n", message);
	print_array(array, size);
	bubble_sort(array, size);
	printf("Sorted array:\n");
	print_array(array, size);
	printf("\n");
}

int main(void)
{
	int array2[] = {};
	size_t size2 = sizeof(array2) / sizeof(array2[0]);
	print_test_case(array2, size2, "Test Case 2:");

	return (0);
}