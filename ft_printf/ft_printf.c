/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:52:15 by akouoi            #+#    #+#             */
/*   Updated: 2022/05/19 20:49:29 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	id(char c)
{
	int		i;
	char	*set;

	set = "cspdiuxX +#";
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (i);
		i++;
	}
	return (20);
}

int	ft_point(va_list ap, int i)
{
	unsigned long long int	n;
	int						n_len;
	char					*str;

	if (i == 2)
		n = va_arg(ap, unsigned long long int);
	if (n == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	str = ft_itoa_base(n, "0123456789abcdef");
	n_len = ft_strlen(str);
	free(str);
	return (2 + n_len);
}

int	ft_format(va_list ap, int i)
{
	int	(*fct[10])(va_list, int);

	fct[0] = ft_putchar;
	fct[1] = ft_putstr;
	fct[2] = ft_point;
	fct[3] = ft_putnbr_dec;
	fct[4] = ft_putnbr_dec;
	fct[5] = ft_utoa;
	fct[6] = ft_putnbr_hex;
	fct[7] = ft_putnbr_hex;
	fct[8] = ft_putnbr_dec;
	fct[9] = ft_putnbr_dec;
	return (fct[i % 10](ap, i));
}

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	int			i;

	i = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
		{
			if (id(*++s) < 10)
			{
				i += ft_format(ap, id(*s) - 7 * (*s == 32 && *(s + 1) == 's'));
				s += (id(*s) == 8 || id(*s) == 9);
			}
			if (id(*s == 10) && (id(*(s + 1)) == 6 || id(*(s + 1)) == 7))
				i += write (1, "0", 1) + ft_format(ap, 10 + id(*(s++ + 1)));
			else if (*s == '%')
					i += write (1, s, 1);
		}
		else if (*s)
			i += write (1, s, 1);
		s++;
	}
	va_end(ap);
	return (i);
}

// int	main()
// {
// 	char *p = "hello";
// 	printf(" | count : %d\n", printf(NULL));
// 	printf(" | count : %d\n", ft_printf(""));
//   	printf(" | count :%d\n", printf("PF U : %u", 16));
//   	printf(" | count :%d\n", ft_printf("FT U : %u", 16));
// 	printf(" | count :%d\n", printf("PF point : %p", &p));
// 	printf(" | count :%d\n", ft_printf("FT point : %p", &p));
// 	printf(" | count :%d\n", printf("PF hex : %x", -1));
// 	printf(" | count :%d\n", ft_printf("FT hex : %x", -1));
//  	printf(" | count :%d\n", printf("PF HEX : %X", 16));
//  	printf(" | count :%d\n", ft_printf("FT HEX : %X", 16));
// 	printf(" | count :%d\n", ft_printf("FT %%"));
// 	printf(" | count :%d\n", printf("PF char - string - dec - int
//		|| %c %s %d %i", 'c', "hello", 2147, -2147483647));
// 	printf(" | count :%d\n", ft_printf("FT char - string - dec - int
//		|| %c %s %d %i", 'c', "hello", 2147, -2147483647));
// 	printf(" | count :%d\n", printf("PF space d : % d", 1));
// 	printf(" | count :%d\n", ft_printf("FT space d : % d", 1));
// 	printf(" | count :%d\n", printf("PF plus d : %+d", 1));
// 	printf(" | count :%d\n", ft_printf("FT plus d : %+d", 1));
// }