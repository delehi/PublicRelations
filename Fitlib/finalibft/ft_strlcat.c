#include "libft.h"

// needs more work
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	if (src_len < size - dest_len)
		ft_memcpy(dst + dest_len, src, src_len + 1);
	else
	{
		ft_memcpy(dst + dest_len, src, size - dest_len - 1);
		dst[size - 1] = '\0';
	}
	return (dest_len + src_len);
}
/* 
#include <stdio.h>
#include <string.h>
int main()
{
    char test1[] = "Hello ";
    char test2[] = "World";
    printf("strlcat = %ld\n", ft_strlcat(test1, test2, 12));
    printf("strlcat = %s\n", test1);
    return 0;
} 
 */