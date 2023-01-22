/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:00:37 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/22 09:29:14 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include "libft.h"
#include "vec4d.h"

double	vec4d_dot(t_vec4d *lhs, t_vec4d *rhs)
{
	return (lhs->x * rhs->x + lhs->y * rhs->y + lhs->z * rhs->z);
}

// t_vec4d	*vec4d_cross(t_vec4d *lhs, t_vec4d *rhs, t_vec4d *out)
// {
// 	out->x = lhs->y * rhs->z - lhs->z * rhs->y;
// 	out->y = lhs->z * rhs->x - lhs->x * rhs->z;
// 	out->z = lhs->x * rhs->y - lhs->y * rhs->z;
// 	out->w = lhs->w;
// 	out->color = lhs->color;
// 	return (out);
// }

double	vec4d_length(t_vec4d *self)
{
	return (sqrt(vec4d_dot(self, self)));
}

// t_vec4d	*vec4d_normalize(t_vec4d *self, t_vec4d *out)
// {
// 	double	length;

// 	length = vec4d_length(self);
// 	out->x = self->x / length;
// 	out->y = self->y / length;
// 	out->z = self->z / length;
// 	out->w = self->w;
// 	out->color = self->color;
// 	return (out);
// }

// void	vec4d_debug(t_vec4d *self)
// {
// 	printf("X:%f Y:%f Z:%f W:%f C: %X\n",
// 		self->x,
// 		self->y,
// 		self->z,
// 		self->w,
// 		self->color.value
// 	);
// }

void	vec4d_xyz(t_vec4d *self, double x, double y, double z)
{
	ft_bzero(self, sizeof(t_vec4d));
	self->x = x;
	self->y = y;
	self->z = z;
	self->w = 1.0;
}

void	vec4d_value(t_vec4d *self, double value)
{
	self->x = value;
	self->y = value;
	self->z = value;
	self->w = value;
}

double	vec4d_distance(t_vec4d *point1, t_vec4d *point2)
{
	t_vec4d	delta;

	vec4d_sub(point2, point1, &delta);
	return (vec4d_length(&delta));
}
