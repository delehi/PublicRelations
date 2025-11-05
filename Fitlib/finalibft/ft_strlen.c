#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}
/* 
#include <stdio.h>
#include <string.h>
int	main (void)
{
	printf("myfunc = %li\n", ft_strlen("12345"));
	printf("orig = %li", strlen("12345"));
}
 */