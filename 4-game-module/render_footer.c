/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_footer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 03:23:42 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/14 04:09:35 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

void	render_footer(t_data *data)
{
	t_vector p, e;

	p.x = 0;
	p.y = WIN_HEIGHT;
	e.x = WIN_WIDTH;
	e.y = WIN_HEIGHT + FOOTER_HEIGHT;

	frame_render_rect(data->frame, p, getcolor(150, 0, 255, 0), e);

	struct timeval cur;
	gettimeofday(&cur, NULL);

	data->fs = my_string_dup("fps ( ");

	char *n = ft_itoa(data->fps_counted);
	my_string_append(&data->fs, n);
	my_string_append(&data->fs, " )");

	mlx_string_put(data->mlx, data->win, WIN_WIDTH - 180, WIN_HEIGHT - 50, getcolor(0, 0, 0, 0), data->fs);

	double pt = (cur.tv_sec - data->stime.tv_sec) * 1000.0f
		+ (cur.tv_usec - data->stime.tv_usec) / 1000.0f;

	if (pt >= 1e3)
	{
		data->fps_counted = data->frame_count;
		data->frame_count = 0;
		gettimeofday(&data->stime, NULL);
	}

	free(n);
	free(data->fs);
}
