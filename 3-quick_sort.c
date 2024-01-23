#include "sort.h"

void swap_int_elems(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_int_elems - Swap two integers in an array.
 * @a: Pointer to argument a
 * @b: Pointer to argument b
 */
void swap_int_elems(int *a, int *b)
{
	int *x;
	int *y;

	x = a;
	y = b;

	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot)
 * @array: Array of integers
 * @size: Size of the array
 * @left: Starting index of the subset to order
 * @right: Ending index of the subset to order
 * Return: return final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_int_elems(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_int_elems(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Quicksort algorithm using recursion
 * @array: Array of integers to sort
 * @size: Size of array
 * @left: Starting index of the array partition to order
 * @right: last index of the array partition to order
 *
 * Description: Uses the Lomuto partition scheme
 * Return: return void
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
