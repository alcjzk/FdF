/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color4d_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:44:06 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 00:32:35 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_bonus.h"

void	color_as_color4d(t_color color, t_color4d *color4d)
{
	color4d->a = color.bytes[c_a];
	color4d->r = color.bytes[c_r];
	color4d->g = color.bytes[c_g];
	color4d->b = color.bytes[c_b];
}

t_color	color_from_color4d(t_color4d *color4d)
{
	t_color	color;

	color.bytes[c_a] = color4d->a;
	color.bytes[c_r] = color4d->r;
	color.bytes[c_g] = color4d->g;
	color.bytes[c_b] = color4d->b;
	return (color);
}
