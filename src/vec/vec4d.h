/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:46:06 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/17 18:23:49 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC4D_H
# define VEC4D_H

# include "color.h"

typedef struct s_vec4d
{
	double	x;
	double	y;
	double	z;
	double	w;
	t_color	color;
}	t_vec4d;

//	Basic operations
t_vec4d	*vec4d_add(t_vec4d *lhs, t_vec4d *rhs, t_vec4d *out);
t_vec4d	*vec4d_sub(t_vec4d *lhs, t_vec4d *rhs, t_vec4d *out);
t_vec4d	*vec4d_mul(t_vec4d *lhs, double rhs, t_vec4d *out);
t_vec4d	*vec4d_div(t_vec4d *lhs, double rhs, t_vec4d *out);

//	Assignment operations
t_vec4d	*vec4d_add_assign(t_vec4d *lhs, t_vec4d *rhs);
t_vec4d	*vec4d_sub_assign(t_vec4d *lhs, t_vec4d *rhs);
t_vec4d	*vec4d_mul_assign(t_vec4d *lhs, double rhs);
t_vec4d	*vec4d_div_assign(t_vec4d *lhs, double rhs);

//	Vector math
double	vec4d_dot(t_vec4d *lhs, t_vec4d *rhs);
t_vec4d	*vec4d_cross(t_vec4d *lhs, t_vec4d *rhs, t_vec4d *out);
double	vec4d_length(t_vec4d *self);
t_vec4d	*vec4d_normalize(t_vec4d *self, t_vec4d *out);
void	vec4d_debug(t_vec4d *self);
void	vec4d_xyz(t_vec4d *self, double x, double y, double z);
void	vec4d_value(t_vec4d *self, double value);
double	vec4d_distance(t_vec4d *point1, t_vec4d *point2);

#endif
