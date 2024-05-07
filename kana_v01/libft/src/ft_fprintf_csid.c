/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:29:47 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/15 10:39:52 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_print_char_fd(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_print_str_fd(int fd, const char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!str)
	{
		write (fd, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		len += ft_print_char_fd(fd, str[i]);
		i++;
	}
	return (len);
}

void	ft_putnbr_fd(int fd, int n)
{
	unsigned int	nb;
	char			c;

	if (n < 0)
	{
		write(fd, "-", 1);
		nb = -n;
	}
	else
		nb = n;
	while (nb > 9)
	{
		ft_putnbr_fd(fd, nb / 10);
		nb %= 10;
	}
	c = nb + '0';
	write(fd, &c, 1);
}

int	ft_print_int_fd(int fd, int n)
{
	int				i;
	unsigned int	num;

	ft_putnbr_fd(fd, n);
	if (!n)
	{
		return (1);
	}
	else if (n < 0)
	{
		i = 1;
		num = -n;
	}
	else
	{
		i = 0;
		num = n;
	}
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

void	ft_putunsigned_fd(int fd, unsigned int nb)
{
	char	c;

	while (nb > 9)
	{
		ft_putunsigned_fd(fd, nb / 10);
		nb %= 10;
	}
	c = nb + '0';
	write(fd, &c, 1);
}
