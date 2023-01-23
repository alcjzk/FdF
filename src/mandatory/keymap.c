/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:16:22 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 01:37:51 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "keymap.h"

void	keymap_init(t_keymap *keymap)
{
	ft_bzero(keymap, sizeof(t_keymap));
	keymap->map[key_esc] = handle_destroy;
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
