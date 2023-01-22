/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_row.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:24:24 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/22 15:33:19 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"
#include "map.h"

t_status	map_rows_from_file(t_map_rows *rows, const char *path)
{
	const char	*line;
	t_map_row	**head;
	int			fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (err_sys);
	head = &rows->start;
	line = get_next_line(fd);
	while (line)
	{
		rows->length++;
		*head = ft_calloc(1, sizeof(t_map_row));
		(*head)->row = ft_split(line, ' ');
		if (!(*head)->row)
			return (err_sys);
		head = &(*head)->next;
		free((void *)line);
		line = get_next_line(fd);
	}
	close(fd);
	return (ok);
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

t_status	map_rows_parse(t_map_rows *rows, size_t width, t_vec4d *vertices)
{
	size_t		i;
	size_t		z;
	t_map_row	*head;

	i = 0;
	z = 0;
	head = rows->start;
	while (head)
	{
		if (map_row_parse(head->row, z, i, vertices) != width)
			return (err_map);
		head = head->next;
		i += width;
		z++;
	}
	return (ok);
}

void	map_rows_destroy(t_map_rows *rows)
{
	t_map_row	*head;
	t_map_row	*next;
	char		*cell;
	char		**row;

	head = rows->start;
	while (head)
	{
		next = head->next;
		row = head->row;
		cell = *(row++);
		while (cell)
		{
			free(cell);
			printf("a ");
			cell = *(row++);
		}
		free(head->row);
		free(head);
		head = next;
	}
}
