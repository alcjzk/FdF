/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:36:53 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/27 01:31:08 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "status.h"

void	print_error(t_status status)
{
	if (status == err_sys)
		perror((void *)0);
	else if (status == err_map)
		write(2, "Map error!\n", 12);
	else if (status == err_arg)
		write(2, "Usage: ./fdf map_path\n", 23);
	else if (status == err_mlx)
		write(2, "Mlx error!\n", 12);
}
