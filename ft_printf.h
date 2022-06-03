/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:52:24 by akouoi            #+#    #+#             */
/*   Updated: 2022/05/23 13:12:52 by akouoi           ###   ########.fr       */
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

int		ft_putstr(va_list ap, int i);
int		ft_putchar(va_list ap, int i);
size_t	ft_strlen(const char *str);
int		ft_nblen(unsigned long long int n, unsigned long long int base_len);
char	*ft_itoa(int n, char *base);
int		ft_putnbr_dec(va_list ap, int i);
char	*ft_itoa_base(unsigned long long int n, char *base);
int		ft_putnbr_hex(va_list ap, int i);
int		ft_putnbr_hexm(va_list ap, int i);
int		ft_printf(const char *s, ...);
int		ft_format(va_list ap, int i);
int		ft_point(va_list ap, int i);
int		id(char c);
int		ft_utoa(va_list ap, int i);

#endif
