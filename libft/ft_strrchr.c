/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:30:38 by eestelle          #+#    #+#             */
/*   Updated: 2021/10/14 12:28:12 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*iter;

	iter = NULL;
	while (*s)
	{
		if (*s == (char)c)
			iter = (char *)s;
		s++;
	}
	if (*s == (char)c)
		iter = (char *)s;
	return (iter);
}
