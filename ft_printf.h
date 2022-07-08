/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:52:24 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/08 11:20:36 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>

typedef	struct s_arg
{
	va_list	ap;
	char	*str;
	int		k;
}	t_arg;

enum e_move
{
	c = 99,
	s = 115,
	p = 112,
	d = 100,
	i = 105,
	u = 117,
	x = 120,
	X = 88,
	sp = 32,
	pc = 37,
	ht = 35,
	pl = 43,
};

//---------------------------------------------------------------------------------------
//		ft_dec.c
//---------------------------------------------------------------------------------------

char	*pf_itoa(int n, char *base);

int		pf_putnbr_dec(va_list ap, int i);

int		pf_utoa(va_list ap, int i);

//---------------------------------------------------------------------------------------
//		ft_hex.c
//---------------------------------------------------------------------------------------

char	*pf_itoa_base(unsigned long long int n, char *base);

int		pf_putnbr_hex(va_list ap, int i);

int		pf_point(va_list ap, int i);

//---------------------------------------------------------------------------------------
//		ft_str.c
//---------------------------------------------------------------------------------------

int		pf_putstr(va_list ap, int i);

int		pf_putchar(va_list ap, int i);

int		pf_nblen(unsigned long long int n, unsigned long long int base_len);

size_t	pf_strlen(const char *str);

//---------------------------------------------------------------------------------------
//		ft_printf.c
//---------------------------------------------------------------------------------------

int		ft_printf(const char *s, ...);

int		id(char c);

int		ft_format(va_list ap, int i);

#endif
