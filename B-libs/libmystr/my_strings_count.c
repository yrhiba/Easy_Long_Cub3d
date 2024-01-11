/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strings_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:06:45 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/03 10:19:04 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmystr.h"

int	my_strings_count(char **strs)
{
	int	i;

	if (!strs)
		return (-1);
	i = 0;
	while (strs[i])
		i++;
	return (i);
}
