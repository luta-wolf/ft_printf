/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 23:13:02 by einterdi          #+#    #+#             */
/*   Updated: 2021/11/07 04:23:35 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

int	ft_print_c(va_list	ap)
{
	char	c;

	c = va_arg(ap, int);
	return (write(1, &c, 1));
}

void	ft_putnbr_u(unsigned int n)
{
	char	tmp;

	if (n >= 10)
		ft_putnbr(n / 10);
	tmp = n % 10 + '0';
	write(1, &tmp, 1);
}
