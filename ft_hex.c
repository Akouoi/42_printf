/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:45:14 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/08 14:33:54 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_itoa_base(unsigned long long int n, char *base)
{
	unsigned long long int	base_len;
	int						n_len;
	char					*str;

	base_len = pf_strlen(base);
	n_len = pf_nblen(n, base_len);
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
	write(1, str, pf_strlen(str));
	return (str);
}

int	pf_putnbr_hex(va_list ap, int k)
{
	unsigned int	n;
	int				n_len;
	char			*base;
	char			*str;

	n_len = 0;
	n = va_arg(ap, unsigned int);
	if (n == 0 && k < X)
		return (0);
	if (k == x - 1 || k == x)
		base = "0123456789abcdef";
	if (n != 0 && k == x - 80)
		n_len += write (1, "x", 1);
	if (k == X - 1 || k == X)
		base = "0123456789ABCDEF";
	if (n != 0 && k == X - 80)
		n_len += write (1, "X", 1);
	str = pf_itoa_base(n, base);
	n_len += pf_strlen(str);
	free(str);
	return (n_len);
}

int	pf_point(va_list ap, int k)
{
	unsigned long long int	n;
	int						n_len;
	char					*str;

	if (k == p)
		n = va_arg(ap, unsigned long long int);
	if (n == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	str = pf_itoa_base(n, "0123456789abcdef");
	n_len = pf_strlen(str);
	free(str);
	return (2 + n_len);
}
