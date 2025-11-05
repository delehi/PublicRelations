#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n-- > 0)
		*ptr++ = c;
	return (s);
}
/* 
int	main (void)
{
	char arr[5];
	memset(arr, 'z', sizeof(arr));
	printf("orig = %s\n", arr);

	ft_memset(arr, 'a', sizeof(arr));
	printf("myfunc = %s\n", arr);
}
 */