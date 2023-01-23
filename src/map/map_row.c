/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_row.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:24:24 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/23 20:18:49 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"
#include "map.h"

t_map_row	*map_row_from_line(const char *line)
{
	t_map_row	*row;

	row = ft_calloc(1, sizeof(t_map_row));
	if (!row)
		return (NULL);
	row->row = ft_split(line, ' ');
	if (!row->row)
		return (NULL);
	return (row);
}

size_t	map_row_width(t_map_row *row)
{
	char	*cell;
	size_t	width;

	width = 0;
	if (!row->row)
		return (0);
	cell = row->row[width];
	while (cell && is_vertex(cell))
	{
		width++;
		cell = row->row[width];
	}
	return (width);
}

size_t	map_row_parse(char **row, double z, size_t i, t_vec4d *vertices)
{
	char	*cell;
	size_t	x;

	x = 0;
	if (!row)
		return (0);
	cell = *(row++);
	while (cell && is_vertex(cell))
	{
		map_vertex(&vertices[i++], cell, x, z);
		cell = *(row++);
		x++;
	}
	return (x);
}
