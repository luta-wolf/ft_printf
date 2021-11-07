/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_specific.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 00:06:40 by einterdi          #+#    #+#             */
/*   Updated: 2021/11/07 03:46:38 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_s(va_list ap)
{
	char	*str;

	str = va_arg(ap, char*);
	if (!str)
		return (write(1, "(null)", 6));
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int ft_print_di(va_list	ap)
{
	long int c;

	c = va_arg(ap, int);
	ft_putnbr(c);
	return (ft_size_nbr(c));
}

int ft_print_u(va_list	ap)
{
	unsigned int c;

	c = va_arg(ap, unsigned int);
	ft_putnbr_u(c);
	return (ft_size_nbr_u(c));
}

int	ft_print_x(va_list	ap, char type)
{
	unsigned int c;
	
	c = va_arg(ap, unsigned int);
	ft_putnbr_hex(c, type);
	return (ft_size_nbr_hex(c));
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
