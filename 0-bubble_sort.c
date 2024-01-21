#include "sort.h"
#include <stdio.h>
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
 * bubble_sort - Sorts an array of integers using the Bubble Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int swapped;
	if (size == 1)
		return;
	for (j = size - 1; j >= 1; j--)
	{
		swapped = 0;
		for (i = 0; i < j; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
				swapped = 1;
				print_array(array, size);
			}
		}

		if (!swapped)
			break;
	}
}
