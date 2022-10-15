/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:40:45 by eestelle          #+#    #+#             */
/*   Updated: 2021/10/14 20:34:01 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	skip_begin(char const **s1, char const *set)
{
	while (**s1 && ft_strchr(set, **s1) != (void *)0)
		(*s1)++;
}

static	size_t	skip_end(char const *s1, char const *set, size_t i)
{
	while (i > 0 && ft_strrchr(set, s1[i - 1]) != (void *)0)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	skip_begin(&s1, set);
	end = ft_strlen(s1);
	if (end)
		end = skip_end(s1, set, end);
	result = (char *)malloc(sizeof(char) * (end + 1));
	if (result == NULL)
		return (result);
	ft_strlcpy(result, s1, end + 1);
	return (result);
}
