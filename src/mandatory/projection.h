/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:33:53 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/27 01:15:40 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

# include "matrix4d.h"
# include "vec3d.h"
# include "mesh.h"
# include "window.h"

typedef struct s_projection
{
	t_matrix4d			mat_ortho;
	t_matrix4d			mat_zyx;
	t_matrix4d			mat_scale;
	t_matrix4d			mat_zyxs;
	t_matrix4d			matrix;
	t_vec3d				rotation;
	double				scale;
}	t_projection;

void	projection_init(
			t_projection *projection,
			t_mesh *mesh,
			t_window *window);
void	projection_update_matrix(t_projection *projection);
void	projection_isometric(t_projection *projection);
void	projection_update(t_projection *projection);

#endif
