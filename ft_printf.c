/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:50:36 by einterdi          #+#    #+#             */
/*   Updated: 2021/11/07 17:23:47 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specific(char type, va_list ap)
{
	int	count;

	count = 0;
	if (type == 'c')
		count = ft_print_c(ap);
	else if (type == 's')
		count = ft_print_s(ap);
	else if (type == 'd' || type == 'i' || type == 'u')
		count = ft_print_di(ap, type);
	else if (type == 'x' || type == 'X')
		count = ft_print_x(ap, type);
	else if (type == 'p')
		count = ft_print_p(ap);
	else
		count = write(1, &type, 1);
	return (count);
}

void	ft_count(va_list ap, char *str, int *count)
{
	int		i;
	char	*istype;

	istype = "cspdiuxX%";
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (!ft_strchr(istype, str[i]) && str[i])
				i++;
			if (!str[i])
				break ;
			*count += specific(str[i], ap);
		}
		else
			*count += write(1, &str[i], 1);
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, str);
	ft_count(ap, (char *)str, &count);
	va_end(ap);
	return (count);
}
