/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:06:42 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/22 09:31:38 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mesh.h"

// void	mesh_line(t_mesh *mesh)
// {
// 	mesh->length = 2;
// 	mesh->vertices = ft_calloc(mesh->length, sizeof(t_vec4d));
// 	mesh->vertices[0] = (t_vec4d){-2, -2,  0.5, 1, {.value = 0x00FF00FF}};
// 	mesh->vertices[1] = (t_vec4d){1, 1,  0.5, 1, {.value = 0x00FF00FF}};
// }

// t_status	mesh_cube(t_mesh *mesh)
// {
// 	mesh->length = 24;
// 	mesh->vertices = ft_calloc(mesh->length, sizeof(t_vec4d));
// 	mesh->vertices[0] = (t_vec4d){-0.5, -0.5,  0.5, 1, {.value = 0x00FF00FF}};
// 	mesh->vertices[1] = (t_vec4d){-0.5,  0.5,  0.5, 1, {.value = 0x00FF00FF}};
// 	mesh->vertices[2] = (t_vec4d){-0.5,  0.5,  0.5, 1, {.value = 0x00FF00FF}};
// 	mesh->vertices[3] = (t_vec4d){ 0.5,  0.5,  0.5, 1, {.value = 0x00FFFF00}};
// 	mesh->vertices[4] = (t_vec4d){ 0.5,  0.5,  0.5, 1, {.value = 0x00FFFF00}};
// 	mesh->vertices[5] = (t_vec4d){ 0.5, -0.5,  0.5, 1, {.value = 0x00FFFF00}};
// 	mesh->vertices[6] = (t_vec4d){ 0.5, -0.5,  0.5, 1, {.value = 0x00FFFF00}};
// 	mesh->vertices[7] = (t_vec4d){-0.5, -0.5,  0.5, 1, {.value = 0x00FF00FF}};
// 	mesh->vertices[8] = (t_vec4d){-0.5, -0.5, -0.5, 1, {.value = 0x000000FF}};
// 	mesh->vertices[9] = (t_vec4d){-0.5,  0.5, -0.5, 1, {.value = 0x000000FF}};
// 	mesh->vertices[10] = (t_vec4d){-0.5,  0.5, -0.5, 1, {.value = 0x000000FF}};
// 	mesh->vertices[11] = (t_vec4d){ 0.5,  0.5, -0.5, 1, {.value = 0x0000FF00}};
// 	mesh->vertices[12] = (t_vec4d){ 0.5,  0.5, -0.5, 1, {.value = 0x0000FF00}};
// 	mesh->vertices[13] = (t_vec4d){ 0.5, -0.5, -0.5, 1, {.value = 0x0000FF00}};
// 	mesh->vertices[14] = (t_vec4d){ 0.5, -0.5, -0.5, 1, {.value = 0x0000FF00}};
// 	mesh->vertices[15] = (t_vec4d){-0.5, -0.5, -0.5, 1, {.value = 0x000000FF}};
// 	mesh->vertices[16] = (t_vec4d){ 0.5,  0.5,  0.5, 1, {.value = 0x00FFFF00}};
// 	mesh->vertices[17] = (t_vec4d){ 0.5,  0.5, -0.5, 1, {.value = 0x0000FF00}};
// 	mesh->vertices[18] = (t_vec4d){-0.5,  0.5,  0.5, 1, {.value = 0x00FF00FF}};
// 	mesh->vertices[19] = (t_vec4d){-0.5,  0.5, -0.5, 1, {.value = 0x000000FF}};
// 	mesh->vertices[20] = (t_vec4d){-0.5, -0.5,  0.5, 1, {.value = 0x00FF00FF}};
// 	mesh->vertices[21] = (t_vec4d){-0.5, -0.5, -0.5, 1, {.value = 0x000000FF}};
// 	mesh->vertices[22] = (t_vec4d){ 0.5, -0.5,  0.5, 1, {.value = 0x00FFFF00}};
// 	mesh->vertices[23] = (t_vec4d){ 0.5, -0.5, -0.5, 1, {.value = 0x0000FF00}};
// 	return (OK);
// }

void	mesh_destroy(t_mesh *mesh)
{
	if (mesh->vertices)
		free(mesh->vertices);
}
