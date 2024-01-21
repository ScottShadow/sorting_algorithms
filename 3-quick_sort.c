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
	size_t current, temp, smallest;

	if (size <= 0)
		return;
	current = 0;
	while (current < size)
	{
		smallest = current;
		temp = current + 1;
		while (temp < size)
		{
			if (array[smallest] > array[temp])
				smallest = temp;
			temp++;
		}
		if (smallest != current)
		{
			swap(&array[smallest], &array[current]);
			print_array(array, size);
		}
		current++;
	}
}
