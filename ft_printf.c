/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:50:36 by einterdi          #+#    #+#             */
/*   Updated: 2021/11/07 03:44:15 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	ft_argument(char type,  va_list ap)
{
	int count = 0;

	if (type == 'c')
		count = ft_print_c(ap);
	else if (type == 's')
	 	count = ft_print_s(ap);
 	else if (type == 'd' || type  == 'i')
	  	count = ft_print_di(ap);
	else if (type == 'u')
	  	count = ft_print_u(ap);
	else if (type == 'x' || type  == 'X')
	  	count = ft_print_x(ap, type);
	else if (type == 'p')
	  	count = ft_print_p(ap);
	else
		count = write(1, &type, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int 	i;
	int 	count;
	char 	*istype;

	i = 0;
	count = 0;
	istype = "cspdiuxX%";
	va_start(ap, str);
	while(str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while(!ft_strchr(istype, str[i]) && str[i])
				i++;
			if(!str[i])
				break ;
			count += ft_argument(str[i], ap);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
