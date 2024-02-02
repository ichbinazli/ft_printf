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
	else if (c == 'x')
		return (ft_hex_nbr(va_arg((*args), unsigned int), 'a' - 10));
	else if (c == 'X')
		return (ft_hex_nbr(va_arg((*args), unsigned int), 'A' - 10));
	else if (c == 'p')
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		return (ft_hex_nbr(va_arg((*args), unsigned long int), 'a' - 10) + 2);
	}
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		tmp;
	int		leng;

	count = -1;
	leng = 0;
	va_start (args, str);
	while (str[++count] != '\0')
	{
		if (str[count] == '%' && ft_flag_check(str[count + 1]))
		{
			tmp = ft_format(&args, str[++count]);
			if (tmp == -1)
				return (-1);
			leng += tmp - 1;
		}
		else if (str[count] == '%')
			leng--;
		else if (ft_putchar(str[count]) == -1)
			return (-1);
		leng++;
	}
	va_end(args);
	return (leng);
}
