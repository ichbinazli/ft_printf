/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naanapa <naanapa@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:31:27 by naanapa           #+#    #+#             */
/*   Updated: 2024/02/01 14:30:43 by naanapa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_int(int number)
{
	int	rtn;

	rtn = 0;
	if (number == 0)
		return (write(1, "0", 1));
	if (number == -2147483648)
		return (write(1, "-2147483648", 11));
	if (number < 0)
	{
		rtn += write(1, "-", 1);
		number *= -1;
	}
	if (number > 9)
		rtn += ft_int(number / 10);
	write(1, &"0123456789"[number % 10], 1);
	return (rtn + 1);
}

int	ft_u_int(unsigned int number)
{
	int	rtn;

	rtn = 0;
	if (number > 9)
		rtn += ft_u_int(number / 10);
	write(1, &"0123456789"[number % 10], 1);
	return (rtn + 1);
}

int	ft_hex_nbr(unsigned int number, char c)
{
	int	rtn;

	rtn = 0;
	if (number > 15)
		rtn += ft_hex_nbr((number / 16), c);
	if (c == 'X')
		write(1, &"0123456789ABCDEF"[number % 16], 1);
	if (c == 'x')
		write(1, &"0123456789abcdef"[number % 16], 1);
	return (rtn + 1);
}

int	ft_point(unsigned long long a, int sign)
{
	int	rtn;

	rtn = 0;
	if (sign == 1)
	{
		rtn = write(1, "0x", 2);
		sign = 0;
	}
	if (a > 15)
		rtn += ft_point((a / 16), 0);
	write(1, &"0123456789abcdef"[a % 16], 1);
	return (rtn + 1);
}
