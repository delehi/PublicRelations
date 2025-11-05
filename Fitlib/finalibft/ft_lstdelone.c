#include "libft.h"

/*
** ft_lstdelone: Deleting a Single Node
**
** PURPOSE:
** To free the memory associated with a single list node.
**
** THE TWO-STEP FREE:
** A node has two parts that might be on the heap:
** 1. The `content` pointer, which might point to something you `malloc`'d
**    (like a string from `ft_strdup`).
** 2. The `node` struct itself, which was created with `ft_lstnew` (using `malloc`).
** You must free both to prevent memory leaks.
**
** THE `del` FUNCTION POINTER:
** The list doesn't know how to free its `content`. Does it point to a simple
** string that needs `free(content)`? Or is it a complex struct that has its
** own special deletion function? The `void (*del)(void*)` function pointer
** lets the *user* of the library provide the correct deletion function for
** their specific data type. This makes the list incredibly generic and powerful.
*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	// --- A NOTE ON THE ORIGINAL `if (lst || del)` ---
	// The original code had `if (lst || del)`. This is a potential bug.
	// If `lst` is NULL but `del` is not, the code would enter the `if` block
	// and immediately crash on `del(lst->content)` because you can't dereference
	// a NULL pointer. The check should always be `if (lst && del)` to ensure
	// both are valid before proceeding.

	// Safety check: Ensure we have a valid node to delete AND a valid function
	// to delete the content with.
	if (lst && del)
	{
		// --- STEP 1: Free the content ---
		// Call the user-provided deletion function `del` on the node's content.
		// This correctly frees the memory that the `content` pointer points to.
		del(lst->content);

		// --- STEP 2: Free the node ---
		// Now that the content is freed, we can free the `t_list` struct itself.
		free(lst);

		// Setting the now-freed pointer to NULL is a good practice, although it
		// won't have an effect outside this function since `lst` is a copy.
		lst = NULL;
	}
}
