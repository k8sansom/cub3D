/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:03:56 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/15 10:40:09 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_search_args(va_list arg, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		return (len += ft_print_char(va_arg(arg, int)));
	else if (c == 's')
		return (len += ft_print_str(va_arg(arg, const char *)));
	else if (c == 'p')
		return (len += ft_print_pointer(va_arg(arg, const void *)));
	else if (c == 'd' || c == 'i')
		return (len += ft_print_int(va_arg(arg, int)));
	else if (c == 'u')
		return (len += ft_print_unsigned_int(va_arg(arg, unsigned int)));
	else if (c == 'x')
		return (len += ft_print_hex_low(va_arg(arg, unsigned int)));
	else if (c == 'X')
		return (len += ft_print_hex_up(va_arg(arg, unsigned int)));
	else if (c == '%')
		return (len += ft_print_char('%'));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	arg;

	if (!format)
		return (-1);
	va_start(arg, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && ((format[i + 1] == 'c' || format[i + 1] == 'd'\
			|| format[i + 1] == 'i' || format[i + 1] == 'x' || \
			format[i + 1] == 'X' || format[i + 1] == 'p' || \
			format[i + 1] == 'u' || format[i + 1] == '%' || \
			format[i + 1] == 's')))
		{
			len += ft_search_args(arg, format[i + 1]);
			i++;
		}
		else
			len += ft_print_char(format[i]);
		i++;
	}
	return (len);
}
