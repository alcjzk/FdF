/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:48:57 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/26 16:29:57 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "state_bonus.h"
#include "map_bonus.h"
#include "view_bonus.h"

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
	view_set_initial_scale(view);
	return (ok);
}

void	view_update(t_view *view, void *param)
{
	t_window	*win;

	win = view->window;
	projection_update(&view->projection, &((t_state *)param)->modifiers);
	view_transform_vertices(view);
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
