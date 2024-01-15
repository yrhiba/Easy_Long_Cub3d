/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 05:11:58 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/15 11:10:44 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
			if (data->map[i][j] == 'X')
				continue;
			if (data->map[i][j] == '0')
				data->zero_count += 1;
			else if (data->map[i][j] == '1')
				data->one_count += 1;
			else if (my_string_have("NSEW", data->map[i][j]))
			{
				data->player_count += 1;
				set_player_data(data, i, j);
				data->map[i][j] = '0';
			}
			else if (ft_toupper(data->map[i][j]) == 'D')
			{
				data->door_count += 1;
				add_door(data, i, j);
			}
			else
				data->invalid_count += 1;
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

void	set_door_adj_content(t_data *data, t_door *door)
{
	int	y;
	int	x;
	int	i;

	i = -1;
	while (++i < 4)
	{
		y = door->y + data->dr[i];
		x = door->x + data->dc[i];
		door->adj[i] = (y < 0 || y >= data->map_height
			|| x < 0 || x >= data->map_width)
				? '1' : data->map[y][x];
	}
}

bool check_door(t_data *data, t_door *door)
{
	set_door_adj_content(data, door);
	if (door->adj[N] == door->adj[S]
		&& door->adj[E] == door->adj[W]
		&& (door->adj[N] == '1' || door->adj[N] == '0')
		&& (door->adj[E] == '1' || door->adj[E] == '0')
		&& door->adj[E] != door->adj[N])
			return true;
	return false;
}

bool	ismapdoorvalid(t_data	*data)
{
	t_my_list *it;

	it = data->doors;
	while (it)
	{
		if (!check_door(data, (t_door *)it->data))
			return (false);
		it = it->next;
	}
	return (true);
}

void	check_for_map(t_data *data)
{
	set_and_counts_map_items(data);
	if (!ismapbordervalid(data) || !ismapdoorvalid(data)
		|| (data->player_count != 1) || (data->invalid_count != 0))
		exit_failure("check_for_map::invalid map");
}
