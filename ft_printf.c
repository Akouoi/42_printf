/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:52:15 by akouoi            #+#    #+#             */
/*   Updated: 2022/05/24 10:25:14 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	id(char c)
{
	int		i;
	char	*set;

	set = "cspdiuxX +#%";
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (i);
		i++;
	}
	return (20);
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
	int			j;

	i = 0;
	j = 0;
	va_start(ap, s);
	while (s[j])
	{
		if (s[j] == '%' && id(s[++j]) < 10)
		{
			i += ft_format(ap, id(s[j]) - 7 * (s[j] == 32 && s[j + 1] == 's'));
			j += (id(s[j]) == 8 || id(s[j]) == 9);
		}
		else if ((s[j - 1] == '%' && id(s[j]) == 10)
			&& (id(s[j + 1]) == 6 || id(s[j + 1]) == 7))
			i += write (1, "0", 1) + ft_format(ap, 10 + id(s[j++ + 1]));
		else if (s[j] == '%')
			i += write (1, &s[j], 1);
		else if (s[j] != '%')
			i += write (1, &s[j], 1);
		j++;
	}
	va_end(ap);
	return (i);
}
/*
int	main(void)
{
	char *p = "hello";
	char	*yo = "\n=====================================\n";
	printf(" | count :%d%s", printf("%%c%%s%%p%%d%%i%%u%%x%%X%%"),yo);
	printf(" | count :%d%s", ft_printf("%%c%%s%%p%%d%%i%%u%%x%%X%%"),yo);
  	printf(" | count :%d%s", printf("PF U : %u", 16), yo);
  	printf(" | count :%d%s", ft_printf("FT U : %u", 16), yo);
	printf(" | count :%d%s", printf("PF P : %p", &p), yo);
	printf(" | count :%d%s", ft_printf("FT P : %p", &p), yo);
	printf(" | count :%d%s", printf("PF P : %s", p), yo);
	printf(" | count :%d%s", ft_printf("FT P : %s", p), yo);
 	printf(" | count :%d%s", printf("PF X : %#X", 0), yo);
 	printf(" | count :%d%s", ft_printf("FT X : %#X", 0), yo);
	printf(" | count :%d%s", ft_printf("FT 0 %%"), yo);
	printf(" | cnt :%d%s", printf("PF m | %c %s %+d % i",'c',"hello",2147,0),yo);
	printf(" | cnt :%d%s", ft_printf("FT m | %c %s %+d % i",'c',"hello",2147,0),yo);
	printf(" | count :%d%s", ft_printf("FT sd : % d", 1), yo);
	printf(" | count :%d%s", printf("PF +d : %+d", 1), yo);
	printf(" | count :%d%s", ft_printf("FT +d : %+d", 1), yo);
}*/
