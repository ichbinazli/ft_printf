/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naanapa <naanapa@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:34:19 by naanapa           #+#    #+#             */
/*   Updated: 2024/01/30 15:56:32 by naanapa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_print_str(char *str);
int	ft_int(int number);
int	ft_u_int(unsigned int number);
int	ft_hex_nbr(unsigned long long int number, char c);
int	ft_point(unsigned long long a, int sign);
int	ft_format(va_list *args, const char c);
int	ft_flag_check(char str);

#endif
