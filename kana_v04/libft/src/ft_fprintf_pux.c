/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:29:27 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/15 10:40:01 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_print_pointer_fd(int fd, const void *ptr)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		write (fd, "(nil)", 5);
		return (5);
	}
	write (fd, "0x", 2);
	len = 2;
	len += ft_print_pval_fd(fd, ptr);
	return (len);
}

int	ft_print_pval_fd(int fd, const void *ptr)
{
	char			rev[17];
	int				i;
	unsigned long	pval;
	int				len;
	char			*hex_low;

	hex_low = "0123456789abcdef";
	i = 0;
	len = 0;
	pval = (unsigned long)ptr;
	while (pval >= 16)
	{
		rev[i] = hex_low[pval % 16];
		pval = pval / 16;
		i++;
	}
	rev[i] = hex_low[pval];
	while (i >= 0)
	{
		write(fd, &rev[i], 1);
		i--;
		len++;
	}
	return (len);
}

int	ft_print_hex_low_fd(int fd, unsigned int nb)
{
	char	rev[17];
	int		i;
	int		len;
	char	*hex_low;

	hex_low = "0123456789abcdef";
	i = 0;
	while (nb >= 16)
	{
		rev[i] = hex_low[nb % 16];
		nb = nb / 16;
		i++;
	}
	rev[i] = hex_low[nb];
	len = 0;
	while (i >= 0)
	{
		write(fd, &rev[i], 1);
		i--;
		len++;
	}
	return (len);
}

int	ft_print_hex_up_fd(int fd, unsigned int nb)
{
	char	rev[17];
	int		i;
	int		len;
	char	*hex_up;

	hex_up = "0123456789ABCDEF";
	i = 0;
	while (nb >= 16)
	{
		rev[i] = hex_up[nb % 16];
		nb = nb / 16;
		i++;
	}
	rev[i] = hex_up[nb];
	len = 0;
	while (i >= 0)
	{
		write(fd, &rev[i], 1);
		i--;
		len++;
	}
	return (len);
}

int	ft_print_unsigned_int_fd(int fd, unsigned int nb)
{
	int	i;

	i = 0;
	ft_putunsigned_fd(fd, nb);
	if (!nb)
		return (1);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
