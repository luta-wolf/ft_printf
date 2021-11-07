/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:46:06 by einterdi          #+#    #+#             */
/*   Updated: 2021/11/07 03:19:40 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_size_nbr(int n)
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

int	ft_size_nbr_u(unsigned int n)
{
	int		len;
	long	i;

	i = (long)n;

	len = 0;
	while (i > 0)
	{
		i = i / 10;
		len++;
	}
	if (n > 0)
		return (len);
	else 
		return (1);
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

void	ft_putnbr_u(unsigned int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	char tmp = n % 10 + '0';
	write(1, &tmp, 1);

}

int	ft_size_nbr_hex(unsigned long long n)
{
	int				len;
	unsigned long long	i;

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

void    ft_putnbr_hex(unsigned long long n, char c)
{
    char	tmp;

    if (n >= 16)
        ft_putnbr_hex(n / 16, c);
    if ((n % 16) >= 0 && (n % 16) <= 9)
        tmp = n % 16 + '0';
    else if (c == 'x')
       tmp = n % 16 + 'a' - 10;
	else if (c == 'X')
       tmp = n % 16 + 'A' - 10;
    write(1, &tmp, 1);
}


