/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:46:55 by ksansom           #+#    #+#             */
/*   Updated: 2023/05/12 16:28:27 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putnbr_fd(int n, int fd)
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
		ft_putnbr_fd((nb / 10), fd);
		nb %= 10;
	}
	c = nb + '0';
	write(fd, &c, 1);
}
