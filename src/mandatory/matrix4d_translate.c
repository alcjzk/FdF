/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:26:32 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/23 21:17:53 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "matrix4d.h"

void	matrix4d_translate(t_matrix4d *matrix, t_vec3d *position)
{
	ft_bzero(matrix, sizeof(t_matrix4d));
	matrix->m[0][3] = position->x;
	matrix->m[1][3] = position->y;
	matrix->m[2][3] = position->z;
	matrix->m[0][0] = 1.0;
	matrix->m[1][1] = 1.0;
	matrix->m[2][2] = 1.0;
	matrix->m[3][3] = 1.0;
}
