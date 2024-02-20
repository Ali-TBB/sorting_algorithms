#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm.
 * @list: Dobule linked list to sort.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *prv, *current, *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			current = node;
			prv = node->prev;
			prv->next = current->next;
			if (current->next)
				current->next->prev = prv;
			current->next = prv;
			current->prev = prv->prev;
			prv->prev = current;
			if (current->prev)
				current->prev->next = current;
			else
				*list = current;
			node = current;
			print_list(*list);
		}
		node = node->next;
	}
}
