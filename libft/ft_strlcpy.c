/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:41:21 by eestelle          #+#    #+#             */
/*   Updated: 2021/10/07 14:18:12 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize - 1 && src[i] && dstsize > 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
/*
typedef unsigned long long  t_ull;
static t_ull    *ft_completion(t_ull *dest, t_ull **src, size_t len)
{
	size_t	i;

	while (len-- && src[i])
	{
		i = 0;
		while (i < 8 && (*src)[i])
			(dest++)[i] = ((*src)++)[i];
		}
		return (dest);
	}

void    *ft_strlcpy(void *dest, const void *src, size_t n)
{
	t_ull   *ptr_dest;
	t_ull   *ptr_src;
	char    *bptr_dest;
	char    *bptr_src;
	size_t  len;

	if (dest == src || n == 0)
		return (dest);
	bptr_dest = (char *)dest;
	bptr_src = (char *)src;
	while ((size_t)bptr_dest % 8 && n-- && *(bptr_src))
		*(bptr_dest++) = *(bptr_src++);
	ptr_dest = (t_ull *)bptr_dest;
	ptr_src = (t_ull *)src; 
	len = (n) / 64; 
	if (len)
		ptr_dest = ft_completion(ptr_dest, &ptr_src, len);
	len = (n % 64) / 8;
	while (len--)
		*(ptr_dest++) = *(ptr_src++);
	bptr_dest = (char *)ptr_dest;
	bptr_src = (char *)ptr_src;
	len = n % 8;
	while (len--)
		*(bptr_dest++) = *(bptr_src++);
	return (dest);
}
*/
