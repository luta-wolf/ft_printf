/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utis_dixX.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:46:06 by einterdi          #+#    #+#             */
/*   Updated: 2021/11/04 19:04:21 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	size_nbr(int n)
{
	int		len;
	long	i;

	i = (long)n;
	if (n < 0)
		i = (long)n * -1;
	len = 0;
	while (i > 0)
	{
		i = i / 10;
		len++;
	}
	if (n > 0)
		return (len);
	else if (n == 0)
		return (1);
	else
		return (len + 1);
}

void	ft_putnbr(long int n)
{

	if (n < 0)
	{
		write (1, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	char tmp = n % 10 + '0';
	write(1, &tmp, 1);

}

int	size_nbr_hex(unsigned int n)
{
	int				len;
	unsigned int	i;

	i = n;
	len = 0;
	while (i > 0)
	{
		i = i / 16;
		len++;
	}
	if (n == 0)
		return (1);
	return (len);
}

void    ft_putnbr_hex(unsigned int n)
{
    char	tmp;

    if (n >= 16)
        ft_putnbr_hex(n / 16);
    if ((n % 16) >= 0 && (n % 16) <= 9)
        tmp = n % 16 + '0';
    else
       tmp = n % 16 + 'a' - 10;
    write(1, &tmp, 1);
}

int ft_print_di(va_list	ap)
{
	int c;
	c = va_arg(ap, int);
	ft_putnbr(c);
	return (size_n(c));
}
