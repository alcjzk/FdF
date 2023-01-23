/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_row_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:24:24 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 00:37:59 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "map_bonus.h"

void	map_row_destroy(t_map_row *row)
{
	char	*cell;
	char	**inner;

	if (row)
	{
		if (row->row)
		{
			inner = row->row;
			cell = *(inner++);
			while (cell)
			{
				free(cell);
				cell = *(inner++);
			}
			free(row->row);
		}
		free(row);
	}
}

t_map_row	*map_row_create(const char *line)
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
