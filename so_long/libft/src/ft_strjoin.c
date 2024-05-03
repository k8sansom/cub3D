/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:38:34 by ksansom           #+#    #+#             */
/*   Updated: 2023/05/12 16:39:05 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	if (s1 == 0 || s2 == 0)
		return (0);
	j = 0;
	i = 0;
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (0);
	while (s1[i] != '\0')
		join[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		join[j++] = s2[i++];
	join[j] = '\0';
	return (join);
}
