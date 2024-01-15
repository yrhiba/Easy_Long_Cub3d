/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:36:04 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/15 10:33:53 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void clear_data(t_data **data)
{
	my_list_clear(&((*data)->doors), clear_door);
	mlx_clear_window((*data)->mlx, (*data)->win);
	mlx_destroy_image((*data)->mlx, (*data)->frame->img);
	mlx_destroy_window((*data)->mlx, (*data)->win);
	free((*data)->frame);
	free((*data)->player);
	free((*data)->textures.ea_file_path);
	free((*data)->textures.no_file_path);
	free((*data)->textures.we_file_path);
	free((*data)->textures.so_file_path);
	free((*data));
}
