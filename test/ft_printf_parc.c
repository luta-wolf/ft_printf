/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:50:36 by einterdi          #+#    #+#             */
/*   Updated: 2021/11/07 17:17:57 by einterdi         ###   ########.fr       */
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
	int		width;
	int 	pres;
	int		point;
	char	type;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			type = '\0';
			width = 0;
			pres = 0;
			point = 0;
			while (!type && str[i])
			{
				if(str[i] == 'c' || str[i] == 's' || str[i] == 'd' \
				|| str[i] == 'i' || str[i] == 'u' || str[i] == 'x' \
				|| str[i] == 'X' || str[i] == 'p' || str[i] == '%')
					type = str[i];
				else if (str[i] >= 0 && str[i] <= 9)
				{
					width = 0;
					while (str[i] >= 0 && str[i] <= 9)
					{
						width = width * 10 + str[i] - '0';
						i++;
					}
				}
				else if (str[i] == '.')
				{
					pres = 0;
					point = 1;
					i++;
					while (str[i] >= 0 && str[i] <= 9)
					{
						pres = pres * 10 + str[i] - '0';
						i++;
					}
				}
				else
					i++;
			}
			if (!str[i])
				break ;
			*count += specific(type, ap);
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
