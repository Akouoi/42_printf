/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:52:09 by akouoi            #+#    #+#             */
/*   Updated: 2022/05/19 18:06:13 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n, char *base)
{
	char	*str;
	int		sign;
	int		n_len;
	int		base_len;

	base_len = ft_strlen(base);
	sign = 1 - 2 * (n < 0);
	n *= sign;
	n_len = ft_nblen(n, base_len);
	str = malloc((n_len + 1 + (sign < 0)) * sizeof(char));
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

int	ft_putnbr_dec(va_list ap, int i)
{
	char	*str;
	int		n_len;
	int		n;

	n_len = 0;
	n = va_arg(ap, int);
	if (n > 0)
	{
		if (i == 8)
			n_len += write(1, " ", 1);
		if (i == 9)
			n_len += write(1, "+", 1);
	}
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	str = ft_itoa(n, "0123456789");
	n_len += ft_strlen(str);
	free(str);
	return (n_len);
}

char	*ft_itoa_base(unsigned long long int n, char *base)
{
	unsigned long long int	base_len;
	int						n_len;
	char					*str;

	base_len = ft_strlen(base);
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

int	ft_putnbr_hex(va_list ap, int i)
{
	unsigned int	n;
	int				n_len;
	char			*base;
	char			*str;

	n_len = 0;
	n = va_arg(ap, unsigned int);
	if (n == 0 && i > 10)
		return (0);
	if (i % 10 == 6)
		base = "0123456789abcdef";
	if (n != 0 && i == 16)
		n_len += write (1, "x", 1);
	if (i % 10 == 7)
		base = "0123456789ABCDEF";
	if (n != 0 && i == 17)
		n_len += write (1, "X", 1);
	str = ft_itoa_base(n, base);
	n_len += ft_strlen(str);
	free(str);
	return (n_len);
}
