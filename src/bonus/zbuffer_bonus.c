/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zbuffer_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:31:12 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 00:46:28 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "libft.h"
#include "zbuffer_bonus.h"

t_status	zbuffer_create(t_zbuffer *buffer, size_t width, size_t height)
{
	ft_bzero(buffer, sizeof(t_zbuffer));
	buffer->buf = malloc(sizeof(float) * width * height);
	if (!buffer->buf)
		return (err_sys);
	buffer->width = width;
	buffer->height = height;
	return (ok);
}

void	zbuffer_destroy(t_zbuffer *buffer)
{
	if (buffer->buf)
		free(buffer->buf);
}

void	zbuffer_clear(t_zbuffer *buffer)
{
	size_t	idx;

	idx = buffer->width * buffer->height;
	while (idx-- > 0)
		buffer->buf[idx] = -INFINITY;
}

BOOL	zbuffer_set(t_zbuffer *buffer, size_t x, size_t y, float value)
{
	size_t	idx;

	idx = y * buffer->width + x;
	if (buffer->buf[idx] > value)
		return (FALSE);
	buffer->buf[idx] = value;
	return (TRUE);
}
