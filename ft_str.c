/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:52:20 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/08 14:31:51 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putstr(va_list ap, int k)
{
	char	*str;

	k = 0;
	str = va_arg(ap, void *);
	if (!str)
		return (write(1, "(null)", 6));
	while (str[k])
		k += write (1, &str[k], 1);
	return (k);
}

int	pf_putchar(va_list ap, int k)
{
	int	ch;

	if (k)
		ch = va_arg(ap, int);
	return (write(1, &ch, 1));
}

size_t	pf_strlen(const char *str)
{
	size_t	k;

	if (!str)
		return (0);
	k = 0;
	while (str[k])
		k++;
	return (k);
}

int	pf_nblen(unsigned long long int n, unsigned long long int base_len)
{
	int	power;

	power = 0;
	while (n >= base_len)
	{
		power++;
		n /= base_len;
	}
	return (power + 1);
}
