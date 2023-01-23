/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 07:25:55 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 01:40:20 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

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

#endif
