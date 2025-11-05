#include "libft.h"

/*
** ft_itoa: Integer to ASCII (string)
**
** PURPOSE:
** To convert an integer `n` into its string representation.
**
** THE ALGORITHM: DECONSTRUCTION AND RECONSTRUCTION
** You can't easily get the *first* digit of a number (e.g., the '1' in 123).
** But you can very easily get the *last* digit using the modulo operator (`%`).
** `123 % 10` gives 3. Then `12 % 10` gives 2. Then `1 % 10` gives 1.
** The algorithm is:
** 1. Figure out how many characters the final string will need.
** 2. Allocate memory for that string.
** 3. Work backwards from the end of the string, filling it with the digits
**    you get from the modulo (`%`) and division (`/`) operations.
*/

// This helper function calculates how many characters are needed for the string.
static size_t	get_digits(long n)
{
	size_t	i; // Our digit counter.

	i = 0;
	// If the number is 0 or negative, we know we need at least one character.
	// For a negative number, this accounts for the '-' sign.
	// For 0, it accounts for the '0' character itself.
	if (n <= 0)
	{
		n *= -1; // Make the number positive for the counting loop.
		i++;    // Add one to the count (for the '-' or for the single '0').
	}
	// This loop counts the digits by repeatedly dividing by 10.
	// 123 -> 12 -> 1 -> 0 (3 loops = 3 digits)
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result; // Pointer for our final, allocated string.
	int		digits;   // How many characters we need.
	long	num;      // Use a `long` to safely handle the most negative int.

	// --- EDGE CASE: INT_MIN ---
	// The most negative integer (`-2147483648`) has no positive equivalent in a
	// 32-bit `int`. If we do `-n`, it will overflow. By casting to a `long`,
	// we ensure we have enough space to safely make the number positive.
	num = n;

	// --- EDGE CASE: ZERO ---
	// The number 0 is a special case. Our `get_digits` logic handles it, but it's
	// often cleaner to just handle it separately at the start.
	if (num == 0)
		return (ft_strdup("0")); // Use our own `strdup` to return a fresh "0".

	// 1. Calculate the number of characters needed for the string.
	digits = get_digits(num);

	// 2. Allocate memory for the string on the heap.
	result = (char *)malloc(sizeof(char) * (digits + 1)); // +1 for the '\0'.
	if (result == NULL)
		return (NULL); // Always check if malloc failed.

	// 3. Place the null terminator at the very end of the allocated space.
	// We will then fill the string in backwards from here.
	result[digits--] = '\0';

	// 4. Handle negative numbers.
	if (num < 0)
	{
		num *= -1; // Make the number positive for our calculations.
		result[0] = '-'; // Place the minus sign at the very beginning.
	}

	// --- THE CONVERSION LOOP ---
	// This loop runs as long as there are digits left in the number.
	while (num > 0)
	{
		// `num % 10` gets the last digit (e.g., 123 -> 3).
		// `+ '0'` converts the integer digit (3) to its character equivalent ('3').
		// We place this character at the current end of the string.
		result[digits--] = num % 10 + '0';

		// Remove the last digit from the number (e.g., 123 -> 12).
		num /= 10;
	}

	// 5. Return the pointer to the newly created string.
	return (result);
}