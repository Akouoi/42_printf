
#include "ft_printf.h"

char	*ft_itoa(int n, char *base)
{
	char	*str;
	int		sign;
	int		n_len;
	int	base_len = ft_strlen(base);

	sign = 1 - 2 * (n < 0);
	n *= sign;
	n_len = ft_nblen(n, base_len);
	str = malloc((n_len + 1 + (sign < 0))* sizeof(char));
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

int	ft_putnbr_dec(va_list ap)
{
	long int	n;
	char	*base = "0123456789";
	char	*str;
	int	n_len;

	n = va_arg(ap, int);
	if (n == -2147483648)
		return(write(1, "-2147483648", 11));
	str = ft_itoa(n, base);
	n_len = ft_strlen(str);
	free(str);
	return (n_len);
}

char	*ft_itoa_base(unsigned long long int n, char *base)
{
	char	*str;
	unsigned long long int	base_len = ft_strlen(base);
	int	n_len;

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

int	ft_putnbr_hex(va_list ap)
{
	unsigned int	n;
	int	n_len;
	char *base = "0123456789abcdef";
	char	*str;

	n = va_arg(ap, unsigned int);
	str = ft_itoa_base(n, base);
	n_len = ft_strlen(str);
	free(str);
	return (n_len);
}

int	ft_putnbr_hexm(va_list ap)
{
	unsigned int	n;
	int	n_len;
	char *base = "0123456789ABCDEF";
	char	*str;

	n = va_arg(ap, unsigned int);
	str = ft_itoa_base(n, base);
	n_len = ft_strlen(str);
	free(str);
	return (n_len);
}
