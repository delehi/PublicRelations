#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	i;

	i = n;
	if (i == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else if (i < 0)
	{
		ft_putchar_fd('-', fd);
		i *= -1;
		ft_putnbr_fd(i, fd);
	}
	else if (i > 9)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
	else
		ft_putchar_fd(i + '0', fd);
}

/* 
int main()
{
	ft_putnbr_fd(-987441, 1);
}
 */