/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds4d_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:33:20 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 00:31:13 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOUNDS4D_BONUS_H
# define BOUNDS4D_BONUS_H

# include <stddef.h>
# include "vec4d_bonus.h"

typedef struct s_bounds4d
{
	t_vec4d	min;
	t_vec4d	max;
}	t_bounds4d;

void	bounds4d_init(t_bounds4d *bounds, t_vec4d *vertices, size_t length);

#endif
