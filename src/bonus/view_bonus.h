/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:48:07 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/26 16:28:28 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_BONUS_H
# define VIEW_BONUS_H

# include "mesh_bonus.h"
# include "status_bonus.h"
# include "image_bonus.h"
# include "vec4d_bonus.h"
# include "window_bonus.h"
# include "zbuffer_bonus.h"
# include "projection_bonus.h"
# include "clip_bonus.h"

typedef struct s_view
{
	t_window		*window;
	t_mesh			mesh;
	t_image			frames[2];
	t_image			*front;
	t_image			*back;
	t_vec4d			*vertices;
	t_clipbox		clipbox;
	t_projection	projection;
	t_zbuffer		zbuffer;
}	t_view;

t_status	view_create(t_view *view, t_window *window, const char *map_path);
t_status	view_create_buffers(t_view *view, t_window *win);
void		view_update(t_view *view, void *param);
void		view_transform_vertices(t_view *view);
void		view_set_initial_scale(t_view *view);
void		view_destroy(t_view *view);
void		view_draw(t_view *view);
void		line_to_screen(t_line4d *line, size_t width, size_t height);

#endif
