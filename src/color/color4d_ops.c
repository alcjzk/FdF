/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color4d_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:42:52 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/16 19:46:33 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void	color4d_sub(t_color4d *lhs, t_color4d *rhs, t_color4d *out)
{
	out->a = lhs->a - rhs->a;
	out->r = lhs->r - rhs->r;
	out->g = lhs->g - rhs->g;
	out->b = lhs->b - rhs->b;
}

void	color4d_sub_assign(t_color4d *lhs, t_color4d *rhs)
{
	lhs->a -= rhs->a;
	lhs->r -= rhs->r;
	lhs->g -= rhs->g;
	lhs->b -= rhs->b;
}

void	color4d_div_assign(t_color4d *lhs, double rhs)
{
	lhs->a /= rhs;
	lhs->r /= rhs;
	lhs->g /= rhs;
	lhs->b /= rhs;
}

void	color4d_add_assign(t_color4d *lhs, t_color4d *rhs)
{
	lhs->a += rhs->a;
	lhs->r += rhs->r;
	lhs->g += rhs->g;
	lhs->b += rhs->b;
}
