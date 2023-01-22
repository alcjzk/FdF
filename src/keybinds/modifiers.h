/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:18:44 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/16 22:32:45 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODIFIERS_H
# define MODIFIERS_H

# define MOD_MAX 12

# include "keymap.h"
# include "bool.h"

typedef enum e_modifier
{
	mod_inc_yaw = 1,
	mod_dec_yaw = 2,
	mod_inc_pitch = 3,
	mod_dec_pitch = 4,
	mod_inc_roll = 5,
	mod_dec_roll = 6,
	mod_inc_scale = 7,
	mod_dec_scale = 8,
	mod_inc_x = 9,
	mod_dec_x = 10,
	mod_inc_y = 11,
	mod_dec_y = 12
}	t_modifier;

typedef struct t_modifiers
{
	BOOL		map[MOD_MAX + 1];
	t_modifier	keymap[KEY_MAX + 1];
}	t_modifiers;

void	modifiers_init(t_modifiers *modifiers);

#endif
