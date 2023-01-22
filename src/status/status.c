/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:36:53 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/22 10:51:48 by tjaasalo         ###   ########.fr       */
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
		write(2, "Map error!", 11);
	else if (status == err_arg)
		write(2, "Invalid number of arguments!", 29);
	else if (status == err_mlx)
		write(2, "Mlx error!", 11);
}
