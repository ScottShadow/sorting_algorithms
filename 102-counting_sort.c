#include "sort.h"
#include <stdint.h>
/**
 * findmax - Finds the maximum value in an array of integers.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * Return: The maximum value.
 */

int findmax(int *array, size_t size)

{
	int max;
	size_t i;

	if (array == NULL || size == 0)
		return (0);

	max = array[0];
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}
/**
 * counting_sort - Sorts an array of integers using the
 *  Counting Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int max = 0;
	int *count_arr = NULL, *rez_arr = NULL;
	int i;
	size_t j;

	if (array == NULL || size == 0)
		return;
	max = findmax(array, size);
	count_arr = malloc((max + 1) * sizeof(int));
	if (count_arr == NULL)
		return;
	rez_arr = malloc(size * sizeof(int));
	if (rez_arr == NULL)
	{
		free(count_arr);
		return;
	}
	for (i = 0; i < max + 1; i++)
		count_arr[i] = 0;

	for (j = 0; j < size; j++)
		count_arr[array[j]]++;
	for (i = 1; i <= max; i++)
		count_arr[i] = count_arr[i - 1] + count_arr[i];

	print_array(count_arr, max + 1);

	for (j = size - 1; j != SIZE_MAX; j--)
	{
		rez_arr[count_arr[array[j]] - 1] = array[j];
		count_arr[array[j]]--;
	}

	for (j = 0; j < size; j++)
	{
		array[j] = rez_arr[j];
	}
	free(count_arr);
	free(rez_arr);
}
