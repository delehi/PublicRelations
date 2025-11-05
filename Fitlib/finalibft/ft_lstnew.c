#include "libft.h"

/*
** ft_lstnew: The Node Factory
**
** PURPOSE:
** To create a single, new "node" for a linked list.
** A node is the fundamental building block of a list.
**
** THE `t_list` STRUCT (from libft.h):
** `typedef struct s_list {`
** `    void          *content;`
** `    struct s_list *next;`
** `} t_list;`
**
** A node has two parts:
** 1. `content`: A `void *` pointer. This is the actual data the node holds.
**    Using `void *` is a genius move in C. It means you can store a pointer
**    to *anything* in your list: a string, an int, another struct, etc.
**    The list doesn't care what the data is, only where to find it.
** 2. `next`: A pointer to another struct of the *same type* (`struct s_list *`).
**    This is the "link" in the "linked list". It points to the next node in
**    the chain.
*/

t_list	*ft_lstnew(void *content)
{
	// Declare a pointer that will hold the address of our new node.
	// The type `t_list` is our custom struct type.
	t_list	*node;

	// --- MEMORY ALLOCATION ---
	// We need to create a new node on the heap, because if we created it on the
	// stack, it would be destroyed as soon as this function returns.
	// `sizeof(t_list)` calculates how many bytes our struct needs (the size of
	// two pointers: `content` and `next`).
	node = (t_list *)malloc(sizeof(t_list));

	// --- SAFETY CHECK ---
	// `malloc` can fail if the system is out of memory. If it does, it returns NULL.
	// A robust program *always* checks the return value of malloc.
	if (node == NULL)
		return (NULL); // Signal that node creation failed.

	// --- INITIALIZATION ---
	// Now we have a valid block of memory. We need to fill in its fields.

	// Set the `content` pointer of our new node to point to the data that was
	// passed into the function.
	// `node->content` is just syntactic sugar for `(*node).content`.
	node->content = content;

	// A new node, by itself, is the end of a list. Its `next` pointer should
	// therefore always be initialized to NULL. It doesn't point to anything yet.
	node->next = NULL;

	// Return the pointer to the new node, so it can be used by other functions
	// like `ft_lstadd_front` or `ft_lstadd_back`.
	return (node);
}