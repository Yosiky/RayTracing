/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:36:22 by eestelle          #+#    #+#             */
/*   Updated: 2021/10/14 18:59:55 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_completion(char *result, long long n, size_t len)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	while (n)
	{
		result[len - 1 - i] = (n % 10) + '0';
		i++;
		n /= 10;
	}
	result[len] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char		*result;
	size_t		len;
	long long	value;

	len = 0;
	value = n;
	if (n < 0)
		len++;
	while (value && ((len++) || 1))
		value /= 10;
	if (n == 0)
		return (ft_strdup("0"));
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	ft_completion(result, n, len);
	return (result);
}
