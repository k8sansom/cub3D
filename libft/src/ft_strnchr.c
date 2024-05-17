/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:02:03 by fszendzi          #+#    #+#             */
/*   Updated: 2024/02/01 22:02:06 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strnchr(char *str, int c, int n)
{
	int	i;

	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}
