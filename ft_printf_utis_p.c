/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utis_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 00:06:40 by einterdi          #+#    #+#             */
/*   Updated: 2021/11/06 18:48:27 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int c;
	c = va_arg(ap, int);
	ft_putnbr_hex(c, a);
	return (ft_size_nbr_hex(c));
}
