/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:04:20 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 00:46:20 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_BONUS_H
# define WINDOW_BONUS_H

# define WINDOW_TITLE "FdF"

# include <stddef.h>
# include "status_bonus.h"

typedef struct s_window
{
	void	*mlx;
	void	*window;
	size_t	height;
	size_t	width;
	double	aspect_ratio;
}	t_window;

t_status	window_create(
				t_window *window,
				void *mlx,
				size_t width,
				size_t height);
void		window_destroy(t_window *window);

#endif
