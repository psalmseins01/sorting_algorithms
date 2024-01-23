#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list
 * @h: Double pointer to head doubly-linked list
 * @n1: Double pointer to first node to swap
 * @n2: pointer second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	listint_t **a;
	listint_t *b;
	a = n1;
	b = n2;

	(*a)->next = b->next;
	if (b->next != NULL)
		b->next->prev = *a;
	b->prev = (*a)->prev;
	b->next = *n1;
	if ((*a)->prev != NULL)
		(*a)->prev->next = b;
	else
		*h = b;
	(*a)->prev = b;
	*a = b->prev;
}

/**
 * insertion_sort_list - Use insertion sort algorithm to sort list
 * @list: Double pointer to the head of a doubly-linked list
 * Description: Prints the list every each swap
 * Return: return void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
