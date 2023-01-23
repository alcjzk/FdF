/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4d_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:55:19 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/23 21:51:21 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec4d.h"

t_vec4d	*vec4d_add(t_vec4d *lhs, t_vec4d *rhs, t_vec4d *out)
{
	out->x = lhs->x + rhs->x;
	out->y = lhs->y + rhs->y;
	out->z = lhs->z + rhs->z;
	out->w = lhs->w;
	out->color = lhs->color;
	return (out);
}

t_vec4d	*vec4d_sub(t_vec4d *lhs, t_vec4d *rhs, t_vec4d *out)
{
	out->x = lhs->x - rhs->x;
	out->y = lhs->y - rhs->y;
	out->z = lhs->z - rhs->z;
	out->w = lhs->w;
	out->color = lhs->color;
	return (out);
}

t_vec4d	*vec4d_mul(t_vec4d *lhs, double rhs, t_vec4d *out)
{
	out->x = lhs->x * rhs;
	out->y = lhs->y * rhs;
	out->z = lhs->z * rhs;
	out->w = lhs->w;
	out->color = lhs->color;
	return (out);
}
