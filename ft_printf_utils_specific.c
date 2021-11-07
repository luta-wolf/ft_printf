/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_specific.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 00:06:40 by einterdi          #+#    #+#             */
/*   Updated: 2021/11/07 03:01:15 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(va_list	ap)
{
	char c;
	c = va_arg(ap, int);
	return (write(1, &c, 1));
}

int ft_print_s(va_list ap)
{
	char	*str;

	str = va_arg(ap, char*);
	if (!str)
		return (write(1, "(null)", 6));
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int ft_print_diu(va_list	ap, char type)
{
	long int c;
	unsigned int a;

	if (type == 'd' || type == 'i')
	{
		c = va_arg(ap, int);
		ft_putnbr(c);
		return (ft_size_nbr(c));
	}
	else
	{
		a = va_arg(ap, unsigned int);
		ft_putnbr_u(a);
		return (ft_size_nbr_u(a));
	}
}

int ft_print_p(va_list	ap)
{
	long int c;
	unsigned long long a;

	c = (long int)va_arg(ap, void*);
	a = (unsigned long long)c;
	write(1, "0x", 2);
	ft_putnbr_hex(a, 'x');
	return (ft_size_nbr_hex(a) + 2);
}

int	ft_print_x(va_list	ap, char a)
{
	unsigned int c;
	c = va_arg(ap, unsigned int);
	ft_putnbr_hex(c, a);
	return (ft_size_nbr_hex(c));
}
