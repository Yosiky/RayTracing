/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:07:11 by eestelle          #+#    #+#             */
/*   Updated: 2021/10/14 19:18:27 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*bptr_s1;
	unsigned char	*bptr_s2;

	if (!n)
		return (0);
	bptr_s1 = (unsigned char *)s1;
	bptr_s2 = (unsigned char *)s2;
	while (n-- && *bptr_s1 == *bptr_s2)
	{
		bptr_s1++;
		bptr_s2++;
	}
	if (!(n + 1))
		return (0);
	return (*bptr_s1 - *bptr_s2);
}
