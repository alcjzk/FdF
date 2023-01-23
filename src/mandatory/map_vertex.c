/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:22:14 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/22 15:15:28 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util.h"
#include "map.h"

BOOL	is_vertex(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (i == 0)
		return (FALSE);
	if (str_startswith(&str[i], ",0x"))
	{
		i += 3;
		while (is_hex(str[i]))
			i++;
	}
	if (str[i] == '\n')
		i++;
	if (!str[i])
		return (TRUE);
	return (FALSE);
}

void	map_vertex(t_vec4d *vertex, char *str, double x, double z)
{
	char	*color;

	color = (char *)0;
	vertex->x = x;
	vertex->y = ft_atoi(str);
	vertex->z = -z;
	vertex->w = 1.0;
	vertex->color = (t_color){.value = 0x00FFFFFF};
	color = ft_strchr(str, ',');
	if (color)
		vertex->color = color_from_str(++color);
}
