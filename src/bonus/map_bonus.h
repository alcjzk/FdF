/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:47:02 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 00:35:33 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

# include <stddef.h>
# include "bool.h"
# include "vec4d_bonus.h"
# include "status_bonus.h"
# include "mesh_bonus.h"

typedef struct s_map_row
{
	struct s_map_row	*next;
	char				**row;
}	t_map_row;

typedef struct s_map_rows
{
	t_map_row	*start;
	size_t		length;
}	t_map_rows;

BOOL		is_vertex(char *str);
void		map_vertex(t_vec4d *vertex, char *str, double x, double z);

size_t		map_row_width(t_map_row *row);
size_t		map_row_parse(char **row, double z, size_t i, t_vec4d *vertices);
t_map_row	*map_row_create(const char *line);
void		map_row_destroy(t_map_row *row);

BOOL		map_rows_create(t_map_rows *rows, const char *path);
BOOL		map_rows_parse(t_map_rows *rows, size_t width, t_vec4d *vertices);
void		map_rows_destroy(t_map_rows *rows);

void		map_transform(t_mesh *mesh);
void		map_vertices_x(t_mesh *mesh, t_vec4d *vertices, size_t w, size_t h);
void		map_vertices_z(t_mesh *mesh, t_vec4d *vertices, size_t w, size_t h);
BOOL		map_alloc(t_mesh *mesh, t_vec4d **vertices, size_t w, size_t h);
t_status	map_mesh_create(t_mesh *mesh, const char *map_path);

#endif
