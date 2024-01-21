#include "sort.h"
/**
 * swaplist - Swaps two nodes in a doubly linked list.
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 * Return: void
 */
void swaplist(listint_t *a, listint_t *b)
{
	if (a->prev != NULL)
		a->prev->next = b;
	else
		b->prev = NULL;

	if (b->next != NULL)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}
/**
 * insertion_sort_list - Sorts a doubly linked list of integers using the
 *                       Insertion Sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertee;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;

	while (current != NULL)
	{
		insertee = current;
		while (insertee->prev != NULL &&
			   insertee->n < insertee->prev->n)
		{
			swaplist(insertee->prev, insertee);
			if (insertee->prev == NULL)
				*list = insertee;
			print_list(*list);
		}
		current = current->next;
	}
}
