/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:43:38 by ksansom           #+#    #+#             */
/*   Updated: 2023/05/12 16:43:49 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static size_t	digit_count(long n)
{
	size_t	i;

	if (n > 0)
		i = 0;
	else
		i = 1;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*str;
	long	num;

	size = digit_count(n);
	if (n >= 0)
		num = n;
	else
		num = -(long)n;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	str[size--] = '\0';
	while (num > 0)
	{
		str[size--] = num % 10 + '0';
		num /= 10;
	}
	if (n == 0)
		str[size] = '0';
	else if (n < 0)
		str[size] = '-';
	return (str);
}

/*#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = -2147483648;
    char *str = ft_itoa(num);
    
    if (str != NULL)
    {
        printf("Integer: %d\n", num);
        printf("String: %s\n", str);
        free(str); // Remember to free the dynamically allocated memory
    }
    else
    {
        printf("Memory allocation failed.\n");
    }
    
    return 0;
}*/