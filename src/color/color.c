/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 06:25:30 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/16 20:25:58 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include "libft.h"
#include "bool.h"
#include "util.h"
#include "color.h"

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

	color.value = 0;
	if (str_startswith(str, "0x"))
		str += 2;
	value = hex_value(*(str++));
	while (value != -1)
	{
		color.value <<= 4;
		color.value |= value;
		value = hex_value(*(str++));
	}
	return (color);
}

void	color_debug(t_color color)
{
	printf("t_color { R:%02X, G:%02X, B:%02X, A:%02X }\n",
		(unsigned char)color.bytes[c_r],
		(unsigned char)color.bytes[c_g],
		(unsigned char)color.bytes[c_b],
		(unsigned char)color.bytes[c_a]
		);
}
