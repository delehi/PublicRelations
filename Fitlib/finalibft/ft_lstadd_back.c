#include "libft.h"

/*
** ft_lstadd_back: Appending a Node to the End
**
** PURPOSE:
** To add a new node, `new`, to the very end of a linked list.
**
** THE ALGORITHM:
** 1. Handle the edge case: What if the list is empty? If it is, adding to the
**    back is the same as adding to the front. We need to change the head
**    pointer itself, which is why we need a double pointer (`t_list **`).
** 2. If the list is NOT empty, we must find the last node.
** 3. Once we have the last node, we change its `next` pointer from `NULL` to
**    point to our `new` node.
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	// Safety check: Don't do anything if the pointer to the head pointer is NULL
	// or if the new node to add is NULL.
	if (lst == NULL || new == NULL)
		return ;

	// --- EDGE CASE: THE LIST IS EMPTY ---
	// `*lst` is the actual head pointer. If it's `NULL`, the list is empty.
	if (*lst == NULL)
	{
		// In this case, the `new` node becomes the first and only node.
		// We are directly modifying the original `head` pointer from `main`.
		*lst = new;
		return; // The job is done.
	}

	// --- FIND THE LAST NODE ---
	// If the list is not empty, we need to find the end.
	// This implementation does it manually. A more DRY (Don't Repeat Yourself)
	// approach would be to simply call the `ft_lstlast` function we already wrote:
	// `last_node = ft_lstlast(*lst);`
	last_node = *lst;
	while (last_node->next)
		last_node = last_node->next;

	// --- LINK THE NEW NODE ---
	// At this point, `last_node` is pointing to the last node in the list.
	// We change its `next` pointer to point to our `new` node, officially
	// linking it to the end of the chain.
	last_node->next = new;
}
