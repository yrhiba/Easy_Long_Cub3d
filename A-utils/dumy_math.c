/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumy_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 03:41:05 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/12 03:42:40 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

int	ft_max(int a, int b)
{
	if (a < b)
		return b;
	return a;
}