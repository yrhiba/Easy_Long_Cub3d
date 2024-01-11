/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:08:33 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/11 06:00:27 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int ac, char **av)
{
	t_data *data;

	init_data(&data);
	do_parsing(data, ac, av);
	init_mlx(data);
	mlx_hook(data->win, ON_KEYDOWN, 0, keypressdown, data);
	mlx_hook(data->win, ON_DESTROY, 0, redcrosspressed, data);
	mlx_loop_hook(data->mlx, frame_update, data);
	return (mlx_loop(data->mlx), clear_data(&data), 0);
}
