/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:44:13 by eestelle          #+#    #+#             */
/*   Updated: 2021/10/14 19:59:17 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef unsigned long long	t_ull;

static	void	ft_fast_completion(char *bdest, char *bsrc, size_t n)
{
	t_ull	*ptr_dest;
	t_ull	*ptr_src;
	size_t	len;

	ptr_dest = (t_ull *)bdest;
	ptr_src = (t_ull *)bsrc;
	len = n / 8;
	while (len--)
		*(ptr_dest++) = *(ptr_src++);
	bdest = (char *)ptr_dest;
	bsrc = (char *)ptr_src;
	len = n % 8;
	while (len--)
		*(bdest++) = *(bsrc++);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*bptr_dest;
	char	*bptr_src;

	if (dest == src || n == 0)
		return (dest);
	bptr_dest = (char *)dest;
	bptr_src = (char *)src;
	while ((size_t)bptr_dest % 8 && n)
	{
		*(bptr_dest++) = *(bptr_src++);
		n--;
	}
	if (n == 0)
		return (dest);
	ft_fast_completion(bptr_dest, bptr_src, n);
	return (dest);
}
