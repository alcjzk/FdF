/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:46:16 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/23 21:16:58 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX4D_H
# define MATRIX4D_H

# include "vec4d.h"
# include "mesh.h"
# include "vec3d.h"

typedef struct s_matrix4d
{
	double	m[4][4];
}	t_matrix4d;

void	matrix4d_yaw(t_matrix4d *matrix, double angle);
void	matrix4d_pitch(t_matrix4d *matrix, double angle);
void	matrix4d_roll(t_matrix4d *matrix, double angle);
void	matrix4d_rotate(t_matrix4d *matrix, t_vec3d *rotation);
void	matrix4d_translate(t_matrix4d *matrix, t_vec3d *position);
void	matrix4d_scale(t_matrix4d *matrix, t_vec3d *scale);
void	matrix4d_multiply(t_matrix4d *lhs, t_matrix4d *rhs, t_matrix4d *out);
void	matrix4d_multiply_vec4d(
			t_matrix4d *matrix,
			t_vec4d *in,
			t_vec4d *out);
void	matrix4d_ortho(t_matrix4d *matrix, t_vec4d *min, t_vec4d *max);
void	matrix4d_scale_uniform(t_matrix4d *matrix, double scale);
void	matrix4d_ortho_mesh(t_matrix4d *matrix, t_mesh *mesh, double ratio);

#endif
