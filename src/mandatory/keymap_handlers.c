/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 10:38:40 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/23 19:35:51 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "state.h"
#include "keymap.h"

int	handle_destroy(t_event *event)
{
	if (event->kind == ek_destroy || event->kind == ek_keyup)
	{
		state_destroy(event->param);
		exit(0);
	}
	return (0);
}

int	handle_set_isometric(t_event *event)
{
	if (event->kind == ek_keydown)
		projection_isometric(&((t_state *)(event->param))->view.projection);
	return (0);
}

int	handle_set_parallel(t_event *event)
{
	if (event->kind == ek_keydown)
		projection_parallel(&((t_state *)(event->param))->view.projection);
	return (0);
}

int	handle_modifier(t_event *event)
{
	t_modifiers	*modifiers;
	t_modifier	modifier;

	modifiers = &((t_state *)event->param)->modifiers;
	modifier = modifiers->keymap[event->keycode];
	if (event->kind == ek_keydown)
		modifiers->map[modifier] = TRUE;
	else if (event->kind == ek_keyup)
		modifiers->map[modifier] = FALSE;
	return (0);
}
