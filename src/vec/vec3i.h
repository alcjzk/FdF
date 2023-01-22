/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3i.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:41:11 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/12 04:00:24 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3I_H
# define VEC3I_H

# include "color.h"
# include "vec4d.h"

typedef struct s_vec3i
{
	int		x;
	int		y;
	int		z;
	t_color	color;
}	t_vec3i;

void	vec3i_from_vec4d(t_vec3i *to, t_vec4d *from);

#endif
