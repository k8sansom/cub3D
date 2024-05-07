/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:29:15 by ksansom           #+#    #+#             */
/*   Updated: 2024/01/08 11:20:27 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char	*ft_strndup(const char *src, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (0);
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_count_splits(const char *str, char c)
{
	int	i;
	int	trigger;
	int	count;

	i = 0;
	trigger = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (str[i] == c)
			trigger = 0;
		i++;
	}
	return (count);
}

static int	ft_free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free (arr);
	return (1);
}

static int	ft_actual(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		k;

	i = 0;
	k = -1;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			arr[++k] = ft_strndup(&s[j], i - j);
			if (!arr[k])
				return (ft_free_arr(arr));
		}
	}
	++k;
	arr[k] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		splits;

	splits = ft_count_splits(s, c);
	arr = (char **)malloc(sizeof(char *) * (splits + 1));
	if (!arr || !s)
		return (0);
	if (ft_actual(arr, s, c) == 1)
		return (NULL);
	return (arr);
}
