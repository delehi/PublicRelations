#include "libft.h"

/*
** ft_memmove: The Safe Memory Copy
**
** PURPOSE:
** To copy `n` bytes from memory area `src` to memory area `dest`.
** Unlike `ft_memcpy`, `ft_memmove` is safe to use even if the `src` and `dest`
** memory blocks overlap.
**
** THE PROBLEM WITH `memcpy` AND OVERLAP:
** Imagine you have a string: "abcdefghi"
** And you want to move the "abc" part to where "bcd" is.
** `src` would point to 'a', `dest` would point to 'b'.
**
**   Memory: [a][b][c][d][e][f][g][h][i][\0]
**   `src`-----^ 
**   `dest`------^
**
** A simple `memcpy` would do this:
** 1. Copy `src[0]` ('a') to `dest[0]` ('b'). Memory becomes: [a][a][c][d]...
** 2. Copy `src[1]` ('a') to `dest[1]` ('c'). Memory becomes: [a][a][a][d]...
** 3. Copy `src[2]` ('a') to `dest[2]` ('d'). Memory becomes: [a][a][a][a]...
** The result is "aaaadef...", which is wrong! We overwrote our source
** before we could read from it.
**
** THE `memmove` SOLUTION:
** `memmove` detects this specific kind of overlap (`dest` is inside `src`).
** When it does, it copies BACKWARDS from the end of the block to avoid
** overwriting the data it needs to read.
**
**   Backwards Copy:
**   1. Copy `src[2]` ('c') to `dest[2]` ('d'). Memory becomes: [...][d]->[c]
**   2. Copy `src[1]` ('b') to `dest[1]` ('c'). Memory becomes: [...][c]->[b]
**   3. Copy `src[0]` ('a') to `dest[0]` ('b'). Memory becomes: [...][b]->[a]
** The result is "aabcdef...", which is correct.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_ptr; // We need char pointers to move byte by byte.
	char	*src_ptr;

	// Cast the generic void pointers to specific char pointers.
	dest_ptr = (char *)dest;
	src_ptr = (char *)src;

	// --- THE CRITICAL CHECK ---
	// This `if` statement is the entire brain of `memmove`.
	// It checks if the destination starts at a higher memory address than the source.
	// If it does, it means there's a risk of the destination overwriting the source
	// as we copy forwards (like the "abcdef" example above).
	if (dest_ptr > src_ptr)
	{
		// --- BACKWARDS COPY ---
		// We have a dangerous overlap. We must copy from the end.
		
		// Move our pointers to the *last byte* of the blocks we need to copy.
		// If we need to copy `n` bytes, the last byte is at an offset of `n-1`.
		dest_ptr += (n - 1);
		src_ptr += (n - 1);

		// Loop `n` times.
		while (n-- > 0)
		{
			// Copy the byte, and *then* decrement the pointers to move backwards.
			// This is the "post-decrement" operator.
			*dest_ptr-- = *src_ptr--;
		}
	}
	else
	{
		// --- FORWARDS COPY ---
		// If `dest_ptr <= src_ptr`, there is no dangerous overlap.
		// The source is either completely separate or *after* the destination.
		// In this case, a simple forward copy is safe and efficient.
		// We can just use our `ft_memcpy` function to do the job.
		return (ft_memcpy(dest_ptr, src_ptr, n));
	}
	
	// The original, unmodified `dest` pointer is returned as per the man page.
	return (dest);
}