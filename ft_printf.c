/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:50:36 by einterdi          #+#    #+#             */
/*   Updated: 2021/11/06 19:28:49 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>

int ft_argument(char c,  va_list ap)
{
	int count = 0;

	if (c == 'c')
		count = ft_print_c(ap);
	if (c == 's')
	{
	 	count = ft_print_s(ap);
		 printf("-|%d|-\n", count);
	}
 	 if (c == 'd' || c == 'i' || c == 'u')
	  	count = ft_print_di(ap, c);
	 if (c == 'p')
	  	count = ft_print_p(ap);
	if (c == 'x' || c == 'X')
	  	count = ft_print_x(ap, c);
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
	count = 0;
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
					count += ft_argument(str[i], ap);
					i++;
					break;
				}
				i++;
			}
		}
		write(1, &str[i], 1);
		i++;
		count++;
	}
	printf("||%d||\n", count);
	return (count);
}


int main()
{
	int a;
	char *b;
	char *c;
	int d;
	char e;

	a = 0;
	d = -25558;
	e = 'a';
	b = "Hello my dear friend ";

//	a = ft_printf("Myyy fun: %s %d %p %c %% \n", b, d, b, e);
	a = ft_printf("Myyy fun: %s", b);
//	printf("%d\n", a);
	//ft_printf("\n");
	a = 0;
//	a = printf("Orig fun: %s %d %p %c %% \n", b, d, b, e);
	a = printf("Orig fun: %s", b);
	printf("%d\n", a);
	return (0);
}
