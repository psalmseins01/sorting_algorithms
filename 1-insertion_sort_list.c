#include "sort.h"

/**
 * swap_nodes_ints - Swap two nodes in a listint_t doubly-linked list
 * @h: Double pointer to head doubly-linked list
 * @n1: Double pointer to first node to swap
 * @n2: pointer second node to swap.
 */
void swap_nodes_ints(listint_t **h, listint_t **n1, listint_t *n2)
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
	listint_t *i, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = temp)
	{
		temp = i->next;
		insert = i->prev;
		while (insert != NULL && i->n < insert->n)
		{
			swap_nodes_ints(list, &insert, i);
			print_list((const listint_t *)*list);
		}
	}
}
