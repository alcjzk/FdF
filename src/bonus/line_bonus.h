/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:46:28 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/24 00:34:46 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_BONUS_H
# define LINE_BONUS_H

# include "vec4d_bonus.h"

typedef struct s_line4d
{
	t_vec4d		start;
	t_vec4d		end;
}	t_line4d;

#endif
