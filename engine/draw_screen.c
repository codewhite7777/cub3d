/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:52:35 by alee              #+#    #+#             */
/*   Updated: 2022/07/25 04:30:47 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "ray_casting.h"

void	draw_screen(t_cub3d *p_data)
{
	int		i;
	t_ray	ray_result;

	i = 0;
	while (i < WIN_WIDTH)
	{
		ray_cast(p_data, &ray_result, i);
		i++;
	}
	(void)p_data;
	(void)ray_result;
	return ;
}
