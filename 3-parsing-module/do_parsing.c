/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 05:03:39 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/12 00:43:03 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	read_file_content(t_data *data, char *file_path)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (false);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (my_list_push_back(&data->map_file_lines,
				my_list_new_elem(my_string_replace_char(line, '\n', '\0'),
					my_string_free)) == -1)
			return (my_list_clear(&(data->map_file_lines),
				my_string_free), close(fd), false);
	}
	return (close(fd), true);
}

void clear_parsing_data(t_data *data)
{
	my_list_clear(&(data->map_file_lines), my_string_free);
}

void	do_parsing(t_data *data, int ac, char **av)
{
	if (ac != 2 || !check_ext(av[1], ".cub"))
	{
		printf("Error\n");
		printf("bad arguments.\n");
		printf("one file must be provided with <.cub> extension\n");
		exit(EXIT_SUCCESS);
	}
	if (!read_file_content(data, av[1]))
	{
		printf("Error\n");
		printf("read_file_content()::failed\n");
		exit(EXIT_FAILURE);
	}
	clear_parsing_data(data);
}
