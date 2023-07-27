#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Double linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	/* Check if the input list is NULL or has only one node (already sorted)*/
	if (list == NULL || (*list)->next == NULL)
		return;

	/* Start sorting from the second node (first node is considered sorted)*/
	node = (*list)->next;
	/* Traverse the list to perform Insertion Sort*/
	while (node)
	{
		/**
		 * Keep moving the current node towards the head of the list
		 * until it reaches its correct position (in ascending order)
		 */
		while ((node->prev) && (node->prev->n > node->n))
		{
			/**
			 * Call the swap_node function to swap the current
			 * node with its previous node
			 */
			node = swap_node(node, list);

			/**
			 * Print the updated list after each swap
			 * (to visualize the sorting process
			 */
			print_list(*list);
		}
		/* Move to the next node in the list */
		node = node->next;
	}
}

/**
 * swap_node - swap a node with its previous one in a doubly linked list
 * @node: The node to be swapped
 * @list: The doubly linked list
 * Return: A pointer to the node which was moved to the new position
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;

	/* Update the pointers of the nodes to perform the swap */
	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;

	/**
	 * Update the head of the list if the current node
	 * was moved to the beginning
	 */
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;

	/* Return the pointer to the node which was moved to the new position */
	return (current);
}
