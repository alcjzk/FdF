/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:42:24 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 01:49:21 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "projection.h"

void	projection_init(
	t_projection *proj,
	t_mesh *mesh,
	t_window *window)
{
	ft_bzero(proj, sizeof(t_projection));
	matrix4d_ortho_mesh(&proj->mat_ortho, mesh, window->aspect_ratio);
	projection_isometric(proj);
}

void	projection_update_matrix(t_projection *proj)
{
	matrix4d_rotate(&proj->mat_zyx, &proj->rotation);
	matrix4d_multiply(&proj->mat_ortho, &proj->mat_zyx, &proj->matrix);
}

void	projection_update(t_projection *projection)
{
	projection_update_matrix(projection);
}
