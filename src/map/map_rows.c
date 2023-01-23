/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rows.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:10:45 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/23 20:52:56 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"
#include "map.h"

BOOL	map_rows_create(t_map_rows *rows, const char *path)
{
	const char	*line;
	t_map_row	**head;
	int			fd;

	ft_bzero(rows, sizeof(t_map_rows));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	head = &rows->start;
	line = get_next_line(fd);
	while (line)
	{
		rows->length++;
		*head = map_row_create(line);
		if (!*head)
			return (FALSE);
		head = &(*head)->next;
		free((void *)line);
		line = get_next_line(fd);
	}
	close(fd);
	return (TRUE);
}

BOOL	map_rows_parse(t_map_rows *rows, size_t width, t_vec4d *vertices)
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
			return (FALSE);
		head = head->next;
		i += width;
		z++;
	}
	return (TRUE);
}

void	map_rows_destroy(t_map_rows *rows)
{
	t_map_row	*head;
	t_map_row	*next;

	head = rows->start;
	while (head)
	{
		next = head->next;
		map_row_destroy(head);
		head = next;
	}
}
