/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:07:18 by eestelle          #+#    #+#             */
/*   Updated: 2021/10/14 20:35:21 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- && *s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	if (!(n + 1))
		return (0);
	return (*((unsigned char *)s1) - *((unsigned char *)s2));
}
