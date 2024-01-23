#include "sort.h"

/**
 * swap_ints - Swaps two integers in a given array
 * @a: Pointer to argument a
 * @b: Pointer to argument b
 * Return: return void
 */
void swap_int_elems(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: Pointer to array of elements
 * @size: The size of the array
 * Description: Prints the array after each swap
 * Return: return void
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_int_elems(array + i, min);
			print_array(array, size);
		}
	}
}
