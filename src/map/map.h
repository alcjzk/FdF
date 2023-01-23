/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:47:02 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/23 20:16:32 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stddef.h>
# include "bool.h"
# include "vec4d.h"
# include "status.h"
# include "mesh.h"

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

typedef struct s_map_parser
{
	size_t		height;
	size_t		width;
	t_vec4d		*vertices;
	t_map_row	*rows;
	double		x;
	double		z;
}	t_map_parser;

typedef struct s_parser
{
	double		x;
	double		z;
	char		*cell;
	char		**row;
	t_map_row	*head;
}	t_parser;

BOOL		is_vertex(char *str);
void		map_vertex(t_vec4d *vertex, char *str, double x, double z);

size_t		map_row_width(t_map_row *row);
size_t		map_row_parse(char **row, double z, size_t i, t_vec4d *vertices);
t_map_row	*map_row_from_line(const char *line);

t_status	map_rows_from_file(t_map_rows *rows, const char *path);
t_status	map_rows_parse(t_map_rows *rows, size_t width, t_vec4d *vertices);
void		map_rows_destroy(t_map_rows *rows);

void		map_transform(t_mesh *mesh);
void		map_vertices_x(t_mesh *mesh, t_vec4d *vertices, size_t w, size_t h);
void		map_vertices_z(t_mesh *mesh, t_vec4d *vertices, size_t w, size_t h);
t_status	map_alloc(t_mesh *mesh, t_vec4d **vertices, size_t w, size_t h);
t_status	map_mesh_create(t_mesh *mesh, const char *map_path);

// void		map_transform(t_mesh *mesh);
// void		map_mesh(t_mesh *mesh, t_map_parser *parser);
// t_status	map_mesh_create(t_mesh *mesh, char *map_path);
// BOOL		map_parse_row(t_map_parser *parser, double z, char **row);
// BOOL		map_parse_rows(t_map_parser *parser);
// t_status	map_row_create(t_map_row **row, char *line);
// void		free_rows(t_map_row *head);

#endif
