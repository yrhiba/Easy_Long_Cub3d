/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 05:03:39 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/11 05:34:34 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void	do_parsing(t_data *data, int ac, char **av)
{
	if (ac != 2 || !check_ext(av[1], ".cub"))
	{
		printf("Error\n");
		printf("bad arguments.\n");
		printf("one file must be provided with <.cub> extension\n");
		exit(EXIT_SUCCESS);
	}
}
