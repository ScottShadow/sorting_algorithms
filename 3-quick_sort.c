#include "sort.h"
#include <stdlib.h>

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
void print_array_range(int *array, size_t start, size_t print_size)
{
	size_t i;

	for (i = 0; i < print_size; i++)
	{
		printf("%d", array[start + i]);
		if (i < print_size - 1)
			printf(", ");
	}
	printf("\n");
}
/**
 * quick_sort - Sorts an array of integers using the Quick Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	size_t pivot, low, high;
	int top = -1;
	int *stack = malloc(size * sizeof(int));

	if (array == NULL || size <= 1)
	{
		free(stack);
		return;
	}

	stack[++top] = 0;
	stack[++top] = size - 1;

	while (top >= 0)
	{
		high = stack[top--];
		low = stack[top--];
		pivot = partiton(array + low, high - low + 1) + low;

		if (pivot > low)
		{
			stack[++top] = low;
			stack[++top] = pivot - 1;
		}
		if (pivot < high)
		{
			stack[++top] = pivot + 1;
			stack[++top] = high;
		}
	}
	free(stack);
}
/**
 * partiton - Chooses the last element as the pivot and
 *             partitions the array accordingly.
 * @array: Pointer to the array to be partitioned.
 * @size: Size of the array.
 * Return: The index of the pivot after partitioning.
 */
size_t partiton(int *array, size_t size)
{
	size_t pivot, current, temp;

	pivot = size - 1;
	current = 0;
	temp = 0;

	for (current = 0; current < size - 1; current++)
	{
		if (array[current] < array[pivot])
		{
			swap(&array[current], &array[temp]);
			print_array_range(array, 0, size);

			temp++;
		}
	}
	swap(&array[current], &array[temp]);
	print_array_range(array, 0, size);

	return (temp);
}
