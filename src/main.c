/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:47:52 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/01/23 22:11:13 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "status.h"
#include "state.h"

void	handle_error(t_status status, t_state *state)
{
	if (state)
		state_destroy(state);
	print_error(status);
	exit(-1);
}

int	main(int argc, char **argv)
{
	t_state		state;
	t_status	status;

	if (argc != 2)
		handle_error(err_arg, NULL);
	status = state_create(&state, 1500, 1000, argv[1]);
	if (status != ok)
		handle_error(status, &state);
	mlx_loop(state.mlx);
	return (0);
}
