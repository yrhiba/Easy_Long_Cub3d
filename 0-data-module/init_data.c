/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:36:04 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/11 23:59:27 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void init_data(t_data **data)
{
	*data = (t_data *)malloc(sizeof(t_data));
	if ((*data) == NULL)
		exit_failure("init_data::malloc failled");
	(*data)->frame = (t_frame *)malloc(sizeof(t_frame));
	for (int i = 0; i < PARTICLES; i++)
	{
		(*data)->virus[i].pos.x = rand() % WIN_WIDTH;
		(*data)->virus[i].pos.y = rand() % WIN_HEIGHT;
		(*data)->virus[i].velocty.x = 100 + rand() % 500;
		(*data)->virus[i].velocty.y = (100 + rand() % 500)
				* (rand()%2 ? 1 : -1);
	}
	(*data)->map = NULL;
	(*data)->mini_map = NULL;
	(*data)->map_width = 0;
	(*data)->map_height = 0;
	srand(time(0));
	gettimeofday(&((*data)->lastframetime), NULL);
}
