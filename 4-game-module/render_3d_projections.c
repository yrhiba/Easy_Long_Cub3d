/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_projections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 06:06:05 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/14 02:54:37 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

void render_3d_projections(t_data *data)
{
	int i;

	// renderCeiling();
	// renderFloor();
	i = -1;
	while (++i < WIN_WIDTH)
	{
		data->rays[i].correct_wall_dis = data->rays[i].distance
			* cos( data->rays[i].ray_angle - data->player->rotation_angle);

		if (data->rays[i].correct_wall_dis < 1e-6)
			data->rays[i].wall_height = WIN_HEIGHT;
		else
			data->rays[i].wall_height = (TILE_HEIGTH / data->rays[i].correct_wall_dis)
								* ((WIN_WIDTH / 2) / tan(FOV / 2));


		data->rays[i].start_row = round((WIN_HEIGHT / 2) - (data->rays[i].wall_height / 2));
		if (data->rays[i].start_row < 0)
			data->rays[i].start_row = 0;

		data->rays[i].end_row = round((WIN_HEIGHT / 2) + (data->rays[i].wall_height / 2));
		if (data->rays[i].start_row >= WIN_HEIGHT)
			data->rays[i].start_row = (WIN_HEIGHT - 1);

		t_vector start, end;

		start.y = data->rays[i].start_row;
		start.x = i;

		end.y = data->rays[i].end_row;
		end.x = i;

		frame_render_line(data->frame, start, end, getcolor(0, 255, 255, 255));
	}
}
