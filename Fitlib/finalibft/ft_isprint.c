#include "libft.h"

int	ft_isprint(int c)
{
	if (c <= 126 && c >= 32)
		return (c);
	return (0);
}
/* 
#include <stdio.h>
#include <ctype.h>
int	main (void)
{
	printf("myfunc = %i\n", ft_isprint(127));
	printf("orig = %i", isprint(127));
}
 */