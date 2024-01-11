/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_pixel_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:08:33 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/10 23:39:55 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	frame_pixel_put(t_frame *frame, int x, int y, int color)
{
	char	*dst;

	dst = frame->addr + (y * frame->line_length + x * (frame->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
