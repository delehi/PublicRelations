#include "libft.h"

/*
** ft_lstiter: Applying a Function to Each Node
**
** PURPOSE:
** To "iterate" over a list and apply a function `f` to the `content` of
** each node. This is a classic example of high-level, abstract programming.
**
** THE FUNCTION POINTER `f`:
** `void (*f)(void *)` is a pointer to a function that takes a `void *`
** (the content) as a parameter and returns nothing.
** This allows you to pass *any* function that matches this signature.
** You could pass a function to print the content, to modify it, to add it
** to a running total, etc. `ft_lstiter` doesn't need to know what `f` does,
** it only needs to know how to call it.
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	// Safety check: Do nothing if the list doesn't exist or if the function
	// pointer `f` is NULL.
	if (lst && f)
	{
		// --- THE TRAVERSAL LOOP ---
		// This is the same simple traversal we saw in `ft_lstsize`.
		// It continues as long as the current node pointer is not NULL.
		while (lst)
		{
			// --- APPLY THE FUNCTION ---
			// For the current node, call the function `f`, passing it the
			// address of the content stored in that node.
			f(lst->content);

			// Walk to the next node in the chain.
			lst = lst->next;
		}
	}
}
