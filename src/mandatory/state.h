/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:40:23 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/23 21:44:15 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# include "status.h"
# include "keymap.h"
# include "view.h"
# include "modifiers.h"
# include "window.h"

typedef struct s_state
{
	void			*mlx;
	t_window		window;
	t_keymap		keymap;
	t_view			view;
	t_modifiers		modifiers;
}	t_state;

t_status	state_create(
				t_state *state,
				size_t width,
				size_t height,
				const char *map_path);
void		state_destroy(t_state *state);
int			state_update(t_state *state);

#endif
