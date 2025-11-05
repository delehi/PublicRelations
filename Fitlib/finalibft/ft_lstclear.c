#include "libft.h"

/*
** ft_lstclear: Deleting an Entire List
**
** PURPOSE:
** To delete and free every node in a list, starting from the node pointed
** to by `*lst`. After the function runs, the original `head` pointer in `main`
** should be set to NULL.
**
** THE ALGORITHM: SAFE TRAVERSAL AND DELETION
** You cannot simply loop and free nodes like this (THIS IS WRONG):
** `while (current) { free(current); current = current->next; }`
** The moment you `free(current)`, you are no longer allowed to access its
** `next` member. This is called a "use-after-free" error.
**
** The correct way is to save the address of the next node *before* deleting
** the current one.
** 1. Save `next_node = current->next`.
** 2. Delete `current` using `ft_lstdelone`.
** 3. Move to the next node: `current = next_node`.
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	// A temporary pointer to hold the address of the next node in the chain.
	t_list	*tmp;

	// Safety check: ensure the pointer to the head pointer is valid.
	if (lst)
	{
		// Loop as long as the head pointer (`*lst`) is not NULL.
		while (*lst)
		{
			// --- STEP 1: Save the next node's address ---
			// Before we destroy the current node (`*lst`), we must first save the
			// location of the next node in our temporary `tmp` pointer.
			tmp = (*lst)->next;

			// --- STEP 2: Delete the current node ---
			// Now that we have a safe reference to the rest of the list, we can
			// completely delete the current node and its content.
			ft_lstdelone(*lst, del);

			// --- STEP 3: Move to the next node ---
			// We update the head of the list to be the `tmp` pointer we saved.
			// In the next loop iteration, `*lst` will be the next node in the list.
			*lst = tmp;
		}
	}
	// When the loop finishes, the original `head` pointer in `main` will be NULL,
	// because we were modifying it directly via `*lst`.
}
