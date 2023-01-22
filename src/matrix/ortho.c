/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ortho.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:55:02 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/22 16:01:26 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bounds4d.h"
#include "util.h"
#include "matrix4d.h"

void	matrix4d_ortho(t_matrix4d *matrix, t_vec4d *min, t_vec4d *max)
{
	ft_bzero(matrix, sizeof(t_matrix4d));
	matrix->m[0][0] = 2 / (max->x - min->x);
	matrix->m[0][3] = -((max->x + min->x) / (max->x - min->x));
	matrix->m[1][1] = 2 / (max->y - min->y);
	matrix->m[1][3] = -((max->y + min->y) / (max->y - min->y));
	matrix->m[2][2] = -2 / (max->z - min->z);
	matrix->m[2][3] = -((max->z + min->z) / (max->z - min->z));
	matrix->m[3][2] = 1;
}

void	matrix4d_ortho_mesh(t_matrix4d *matrix, t_mesh *mesh, double ratio)
{
	t_bounds4d	bounds;
	double		max;

	bounds4d_init(&bounds, mesh->vertices, mesh->length);
	bounds.max.x = dmax(dabs(bounds.max.x), dabs(bounds.min.x));
	bounds.max.y = dmax(dabs(bounds.max.y), dabs(bounds.min.y));
	max = dmax(bounds.max.x, bounds.max.y);
	bounds.max.x = max * ratio;
	bounds.min.x = -bounds.max.x;
	bounds.max.y = max;
	bounds.min.y = -max;
	bounds.max.z = 100.0;
	bounds.min.z = -100.0;
	matrix4d_ortho(matrix, &bounds.min, &bounds.max);
}
