/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4d_ops_assign_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:55:19 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 00:44:59 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec4d_bonus.h"

t_vec4d	*vec4d_add_assign(t_vec4d *lhs, t_vec4d *rhs)
{
	lhs->x += rhs->x;
	lhs->y += rhs->y;
	lhs->z += rhs->z;
	return (lhs);
}

t_vec4d	*vec4d_div_assign(t_vec4d *lhs, double rhs)
{
	lhs->x /= rhs;
	lhs->y /= rhs;
	lhs->z /= rhs;
	return (lhs);
}
