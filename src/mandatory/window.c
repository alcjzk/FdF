/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:06:18 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/23 22:06:05 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "window.h"

t_status	window_create(
				t_window *window,
				void *mlx,
				size_t width,
				size_t height)
{
	window->window = mlx_new_window(mlx, width, height, WINDOW_TITLE);
	if (!window->window)
		return (err_mlx);
	window->width = width;
	window->height = height;
	window->mlx = mlx;
	window->aspect_ratio = (double)width / (double)height;
	return (ok);
}

void	window_destroy(t_window *window)
{
	if (window->window)
		mlx_destroy_window(window->mlx, window->window);
}
