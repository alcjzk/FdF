/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:40:58 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 01:31:29 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "hooks.h"
#include "state.h"

t_status	state_create(
				t_state *state,
				size_t width,
				size_t height,
				const char *map_path)
{
	t_status	status;

	state->mlx = mlx_init();
	if (!state->mlx)
		return (err_mlx);
	status = window_create(&state->window, state->mlx, width, height);
	if (status != ok)
		return (status);
	status = view_create(&state->view, &state->window, map_path);
	if (status != ok)
		return (status);
	keymap_init(&state->keymap);
	mlx_loop_hook(state->mlx, state_update, (void *)state);
	mlx_do_key_autorepeatoff(state->mlx);
	mlx_hook(state->window.window, ek_destroy, 0, on_destroy, state);
	mlx_hook(state->window.window, ek_keydown, 0, on_keydown, state);
	mlx_hook(state->window.window, ek_keyup, 0, on_keyup, state);
	modifiers_init(&state->modifiers);
	return (ok);
}

void	state_destroy(t_state *state)
{
	view_destroy(&state->view);
	window_destroy(&state->window);
}

int	state_update(t_state *state)
{
	(void)state;
	view_update(&state->view);
	return (0);
}
