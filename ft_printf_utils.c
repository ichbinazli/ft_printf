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
	int		len;
	int		temp;
	long	n;

	len = 0;
	n = number;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n *= -1;
		len++;
	}
	if (n > 9)
	{
		temp = ft_int(n / 10);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (write(1, &"0123456789"[n % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_u_int(unsigned int number)
{
	int	len;
	int	temp;

	len = 0;
	if (number > 9)
	{
		temp = ft_u_int(number / 10);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (write(1, &"0123456789"[number % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_hex_nbr(unsigned int number, char c)
{
	int	len;
	int	temp;

	len = 0;
	if (number >= 16)
	{
		temp = ft_hex_nbr(number / 16, c);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (c == 'X')
	{
		if (write(1, &"0123456789ABCDEF"[number % 16], 1) == -1)
			return (-1);
	}
	if (c == 'x')
	{
		if (write(1, &"0123456789abcdef"[number % 16], 1) == -1)
			return (-1);
	}
	return (len + 1);
}

int	ft_point(unsigned long number, int i)
{
	int	len;
	int	temp;

	len = 0;
	if (i == 1)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		i = 0;
		len += 2;
	}
	if (number >= 16)
	{
		temp = ft_point(number / 16, i);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (write(1, &"0123456789abcdef"[number % 16], 1) == -1)
		return (-1);
	return (len + 1);
}
