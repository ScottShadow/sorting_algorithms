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
    size_t current, temp, end = 0, i;
    int temp_set = 0;

    current = 1;
    temp = 0;
    for (; current < size; current++)
    {
        while (temp <= current)
        {
            /* printf("\n------------\n ---->"); */
            /* print_array(array, size); */
            /* printf("------------\n"); */
            /* printf("\n----comparing %d and %d------\n", array[current], array[temp]); */

            if (array[current] < array[temp])
            {

                if (end == 0)
                {

                    /* printf("\n----swapping %d and %d------\n", */
                    /*    array[current], array[temp]); */

                    swap(&array[current], &array[temp]);
                    temp = 0;
                    temp_set = 1;
                    print_array(array, size);
                    end++;
                    break;
                }
                else if (end != 0)
                {

                    /* printf("\n----swapping %d and %d with shift------\n", */
                    /*  array[current], array[temp]); */

                    for (i = current; i > temp; i--)
                        swap(&array[i], &array[i - 1]);
                    temp = 0;
                    temp_set = 1;
                    print_array(array, size);
                    end++;
                    break;
                }
            }

            if (temp == current)
            {
                /* printf("\n----end set to %d", array[temp]); */
                end = temp;
                if (end == size - 1)
                    break;
                temp = 0;
                temp_set = 1;
                current++;
            }
            if (temp_set == 0)
                temp++;
            temp_set = 0;
        }
    }
}
