#include "libftprintf.h"

int	ft_putstr(va_list ap)
{
	int	i;
	char	*s;

	i = 0;
	s = va_arg(ap, char *);
	if (!s)
		return (0);
	while (s[i])	
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}
int	ft_putchar(va_list ap)
{
	char	c;

	c = va_arg(ap, int) + '0';
	write(1, &c, 1);
	return (1);
}
static int	ft_nblen(int n)
{
	int	power;
	int	sign;

	sign = 1 - 2 * (n < 0);
	power = 0;
	n *= sign;
	while (n > 0)
	{
		power++;
		n /= 10;
	}
	return (power + (sign < 0));
}

void	ft_putnbr(int n)
{
	char	*p;

	p = NULL;
	if (n == -2147483648)
		write(1, "-2147483648", 12);
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	*p = n % 10 + '0';
	write(1, p, 1);
}

int	ft_nbr(va_list ap)
{
	int	n;

	n = va_arg(ap, int);
	ft_putnbr(n);
	return (ft_nblen(n));
}

static int	ft_index(int c)
{
	int	i;
	char	*set;

	set = "cspdiuxX";
	i = 0;
	while(set[i])
	{
		if (set[i] == c)
			return (i);
		i++;
	}
	printf("index = %d\n", i);
	return (i);
}

int	ft_format(va_list ap, int i)
{
	int	(*fct[9])(va_list);

	//fct[0] = ft_putchar;
	fct[1] = ft_putstr;
	fct[3] = ft_nbr;

	return (fct[i](ap));
}

int 	ft_printf(const char *s, ...)
{
	int	i;
	va_list	ap;

	if (!s)
		return (-1);
	i = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*(s - 1) == '%')
		{
			if (ft_index(*s) < 8)
			{
				i += ft_format(ap, ft_index(*s));
				if (s+1)
					s++;
			}
			else
			{
				write (1, s, 1);
				i++;
			}
		}
		s++;

	}
	return (i);
}

int	main()
{
	printf("\n%d\n", printf("%s", "hello"));
	printf("\n%d\n", ft_printf("%s", "hello"));
//	printf("\n%d\n", printf("%d", 12));
//	printf("\n%d\n", ft_printf("%d", 12));
}