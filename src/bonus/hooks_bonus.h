/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 07:25:55 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 00:33:35 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_BONUS_H
# define HOOKS_BONUS_H

typedef enum e_eventkind
{
	ek_keydown = 2,
	ek_keyup = 3,
	ek_destroy = 17,
	ek_expose = 12
}	t_eventkind;

typedef struct s_event
{
	t_eventkind	kind;
	void		*param;
	int			keycode;
}	t_event;

int	on_destroy(void *param);
int	on_keyup(int keycode, void *param);
int	on_keydown(int keycode, void *param);

#endif
