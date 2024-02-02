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

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	i;

	i = -1;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[++i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
	}
	return (i);
}

int	ft_int(int number)
{
	int		tmp;
	int		len;
	long	n;

	n = number;
	len = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len++;
		n *= -1;
	}
	if (n >= 10)
	{
		tmp = ft_int(n / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (len + 1);
}

int	ft_u_int(unsigned int number)
{
	int	len;
	int	tmp;

	len = 0;
	if (number >= 10)
	{
		tmp = ft_u_int(number / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (ft_putchar((number % 10) + '0') == -1)
		return (-1);
	return (len + 1);
}

int	ft_hex_nbr(unsigned long long int number, char c)
{
	int	tmp;
	int	len;

	len = 0;
	if (number > 15)
	{
		tmp = ft_hex_nbr(number / 16, c);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (number % 16 < 10)
	{
		if (ft_putchar((number % 16) + '0') == -1)
			return (-1);
	}
	else if (ft_putchar((number % 16) + c) == -1)
		return (-1);
	return (len + 1);
}
