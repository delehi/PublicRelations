#include "libft.h"

/*
** ft_lstadd_front: Adding a New Head to the List
**
** PURPOSE:
** To add a new node, `new`, to the very beginning of a linked list.
**
** THE GENIUS OF POINTER-TO-POINTER (`**`):
** This is the most important concept to understand here. Why `t_list **lst`
** instead of just `t_list *lst`?
**
** Analogy: The "Head of the Class" Note
** - Imagine you have a variable in your `main` function called `head`.
**   `t_list *head = NULL;`
** - This `head` pointer is like a sticky note on your desk that tells you the
**   memory address of the student who is currently at the head of the class.
**
** - If you pass `head` to a function like `void do_something(t_list *lst)`,
**   the function gets a *copy* of that sticky note. It knows where the head
**   of the class is, but it can't change the note on *your* desk.
**
** - But `ft_lstadd_front` needs to change the note on your desk! It needs to
**   make `head` point to a new student (the `new` node).
**
** - The Solution: Instead of passing a copy of the note, you pass the
**   *address of the note itself*. You pass a pointer to your pointer.
**   `t_list **lst` means "`lst` is the address of a pointer to a t_list".
**
** - Inside the function:
**   - `lst` holds the address of your `head` variable.
**   - `*lst` lets you access and *change* the original `head` variable.
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	// Safety check: ensure that we have a valid address for the list's head
	// pointer AND that the new node we're trying to add actually exists.
	if (lst != NULL && new != NULL)
	{
		// --- STEP 1: Link the new node to the old head ---
		// `*lst` gives us the actual `head` pointer from our main function.
		// It currently points to the old first node of the list.
		// We set the `next` pointer of our `new` node to point to that old first node.
		// The `new` node is now linked in, just before the old head.
		//
		//   Before: new -> NULL      head -> [Old Node 1] -> [Old Node 2]
		//
		//   After this line: new -> [Old Node 1] -> [Old Node 2]
		//                    head still points to [Old Node 1]
		new->next = *lst;

		// --- STEP 2: Update the head pointer ---
		// Now, we change the original `head` pointer (the sticky note on your desk)
		// to point to our `new` node, making it the official new head of the list.
		//
		//   Before: new -> [Old Node 1] -> [Old Node 2]
		//           head -> [Old Node 1]
		//
		//   After this line: head -> new -> [Old Node 1] -> [Old Node 2]
		*lst = new;
	}
}