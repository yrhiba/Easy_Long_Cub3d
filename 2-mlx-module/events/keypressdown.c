/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypressdown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 00:42:26 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/11 01:11:22 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int keypressdown(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		redcrosspressed(data);
	return (0);
}
