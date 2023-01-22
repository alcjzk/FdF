/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:41:20 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/15 15:41:17 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3i.h"

void	vec3i_from_vec4d(t_vec3i *to, t_vec4d *from)
{
	to->x = (int)from->x;
	to->y = (int)from->y;
	to->z = (int)from->z;
	to->color = from->color;
}
