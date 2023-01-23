/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_rotation_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:49:28 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 00:41:34 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection_bonus.h"

void	projection_update_pitch(
	double *pitch,
	t_modifiers *modifiers,
	double timescale)
{
	if (modifiers->map[mod_inc_pitch] && !modifiers->map[mod_dec_pitch])
	{
		*pitch += ROTATION_INCREMENT * timescale;
		if (*pitch > 180.0)
			*pitch -= 360.0;
	}
	else if (modifiers->map[mod_dec_pitch] && !modifiers->map[mod_inc_pitch])
	{
		*pitch -= ROTATION_INCREMENT * timescale;
		if (*pitch < -180.0)
			*pitch += 360.0;
	}
}

void	projection_update_yaw(
	double *yaw,
	t_modifiers *modifiers,
	double timescale)
{
	if (modifiers->map[mod_inc_yaw] && !modifiers->map[mod_dec_yaw])
	{
		*yaw += ROTATION_INCREMENT * timescale;
		if (*yaw > 180.0)
			*yaw -= 360.0;
	}
	else if (modifiers->map[mod_dec_yaw] && !modifiers->map[mod_inc_yaw])
	{
		*yaw -= ROTATION_INCREMENT * timescale;
		if (*yaw < -180.0)
			*yaw += 360.0;
	}
}

void	projection_update_roll(
	double *roll,
	t_modifiers *modifiers,
	double timescale)
{
	if (modifiers->map[mod_inc_roll] && !modifiers->map[mod_dec_roll])
	{
		*roll += ROTATION_INCREMENT * timescale;
		if (*roll > 180.0)
			*roll -= 360.0;
	}
	else if (modifiers->map[mod_dec_roll] && !modifiers->map[mod_inc_roll])
	{
		*roll -= ROTATION_INCREMENT * timescale;
		if (*roll < -180.0)
			*roll += 360.0;
	}
}
