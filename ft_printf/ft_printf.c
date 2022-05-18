#include "ft_printf.h"

int	ft_putstr(va_list ap)
{
	int	i;
	char	*s;

	i = 0;
	s = va_arg(ap, char *);
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

char	*ft_itoa(int n, char *base)
{
	char	*str;
	int		sign;
	int		n_len;
	int	base_len = ft_strlen(base);

	sign = 1 - 2 * (n < 0);
	n *= sign;
	n_len = ft_nblen(n, base_len);
	str = malloc((n_len + 1 + (sign < 0))* sizeof(char));
	if (!str)
		return (NULL);
	str[n_len + (sign < 0)] = 0;
	while (--n_len + (sign < 0) >= 0)
	{
		str[n_len + (sign < 0)] = base[n % base_len];
		n /= base_len;
	}
	if (sign < 0)
		str[0] = '-';
	write(1, str, ft_strlen(str));
	return (str);
}

int	ft_putnbr_dec(va_list ap)
{
	int	n;
	char	*base = "0123456789";
	char	*str;
	int	n_len;

	n = va_arg(ap, int);
	if (n == -2147483648)
		return(write(1, "-2147483648", 12));
	str = ft_itoa(n, base);
	n_len = ft_strlen(str);
	free(str);
	return (n_len);
}


char	*ft_itoa_base(unsigned long long int n, char *base)
{
	char	*str;
	unsigned long long int	base_len = ft_strlen(base);
	int	n_len;

	n_len = ft_nblen(n, base_len);
	str = malloc((n_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[n_len] = 0;
	while (n_len - 1 >= 0)
	{
		str[n_len - 1] = base[n % base_len];
		n /= base_len;
		n_len--;
	}
	write(1, str, ft_strlen(str));
	return (str);
}

int	ft_putnbr_hex(va_list ap)
{
	unsigned long long int	n;
	int	n_len;
	char *base = "0123456789abcdef";
	char	*str;

	n = va_arg(ap, unsigned long long int);
	str = ft_itoa_base(n, base);
	n_len = ft_strlen(str);
	free(str);
	return (n_len);
}

int	ft_putnbr_hexm(va_list ap)
{
	int	n;
	int	n_len;
	char *base = "0123456789ABCDEF";
	char	*str;

	n = va_arg(ap, int);
	str = ft_itoa_base((unsigned int) n, base);
	n_len = ft_strlen(str);
	free(str);
	return (n_len);
}

int	ft_point(va_list ap)
{
	write(1, "0x", 2);
	return(2 + ft_putnbr_hex(ap));
}
int	ft_format(va_list ap, int i)
{
	int	(*fct[9])(va_list);

	fct[0] = ft_putchar;
	fct[1] = ft_putstr;
	fct[2] = ft_point;
	fct[3] = ft_putnbr_dec;
	fct[4] = ft_putnbr_dec;
	fct[6] = ft_putnbr_hex;
	fct[7] = ft_putnbr_hexm;

	return (fct[i](ap));
}

static int	ft_index(char c)
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
	return (i);
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
		if (*s == '%')
		{
			if (ft_index(*(s + 1)) < 8)
				i += ft_format(ap, ft_index(*(s++ + 1)));
			if (*(s + 1) == '%')
				i += write (1, s++, 1);
		}
		else
			i += write (1, s, 1);
		s++;
	}
	return (i);
}

#include <limits.h>
int	main()
{
	char *p = "hello";
	printf(" | count :%d\n", printf("point : %p\n", &p));
	printf(" | count :%d\n", ft_printf("point : %p\n", &p));
	printf(" | count :%d\n", printf("hex : %x\n", 0));
	printf(" | count :%d\n", ft_printf("hex : %x\n", 0));
	printf(" | count :%d\n", ft_printf("%%\n"));
	printf(" | count :%d\n", printf("HEX : %X\n", 0));
	printf(" | count :%d\n", ft_printf("HEX : %X\n", 0));
	printf(" | count :%d\n", printf("char - string - dec - int|| %c %s %d %i", 'c', "hello", 2147, -2147483647));
	printf(" | count :%d\n", ft_printf("char - string - dec - int|| %c %s %d %i", 'c', "hello", 2147, -2147483647));
}