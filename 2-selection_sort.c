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
 * selection_sort - Sorts an array of integers
 * using the Selection Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t current, temp, to_switch;

	if (size <= 1)
		return;
	for (current = 0; current < size - 1; current++)
	{
		/*
		 * printf("-------------\n--->");
		 *print_array(array, size);
		 *printf("---------------\n");
		 */
		to_switch = current;
		for (temp = current + 1; temp < size; temp++)
		{
			/**
			 *printf("---------comparing %d and %d--------\n",
			 *	   array[to_switch], array[temp]);
			 */
			if (array[to_switch] > array[temp])
			{
				/**
				 * printf("---------new small %d --------\n",
				 *	   array[temp]);
				 */
				to_switch = temp;
			}
		}
		swap(&array[current], &array[to_switch]);
		if (to_switch != current)
			print_array(array, size);
	}
}
