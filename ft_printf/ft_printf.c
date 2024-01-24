/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naanapa <naanapa@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:34:44 by naanapa           #+#    #+#             */
/*   Updated: 2024/01/24 16:28:48 by naanapa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_data(va_list *args, const char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg((*args), int)));
	else if (c == 's')
		return (ft_print_str(va_arg((*args), char *)));
	else if (c == 'p')
		return (ft_point(va_arg((*args), unsigned long long), 1));
	else if (c == 'd' || c == 'i')
		return (ft_int(va_arg((*args), int)));
	else if (c == 'u')
		return (ft_u_int(va_arg((*args), unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_hex_nbr(va_arg((*args), unsigned int), c));
	else
		return (ft_putchar('%'));
}

int	ft_flag_check(const char *str, int i)
{
	return (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 'd'
			|| str[i + 1] == 'i' || str[i + 1] == 'u' || str[i + 1] == 'x'
			|| str[i + 1] == 'X' || str[i + 1] == 'p' || str[i + 1] == 's'
			|| str[i + 1] == '%'));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		rtn;

	rtn = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (ft_flag_check(str, i))
		{
			rtn += ft_print_data(&args, str[i + 1]);
			i++;
		}
		else if (str[i] != '%')
			rtn += write(1, &str[i], 1);
		i++;
	}
	return (rtn);
}
