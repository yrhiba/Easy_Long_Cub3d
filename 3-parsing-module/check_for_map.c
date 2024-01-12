/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 05:11:58 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/12 07:43:42 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_player_data(t_data *data, int y, int x)
{
	data->player->pos.x = (x * TILE_WIDTH) + (TILE_WIDTH / 2);
	data->player->pos.y = (y * TILE_HEIGTH) + (TILE_HEIGTH / 2);
}

void	set_and_counts_map_items(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < data->map_width)
		{
			if (data->map[i][j] == '0')
				data->zero_count += 1;
			if (data->map[i][j] == '1')
				data->one_count += 1;
			if (my_string_have("NSEW", data->map[i][j]))
			{
				data->player_count += 1;
				set_player_data(data, i, j);
				data->map[i][j] = '0';
			}
		}
	}
}

bool	check_adj_x(t_data *data, int i, int j)
{
	int	ii;
	int	jj;
	int	d;

	d = -1;
	while (++d < 4)
	{
		ii	= i + data->dr[d];
		jj	= j + data->dc[d];
		if (ii < 0 || ii >= data->map_height)
			continue;
		if (jj < 0 || jj >= data->map_width)
			continue;
		if (data->map[ii][jj] != 'X' && data->map[ii][jj] != '1')
			return (false);
	}
	return (true);
}

bool	ismapbordervalid(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < data->map_width)
		{
			if (data->map[i][j] != 'X')
				continue;
			if (!check_adj_x(data, i, j))
				return (false);
		}
	}
	return (true);
}

void	check_for_map(t_data *data)
{
	set_and_counts_map_items(data);
	if (!ismapbordervalid(data) || (data->player_count != 1))
		exit_failure("check_for_map::invalid map");
}
