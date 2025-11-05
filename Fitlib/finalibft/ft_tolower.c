#include "libft.h"

int	ft_tolower(int c)
{
	if (c <= 90 && c >= 65)
		return (c + 32);
	else
		return (c);
}
/* 
#include <stdio.h>
#include <ctype.h>
int	main (void)
{
	char s = 'A';
	printf("orig = %c\n", ft_tolower(s));
	printf("orig = %c", tolower(s));
}
 */