/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:18:28 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/22 15:17:31 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "modifiers.h"

void	modifiers_init(t_modifiers *modifiers)
{
	ft_bzero(modifiers, sizeof(t_modifiers));
	modifiers->keymap[key_right] = mod_inc_x;
	modifiers->keymap[key_left] = mod_dec_x;
	modifiers->keymap[key_up] = mod_inc_y;
	modifiers->keymap[key_down] = mod_dec_y;
	modifiers->keymap[key_w] = mod_inc_pitch;
	modifiers->keymap[key_s] = mod_dec_pitch;
	modifiers->keymap[key_a] = mod_inc_yaw;
	modifiers->keymap[key_d] = mod_dec_yaw;
	modifiers->keymap[key_q] = mod_inc_roll;
	modifiers->keymap[key_e] = mod_dec_roll;
	modifiers->keymap[key_i] = mod_inc_scale;
	modifiers->keymap[key_o] = mod_dec_scale;
}
