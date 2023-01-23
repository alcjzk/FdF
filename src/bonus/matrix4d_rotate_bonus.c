/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4d_rotate_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:15:17 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 00:39:10 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "matrix4d_bonus.h"

void	matrix4d_rotate(t_matrix4d *matrix, t_vec3d *rotation)
{
	t_matrix4d	pitch;
	t_matrix4d	yaw;
	t_matrix4d	roll;
	t_matrix4d	yx;

	matrix4d_pitch(&pitch, rotation->x);
	matrix4d_yaw(&yaw, rotation->y);
	matrix4d_roll(&roll, rotation->z);
	matrix4d_multiply(&pitch, &yaw, &yx);
	matrix4d_multiply(&yx, &roll, matrix);
}

void	matrix4d_yaw(t_matrix4d *matrix, double angle)
{
	ft_bzero(matrix, sizeof(t_matrix4d));
	angle = angle * M_PI / 180.0;
	matrix->m[0][0] = cos(angle);
	matrix->m[0][2] = -sin(angle);
	matrix->m[1][1] = 1.0;
	matrix->m[2][0] = sin(angle);
	matrix->m[2][2] = cos(angle);
	matrix->m[3][3] = 1.0;
}

void	matrix4d_pitch(t_matrix4d *matrix, double angle)
{
	ft_bzero(matrix, sizeof(t_matrix4d));
	angle = angle * M_PI / 180.0;
	matrix->m[0][0] = 1.0;
	matrix->m[1][1] = cos(angle);
	matrix->m[1][2] = -sin(angle);
	matrix->m[2][1] = sin(angle);
	matrix->m[2][2] = cos(angle);
	matrix->m[3][3] = 1.0;
}

void	matrix4d_roll(t_matrix4d *matrix, double angle)
{
	ft_bzero(matrix, sizeof(t_matrix4d));
	angle = angle * M_PI / 180.0;
	matrix->m[0][0] = cos(angle);
	matrix->m[0][1] = -sin(angle);
	matrix->m[1][0] = sin(angle);
	matrix->m[1][1] = cos(angle);
	matrix->m[2][2] = 1.0;
	matrix->m[3][3] = 1.0;
}
