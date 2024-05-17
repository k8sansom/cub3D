/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:07:06 by ksansom           #+#    #+#             */
/*   Updated: 2023/05/12 18:07:09 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*dest;

	len = ft_strlen(s) + 1;
	i = 0;
	dest = (char *)malloc(sizeof(char) * len);
	if (!dest)
		return (0);
	while (s[i])
	{
		((unsigned char *)dest)[i] = ((unsigned char *)s)[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
