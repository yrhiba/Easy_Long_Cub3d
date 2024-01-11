/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_parsing_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 00:45:36 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/12 00:46:22 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

void clear_parsing_data(t_data *data)
{
	my_list_clear(&(data->map_file_lines), my_string_free);
}
