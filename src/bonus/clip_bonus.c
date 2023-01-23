/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:18:10 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 00:31:34 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_bonus.h"
#include "clip_bonus.h"

t_region	region(t_vec4d *point, t_clipbox *clipbox)
{
	t_region	region;

	region = 0;
	if (point->x > clipbox->right.point.x)
		region |= RIGHT;
	else if (point->x < clipbox->left.point.x)
		region |= LEFT;
	if (point->y > clipbox->top.point.y)
		region |= ABOVE;
	else if (point->y < clipbox->bottom.point.y)
		region |= BELOW;
	return (region);
}

void	clip_color(t_line4d *line, t_vec4d *new_point)
{
	t_color4d	start;
	t_color4d	end;
	double		prev_distance;
	double		new_distance;

	prev_distance = vec4d_distance(&line->start, &line->end);
	new_distance = vec4d_distance(&line->start, new_point);
	if (new_distance == 0)
		new_point->color = line->start.color;
	else
	{
		color_as_color4d(line->start.color, &start);
		color_as_color4d(line->end.color, &end);
		color4d_sub_assign(&end, &start);
		color4d_div_assign(&end, prev_distance / new_distance);
		color4d_add_assign(&start, &end);
		new_point->color = color_from_color4d(&start);
	}
}

void	clip_point(
	t_line4d *line,
	t_vec4d *point,
	t_region region,
	t_clipbox *clipbox)
{
	t_vec4d	new_point;

	if (region & ABOVE)
		plane4d_intersect(&clipbox->top, line, &new_point);
	else if (region & BELOW)
		plane4d_intersect(&clipbox->bottom, line, &new_point);
	else if (region & RIGHT)
		plane4d_intersect(&clipbox->right, line, &new_point);
	else
		plane4d_intersect(&clipbox->left, line, &new_point);
	clip_color(line, &new_point);
	*point = new_point;
}

void	clipbox_default(t_clipbox *clipbox)
{
	vec4d_xyz(&clipbox->top.point, 0.0, 1.0, 0.0);
	vec4d_xyz(&clipbox->top.normal, 0.0, 1.0, 0.0);
	vec4d_xyz(&clipbox->right.point, 1.0, 0.0, 0.0);
	vec4d_xyz(&clipbox->right.normal, 1.0, 0.0, 0.0);
	vec4d_xyz(&clipbox->bottom.point, 0.0, -1.0, 0.0);
	vec4d_xyz(&clipbox->bottom.normal, 0.0, 1.0, 0.0);
	vec4d_xyz(&clipbox->left.point, -1.0, 0.0, 0.0);
	vec4d_xyz(&clipbox->left.normal, 1.0, 0.0, 0.0);
}

BOOL	clip_line(t_line4d *line, t_clipbox *clipbox)
{
	t_region	start;
	t_region	end;

	start = region(&line->start, clipbox);
	end = region(&line->end, clipbox);
	while (start | end)
	{
		if (start & end)
			return (FALSE);
		if (start)
		{
			clip_point(line, &line->start, start, clipbox);
			start = region(&line->start, clipbox);
			continue ;
		}
		clip_point(line, &line->end, end, clipbox);
		end = region(&line->end, clipbox);
	}
	return (TRUE);
}
