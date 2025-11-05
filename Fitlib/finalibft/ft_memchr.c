#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		if (*ptr == (unsigned char)c)
		{
			return ((void *)(ptr));
		}
		ptr++;
		i++;
	}
	return (NULL);
}
/* 
int	main(void)
{
	char *arr = "abcde";
	const char *str;
	str = ft_memchr("bonjour", 'b', 4);
	printf("result = %s\n", str);
	printf("result = %p\n", &arr[3]);

	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};

	printf("%ls", (int *)ft_memchr(tab, -1, 7));
}
 */