#include "libft.h"

/*
** ft_strtrim: The Two-Pointer Squeeze
**
** PURPOSE:
** To create a new string by trimming all characters from the `set` string
** off the beginning AND end of the original string `s1`.
**
** THE ALGORITHM: A TWO-POINTER SQUEEZE
** The core idea is to find the first character from the beginning that is *not*
** in the `set`, and the first character from the end that is *not* in the `set`.
** The new string is simply the substring between these two points.
**
**   Example: s1 = "__--__hello__--__", set = "_-"
**
**   1. Find the start: 
**      - Is s1[0] ('_') in the set? Yes. Move start to 1.
**      - Is s1[1] ('_') in the set? Yes. Move start to 2.
**      - Is s1[2] ('-') in the set? Yes. Move start to 3.
**      - ...and so on, until...
**      - Is s1[6] ('h') in the set? No. Stop. `start` is now 6.
**
**   2. Find the end:
**      - `end` starts at the last index.
**      - Is s1[end] ('_') in the set? Yes. Move end to end-1.
**      - ...and so on, until...
**      - Is s1[10] ('o') in the set? No. Stop. `end` is now 10.
**
**   3. Create the substring:
**      - We now know the good part of the string is from index 6 to index 10.
**      - The length of this part is `end - start + 1` (10 - 6 + 1 = 5).
**      - Call `ft_substr(s1, start, length)` which is `ft_substr(s1, 6, 5)`.
**      - This will create and return a new string: "hello".
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start; // Will hold the index of the first non-set character.
	size_t	end;   // Will hold the index of the last non-set character.

	// Always check for NULL inputs first.
	if (s1 == NULL || set == NULL)
		return (0);

	// --- FIND THE START --- 
	start = 0;
	// Loop as long as the character at `s1[start]` can be found within the `set`.
	// `ft_strchr` returns a pointer if the character is found, and NULL otherwise.
	// A non-NULL pointer evaluates to "true" in a while loop condition.
	while (ft_strchr(set, s1[start]))
		start++;

	// --- FIND THE END ---
	end = ft_strlen(s1) - 1;
	// Loop backwards from the end of the string as long as the character at `s1[end]`
	// is found in the `set`.
	// NOTE: The original code uses `ft_strrchr`, which is slightly inefficient here
	// since we only care IF the character exists, not where it last appears.
	// `ft_strchr` would work identically and be slightly faster.
	while (ft_strrchr(set, s1[end]))
		end--;

	// --- CREATE AND RETURN THE SUBSTRING ---
	// This is a brilliant use of your own library functions.
	// You pass the original string, the `start` index you found, and the calculated
	// length of the good part (`end - start + 1`) to `ft_substr`.
	// `ft_substr` will handle the memory allocation and copying for you.
	return (ft_substr(s1, start, end - start + 1));
}