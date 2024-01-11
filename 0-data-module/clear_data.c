/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:36:04 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/12 00:00:41 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void clear_data(t_data **data)
{
	mlx_clear_window((*data)->mlx, (*data)->win);
	mlx_destroy_image((*data)->mlx, (*data)->frame->img);
	mlx_destroy_window((*data)->mlx, (*data)->win);
	free((*data)->frame);
	free((*data));
}
