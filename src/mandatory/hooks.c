/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 07:26:18 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 01:39:44 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keymap.h"
#include "state.h"
#include "hooks.h"

int	on_destroy(void *param)
{
	t_event	event;

	event.param = param;
	event.kind = ek_destroy;
	return (handle_destroy(&event));
}

int	on_keyup(int keycode, void *param)
{
	t_event		event;

	event.param = param;
	event.kind = ek_keyup;
	event.keycode = keycode;
	return (keymap_handle_key(&((t_state *)param)->keymap, &event));
}
