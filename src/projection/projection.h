/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:33:53 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/23 21:39:44 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

# define SCALE_MAX 10.0
# define SCALE_MIN 0.001
# define POSITION_MAX 10
# define POSITION_MIN -10

//	Change in angle per second
# define ROTATION_INCREMENT 30.0

//	Change in position per second
# define POSITION_INCREMENT 0.2

//	Change in scale per second
# define SCALE_INCREMENT 0.5

# include <sys/time.h>
# include "matrix4d.h"
# include "vec3d.h"
# include "modifiers.h"
# include "mesh.h"
# include "window.h"

typedef struct s_projection
{
	t_matrix4d			mat_ortho;
	t_matrix4d			mat_pos;
	t_matrix4d			mat_scale;
	t_matrix4d			mat_zyx;
	t_matrix4d			mat_sp;
	t_matrix4d			mat_zyxsp;
	t_matrix4d			matrix;
	t_vec3d				position;
	t_vec3d				rotation;
	double				scale;
	unsigned long long	timestamp;
}	t_projection;

void	projection_init(
			t_projection *projection,
			t_mesh *mesh,
			t_window *window);
void	projection_update_matrix(t_projection *projection);
void	projection_isometric(t_projection *projection);
void	projection_parallel(t_projection *projection);
void	projection_update_x(
			double *x,
			t_modifiers *modifiers,
			double timescale);
void	projection_update_y(
			double *y,
			t_modifiers *modifiers,
			double timescale);
void	projection_update_pitch(
			double *pitch,
			t_modifiers *modifiers,
			double timescale);
void	projection_update_yaw(
			double *yaw,
			t_modifiers *modifiers,
			double timescale);
void	projection_update_roll(
			double *roll,
			t_modifiers *modifiers,
			double timescale);
void	projection_update_scale(
			double *scale,
			t_modifiers *modifiers,
			double timescale);
void	projection_update(t_projection *projection, t_modifiers *modifiers);

#endif
