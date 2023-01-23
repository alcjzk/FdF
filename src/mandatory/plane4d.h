/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane4d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:44:32 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/17 18:59:05 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE4D_H
# define PLANE4D_H

# include "vec4d.h"
# include "line.h"

typedef struct s_plane4d
{
	t_vec4d	point;
	t_vec4d	normal;
}	t_plane4d;

void	plane4d_intersect(t_plane4d *plane, t_line4d *line, t_vec4d *out);

#endif
