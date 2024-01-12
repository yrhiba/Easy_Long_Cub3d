/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 05:03:39 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/12 08:12:59 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void check_arguments(int ac, char **av)
{
	if (ac != 2 || !check_ext(av[1], ".cub"))
	{
		exit_failure("one file must be provided with <.cub> extension");
	}
}

void read_input_file(t_data *data, char **av)
{
	if (!read_file_content(data, av[1]))
	{
		exit_failure("read_file_content()::failed");
	}
}

void check_for_vars(t_data *data)
{
	if (!data->floor_color_given
		|| !data->ceiling_color_given
		|| !(data->textures.ea_file_path)
		|| !(data->textures.so_file_path)
		|| !(data->textures.we_file_path)
		|| !(data->textures.no_file_path))
			exit_failure("check_for_vars::vars missing in the file");
}

void	parse_vars_till_map_found(t_data *data, t_my_list **it)
{
	bool	map_found;

	map_found = false;
	while (*it)
	{
		check_line(data, (char *)(*it)->data, &map_found);
		if (map_found)
			return ;
		(*it) = (*it)->next;
	}
}

void	pushing_map_lines(t_data *data, t_my_list **it)
{
	while (*it)
	{
		if (my_list_push_back(&data->map_only_lines,
			my_list_new_elem(my_string_dup((char *)(*it)->data), my_string_free)) == -1)
				exit_failure("do_parsing::my_list_push_back::failed");
		data->map_width = ft_max(ft_strlen((char *)(*it)->data), data->map_width);
		data->map_height += 1;
		*it = (*it)->next;
	}
}

void	do_parsing(t_data *data, int ac, char **av)
{
	t_my_list	*it;

	check_arguments(ac, av);
	read_input_file(data, av);
	it = data->map_file_lines;
	parse_vars_till_map_found(data, &it);
	pushing_map_lines(data, &it);
	check_for_vars(data);
	construct_map(data);
	set_directions(data);
	check_for_map(data);
	clear_parsing_data(data);
}
