/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:33:53 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 01:31:07 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

# include <sys/time.h>
# include "matrix4d.h"
# include "vec3d.h"
# include "mesh.h"
# include "window.h"

typedef struct s_projection
{
	t_matrix4d			mat_ortho;
	t_matrix4d			mat_zyx;
	t_matrix4d			matrix;
	t_vec3d				rotation;
	unsigned long long	timestamp;
}	t_projection;

void	projection_init(
			t_projection *projection,
			t_mesh *mesh,
			t_window *window);
void	projection_update_matrix(t_projection *projection);
void	projection_isometric(t_projection *projection);
void	projection_update(t_projection *projection);

#endif
