/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:24:46 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/30 13:24:47 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

bool	ft_isdir(char *map)
{
	int		fd;

	fd = open(map, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		return (true);
	}
	return (false);
}
