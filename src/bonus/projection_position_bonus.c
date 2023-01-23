/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_position_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:48:36 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 00:41:30 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection_bonus.h"

void	projection_update_scale(
	double *scale,
	t_modifiers *modifiers,
	double timescale)
{
	if (modifiers->map[mod_inc_scale] && !modifiers->map[mod_dec_scale])
	{
		*scale += SCALE_INCREMENT * timescale;
		if (*scale > SCALE_MAX)
			*scale = SCALE_MAX;
	}
	else if (modifiers->map[mod_dec_scale] && !modifiers->map[mod_inc_scale])
	{
		*scale -= SCALE_INCREMENT * timescale;
		if (*scale < SCALE_MIN)
			*scale = SCALE_MIN;
	}
}

void	projection_update_x(
	double *x,
	t_modifiers *modifiers,
	double timescale)
{
	if (modifiers->map[mod_inc_x] && !modifiers->map[mod_dec_x])
	{
		*x += POSITION_INCREMENT * timescale;
		if (*x > POSITION_MAX)
			*x = POSITION_MAX;
	}
	else if (modifiers->map[mod_dec_x] && !modifiers->map[mod_inc_x])
	{
		*x -= POSITION_INCREMENT * timescale;
		if (*x < POSITION_MIN)
			*x = POSITION_MIN;
	}
}

void	projection_update_y(
	double *y,
	t_modifiers *modifiers,
	double timescale)
{
	if (modifiers->map[mod_inc_y] && !modifiers->map[mod_dec_y])
	{
		*y += POSITION_INCREMENT * timescale;
		if (*y > POSITION_MAX)
			*y = POSITION_MAX;
	}
	else if (modifiers->map[mod_dec_y] && !modifiers->map[mod_inc_y])
	{
		*y -= POSITION_INCREMENT * timescale;
		if (*y < POSITION_MIN)
			*y = POSITION_MIN;
	}
}
