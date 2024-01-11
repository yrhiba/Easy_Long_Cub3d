/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 02:19:26 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/12 00:11:47 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int frame_update(t_data *data)
{
	struct timeval curtime;
	gettimeofday(&curtime, NULL);

	double timepassedms = (curtime.tv_sec - data->lastframetime.tv_sec) * 1000.0f
		+ (curtime.tv_usec - data->lastframetime.tv_usec) / 1000.0f;

	if (timepassedms < FRAME_MS_TIME)
		return (0);

	float deltatime = timepassedms / 1000.0f;

	/* ########## */
	frame_fill_with_color(data->frame, getcolor(rand()%256, 0, rand()%256, rand()%256));

	for (int virusId = 0; virusId < PARTICLES; virusId++)
	{
		t_vector new_player_pos;

		new_player_pos.x = data->virus[virusId].pos.x + round(data->virus[virusId].velocty.x * deltatime);
		new_player_pos.y = data->virus[virusId].pos.y + round(data->virus[virusId].velocty.y * deltatime);

		if (new_player_pos.x - 30 < 0 || new_player_pos.x + 30 >= WIN_WIDTH)
			data->virus[virusId].velocty.x *= -1;

		if (new_player_pos.y - 30 < 0 || new_player_pos.y + 30 >= WIN_HEIGHT)
			data->virus[virusId].velocty.y *= -1;

		data->virus[virusId].pos.x += round(data->virus[virusId].velocty.x * deltatime);
		data->virus[virusId].pos.y += round(data->virus[virusId].velocty.y * deltatime);

		for (int i = -30; i <= 30; i++)
			for (int j = -30; j <= 30; j++)
			{
				int px = i + data->virus[virusId].pos.x, py = j + data->virus[virusId].pos.y;

				double distance = (px - data->virus[virusId].pos.x) * (px - data->virus[virusId].pos.x)
					+ (py - data->virus[virusId].pos.y) * (py - data->virus[virusId].pos.y);

				double range = 30;

				if ((distance <= range*range) 
					&& 0 <= px && px < WIN_WIDTH && 0 <= py && py < WIN_HEIGHT)
					frame_pixel_put(data->frame, px, py, getcolor(100 + rand()%156, 255, 0, 0));
			}
	}
	/* ########## */

	// mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->frame->img, 0, 0);
	gettimeofday(&(data->lastframetime), NULL);
	return (0);
}
