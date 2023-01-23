/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:06:42 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 00:39:26 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mesh_bonus.h"

void	mesh_destroy(t_mesh *mesh)
{
	if (mesh->vertices)
		free(mesh->vertices);
}
