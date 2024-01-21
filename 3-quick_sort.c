#include "sort.h"

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
/**
 * quick_sort - Sorts an array of integers using the Quick Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	size_t pivot, current, temp;

	if (size <= 1)
		return;

	pivot = size - 1;
	current = 0;
	temp = current - 1;

	while (current <= pivot)
	{
		if (array[current] < array[pivot] || current == pivot)
		{
			temp++;
			swap(&array[current], &array[temp]);
			print_array(array, size);
		}
		current++;
	}
	if (temp > 0)
		quick_sort(array, temp);
	quick_sort(array + temp + 1, size - temp - 1);
}
