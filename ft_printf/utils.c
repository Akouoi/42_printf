#include "ft_printf.h"

int	ft_putstr(va_list ap)
{
	int	i;
	char	*s;

	i = 0;
	s = va_arg(ap, void *);
	if (!s)
		return (0);
	while (s[i])	
		i += write (1, &s[i], 1);
	return (i);
}

int	ft_putchar(va_list ap)
{
	int	c;

	c = va_arg(ap, int);
	return (write(1, &c, 1));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_nblen(unsigned long long int n, unsigned long long int base_len)
{
	int	power;

	power = 0;
	while (n > base_len)
	{
		power++;
		n /= base_len;
	}
	return (power + 1);
}
