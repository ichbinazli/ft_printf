/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naanapa <naanapa@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:34:44 by naanapa           #+#    #+#             */
/*   Updated: 2024/02/01 14:25:53 by naanapa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_flag_check(char str)
{
	return (str == 'c' || str == 's' || str == 'p' || str == 'd' || str == 'i'
		|| str == 'u' || str == 'x' || str == 'X' || str == '%');
}

int	ft_format(va_list *args, const char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg ((*args), int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'd' || c == 'i')
		return (ft_int(va_arg ((*args), int)));
	else if (c == 's')
		return (ft_print_str(va_arg ((*args), char *)));
	else if (c == 'u')
		return (ft_u_int(va_arg ((*args), unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_hex_nbr(va_arg((*args), unsigned int), c));
	else if (c == 'p')
		return (ft_point(va_arg((*args), unsigned long), 1));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len;
	int		i;
	int		value;

	len = 0;
	i = -1;
	va_start(arg, str);
	while (str[++i])
	{
		if (str[i] == '%' && ft_flag_check(str[i + 1]))
		{
			value = ft_format(&arg, str[++i]);
			if (value == -1)
				return (-1);
			len += value;
		}
		else if (str[i] != '%' && ft_putchar(str[i]) == -1)
			return (-1);
		else if (str[i] != '%')
			len++;
	}
	va_end(arg);
	return (len);
}
