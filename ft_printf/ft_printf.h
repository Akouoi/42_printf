#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>

int	ft_putstr(va_list ap);
int	ft_putchar(va_list ap);
size_t	ft_strlen(const char *str);
int	ft_nblen(unsigned long long int n, unsigned long long int base_len);
char	*ft_itoa(int n, char *base);
int	ft_putnbr_dec(va_list ap);
char	*ft_itoa_base(unsigned long long int n, char *base);
int	ft_putnbr_hex(va_list ap);
int	ft_putnbr_hexm(va_list ap);
int 	ft_printf(const char *s, ...);
int	ft_format(va_list ap, int i);
int	ft_point(va_list ap);
int	ft_index(char c);
int	ft_utoa(va_list ap);

#endif