/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:17:08 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 00:31:57 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIP_BONUS_H
# define CLIP_BONUS_H

# define ABOVE	0b1000
# define BELOW	0b0100
# define RIGHT	0b0010
# define LEFT	0b0001

# include "bool.h"
# include "line_bonus.h"
# include "vec4d_bonus.h"
# include "plane4d_bonus.h"

typedef struct s_clipbox
{
	t_plane4d	top;
	t_plane4d	left;
	t_plane4d	bottom;
	t_plane4d	right;
}	t_clipbox;

typedef int	t_region;

t_region	region(t_vec4d *point, t_clipbox *clipbox);
void		clip_color(t_line4d *line, t_vec4d *new_point);
void		clipbox_default(t_clipbox *clipbox);
void		clip_point(
				t_line4d *line,
				t_vec4d *point,
				t_region region,
				t_clipbox *clipbox);
BOOL		clip_line(t_line4d *line, t_clipbox *clipbox);

#endif
