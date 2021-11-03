/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:50:36 by einterdi          #+#    #+#             */
/*   Updated: 2021/11/02 23:14:57 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

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
			while(str[i] != istype)
				i++;
			type = str[i];
		}
		ft_putchar(str[i]);
		i++;
		count++;

	}
}
