/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 08:45:37 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/14 09:16:36 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

void	check_textures(t_data *data)
{
	if (!data->so_tex.img || !data->no_tex.img 
		|| !data->we_tex.img || !data->ea_tex.img)
		exit_failure("load_textures::failed");
}

void	set_textures_data(t_data *data)
{
	data->so_tex.addr = mlx_get_data_addr(data->so_tex.img,
		&(data->so_tex.bits_per_pixel),
		&(data->so_tex.line_length),
		&(data->so_tex.endian)
	);
	data->no_tex.addr = mlx_get_data_addr(data->no_tex.img,
		&(data->no_tex.bits_per_pixel),
		&(data->no_tex.line_length),
		&(data->no_tex.endian)
	);
	data->we_tex.addr = mlx_get_data_addr(data->we_tex.img,
		&(data->we_tex.bits_per_pixel),
		&(data->we_tex.line_length),
		&(data->we_tex.endian)
	);
	data->ea_tex.addr = mlx_get_data_addr(data->ea_tex.img,
		&(data->ea_tex.bits_per_pixel),
		&(data->ea_tex.line_length),
		&(data->ea_tex.endian)
	);
}

void	check_textures_data(t_data *data)
{
	if (!data->so_tex.addr || !data->no_tex.addr 
		|| !data->we_tex.addr || !data->ea_tex.addr)
		exit_failure("load_textures::failed");
}

void	load_textures(t_data *data)
{
	data->so_tex.img = mlx_xpm_file_to_image(
		data->mlx,
		data->textures.so_file_path,
		&(data->so_tex.width),
		&(data->so_tex.height)
	);
	data->no_tex.img = mlx_xpm_file_to_image(
		data->mlx,
		data->textures.no_file_path,
		&(data->no_tex.width),
		&(data->no_tex.height)
	);
	data->we_tex.img = mlx_xpm_file_to_image(
		data->mlx,
		data->textures.we_file_path,
		&(data->we_tex.width),
		&(data->we_tex.height)
	);
	data->ea_tex.img = mlx_xpm_file_to_image(
		data->mlx,
		data->textures.ea_file_path,
		&(data->ea_tex.width),
		&(data->ea_tex.height)
	);
	check_textures(data);
	set_textures_data(data);
	check_textures_data(data);
}
