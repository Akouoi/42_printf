/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:52:15 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/08 14:41:59 by akouoi           ###   ########.fr       */
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
	fct[c - 99] = pf_putchar;
	fct[s - 115 + 1] = pf_putstr;
	fct[p - 112 + 2] = pf_point;
	fct[d - 100 + 3] = pf_putnbr_dec;
	fct[i - 105 + 4] = pf_putnbr_dec;
	fct[u - 117 + 5] = pf_utoa;
	fct[x - 120 + 6] = pf_putnbr_hex;
	fct[X - 88 + 7] = pf_putnbr_hex;
	fct[sp - 32 + 8] = pf_putnbr_dec;
	fct[pl - 43 + 9] = pf_putnbr_dec;
	fct[x - 80] = pf_putnbr_hex;
	fct[X - 80] = pf_putnbr_hex;
	return (fct[j % 10](ap, j));
}*/

int	ft_format(va_list ap, int j)
{
	int	(*fct[122])(va_list, int);

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
	fct[x - 1] = pf_putnbr_hex;
	fct[X - 1] = pf_putnbr_hex;
	// return(fct[c](ap, 0));
	// if (j == x - 80 || j == X - 80)
		 
	return (fct[j](ap, j));
}
int	ft_print_step(const char *t, va_list ap)
{
	int			k;
	int			j;

	k = 0;
	j = 0;


	while (t[j])
	{
		if (t[j] == pc && id(t[++j]) < 10)
		{
			k += ft_format(ap, t[j]);
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

	k = 0;
	va_start(ap, s);
	k = ft_print_step(s, ap);
	va_end(ap);
	return (k);
}

// int	main(void)
// {
	// char *p[10];
	// char	*yo = "\n=====================================\n";

	// p[0] = "%%c%%s%%p%%d%%i%%u%%x%%X%%";
	// p[1] = "PF m | %c %s %+d % i";
	// printf(" | count :%d%s", printf(p[0], 'a', "hello", &p[0], 1, 1, 1, 1, 1),yo);
	// printf(" | count :%d%s", ft_printf(p[0]),yo);
	// printf(" | cnt :%d%s", printf(p[1],'c',"hello",2147,0),yo);
	// printf(" | cnt :%d%s", ft_printf("PF m | %c %s %+d % i",'c',"hello",2147,0),yo);
  	// printf(" | count :%d%s", printf("PF U : %u", 16), yo);
  	// printf(" | count :%d%s", ft_printf("FT U : %u", 16), yo);
	// printf(" | count :%d%s", printf("PF P : %p", &p), yo);
	// printf(" | count :%d%s", ft_printf("FT P : %p", &p), yo);
	// printf(" | count :%d%s", printf("PF P : %c", 'a'), yo);
	// printf(" | count :%d%s", ft_printf("FT P : %c", 'a'), yo);
	// printf(" | count :%d%s", printf("PF P : %s", "hello"), yo);
	// printf(" | count :%d%s", ft_printf("FT P : %s", "hello"), yo);
 	// printf(" | count :%d%s", printf("PF X : %#X", 0), yo);
 	// printf(" | count :%d%s", ft_printf("FT X : %#X", 0), yo);
	// printf(" | count :%d%s", printf("PF 0 %%"), yo);
	// printf(" | count :%d%s", ft_printf("FT 0 %%"), yo);
	// printf(" | count :%d%s", printf("PF sd : % d", 1), yo);
	// printf(" | count :%d%s", ft_printf("FT sd : % d", 1), yo);
	// printf(" | count :%d%s", printf("PF +d : %+d", 1), yo);
	// printf(" | count :%d%s", ft_printf("FT +d : %+d", 1), yo);
// 	ft_printf("%+i this is %i getting%+ix hard :/\n", (int)-2147486, -2, 42);
// 	printf("%+i this is %i getting%+ix hard :/\n", (int)-2147486, -2, 42);
// }
