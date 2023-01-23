/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 09:06:38 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 00:44:23 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_BONUS_H
# define UTIL_BONUS_H

# include "bool.h"

double	dmax(double a, double b);
double	dmin(double a, double b);
double	dabs(double value);
BOOL	str_startswith(const char *str, const char *substr);
BOOL	is_hex(char c);

#endif
