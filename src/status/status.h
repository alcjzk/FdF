/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:33:14 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/22 10:51:14 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATUS_H
# define STATUS_H

typedef enum e_status
{
	ok = 0,
	err_sys = 1,
	err_arg = 2,
	err_map = 3,
	err_mlx = 4
}	t_status;

void	print_error(t_status status);

#endif
