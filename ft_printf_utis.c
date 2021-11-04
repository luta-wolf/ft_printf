/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 23:13:02 by einterdi          #+#    #+#             */
/*   Updated: 2021/11/04 18:50:25 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_c(va_list	ap)
{
	char c;
	c = va_arg(ap, int);
	return (write(1, &c, 1));
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int ft_print_s(va_list ap)
{
	char *str;
	str = va_arg(ap, char*);
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

/*void	ft_putnbr(int n)
{
	char tmp;

	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = n * -1;
		}
		if (n >= 10)
			ft_putnbr(n / 10);
		tmp = (n % 10) + '0';
		write (1, &tmp, 1);
	}
}*/

char	*ft_strchr(const char *str, int ch)
{
	while (*str != '\0')
	{
		if ((unsigned char)*str == (unsigned char)ch)
			return ((char *)str);
		str++;
	}
	if (ch == 0)
		return ((char *)str);
	return (NULL);
}
