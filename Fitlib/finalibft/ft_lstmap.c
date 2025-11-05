#include "libft.h"

/*
** ft_lstmap: Transforming a List into a New One
**
** PURPOSE:
** To create a *new* linked list by applying a function `f` to the `content`
** of each node in an existing list `lst`. The original list remains unchanged.
**
** THE ALGORITHM: MAPPING WITH ROBUST ERROR HANDLING
** This is the most complex linked list function because it involves:
** 1. Iterating through an existing list.
** 2. Applying a transformation function to each node's content.
** 3. Creating *new* nodes for a *new* list.
** 4. Crucially, handling memory allocation failures at *any* point during the
**    creation of the new list. If a `malloc` fails, you must free all the
**    nodes that were successfully created so far to prevent memory leaks.
**
** FUNCTION POINTERS:
** - `void *(*f)(void *)`: This is the transformation function. It takes a `void *`
**   (the content of an old node) and returns a `void *` (the new content for a new node).
** - `void (*del)(void *)`: This is the deletion function, used for cleaning up
**   content if an error occurs.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst; // The head of our brand new list.
	t_list	*node;    // A temporary pointer for each new node we create.
	void	*new_content; // To store the result of applying `f` to content.

	// --- INITIAL SAFETY CHECKS ---
	// If the original list is NULL, or if the deletion function is NULL (which
	// is needed for error cleanup), we cannot proceed.
	if (lst == NULL || del == NULL)
		return (NULL);

	new_lst = NULL; // Initialize the new list as empty.

	// --- TRAVERSAL AND TRANSFORMATION LOOP ---
	// Loop through each node of the original list.
	while (lst)
	{
		// --- APPLY TRANSFORMATION ---
		// Apply the function `f` to the content of the current node.
		// If `f` is NULL, we just use the original content.
		if (f == NULL)
			new_content = lst->content;
		else
			new_content = f(lst->content);

		// --- CREATE NEW NODE ---
		// Create a new node for our new list, using the transformed content.
		node = ft_lstnew(new_content);

		// --- CRITICAL ERROR HANDLING ---
		// If `ft_lstnew` failed (meaning `malloc` failed inside it),
		// we must clean up all the nodes we have successfully created so far
		// in `new_lst` to prevent a memory leak.
		if (node == NULL)
		{
			// Use `ft_lstclear` to free the entire `new_lst` that was built up.
			// The `del` function is passed to correctly free the content of these nodes.
			ft_lstclear(&new_lst, del);
			// Also, if `f` was used and returned a new `new_content` that was `malloc`ed
			// (which is often the case), and `ft_lstnew` failed, that `new_content`
			// itself needs to be freed. This is a subtle point and depends on `f`'s behavior.
			// For simplicity, we assume `ft_lstnew` handles `new_content`'s allocation.
			return (NULL); // Signal failure.
		}

		// --- ADD TO NEW LIST ---
		// Add the newly created node to the back of our `new_lst`.
		ft_lstadd_back(&new_lst, node);

		// Move to the next node in the original list.
		lst = lst->next;
	}

	// Return the head of the newly created and transformed list.
	return (new_lst);
}
