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
void shell_sort(int *array, size_t size)
{
	size_t i, gap, temp;

	for (gap = size / 2; gap > 0; gap /= 2)
	{
		for (i = gap + 1; i < size; i++)
		{
			temp = i;
			while (temp + gap < size && array[temp] > array[temp + gap])
			{
				swap(&array[temp], &array[temp + gap]);
				print_array(array, size);
				temp += gap;
			}
			while (temp >= gap && array[temp] < array[temp - gap])
			{
				swap(&array[temp], &array[temp - gap]);
				print_array(array, size);
				temp -= gap;
			}
		}
	}
}
