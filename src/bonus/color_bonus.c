/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 06:25:30 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 06:29:45 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util_bonus.h"
#include "color_bonus.h"

static int	hex_value(unsigned char c)
{
	c = ft_toupper(c);
	if (ft_isdigit(c))
		return (c - 48);
	if (c >= 'A' && c <= 'F')
		return (c - 55);
	return (-1);
}

t_color	color_from_str(const char *str)
{
	t_color		color;
	int			value;
	size_t		max;

	max = 4;
	color.value = 0;
	if (str_startswith(str, "0x"))
		str += 2;
	value = hex_value(*(str++));
	while (max-- > 0 && value != -1)
	{
		color.value <<= 4;
		color.value |= value;
		value = hex_value(*(str++));
	}
	return (color);
}
