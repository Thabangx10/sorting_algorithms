#include "sort.h"

/**
 * Function - sorts by the marker of the array
 * @list: a listint type
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if ((*list)->next == NULL || list == NULL || (*list) == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
/**
 * swap_node - swap a node for his previous one
 * @node: node list
 * @list: list containing a node
 *
 * Return - return a pointer to a node which was enter it
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
