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
 * cocktail_sort_list - Sorts nodes in a doubly linked list.
 * @list: Pointer to the first node.
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *nextp, *temp;
	int direction = 2;

	if (*list == NULL || (*list)->next == NULL)
		return;
	temp = *list;
	for (; temp->next != NULL; temp = temp->next)
	{
		current = temp;
		while ((current->next != NULL && direction % 2 == 0) ||
			   (current != NULL && direction % 2 == 1))
		{
			nextp = current->next;
			if (current->n > nextp->n)
			{
				swaplist(current, nextp);
				if (current->prev == NULL)
					*list = current;
				else if (nextp->prev == NULL)
					*list = nextp;
				print_list(*list);
				if (current->next == NULL)
					direction++;
				if (current->prev == NULL)
					*list = current;
				if (current->prev)
					current = current->prev;
			}

			if (direction % 2 == 0)
				current = current->next;
			else if (direction % 2 == 1)
			{
				if (current->prev)
					current = current->prev;
				else
					break;
			}
		}
	}
}
