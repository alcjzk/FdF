/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:05:55 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/17 18:55:21 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix4d.h"

void	matrix4d_multiply(
	t_matrix4d *lhs,
	t_matrix4d *rhs,
	t_matrix4d *out)
{
	size_t	row;
	size_t	cell;

	row = 0;
	while (row < 4)
	{
		cell = 0;
		while (cell < 4)
		{
			out->m[row][cell]
				= lhs->m[row][0] * rhs->m[0][cell]
				+ lhs->m[row][1] * rhs->m[1][cell]
				+ lhs->m[row][2] * rhs->m[2][cell]
				+ lhs->m[row][3] * rhs->m[3][cell];
			cell++;
		}
		row++;
	}
}

void	matrix4d_multiply_vec4d(t_matrix4d *m, t_vec4d *in, t_vec4d *out)
{
	out->x
		= m->m[0][0] * in->x + m->m[0][1] * in->y
		+ m->m[0][2] * in->z + m->m[0][3] * in->w;
	out->y
		= m->m[1][0] * in->x + m->m[1][1] * in->y
		+ m->m[1][2] * in->z + m->m[1][3] * in->w;
	out->z
		= m->m[2][0] * in->x + m->m[2][1] * in->y
		+ m->m[2][2] * in->z + m->m[2][3] * in->w;
	out->w
		= m->m[3][0] * in->x + m->m[3][1] * in->y
		+ m->m[3][2] * in->z + m->m[3][3] * in->w;
	out->color = in->color;
}
