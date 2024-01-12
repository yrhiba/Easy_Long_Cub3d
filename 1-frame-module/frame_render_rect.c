/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_render_rect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 06:05:33 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/12 06:12:08 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	frame_render_rect(t_frame *frame, t_vector pos, int color, int width, int height)
{
	int	x;
	int	y;

	x = -1;
	while (++x < width)
	{
		y = -1;
		while (++y < height)
			frame_pixel_put(frame, pos.x + x, pos.y + y, color);
	}
	return (0);
}
