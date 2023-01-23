/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 10:38:40 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 01:40:06 by tjaasalo         ###   ########.fr       */
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
