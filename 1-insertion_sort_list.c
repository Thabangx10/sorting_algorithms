#include "sort.h"

/**
 * Function - sorts by the marker of the array
 * @list: a listint type
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *mark = NULL;

	if ((*list)->next == NULL || list == NULL || (*list) == NULL)
		return;

	temp = *list;

	/* marker point in the array */
	marker = *list;

	while (marker != NULL)
	{
		marker = marker->next;

		while (temp->prev && (temp->n < temp->prev->n))
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->prev->next = temp;
			else
				*list = temp;
			temp->next->prev = temp;
			print_list(*list);
		}
		temp = mark;
	}
}
