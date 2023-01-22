/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:06:10 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/21 23:56:23 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util.h"
#include "draw.h"

BOOL	line_init(t_line *line, t_vec4d *start, t_vec4d *end)
{
	t_color4d	end_color;
	int			dx;
	int			dy;

	dx = (int)end->x - (int)start->x;
	dy = (int)end->y - (int)start->y;
	line->steps = ft_imax(ft_abs(dx), ft_abs(dy));
	if (!line->steps)
		return (FALSE);
	vec4d_sub(end, start, &line->point_increment);
	vec4d_div_assign(&line->point_increment, line->steps);
	line->point = *start;
	color_as_color4d(start->color, &line->color);
	color_as_color4d(end->color, &end_color);
	color4d_sub(&end_color, &line->color, &line->color_increment);
	color4d_div_assign(&line->color_increment, line->steps);
	return (TRUE);
}

BOOL	line_next(t_line *line, t_pixel *pixel)
{
	if (line->steps < 0)
		return (FALSE);
	pixel->x = line->point.x;
	pixel->y = line->point.y;
	pixel->z = line->point.z;
	pixel->color = color_from_color4d(&line->color);
	color4d_add_assign(&line->color, &line->color_increment);
	vec4d_add_assign(&line->point, &line->point_increment);
	line->steps--;
	return (TRUE);
}
