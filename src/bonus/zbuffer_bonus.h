/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zbuffer_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:31:21 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 00:46:40 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZBUFFER_BONUS_H
# define ZBUFFER_BONUS_H

# include <stddef.h>
# include "bool.h"
# include "status_bonus.h"

typedef struct s_zbuffer
{
	float	*buf;
	size_t	width;
	size_t	height;
}	t_zbuffer;

t_status	zbuffer_create(t_zbuffer *buffer, size_t width, size_t height);
void		zbuffer_destroy(t_zbuffer *buffer);
void		zbuffer_clear(t_zbuffer *buffer);
BOOL		zbuffer_set(t_zbuffer *buffer, size_t x, size_t y, float value);

#endif
