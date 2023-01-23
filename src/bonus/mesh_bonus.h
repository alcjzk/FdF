/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:07:18 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 00:39:42 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_BONUS_H
# define MESH_BONUS_H

# include <stddef.h>
# include "status_bonus.h"
# include "vec4d_bonus.h"

typedef struct s_mesh
{
	t_vec4d		*vertices;
	size_t		length;
}	t_mesh;

void	mesh_destroy(t_mesh *mesh);

#endif
