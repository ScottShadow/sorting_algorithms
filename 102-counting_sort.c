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
	int *count = NULL, *output = NULL;
	int i;
	size_t j;

	if (array == NULL || size == 0)
		return;
	max = findmax(array, size);
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;
	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}
	for (i = 0; i < max + 1; i++)
		count[i] = 0;

	for (j = 0; j < size; j++)
		count[array[j]]++;
	for (i = 1; i <= max; i++)
		count[i] = count[i - 1] + count[i];

	print_array(count, max + 1);

	for (j = size - 1; j != SIZE_MAX; j--)
	{
		output[count[array[j]] - 1] = array[j];
		count[array[j]]--;
	}

	for (j = 0; j < size; j++)
	{
		array[j] = output[j];
	}
	free(count);
	free(output);
}
