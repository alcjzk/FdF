/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane4d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:49:17 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/17 18:59:19 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "plane4d.h"
#include <stdlib.h>
#include <math.h>

void	plane4d_intersect(t_plane4d *plane, t_line4d *line, t_vec4d *out)
{
	double	plane_d;
	double	start_d;
	double	end_d;
	double	scale;

	ft_bzero(out, sizeof(t_vec4d));
	plane_d = vec4d_dot(&plane->normal, &plane->point);
	start_d = vec4d_dot(&line->start, &plane->normal);
	end_d = vec4d_dot(&line->end, &plane->normal);
	if (end_d - start_d == 0)
		return ;
	scale = (plane_d - start_d) / (end_d - start_d);
	vec4d_sub(&line->end, &line->start, out);
	vec4d_mul(out, scale, out);
	vec4d_add(&line->start, out, out);
}
