/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:42:24 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 01:48:38 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util_bonus.h"
#include "projection_bonus.h"

static unsigned long long	utimestamp(void)
{
	struct timeval		time;
	unsigned long long	timestamp;

	gettimeofday(&time, NULL);
	timestamp = time.tv_sec * 1000000 + time.tv_usec;
	return (timestamp);
}

void	projection_init(
	t_projection *proj,
	t_mesh *mesh,
	t_window *window)
{
	ft_bzero(proj, sizeof(t_projection));
	matrix4d_ortho_mesh(&proj->mat_ortho, mesh, window->aspect_ratio);
	proj->scale = 1.0;
	proj->timestamp = utimestamp();
	projection_isometric(proj);
}

void	projection_update_matrix(t_projection *proj)
{
	matrix4d_rotate(&proj->mat_zyx, &proj->rotation);
	matrix4d_translate(&proj->mat_pos, &proj->position);
	matrix4d_scale_uniform(&proj->mat_scale, proj->scale);
	matrix4d_multiply(&proj->mat_pos, &proj->mat_scale, &proj->mat_sp);
	matrix4d_multiply(&proj->mat_sp, &proj->mat_zyx, &proj->mat_zyxsp);
	matrix4d_multiply(&proj->mat_ortho, &proj->mat_zyxsp, &proj->matrix);
}

void	projection_update(t_projection *projection, t_modifiers *modifiers)
{
	unsigned long long	timestamp;
	unsigned long long	timestamp_d;
	double				timescale;

	timestamp = utimestamp();
	timestamp_d = timestamp - projection->timestamp;
	timescale = (1.0 / 1000000.0) * (double)timestamp_d;
	projection->timestamp = timestamp;
	projection_update_x(&projection->position.x, modifiers, timescale);
	projection_update_y(&projection->position.y, modifiers, timescale);
	projection_update_pitch(&projection->rotation.x, modifiers, timescale);
	projection_update_yaw(&projection->rotation.y, modifiers, timescale);
	projection_update_roll(&projection->rotation.z, modifiers, timescale);
	projection_update_scale(&projection->scale, modifiers, timescale);
	projection_update_matrix(projection);
}
