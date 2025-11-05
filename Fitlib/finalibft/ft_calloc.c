#include "libft.h"

/*
** ft_calloc: The Safe and Clean Allocator
**
** PURPOSE:
** To allocate a block of memory for an array and initialize all its bytes to zero.
** It stands for "Contiguous Allocation".
**
** WHY NOT JUST `malloc(nmemb * size)`?
** Two reasons:
** 1. Security (Integer Overflow): If `nmemb` and `size` are very large numbers,
**    their product (`nmemb * size`) could be *larger* than the maximum value
**    `size_t` can hold. When this happens, the number "wraps around" and becomes
**    a small number. `malloc` would then allocate a tiny, incorrect amount of
**    memory, leading to buffer overflows when you try to write to it. This is
**    a major security vulnerability.
** 2. Cleanliness: `malloc` returns a block of memory filled with garbage data
**    from whatever was there before. `calloc` guarantees the memory is clean
**    and filled with zeros, which is often a safer starting point.
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;   // A generic pointer to hold the address of our new memory block.
	size_t	total;  // The total number of bytes to allocate.

	// --- EDGE CASE ---
	// If either the number of members or the size of each member is zero,
	// the total allocation size is zero. Some systems allow `malloc(0)` to return
	// NULL, while others return a valid pointer to a zero-sized block. The `man`
	// page for `calloc` says it can do either. This implementation chooses to
	// allocate a single byte, which is a common and safe way to handle this case.
	if (size == 0 || nmemb == 0)
		return (malloc(1));

	// Calculate the total number of bytes required.
	total = nmemb * size;

	// --- THE SECURITY CHECK (INTEGER OVERFLOW) ---
	// This is the most important part of `calloc`'s safety.
	// We check if our multiplication `nmemb * size` overflowed.
	// The logic: If we divide the `total` by `nmemb`, we should get `size` back.
	// If `total / nmemb` is NOT equal to `size`, it means `total` is a "wrapped around"
	// number, and an overflow occurred. In this case, we must not allocate memory.
	// We also check `nmemb != 0` to avoid division by zero, although the first
	// `if` statement already handles this.
	if (total / nmemb != size && nmemb != 0)
		return (NULL); // Return NULL to signal an error.

	// --- ALLOCATION ---
	// Perform the actual memory allocation on the heap.
	ptr = (void *)malloc(total);

	// Always check if `malloc` was successful. If the system is out of memory,
	// `malloc` will return NULL.
	if (ptr == NULL)
		return (NULL);

	// --- ZEROING ---
	// `malloc` gives us garbage data. We now use our own `ft_bzero` function
	// to fill the entire block of newly allocated memory with zeros.
	// This is the second key feature of `calloc`.
	ft_bzero(ptr, total);

	// Return the pointer to the start of our new, clean memory block.
	return ((void *)(ptr));
}
