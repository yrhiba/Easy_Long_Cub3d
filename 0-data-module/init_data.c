/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:36:04 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/12 00:34:32 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void init_data(t_data **data)
{
	*data = (t_data *)malloc(sizeof(t_data));
	if ((*data) == NULL)
		exit_failure("init_data::malloc failled");
	(*data)->frame = (t_frame *)malloc(sizeof(t_frame));
	(*data)->player = (t_player *)malloc(sizeof(t_player));
	if (((*data)->player == NULL) || ((*data)->frame == NULL))
		exit_failure("init_data::malloc failled");
	(*data)->map = NULL;
	(*data)->mini_map = NULL;
	(*data)->map_width = 0;
	(*data)->map_height = 0;
	(*data)->map_file_lines = NULL;
	gettimeofday(&((*data)->lastframetime), NULL);
}
