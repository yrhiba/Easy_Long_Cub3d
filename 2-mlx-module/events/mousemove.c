/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousemove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:07:57 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/15 20:44:26 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

int	mousemove(int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	(void)data;

	// printf("%d, %d, %d\n", x, y, data->mouse_on);
	if (data->mouse_on)
	{
		data->player->rotation_angle += (x - data->lastmouse) * 1e-3;
	}

	data->lastmouse = x;
	return (0);
}
