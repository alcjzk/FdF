/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:46:55 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 10:29:21 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bounds4d.h"
#include "util.h"
#include "map.h"

void	map_transform(t_mesh *mesh)
{
	t_bounds4d	bounds;
	t_vec4d		position;
	size_t		i;
	double		max;

	i = 0;
	bounds4d_init(&bounds, mesh->vertices, mesh->length);
	position.x = -bounds.min.x - ((bounds.max.x - bounds.min.x) / 2);
	position.y = -bounds.min.y - ((bounds.max.y - bounds.min.y) / 2);
	position.z = -bounds.min.z - ((bounds.max.z - bounds.min.z) / 2);
	max = dmax(bounds.max.x, dmax(bounds.max.y, bounds.max.z));
	while (i < mesh->length)
	{
		vec4d_add_assign(&mesh->vertices[i], &position);
		vec4d_div_assign(&mesh->vertices[i++], max);
	}
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

BOOL	map_alloc(t_mesh *mesh, t_vec4d **vertices, size_t w, size_t h)
{
	*vertices = ft_calloc(w * h, sizeof(t_vec4d));
	if (!*vertices)
		return (FALSE);
	mesh->length = (w * (h - 1) + (w - 1) * h) * 2;
	mesh->vertices = ft_calloc(mesh->length, sizeof(t_vec4d));
	if (!mesh->vertices)
		return (FALSE);
	return (TRUE);
}

static t_status	map_mesh_create_impl(
	t_mesh *mesh,
	const char *map_path,
	t_map_rows *rows,
	t_vec4d **vertices)
{
	size_t		width;

	ft_bzero(rows, sizeof(t_map_rows));
	*vertices = NULL;
	if (!map_rows_create(rows, map_path))
		return (err_sys);
	width = map_row_width(rows->start);
	if (width == 0)
		return (err_map);
	if (!map_alloc(mesh, vertices, width, rows->length))
		return (err_sys);
	if (!map_rows_parse(rows, width, *vertices))
		return (err_map);
	map_vertices_x(mesh, *vertices, width, rows->length);
	map_vertices_z(mesh, *vertices, width, rows->length);
	map_transform(mesh);
	return (ok);
}

t_status	map_mesh_create(t_mesh *mesh, const char *map_path)
{
	t_status	status;
	t_map_rows	rows;
	t_vec4d		*vertices;

	vertices = NULL;
	status = map_mesh_create_impl(mesh, map_path, &rows, &vertices);
	map_rows_destroy(&rows);
	free(vertices);
	return (status);
}
