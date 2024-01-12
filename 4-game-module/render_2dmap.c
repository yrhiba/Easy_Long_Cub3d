/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2dmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 06:20:25 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/12 10:17:58 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

void render_player_in2dmap(t_data *data)
{
	t_vector	pos;
	t_vector	vel;
	int			player_size;

	player_size = 15;
	pos.x = data->player->pos.x - (player_size/2);
	pos.y = data->player->pos.y - (player_size/2);
	vel.x = data->player->pos.x + round(cos(data->player->rotation_angle) * 30);
	vel.y = data->player->pos.y + round(sin(data->player->rotation_angle) * 30);
	frame_render_rect(data->frame, pos, getcolor(0, 0, 255, 0), player_size, player_size);
	frame_render_line(data->frame, data->player->pos, vel, getcolor(0, 255, 0, 0));
}

void render_2dmap(t_data *data)
{
	int color;
	t_vector pos;
	t_vector g;

	pos.y = -1;
	while (++(pos.y) < data->map_height)
	{
		pos.x = -1;
		while (++(pos.x) < data->map_width)
		{
			if (data->map[pos.y][pos.x] == 'X')
				color = getcolor(0, 156, 156, 156);
			if (data->map[pos.y][pos.x] == '0')
				color = getcolor(0, 255, 255, 255);
			if (data->map[pos.y][pos.x] == '1')
				color = getcolor(0, 0, 0, 0);
			g.x = pos.x * TILE_WIDTH;
			g.y = pos.y * TILE_HEIGTH;
			frame_render_rect(data->frame, g, color, TILE_WIDTH, TILE_HEIGTH);
		}
	}
	render_player_in2dmap(data);
}
