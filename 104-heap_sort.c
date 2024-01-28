#include "sort.h"

void swap_int_elems(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_int_elems - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_int_elems(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: Pointer to array of integers representing a binary tree
 * @size: The size of the array/tree
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_int_elems(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array using the heap sort algorithm
 * @array: Pointer to an array of integers
 * @size: Size of the array
 * Description: Implements the sift-down heap sort algorithm
 * Return: return void
 */
void heap_sort(int *array, size_t size)
{
	int index;

	if (array == NULL || size < 2)
		return;

	for (index = (size / 2) - 1; index >= 0; index--)
		max_heapify(array, size, size, index);

	for (index = size - 1; index > 0; index--)
	{
		swap_int_elems(array, array + index);
		print_array(array, size);
		max_heapify(array, size, index, 0);
	}
}
