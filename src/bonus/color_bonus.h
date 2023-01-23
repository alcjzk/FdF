/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 07:00:01 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 00:32:23 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_BONUS_H
# define COLOR_BONUS_H

# include <stddef.h>

typedef union u_color
{
	int				value;
	unsigned char	bytes[4];
}	t_color;

typedef enum e_color_channel
{
	c_a = 0,
	c_r = 1,
	c_g = 2,
	c_b = 3
}	t_color_channel;

typedef struct s_color4d
{
	double	a;
	double	r;
	double	g;
	double	b;
}	t_color4d;

//	Color
t_color	color_from_str(const char *str);
//	Color4d
t_color	color_from_color4d(t_color4d *color4d);
void	color_as_color4d(t_color color, t_color4d *color4d);
//	Ops
void	color4d_sub(t_color4d *lhs, t_color4d *rhs, t_color4d *out);
void	color4d_sub_assign(t_color4d *lhs, t_color4d *rhs);
void	color4d_div_assign(t_color4d *lhs, double rhs);
void	color4d_add_assign(t_color4d *lhs, t_color4d *rhs);

#endif
