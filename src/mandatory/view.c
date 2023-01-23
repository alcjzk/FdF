/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:48:57 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 01:28:25 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "map.h"
#include "view.h"

static void	buffer_swap(void **front, void **back)
{
	void	*tmp;

	tmp = *front;
	*front = *back;
	*back = tmp;
}

t_status	view_create_buffers(t_view *view, t_window *win)
{
	t_status	status;

	view->front = &view->frames[0];
	view->back = &view->frames[1];
	status = image_create(view->front, win->mlx, win->width, win->height);
	if (status != ok)
		return (status);
	status = image_create(view->back, win->mlx, win->width, win->height);
	if (status != ok)
		return (status);
	status = zbuffer_create(&view->zbuffer, win->width, win->height);
	return (status);
}

t_status	view_create(t_view *view, t_window *win, const char *map_path)
{
	t_status	status;

	ft_bzero(view, sizeof(t_view));
	status = map_mesh_create(&view->mesh, (char *)map_path);
	if (status != ok)
		return (status);
	view->window = win;
	status = view_create_buffers(view, win);
	if (status != ok)
		return (status);
	view->vertices = ft_calloc(view->mesh.length, sizeof(t_vec4d));
	if (!view->vertices)
		return (err_sys);
	clipbox_default(&view->clipbox);
	projection_init(&view->projection, &view->mesh, win);
	return (ok);
}

void	view_update(t_view *view)
{
	t_vec4d		*vec_in;
	t_vec4d		*vec_out;
	t_window	*win;
	size_t		i;

	i = 0;
	win = view->window;
	projection_update(&view->projection);
	while (i < view->mesh.length)
	{
		vec_in = &view->mesh.vertices[i];
		vec_out = &view->vertices[i];
		matrix4d_multiply_vec4d(&view->projection.matrix, vec_in, vec_out);
		i++;
	}
	zbuffer_clear(&view->zbuffer);
	image_clear(view->back);
	view_draw(view);
	buffer_swap((void **)&view->front, (void **)&view->back);
	mlx_put_image_to_window(win->mlx, win->window, view->front->img, 0, 0);
}

void	view_destroy(t_view *view)
{
	image_destroy(view->front);
	image_destroy(view->back);
	zbuffer_destroy(&view->zbuffer);
	if (view->vertices)
		free(view->vertices);
	mesh_destroy(&view->mesh);
}
