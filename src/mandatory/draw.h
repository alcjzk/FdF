/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:06:21 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/23 19:21:18 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "bool.h"
# include "vec4d.h"
# include "color.h"

typedef struct s_line
{
	int				steps;
	t_vec4d			point;
	t_vec4d			point_increment;
	t_color4d		color;
	t_color4d		color_increment;
}	t_line;

typedef struct s_pixel
{
	int		x;
	int		y;
	float	z;
	t_color	color;
}	t_pixel;

BOOL	line_init(t_line *line, t_vec4d *start, t_vec4d *end);
BOOL	line_next(t_line *line, t_pixel *pixel);

#endif
