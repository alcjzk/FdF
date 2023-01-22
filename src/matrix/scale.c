/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:29:32 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/17 18:51:16 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "matrix4d.h"

void	matrix4d_scale(t_matrix4d *matrix, t_vec3d *scale)
{
	ft_bzero(matrix, sizeof(t_matrix4d));
	matrix->m[0][0] = scale->x;
	matrix->m[1][1] = scale->y;
	matrix->m[2][2] = scale->z;
	matrix->m[3][3] = 1.0;
}

void	matrix4d_scale_uniform(t_matrix4d *matrix, double scale)
{
	ft_bzero(matrix, sizeof(t_matrix4d));
	matrix->m[0][0] = scale;
	matrix->m[1][1] = scale;
	matrix->m[2][2] = scale;
	matrix->m[3][3] = 1.0;
}
