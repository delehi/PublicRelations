#include "libft.h"

/*
** ft_split: The Master Plan
**
** 1. COUNT_WORDS: First, walk through the input string `s` to count how many
**    separate "words" (substrings) exist between the delimiter `c`. This is
**    crucial because we need to know the exact size of the main array to
**    allocate.
**
** 2. ALLOCATE THE MAIN ARRAY: Allocate a block of memory to hold the array of
**    pointers. This will be an array of `char *`, so its size is
**    `(word_count + 1) * sizeof(char *)`. The `+ 1` is for the final `NULL`
**    pointer that marks the end of the array, a critical convention in C.
**
** 3. CREATE AND FILL SUB-ARRAYS (THE WORDS): Loop through the input string `s`
**    a second time. For each word you find:
**      a. GET WORD LENGTH: Calculate the length of the current word.
**      b. ALLOCATE FOR WORD: Allocate a new block of memory on the heap just
**         big enough to hold that word (`word_len + 1` for the `\0`).
**      c. COPY THE WORD: Copy the characters of the word from `s` into the
**         newly allocated block.
**      d. STORE THE POINTER: Store the pointer to this new word-string into
**         the main `char **` array.
**
** 4. NULL TERMINATE: After the loop, place the final `NULL` pointer at the
**    end of the main `char **` array.
**
** 5. RETURN: Return the pointer to the main array.
*/

// This is a simple helper function. Its only job is to check if a single
// character `c` is the separator/delimiter `sep`. It makes the code in other
// functions slightly more readable than `if (c == sep)`.
static int	check_sep(char c, char sep)
{
	if (c == sep)
		return (1); // 1 is "true" in C
	return (0); // 0 is "false"
}

// This function's only job is to count how many words are in the string.
// It does this by using a state machine concept with the `in_word` flag.
static int	count_words(const char *str, char sep)
{
	int	i;
	int	words;
	int	in_word; // This acts as a "flag" or a "state". 0 = we are in a separator, 1 = we are in a word.

	i = 0;
	words = 0;
	in_word = 0;
	// Loop through the entire string until the null terminator.
	while (str[i])
	{
		// This condition is only true for the *first* character of a new word.
		// If the character is NOT a separator AND we are NOT currently inside a word...
		if (str[i] != sep && in_word == 0)
		{
			// We have found the beginning of a new word!
			in_word = 1; // Set the flag to say "we are now in a word".
			words++;     // Increment the word counter.
			// This inner loop is just to skip past the rest of the current word.
			while (str[i] && str[i] != sep)
				i++;
		}
		// If the character IS a separator...
		else if (str[i] == sep)
		{
			// We are now in a separator, so we reset the flag.
			in_word = 0;
			i++; // Move to the next character.
		}
	}
	return (words);
}

// Helper function to get the length of a single word.
// It starts from the given `str` pointer and counts characters until it hits
// either the separator `c` or the end of the string `\0`.
static int	word_len(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && !check_sep(str[i], c))
		i++;
	return (i);
}

// A custom version of `strdup` that only duplicates up to the next separator.
// This is the function that allocates memory for and creates each individual word.
static char	*ft_strdup_split(const char *str, char c)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	// 1. Calculate the exact length of the word we need to copy.
	len = word_len(str, c);
	// 2. Allocate exactly that much memory on the heap, plus one byte for the `\0`.
	word = (char *) malloc (sizeof(char) * (len + 1));
	// 3. Copy the characters from the source string into our new memory block.
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	// 4. Add the null terminator to make it a valid C string.
	word[i] = '\0';
	// 5. Return the pointer to the new, freshly allocated word.
	return (word);
}

// The main function that orchestrates the entire process.
char	**ft_split(char const *s, char c)
{
	char	**result; // This will be our main array of strings (array of pointers).
	int		i;

	// --- MEMORY ALLOCATION (PART 1) ---
	// Allocate memory for the main array that will hold the pointers to each word.
	// We use `count_words` to know exactly how many `char *` pointers we need to store.
	// We add 1 to make space for the final NULL pointer that terminates the array.
	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));

	// --- SAFETY CHECKS ---
	// A robust function always checks for errors.
	// 1. If the input string `s` is NULL, we can't do anything.
	// 2. If the `malloc` for `result` failed, it returns NULL, so we must stop.
	// 3. The `count_words` check is a small optimization in this implementation.
	if (s == NULL || result == NULL || count_words(s, c) == 0)
		return (free(result), NULL); // `free(NULL)` is safe. This line handles failure or an empty string.

	i = 0;
	// Loop through the input string `s` character by character.
	while (*s)
	{
		// If we are not on a separator character...
		if (*s != c)
		{
			// --- MEMORY ALLOCATION (PART 2) ---
			// We've found the start of a word. Call our helper to `malloc` and copy it.
			result[i] = ft_strdup_split(s, c);
			
			// This inner loop fast-forwards the `s` pointer past the word we just copied.
			while (*s && *s != c)
				s++;
			
			// Increment the index for the main `result` array to prepare for the next word.
			i++;
		}
		// If we ARE on a separator character...
		else
		{
			// Just skip it.
			s++;
		}
	}
	// --- FINAL STEP: NULL TERMINATION ---
	// Add the final NULL pointer to the end of our array of strings.
	// This is how other functions (like a `while(result[i])` loop) will know
	// where the array ends.
	result[i] = 0;
	return (result);
}