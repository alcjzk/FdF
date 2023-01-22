/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds4d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:37:28 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/22 16:01:06 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "util.h"
#include "bounds4d.h"

void	bounds4d_init(t_bounds4d *bounds, t_vec4d *vertices, size_t length)
{
	size_t	i;
	t_vec4d	*vertex;

	i = 0;
	vec4d_value(&bounds->min, INFINITY);
	vec4d_value(&bounds->max, -INFINITY);
	while (i < length)
	{
		vertex = &vertices[i++];
		bounds->max.x = dmax(vertex->x, bounds->max.x);
		bounds->max.y = dmax(vertex->y, bounds->max.y);
		bounds->max.z = dmax(vertex->z, bounds->max.z);
		bounds->min.x = dmin(vertex->x, bounds->min.x);
		bounds->min.y = dmin(vertex->y, bounds->min.y);
		bounds->min.z = dmin(vertex->z, bounds->min.z);
	}
}
