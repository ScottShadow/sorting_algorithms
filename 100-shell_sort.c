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
 * shell_sort - Sorts an array of integers using the Shell Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, gap, temp;

	for (gap = 1; gap < size / 3; gap = 3 * gap + 1)
		;
	while (gap > 0)
	{
		/* printf("\ngap: %ld\n", gap); */
		for (i = gap; i < size; i++)
		{
			temp = i;
			/* printf("\n temp: %ld\n", temp); */

			while (temp >= gap && array[temp] < array[temp - gap])
			{
				/* printf("\n----------comparing %d and %d--------\n", */
				/* array[temp], array[temp - gap]); */
				swap(&array[temp], &array[temp - gap]);

				temp -= gap;
				/* printf("\n-----temp: %ld\n", temp); */
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}
