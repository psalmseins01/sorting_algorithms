#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sort a subarray of integers.
 * @subarr: Pointer to subarray of an array of integers to sort.
 * @buff: Pointer to buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t index, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (index = front, j = mid; index < mid && j < back; k++)
		buff[k] = (subarr[index] < subarr[j]) ? subarr[index++] : subarr[j++];
	for (; index < mid; index++)
		buff[k++] = subarr[index];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (index = front, k = 0; index < back; index++)
		subarr[index] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implementing merge sort algorithm through recursion
 * @subarr: Pointer to subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array using the merge sort algorithm
 * @array: Pointer to array of integers
 * @size: Size of the array
 * Description: Implements the top-down merge sort algorithm
 * Return: return void
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}
