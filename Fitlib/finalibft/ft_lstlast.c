#include "libft.h"

/*
** ft_lstlast: Finding the End of the Line
**
** PURPOSE:
** To find and return a pointer to the very last node in a linked list.
**
** THE ALGORITHM: TRAVERSAL UNTIL THE END
** This function also traverses the list, but the stopping condition is different
** from `ft_lstsize`. We don't want to fall off the end of the list (by reaching
** NULL). We want to stop on the *last valid node*.
** The last node is the one whose `next` pointer is NULL.
*/

t_list	*ft_lstlast(t_list *lst)
{
	// --- EDGE CASE ---
	// If the list is empty to begin with (`lst` is NULL), there is no last node.
	// So, we return NULL immediately.
	if (!lst)
		return (NULL);

	// --- THE TRAVERSAL LOOP ---
	// The condition `while (lst->next)` is shorthand for `while (lst->next != NULL)`.
	// This loop will continue as long as the *next* node is not NULL.
	// This means the loop will stop when we are on the node whose `next` pointer
	// *is* NULL. That node is the last one.
	while (lst->next)
	{
		// Walk to the next node.
		lst = lst->next;
	}

	// The loop has finished, which means `lst` is now pointing to the last node
	// in the list. We return this pointer.
	return (lst);
}