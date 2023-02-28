/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:05:42 by eestelle          #+#    #+#             */
/*   Updated: 2023/02/28 23:07:38 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdint.h>
# include "libft.h"
# include "get_next_line.h"
# include "fcntl.h"
# include "objects.h"

enum e_PARSE_NUMBER
{
	PARSE_NONE_TYPE = -1,
	PARSE_AMBIENT,
	PARSE_POINT,
	PARSE_CAMERA,
	PARSE_SPHERE,
	PARSE_PLANE,
	PARSE_CYLINDER
};

typedef struct s_file
{
	char		**data;
	uint32_t	size;
	uint32_t	count;
}	t_file;

uint64_t	count_type_in_file(t_file *ptr);
t_file		*read_file(const char *name_file);
int			get_type_line(const char *str);
void		t_file_clean(t_file *ptr);

#endif
