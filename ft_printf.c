/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:50:36 by einterdi          #+#    #+#             */
/*   Updated: 2021/11/03 22:52:08 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int ft_argument(char c, int count)
{


	if (c == 'c')
		count += ft_prtint_c(ap);
	 if (c == 's')
	 	count += ft_putstr(s);
	// if (c == 'p')
	// 	count =
 	if (c == 'd' || 'i')
	 	count +=
	// if (c == 'u')
	// 	count =
	// if (c == 'x' || 'X')
	// 	count =
	// if (c == '%')
	// 	count =
}



int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int 	i;
	int 	count;
	char 	*istype;
	char	type;

	i = 0;
	istype = "cspdiuxX%";
	va_start(ap, str);
	while(str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while(str[i] != *ft_strchr(istype, str[i]))
				i++;
			type = str[i];
		}
		ft_putchar(str[i]);
		i++;
		count++;

	}
}
