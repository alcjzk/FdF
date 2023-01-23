/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:16:04 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 01:29:28 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYMAP_H
# define KEYMAP_H

# include "hooks.h"

# define KEY_MAX 126
# define KEY_MIN 0

typedef enum e_key
{
	key_esc = 53,
	key_d = 2,
	key_a = 0,
	key_w = 13,
	key_s = 1,
	key_e = 14,
	key_q = 12,
	key_left = 123,
	key_up = 126,
	key_right = 124,
	key_down = 125,
	key_c = 8,
	key_f = 3,
	key_i = 34,
	key_o = 31,
	key_1 = 18,
	key_2 = 19
}	t_key;

typedef int	(*t_handler)(t_event *);

typedef struct s_keymap
{
	t_handler	map[KEY_MAX + 1];
}	t_keymap;

void	keymap_init(t_keymap *keymap);
int		keymap_handle_key(t_keymap *keymap, t_event *event);
int		handle_modifier(t_event *event);
int		handle_destroy(t_event *event);
int		handle_set_isometric(t_event *event);

#endif
