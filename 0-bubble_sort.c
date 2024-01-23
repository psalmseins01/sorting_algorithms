#include "sort.h"

/**
 * swap_int_elems - Swap two integers in an array.
 * @a: pointer to argument a to swap
 * @b: pointer to argument b to swap
 */
void swap_int_elems(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: Pointer to an array of int to sort
 * @size: Pointer to size of the array
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n = size;
	bool bub = false;

	if (array == NULL || size < 2)
		return;

	while (bub == false)
	{
		bub = true;
		for (i = 0; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_int_elems(array + i, array + i + 1);
				print_array(array, size);
				bub = false;
			}
		}
		n--;
	}
}
