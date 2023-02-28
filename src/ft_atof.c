/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:32:57 by eestelle          #+#    #+#             */
/*   Updated: 2023/02/27 23:33:31 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

static double	get_double_part(const char *str)
{
	double		dst;
	uint32_t	count;

	if (*str != '.')
		return (0);
	++str;
	dst = 0;
	count = 0;
	while (ft_isdigit(str[count]))
		++count;
	if (str[count] != 0)
		ee_error(4, "ERROR: not valid value in file\n");
	while (count-- > 0)
		dst = (dst + (str[count] - '0')) * 0.1;
	return (dst);
}

double	ft_atof(const char *str)
{
	double	dst;

	if (!ft_strncmp(str, "INF", 4) || !ft_strncmp(str, "inf", 4)
		|| !ft_strncmp(str, "-INF", 5) || !ft_strncmp(str, "-inf", 5))
		ee_error(4, "ERROR: not valid value in file\n");
	dst = (double)ft_atoi(str);
	if (*str == '-')
		++str;
	while (ft_isdigit(*str))
		++str;
	if (*str == '.')
		dst += get_double_part(str);
	else if (*str != 0)
		ee_error(4, "ERROR: not valid value in file\n");
	return (dst);
}
