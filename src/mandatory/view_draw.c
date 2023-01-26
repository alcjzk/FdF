/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 08:24:25 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/27 01:14:13 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "bounds4d.h"
#include "util.h"
#include "view.h"

void	line_to_screen(t_line4d *line, size_t width, size_t height)
{
	line->start.x = (line->start.x + 1) / 2 * (width - 1);
	line->start.y = (-line->start.y + 1) / 2 * (height - 1);
	line->end.x = (line->end.x + 1) / 2 * (width - 1);
	line->end.y = (-line->end.y + 1) / 2 * (height - 1);
}

void	view_draw(t_view *view)
{
	size_t		i;
	t_line4d	*line_in;
	t_line		line_out;
	t_pixel		pixel;

	i = 0;
	while (i < view->mesh.length)
	{
		line_in = (t_line4d *)&(view->vertices[i]);
		i += 2;
		if (!clip_line(line_in, &view->clipbox))
			continue ;
		line_to_screen(line_in, view->window->width, view->window->height);
		if (!line_init(&line_out, &line_in->start, &line_in->end))
			continue ;
		while (line_next(&line_out, &pixel))
		{
			if (zbuffer_set(&view->zbuffer, pixel.x, pixel.y, pixel.z))
				image_put_pixel(view->back, pixel.x, pixel.y, pixel.color);
		}
	}
}

void	view_transform_vertices(t_view *view)
{
	t_vec4d	*vec_in;
	t_vec4d	*vec_out;
	size_t	i;

	i = 0;
	while (i < view->mesh.length)
	{
		vec_in = &view->mesh.vertices[i];
		vec_out = &view->vertices[i];
		matrix4d_multiply_vec4d(&view->projection.matrix, vec_in, vec_out);
		i++;
	}
}

void	view_set_initial_scale(t_view *view)
{
	t_bounds4d	bounds;
	double		dx;
	double		dy;

	projection_update_matrix(&view->projection);
	view_transform_vertices(view);
	bounds4d_init(&bounds, view->vertices, view->mesh.length);
	dx = dabs(bounds.min.x - bounds.max.x);
	dy = dabs(bounds.min.y - bounds.max.y);
	view->projection.scale = 0.8 * (2.0 / dmax(dx, dy));
}
