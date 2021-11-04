/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:50:40 by einterdi          #+#    #+#             */
/*   Updated: 2021/11/04 16:54:33 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>

typedef struct s_flags
{
	int		f_minus;
	int		f_plus;
	int		f_zero;
	int		f_space;
	int		f_octothorpe;
	int		count;
	int		i;
	char	*type;
}			t_flags;


int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_strlen(const char *str);
int		ft_putstr(char *str);
char	*ft_strchr(const char *str, int ch);

int		ft_print_s(va_list ap);
int		ft_print_c(va_list ap);



#endif
