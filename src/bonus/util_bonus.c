/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 09:06:31 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 00:44:13 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util_bonus.h"

double	dmax(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double	dmin(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

double	dabs(double value)
{
	if (value < 0)
		return (-value);
	return (value);
}

BOOL	str_startswith(const char *str, const char *substr)
{
	if (!str || !substr)
		return (FALSE);
	while (*substr)
	{
		if (*(substr++) != *(str++))
			return (FALSE);
	}
	return (TRUE);
}

BOOL	is_hex(char c)
{
	if (ft_isdigit(c))
		return (TRUE);
	c = ft_toupper(c);
	if (c >= 'A' && c <= 'F')
		return (TRUE);
	return (FALSE);
}
