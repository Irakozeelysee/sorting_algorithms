#include <stdio.h>
#include "sort.h"

/**
 * sortBackward - Sorts a node going backward of the list
 * @list: Doubly linked list
 * @node: Node to sort
 */
void sortBackward(listint_t **list, listint_t *node)
{
	listint_t *tmp;

	if (node != NULL && node->prev != NULL)
	{
		if (node->n < node->prev->n)
		{
			tmp = node->prev;
			tmp->next = node->next;
			node->prev = tmp->prev;
			node->next = tmp;
			tmp->prev = node;
			if (tmp->next != NULL)
				tmp->next->prev = tmp;
			if (node->prev != NULL)
				node->prev->next = node;
			else
				*list = node;
			print_list(*list);
			sortBackward(list, node);
		}
	}
}
/**
 * insertion_sort_list - Sorts a doubly linked list using
 * Insertion Sort algorithm
 * @list: Doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (current != NULL)
	{
		listint_t *temp = current;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			if (temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;
			print_list(*list);
			sortBackward(list, temp);
		}
		current = current->next;
	}
}
