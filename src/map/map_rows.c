/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rows.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:10:45 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/23 20:20:01 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"
#include "map.h"

t_status	map_rows_from_file(t_map_rows *rows, const char *path)
{
	const char	*line;
	t_map_row	**head;
	int			fd;

	ft_bzero(rows, sizeof(t_map_rows));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (err_sys);
	head = &rows->start;
	line = get_next_line(fd);
	while (line)
	{
		rows->length++;
		*head = map_row_from_line(line);
		if (!*head)
			return (err_sys);
		head = &(*head)->next;
		free((void *)line);
		line = get_next_line(fd);
	}
	close(fd);
	return (ok);
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
			cell = *(row++);
		}
		free(head->row);
		free(head);
		head = next;
	}
}
