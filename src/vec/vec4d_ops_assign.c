/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4d_ops_assign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:55:19 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/16 16:15:02 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec4d.h"

t_vec4d	*vec4d_add_assign(t_vec4d *lhs, t_vec4d *rhs)
{
	lhs->x += rhs->x;
	lhs->y += rhs->y;
	lhs->z += rhs->z;
	return (lhs);
}

t_vec4d	*vec4d_sub_assign(t_vec4d *lhs, t_vec4d *rhs)
{
	lhs->x -= rhs->x;
	lhs->y -= rhs->y;
	lhs->z -= rhs->z;
	return (lhs);
}

t_vec4d	*vec4d_mul_assign(t_vec4d *lhs, double rhs)
{
	lhs->x *= rhs;
	lhs->y *= rhs;
	lhs->z *= rhs;
	return (lhs);
}

t_vec4d	*vec4d_div_assign(t_vec4d *lhs, double rhs)
{
	lhs->x /= rhs;
	lhs->y /= rhs;
	lhs->z /= rhs;
	return (lhs);
}
