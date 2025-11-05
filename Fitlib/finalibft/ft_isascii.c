#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/* 
#include <stdio.h>
#include <ctype.h>
int	main (void)
{
	printf("myfunc = %i\n", ft_isascii(0));
	printf("orig = %i\n", isascii(0));
	printf("bool = %i\n", 0 >= 0 && 0 <= 127);
}
 */