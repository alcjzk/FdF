/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_select.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:16:12 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 01:21:20 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

void	projection_isometric(t_projection *projection)
{
	projection->rotation.x = -35.264;
	projection->rotation.y = 45.0;
	projection->rotation.z = 0.0;
	projection_update_matrix(projection);
}
