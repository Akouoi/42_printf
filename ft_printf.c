/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:52:15 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/08 11:59:05 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	id(char ch)
{
	int		j;
	char	*set;

	set = "cspdiuxX +#%";
	j = 0;
	while (set[j])
	{
		if (set[j] == ch)
			return (j);
		j++;
	}
	return (20);
}
/*
int	ft_format(va_list ap, int j)
{
	int	(*fct[10])(va_list, int);

	fct[c] = pf_putchar;
	fct[s] = pf_putstr;
	fct[p] = pf_point;
	fct[d] = pf_putnbr_dec;
	fct[i] = pf_putnbr_dec;
	fct[u] = pf_utoa;
	fct[x] = pf_putnbr_hex;
	fct[X] = pf_putnbr_hex;
	fct[8] = pf_putnbr_dec;
	fct[9] = pf_putnbr_dec;
	return (fct[j % 10](ap, j));
}*/

int	ft_format(va_list ap, int j)
{
	int	(*fct[157])(va_list, int);

	(void)j;
	fct[c] = pf_putchar;
	fct[s] = pf_putstr;
	fct[p] = pf_point;
	fct[d] = pf_putnbr_dec;
	fct[i] = pf_putnbr_dec;
	fct[u] = pf_utoa;
	fct[x] = pf_putnbr_hex;
	fct[X] = pf_putnbr_hex;
	fct[sp] = pf_putnbr_dec;
	fct[pl] = pf_putnbr_dec;
	fct[x - ht +34] = pf_putnbr_hex;
	fct[X - ht +34] = pf_putnbr_hex;
	// return(fct[c](ap, 0));
	return (fct[j % 10](ap, j));
}
int	ft_print_step(const char *t, va_list ap)
{
	int			k;
	int			j;

	k = 0;
	j = 0;
	while (t[j])
	{
		printf("t[] = %c\tn", t[j]);
		if (t[j] == pc && id(t[++j]) < 10)
		{
			k += ft_format(ap, t[j]) * !(t[j] == sp && t[j + 1] == s)
				+ ft_format(ap, s) * (t[j] == sp && t[j + 1] == s);
			printf("\t2\n\n");
			j += (t[j] == sp || t[j] == pl);
		}
		else if ((t[j - 1] == pc && t[j] == ht)
			&& (t[j + 1] == x || t[j + 1] == X))
			k += write (1, "0", 1) + ft_format(ap, t[j++ + 1] - 1);
		else if (t[j] == pc)
			k += write (1, &t[j], 1);
		else if (t[j] != pc)
			k += write (1, &t[j], 1);
		j++;
	}
	return (k);
}


int	ft_printf(const char *s, ...)
{
	va_list		ap;
	int			k;
	// t_arg		*arg;

	// arg = malloc (sizeof(t_arg));
	
	va_start(ap, s);
	k = ft_print_step(s, ap);
	// while (s[j])
	// {
	// 	if (s[j] == '%' && id(s[++j]) < 10)
	// 	{
	// 		k += ft_format(ap, id(s[j]) - 7 * (s[j] == 32 && s[j + 1] == 's'));
	// 		j += (id(s[j]) == 8 || id(s[j]) == 9);
	// 	}
	// 	else if ((s[j - 1] == '%' && id(s[j]) == 10)
	// 		&& (id(s[j + 1]) == 6 || id(s[j + 1]) == 7))
	// 		k += write (1, "0", 1) + ft_format(ap, 10 + id(s[j++ + 1]));
	// 	else if (s[j] == '%')
	// 		k += write (1, &s[j], 1);
	// 	else if (s[j] != '%')
	// 		k += write (1, &s[j], 1);
	// 	j++;
	// }
	va_end(ap);
	return (k);
}

int	main(void)
{
	char *p[10];
	char	*yo = "\n=====================================\n";

	// p[0] = "%%c%%s%%p%%d%%i%%u%%x%%X%%";
	p[1] = "PF m | %c %s %+d % i";
	// printf(" | count :%d%s", printf(p[0], 'a', "hello", &p[0], 1, 1, 1, 1, 1),yo);
	// printf(" | count :%d%s", ft_printf(p[0]),yo);
	printf(" | cnt :%d%s", printf("PF m | %c %s %+d % i",'c',"hello",2147,0),yo);
	printf(" | cnt :%d%s", ft_printf("PF m | %c %s %+d % i",'c',"hello",2147,0),yo);
  	printf(" | count :%d%s", printf("PF U : %u", 16), yo);
  	printf(" | count :%d%s", ft_printf("FT U : %u", 16), yo);
	printf(" | count :%d%s", printf("PF P : %p", &p), yo);
	printf(" | count :%d%s", ft_printf("FT P : %p", &p), yo);
	printf(" | count :%d%s", printf("PF P : %s", p[0]), yo);
	printf(" | count :%d%s", ft_printf("FT P : %s", p), yo);
 	printf(" | count :%d%s", printf("PF X : %#X", 0), yo);
 	printf(" | count :%d%s", ft_printf("FT X : %#X", 0), yo);
	printf(" | count :%d%s", printf("PF 0 %%"), yo);
	printf(" | count :%d%s", ft_printf("FT 0 %%"), yo);
	printf(" | count :%d%s", printf("PF sd : % d", 1), yo);
	printf(" | count :%d%s", ft_printf("FT sd : % d", 1), yo);
	printf(" | count :%d%s", printf("PF +d : %+d", 1), yo);
	printf(" | count :%d%s", ft_printf("FT +d : %+d", 1), yo);
}
