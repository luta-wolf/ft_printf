/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:50:36 by einterdi          #+#    #+#             */
/*   Updated: 2021/11/04 18:55:39 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>

int ft_argument(char c,  va_list ap)
{
	int count;

	if (c == 'c')
		count = ft_print_c(ap);
	if (c == 's')
	 	count = ft_print_s(ap);
 	 if (c == 'd' || 'i')
	  	count = ft_print_di(ap);
	// if (c == 'p')
	//  	count = ft_print_p(ap);
	// if (c == 'u')
	//  	count = ft_print_u(ap);
	//  if (c == 'x' || 'X')
	//  	count = ft_print_x(ap, c);
	 if (c == '%')
	 	count = write(1, "%", 1);
	return (count);
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
			while(str[i])
			{
				if (ft_strchr(istype, str[i]))
				{
					count = ft_argument(str[i], ap);
					break;
				}
				i++;
			}
		}
		i++;
//		count++;
	}
	return (count);
}


int main()
{
	int a;
	char *b;
	int x = 0xf;

	b = "Hello my dear friend";

	a = ft_printf("My fun Decimal:%s\n", b);
	printf("%d\n", a);
	a = printf("My fun Decimal:%s\n", b);
	printf("%d\n", a);
	return (0);
}
