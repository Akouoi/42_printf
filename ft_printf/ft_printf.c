#include "ft_printf.h"

int	ft_index(char c)
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

int	ft_point(va_list ap)
{
	unsigned long long int	n;
	int	n_len;
	char *base = "0123456789abcdef";
	char	*str;

	n = va_arg(ap, unsigned long long int);
	if (n == 0)
		return(write(1, "(nil)", 5));
	write(1, "0x", 2);
	str = ft_itoa_base(n, base);
	n_len = ft_strlen(str);
	free(str);
	return(2 + n_len);
}

int	ft_format(va_list ap, int i)
{
	int	(*fct[9])(va_list);

	fct[0] = ft_putchar;
	fct[1] = ft_putstr;
	fct[2] = ft_point;
	fct[3] = ft_putnbr_dec;
	fct[4] = ft_putnbr_dec;
	fct[5] = ft_utoa;
	fct[6] = ft_putnbr_hex;
	fct[7] = ft_putnbr_hexm;
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
		if (*s == '%')
		{
			if (ft_index(*(++s)) < 8)
				i += ft_format(ap, ft_index(*s));
			else if (*s == '%')
				i += write (1, s, 1);
		}
		else
			i += write (1, s, 1);
		s++;
	}
	return (i);
}

// #include <limits.h>
// int	main()
// {
// 	char *p = "hello";
  	// printf(" | count :%d\n", printf("U : %u\n", 16));
  	// printf(" | count :%d\n", ft_printf("U : %u\n", 16));
// 	printf(" | count :%d\n", printf("point : %p\n", &p));
// 	printf(" | count :%d\n", ft_printf("point : %p\n", &p));
// 	printf(" | count :%d\n", printf("hex : %x\n", 0));
// 	printf(" | count :%d\n", ft_printf("hex : %x\n", 0));
// 	printf(" | count :%d\n", ft_printf("%%\n"));
//  	printf(" | count :%d\n", printf("HEX : %X\n", 16));
//  	printf(" | count :%d\n", ft_printf("HEX : %X\n", 16));
// 	printf(" | count :%d\n", printf("char - string - dec - int|| %c %s %d %i", 'c', "hello", 2147, -2147483647));
// 	printf(" | count :%d\n", ft_printf("char - string - dec - int|| %c %s %d %i", 'c', "hello", 2147, -2147483647));
// 	printf(" | count :%d\n", printf("printf: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
// 	printf(" | count :%d\n", ft_printf("ft_pri: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
// }