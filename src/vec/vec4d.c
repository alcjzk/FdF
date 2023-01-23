/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:00:37 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/23 21:53:24 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "vec4d.h"

double	vec4d_dot(t_vec4d *lhs, t_vec4d *rhs)
{
	return (lhs->x * rhs->x + lhs->y * rhs->y + lhs->z * rhs->z);
}

double	vec4d_length(t_vec4d *self)
{
	return (sqrt(vec4d_dot(self, self)));
}

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
