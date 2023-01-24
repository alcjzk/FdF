/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vertex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:22:14 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 10:31:32 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util_bonus.h"
#include "map_bonus.h"

BOOL	is_vertex(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (i == 0)
		return (FALSE);
	if (str_startswith(&str[i], ",0x"))
	{
		i += 3;
		while (is_hex(str[i]))
			i++;
	}
	if (str[i] == '\n')
		i++;
	if (!str[i])
		return (TRUE);
	return (FALSE);
}

void	map_vertex(t_vec4d *vertex, char *str, double x, double z)
{
	char	*color;

	color = (char *)0;
	vertex->x = x;
	vertex->y = ft_atoi(str);
	vertex->z = -z;
	vertex->w = 1.0;
	vertex->color = (t_color){.value = 0x00FFFFFF};
	color = ft_strchr(str, ',');
	if (color)
		vertex->color = color_from_str(++color);
}

void	map_vertices_x(t_mesh *mesh, t_vec4d *vertices, size_t w, size_t h)
{
	size_t	x;
	size_t	z;
	size_t	i;

	i = 0;
	z = 0;
	while (z < h)
	{
		x = 1;
		while (x < w)
		{
			mesh->vertices[i++] = vertices[z * w + (x - 1)];
			mesh->vertices[i++] = vertices[z * w + (x++)];
		}
		z++;
	}
}

void	map_vertices_z(t_mesh *mesh, t_vec4d *vertices, size_t w, size_t h)
{
	size_t	x;
	size_t	z;
	size_t	i;

	x = 0;
	i = (h * (w - 1)) * 2;
	while (x < w)
	{
		z = 1;
		while (z < h)
		{
			mesh->vertices[i++] = vertices[(z - 1) * w + x];
			mesh->vertices[i++] = vertices[(z++) * w + x];
		}
		x++;
	}
}
