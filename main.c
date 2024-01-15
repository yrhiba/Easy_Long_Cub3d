/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:08:33 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/15 14:41:55 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void ParsingDebug(t_data *data)
{
	printf("h:%d, w:%d\n", data->map_height, data->map_width);
	printf("no:%s\n", data->textures.no_file_path);
	printf("so:%s\n", data->textures.so_file_path);
	printf("we:%s\n", data->textures.we_file_path);
	printf("ea:%s\n", data->textures.ea_file_path);
	printf("f-color:%d,%d,%d\n",
		data->floor_color.red,
		data->floor_color.green,
		data->floor_color.blue
	);
	printf("c-color:%d,%d,%d\n",
		data->ceiling_color.red,
		data->ceiling_color.green,
		data->ceiling_color.blue
	);
	for (int i = 0; i < data->map_height; i++)
	{
		for (int j = 0; j < data->map_width; j++)
			printf("%c", data->map[i][j]); // 0 1
		printf("\n");
	}
	printf("h:%d, w:%d\n", data->map_height, data->map_width);
	printf("player: (r:%d, c:%d)\n", data->player->pos.y, data->player->pos.x);
}

int		main(int ac, char **av)
{
	t_data *data;

	init_data(&data);
	do_parsing(data, ac, av);
	#if DEBUG
	ParsingDebug(data);
	#endif
	init_mlx(data);
	load_textures(data);
	init_sprites(data);
	mlx_hook(data->win, ON_KEYDOWN, 0, keypressdown, data);
	mlx_hook(data->win, ON_KEYUP, 0, keypressdup, data);
	mlx_hook(data->win, ON_DESTROY, 0, redcrosspressed, data);
	mlx_loop_hook(data->mlx, frame_update, data);
	return (mlx_loop(data->mlx), clear_data(&data), 0);
}
