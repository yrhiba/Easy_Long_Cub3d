/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 02:19:26 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/13 04:08:32 by yrhiba           ###   ########.fr       */
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

	/* update player */
	update_player(data, deltatime);
	/* update player */

	/* cast all rays */
	cast_all_rays(data);
	/* cast all rays */

	/* clear the frame */
	frame_fill_with_color(data->frame, getcolor(0, 0, 0, 0));
	/* clear the frame */

	/* start rendering */
	render_2dmap(data);
	render_2dallrays(data);
	render_player_in2dmap(data);
	/* start rendering */

	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->frame->img, 0, 0);
	gettimeofday(&(data->lastframetime), NULL);
	return (0);
}
