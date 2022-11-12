/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:10:18 by eestelle          #+#    #+#             */
/*   Updated: 2021/10/14 20:30:28 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst < dstsize - 1 && dstsize > 0)
	{
		if (len_dst + len_src < dstsize)
			ft_strlcpy(dst + len_dst, src, len_src + 1);
		else
			ft_strlcpy(dst + len_dst, src, dstsize - len_dst);
	}
	if (len_dst >= dstsize)
		len_dst = dstsize;
	return (len_dst + len_src);
}
