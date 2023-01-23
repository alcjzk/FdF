/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:46:28 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/17 18:44:33 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "vec4d.h"

typedef struct s_line4d
{
	t_vec4d		start;
	t_vec4d		end;
}	t_line4d;

#endif
