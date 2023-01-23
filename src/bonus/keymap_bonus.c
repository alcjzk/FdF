/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:16:22 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 00:34:05 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "keymap_bonus.h"

void	keymap_init(t_keymap *keymap)
{
	ft_bzero(keymap, sizeof(t_keymap));
	keymap->map[key_esc] = handle_destroy;
	keymap->map[key_right] = handle_modifier;
	keymap->map[key_left] = handle_modifier;
	keymap->map[key_up] = handle_modifier;
	keymap->map[key_down] = handle_modifier;
	keymap->map[key_w] = handle_modifier;
	keymap->map[key_s] = handle_modifier;
	keymap->map[key_d] = handle_modifier;
	keymap->map[key_a] = handle_modifier;
	keymap->map[key_e] = handle_modifier;
	keymap->map[key_q] = handle_modifier;
	keymap->map[key_i] = handle_modifier;
	keymap->map[key_o] = handle_modifier;
	keymap->map[key_1] = handle_set_isometric;
	keymap->map[key_2] = handle_set_parallel;
}

int	keymap_handle_key(t_keymap *keymap, t_event *event)
{
	t_handler	func;

	if (event->keycode < KEY_MIN || event->keycode > KEY_MAX)
		return (0);
	func = keymap->map[event->keycode];
	if (!func)
		return (0);
	return (func(event));
}
