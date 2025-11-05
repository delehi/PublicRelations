#include "libft.h"

/*
** ft_lstsize: Counting the Nodes
**
** PURPOSE:
** To count the number of nodes in a linked list.
**
** THE ALGORITHM: TRAVERSAL
** "Traversal" is the official term for walking through a data structure.
** For a linked list, it means starting at the head and following the `next`
** pointers from node to node until you reach the end (NULL).
*/

int	ft_lstsize(t_list *lst)
{
	size_t	count; // Use `size_t` for counts and sizes, it's the correct type.

	count = 0;

	// --- THE TRAVERSAL LOOP ---
	// The loop condition `while (lst)` is shorthand for `while (lst != NULL)`.
	// It continues as long as our current `lst` pointer is not pointing to NULL,
	// which signifies the end of the list.
	while (lst)
	{
		// If we are on a valid node, increment our counter.
		count++;

		// --- THE "WALK" ---
		// This is the most important step in any list traversal.
		// We update our `lst` pointer to now point to the *next* node in the chain.
		// In the next iteration of the loop, we will be examining the next node.
		lst = lst->next;
	}

	// Once the loop finishes (because `lst` has become NULL), we have visited
	// every node, and `count` holds the total number of nodes.
	return (count);
}