/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:07:18 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/23 21:35:50 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H

# include <stddef.h>
# include "status.h"
# include "vec4d.h"

typedef struct s_mesh
{
	t_vec4d		*vertices;
	size_t		length;
}	t_mesh;

void	mesh_destroy(t_mesh *mesh);

#endif
