/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:14:56 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/21 23:08:39 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <stddef.h>
# include "color.h"
# include "status.h"
# include "bool.h"

typedef struct s_image
{
	void				*mlx;
	void				*img;
	char				*addr;
	size_t				width;
	size_t				height;
	int					bpp;
	int					endian;
	int					foo;
}	t_image;

t_status	image_new(t_image *image, void *mlx, size_t width, size_t height);
void		image_put_pixel(t_image *image, int x, int y, t_color color);
void		image_clear(t_image *image);
void		image_destroy(t_image *image);

#endif
